#include "matrix.h"

#ifndef ROW_OPERATIONS_H
#define ROW_OPERATIONS_H

void rowSwap(Matrix *matrix, int row1, int row2);

void rowMultiply(Matrix *matrix, int row, double factor);

void rowMultiplyAndAdd(Matrix *matrix, int addRow, int multiplyRow, double factor);

#endif