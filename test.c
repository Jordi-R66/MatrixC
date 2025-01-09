#include <stdio.h>
#include <string.h>

#include "matrix.h"

int main(void) {
	double* row_buffer;

	Matrix A;

	A.rows = 3;
	A.cols = 3;

	allocMatrix(&A);
	Matrix B;

	B.rows = 3;
	B.cols = 3;

	allocMatrix(&B);

	Matrix C;

	double A_content[] = { -2, 1, -3, 4, 1, 3, 4, -1 ,5 };
	double B_content[] = { -5, 1, -3, 4, -2, 3, 4, -1, 2 };

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