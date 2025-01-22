#include "advMatrix.h"

int main(void) {
	Tracker tracker;
	InitTracker(&tracker);
	Matrix A;

	A.rows = 3;
	A.cols = 4;

	allocMatrix(&A);

	value_t A_content[] = {
		0, -2, 3, 2,
		0, 2, -1, 3,
		0, -1, 2, 1 };

	setMatrix(&A, A_content);

	Gauss(&A, &tracker);

	printMatrix(&A);

	printTrackingLogs(&tracker);

	printf("Freeing ...\n");
	deallocTracker(&tracker);
	printf("Tracker freed\n");
	deallocMatrix(&A);
	printf("Done\n");

	return 0;
}