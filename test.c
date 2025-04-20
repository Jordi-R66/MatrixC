#include "matrix.h"

int main(void) {

	Matrix A, B, C;

	A.cols = 3;
	A.rows = 2;

	B.cols = 2;
	B.rows = 3;

	value_t A_values[6] = {1, 4, 2, 0, -1, 3};
	value_t B_values[6] = {3, 1, 2, -2, -1, 5};

	allocMatrix(&A);
	allocMatrix(&B);

	setMatrix(&A, A_values);
	setMatrix(&B, B_values);

	matrixMultiplication(&A, &B, &C);

	printMatrix(&A);
	printMatrix(&B);
	printf("\n");
	printMatrix(&C);

	deallocMatrix(&A);
	deallocMatrix(&B);

	return 0;
}