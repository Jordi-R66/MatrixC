#include "common.h"
#include "matrix.h"

#include "gauss.h"

int main(void) {
	Matrix A;

	A.rows = 3;
	A.cols = 4;

	allocMatrix(&A);

	double A_content[] = {
		2, -2, 3, 2,
		1, 2, -1, 3,
		3, -1, 2, 1 };

	setMatrix(&A, A_content);

	Gauss(&A);

	printMatrix(&A);

	deallocMatrix(&A);

	return 0;
}