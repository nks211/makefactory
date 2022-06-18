#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* Matrix; FILE* keynumber;

	fopen_s(&Matrix, "in.txt", "r");
	fopen_s(&keynumber, "key.txt", "r");
	int Matrixnumber[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fscanf_s(Matrix, "%d", &Matrixnumber[i][j]);
		}
	}
	int length;
	fscanf_s(keynumber, "%d", &length);
	int* Arraynumber = (int*)malloc(sizeof(length));
	for (int k = 0; k < length; k++) {
		fscanf_s(keynumber, "%d", &Arraynumber[k]);
	}

	int checkrow = -1; int checkcol = -1; int pointer = 0;
	for (int m = 0; m < 10; m++) {
		for (int n = 0; n < 10; n++) {
			if (Arraynumber[pointer] == Matrixnumber[m][n]) {
				pointer++;
				if (pointer == length) {
					checkrow = m;
					checkcol = n - length + 1;
					break;
				}
			}	
			else
				pointer = 0;
		}
		pointer = 0;
	}
	printf("(%d, %d)\n", checkrow, checkcol);


	fclose(Matrix); fclose(keynumber);

	return 0;

}