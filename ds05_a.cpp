#include <stdio.h>
#include <malloc.h>

int main() {

	FILE* matrix1; 
	FILE* matrix2;

	fopen_s(&matrix1, "m1.txt", "r");
	fopen_s(&matrix2, "m2.txt", "r");
	int row, column;
	fscanf_s(matrix1, "%d", &row);
	fscanf_s(matrix2, "%d", &row);
	fscanf_s(matrix1, "%d", &column);
	fscanf_s(matrix2, "%d", &column);

	printf("%d %d\n", row, column);

	int** Matrix1; int** Matrix2; int** MatrixOutput;
	Matrix1 = (int**)malloc(sizeof(*Matrix1) * row);
	Matrix2 = (int**)malloc(sizeof(*Matrix2) * row);
	MatrixOutput = (int**)malloc(sizeof(*MatrixOutput) * row);
	for (int i = 0; i < row; i++) {
		Matrix1[i] = (int*)malloc(sizeof(**Matrix1) * column);
		Matrix2[i] = (int*)malloc(sizeof(**Matrix2) * column);
		MatrixOutput[i] = (int*)malloc(sizeof(**MatrixOutput) * column);
		for (int j = 0; j < column; j++) {
			fscanf_s(matrix1, "%d", &Matrix1[i][j]);
			fscanf_s(matrix2, "%d", &Matrix2[i][j]);
			MatrixOutput[i][j] = Matrix1[i][j] + Matrix2[i][j];
			printf("%d ", MatrixOutput[i][j]);
		}
		printf("\n");
	}

	//for(int k = 0; k < row; k++){
	//	free(Matrix1[k]); free(Matrix2[k]); free(MatrixOutput[k]);
	//}

	fclose(matrix1); fclose(matrix2);
	return 0;

}