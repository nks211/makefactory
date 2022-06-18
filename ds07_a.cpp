#include <stdio.h>
#include <malloc.h>

typedef struct element{
	int rownumber;
	int colnumber;
	int valuenumber;
};

void FastTranspose(element A[], element B[]) {
	int StartPosition[12];
	int Rowcount[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	StartPosition[0] = 1; int index;
	B[0].rownumber = A[0].colnumber;
	B[0].colnumber = A[0].rownumber;
	B[0].valuenumber = A[0].valuenumber;
	if (A[0].valuenumber > 0) {
		for (int m = 1; m <= A[0].valuenumber; m++)
			Rowcount[A[m].colnumber]++;
		for (int n = 1; n < A[0].colnumber; n++)
			StartPosition[n] = StartPosition[n - 1] + Rowcount[n - 1];
		for (int o = 1; o <= A[0].valuenumber; o++) {
			index = StartPosition[A[o].colnumber]++;
			B[index].rownumber = A[o].colnumber;
			B[index].colnumber = A[o].rownumber;
			B[index].valuenumber = A[o].valuenumber;
		}
	}
}

int main() {

	FILE* Matrix;
	FILE* TransposeMatrix;

	fopen_s(&Matrix, "m.txt", "r");
	int Matrixnumber[10][12];
	int nonzerocount = 0;
	element* NonzeroElement = (element*)malloc(sizeof(element) * 121);
	NonzeroElement[0].rownumber = 10;
	NonzeroElement[0].colnumber = 12;
	NonzeroElement[0].valuenumber = nonzerocount;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			fscanf_s(Matrix, "%d", &Matrixnumber[i][j]);
			if (Matrixnumber[i][j] != 0) {
				nonzerocount++;
				NonzeroElement[nonzerocount].rownumber = i;
				NonzeroElement[nonzerocount].colnumber = j;
				NonzeroElement[nonzerocount].valuenumber = Matrixnumber[i][j];
				NonzeroElement[0].valuenumber++;
			}
		}
	}
	fclose(Matrix);

	for (int k = 0; k <= nonzerocount; k++) {
		printf("%d %d %d\n", NonzeroElement[k].rownumber, NonzeroElement[k].colnumber, NonzeroElement[k].valuenumber);
	}

	fopen_s(&TransposeMatrix, "out.txt", "w");
	element* TransposeElement = (element*)malloc(sizeof(element) * (nonzerocount + 1));
	FastTranspose(NonzeroElement, TransposeElement);
	for (int element = 0; element <= nonzerocount; element++) {
		fprintf_s(TransposeMatrix, "%d ", TransposeElement[element].rownumber);
		fprintf_s(TransposeMatrix, "%d ", TransposeElement[element].colnumber);
		fprintf_s(TransposeMatrix, "%d ", TransposeElement[element].valuenumber);
		fprintf_s(TransposeMatrix, "\n");
	}
	fclose(TransposeMatrix);

	return 0;

}