/*
Copyright 2012-2018 Jun Wako, Jack Humbert, Yiancar

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "matrix.h"
#include "quantum.h"

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

// Wait for stable signal after setting pin to output
void select_delay(void)   { wait_us(0.25); }

// Wait for stable signal after setting pin to input
void unselect_delay(void) { wait_us(30); }

static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinInputHigh_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinInputHigh(pin);
    }
}

// Read input pin state. Return 1 (not pressed) if pin is NO_PIN.
static inline uint8_t readMatrixPin(pin_t pin) {
    if (pin == NO_PIN) return 1;

    return readPin(pin);
}

// Set row pin to OUTPUT_LOW. Return false if row uses NO_PIN.
static bool select_row(uint8_t row) {
    pin_t pin = row_pins[row];
    if (pin == NO_PIN) return false;

    setPinOutput_writeLow(pin);
    return true;
}

// Set row pin to INPUT_PULLUP
static void unselect_row(uint8_t row) {
    pin_t pin = row_pins[row];
    if (pin == NO_PIN) return;

    setPinInputHigh_atomic(pin);
}

// Set all row pins to INPUT_PULLUP
static void unselect_rows(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        unselect_row(row);
    }
}

// Set col pin to OUTPUT_LOW. Return false if col uses NO_PIN.
static bool select_col(uint8_t col) {
    pin_t pin = col_pins[col];
    if (pin == NO_PIN) return false;

    setPinOutput_writeLow(pin);
    return true;
}

// Set col pin to INPUT_PULLUP
static void unselect_col(uint8_t col) {
    pin_t pin = col_pins[col];
    if (pin == NO_PIN) return;

    setPinInputHigh_atomic(pin);
}

// Set all col pins to INPUT_PULLUP
static void unselect_cols(void) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        unselect_col(col);
    }
}



static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t row_index) {
    // Select row pin
    if (!select_row(row_index)) {  // skip NO_PIN rows
        return false;
    }
    select_delay();

    bool matrix_has_changed = false;

    // Store last value of row prior to reading
    matrix_row_t last_row_value    = current_matrix[row_index];
    matrix_row_t current_row_value = last_row_value;
    matrix_row_t row_shifter = MATRIX_ROW_SHIFTER;

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++, row_shifter <<= 1) {
        if (col_pins[col_index] == NO_PIN) continue;  // Skip any NO_PIN

        // Check col pin state
        if (readMatrixPin(col_pins[col_index]) == 0) {
            // Pin LO, set col bit
            current_row_value |= row_shifter;
        } else {
            // Pin HI, clear col bit
            current_row_value &= ~row_shifter;
        }
    }

    // Determine if the matrix changed state
    if (current_matrix[row_index] != current_row_value) {
        current_matrix[row_index] = current_row_value;
        matrix_has_changed = true;
    }

    unselect_row(row_index);
    unselect_delay();
    return matrix_has_changed;
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col, matrix_row_t row_shifter) {
    // Select column pin
    if (!select_col(current_col)) { // skip NO_PIN columns
        return false;
    }
    select_delay();

    bool matrix_changed = false;

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        if (row_pins[row_index] == NO_PIN) continue;  // Skip any NO_PIN

        // Store last value of row prior to reading
        matrix_row_t last_row_value    = current_matrix[row_index];
        matrix_row_t current_row_value = last_row_value;

        // Check row pin state
        if (readMatrixPin(row_pins[row_index]) == 0) {
            // Pin LO, set col bit
            current_row_value |= row_shifter;
        } else {
            // Pin HI, clear col bit
            current_row_value &= ~row_shifter;
        }

        // Determine if the matrix changed state
        if ((last_row_value != current_row_value)) {
            matrix_changed = true;
			current_matrix[row_index] = current_row_value;
        }
    }

    unselect_col(current_col);
    unselect_delay();
    return matrix_changed;
}


void matrix_init_custom(void) {
    unselect_rows();
    unselect_cols();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

    // Set row, read cols
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        matrix_has_changed |= read_cols_on_row(current_matrix, row_index);
    }
    // Set col, read rows
    matrix_row_t row_shifter = MATRIX_ROW_SHIFTER << (MATRIX_COLS/2);  // start at the second half of each matrix row
    for (uint8_t col_idx = 0; col_idx < MATRIX_COLS; col_idx++, row_shifter <<= 1) {
        matrix_has_changed |= read_rows_on_col(current_matrix, col_idx, row_shifter);
    }

    return matrix_has_changed;
}
