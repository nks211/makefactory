#include <stdio.h>
#include <malloc.h>

int main() {

	FILE* matrix1;
	FILE* matrix2;

	fopen_s(&matrix1, "m1.txt", "r");
	fopen_s(&matrix2, "m2.txt", "r");
	int index1, index2, index3;
	fscanf_s(matrix1, "%d", &index1);
	fscanf_s(matrix1, "%d", &index2);
	fscanf_s(matrix2, "%d", &index2);
	fscanf_s(matrix2, "%d", &index3);

	printf("%d %d\n", index1, index3);

	int** Matrix1; int** Matrix2; int** MatrixOutput;
	Matrix1 = (int**)malloc(sizeof(*Matrix1) * index1);
	Matrix2 = (int**)malloc(sizeof(*Matrix2) * index2);
	MatrixOutput = (int**)malloc(sizeof(*MatrixOutput) * index1);

	int row = (index1 >= index2) ? index1 : index2;
	int column = (index2 >= index3) ? index2 : index3;
	for (int i = 0; i < row; i++) {
		if(i < index1){
			Matrix1[i] = (int*)malloc(sizeof(**Matrix1) * index2);
		}
		if (i < index2) {
			Matrix2[i] = (int*)malloc(sizeof(**Matrix2) * index3);
		}
		for (int j = 0; j < column; j++) {
			if (j < index2) {
				fscanf_s(matrix1, "%d", &Matrix1[i][j]);
			}
			if (j < index3) {
				fscanf_s(matrix2, "%d", &Matrix2[i][j]);
			}
		}
	}
	for (int k = 0; k < index1; k++) {
		MatrixOutput[k] = (int*)malloc(sizeof(**MatrixOutput) * index3);
		for (int l = 0; l < index3; l++) {
			int index = 0;
			for (int m = 0; m < index2; m++) {
				index += Matrix1[k][m] * Matrix2[m][l];
			}
			MatrixOutput[k][l] = index;
			printf("%d ", MatrixOutput[k][l]);
		}
		printf("\n");
	}

	fclose(matrix1); fclose(matrix2);
	return 0;

}