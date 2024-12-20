#include <stdio.h>
#include <string.h>

#include "matrix.h"

int main(void) {
	double* row_buffer;

	Matrix A;

	A.rows = 3;
	A.cols = 2;

	allocMatrix(&A);
	Matrix B;

	B.rows = 2;
	B.cols = 4;

	allocMatrix(&B);

	Matrix C;

	double A_content[] = { 1.0, -2.0, 2.0, 0.0, -1.0, 4.0 };
	double B_content[] = { 0.0, 2.0, 1.0, -1.0, -2.0, 3.0, 1.0, 0.0 };

	memcpy(A.data, A_content, sizeof(A_content));
	memcpy(B.data, B_content, sizeof(B_content));

	matrixMultiplication(&A, &B, &C);
	row_buffer = (double*)calloc(C.cols, sizeof(double));

	for (size_t row = 0; row < C.rows; row++) {
		getMatrixRow(&C, row, row_buffer);

		for (size_t i = 0; i < C.cols; i++) {
			printf("%.0f ", row_buffer[i]);
		}
		printf("\n");
	}

	deallocMatrix(&A);
	deallocMatrix(&B);
	deallocMatrix(&C);

	free(row_buffer);

	return 0;
}