#include "common.h"
#include "matrix.h"

#include "gauss.h"

int main(void) {
	double* row_buffer;

	Matrix A;

	A.rows = 3;
	A.cols = 3;

	allocMatrix(&A);
	//Matrix B;

	//B.rows = 3;
	//B.cols = 3;

	//allocMatrix(&B);

	//Matrix C;

	double A_content[] = {
		-2, 1, -3,
		4, 0, 3,
		0, 0 ,5 };

	double B_content[] = {
		-5, 1, -3,
		4, -2, 3,
		4, -1, 2 };

	setMatrix(&A, A_content);
	//setMatrix(&B, B_content);

	//matrixMultiplication(&A, &B, &C);
	//row_buffer = (double*)calloc(C.cols, sizeof(double));

	//printMatrix(&C);

	//subtractRows(&C, 0, 2, 1);

	printMatrix(&A);

	printf("-------------------------\n");

	Swap* swaps = (Swap*)malloc(1 * sizeof(Swap));
	size_t swapsMade = 0;

	QuickSort(&A, 0, A.rows-1, &swaps, &swapsMade);

	free(swaps);

	deallocMatrix(&A);
	//deallocMatrix(&B);
	//deallocMatrix(&C);

	//free(row_buffer);

	return 0;
}