#include "matrix.h"

int main(void) {

	Matrix M, A, B, C, D, E;

	M.rows = 4;
	M.cols = M.rows;

	allocMatrix(&M);

	value_t vals[16] = {0, 2, 1, 1,
						2, 2, 0, 0,
						1, 0, 0, 3,
						1, 0, 3, 0};

	setMatrix(&M, vals);

	printMatrix(&M);
	printf("EXP 2 -------------------------------------------------------\n");
	matrixMultiplication(&M, &M, &A);

	printMatrix(&A);
	printf("EXP 3 -------------------------------------------------------\n");
	matrixMultiplication(&A, &M, &B);

	printMatrix(&B);
	printf("EXP 4-------------------------------------------------------\n");
	matrixMultiplication(&B, &M, &C);

	printMatrix(&C);

	size_t n = getMatrixCase(&C, 2, 4);

	printf("%zu parcours\n", n);

	deallocMatrix(&A);
	deallocMatrix(&B);
	deallocMatrix(&C);
	deallocMatrix(&M);

	return 0;
}