#include <stdio.h>
#include <malloc.h>

int main() {
	
	FILE* fnumber;
	int number; int index = 0;

	fopen_s(&fnumber, "in.txt", "r");
	fscanf_s(fnumber, "%d", &number);
	printf("n: %d\n", number);
	int* L = (int*) malloc(sizeof(int) * number);
	int minnumber = 99999999, maxnumber = 0;

	while (!feof(fnumber)) {
		fscanf_s(fnumber, "%d", &L[index]);
		minnumber = (L[index] < minnumber) ? L[index] : minnumber;
		maxnumber = (L[index] >= maxnumber) ? L[index] : maxnumber;
		index++;
	}

	printf("�ּڰ�: %d\n", minnumber);
	printf("�ִ�: %d\n", maxnumber);

	int x;
	do {
		printf("���� �Է�: ");
		scanf_s("%d", &x);
		if (x > 0)
			break;
	} while (x <= 0);

	FILE* ffnumber;
	fopen_s(&ffnumber, "out.txt", "w");
	fprintf_s(ffnumber, "%d�� ���: ", x);
	printf("%d�� ���: ", x);
	for (int i = 0; i < number; i++) {
		if (L[i] % x == 0) {
			fprintf_s(ffnumber, "%d ", L[i]);
			printf("%d ", L[i]);
		}
	}


	fclose(fnumber);
	fclose(ffnumber);

	return 0;

}