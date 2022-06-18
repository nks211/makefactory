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

	printf("최솟값: %d\n", minnumber);
	printf("최댓값: %d\n", maxnumber);

	int x;
	do {
		printf("정수 입력: ");
		scanf_s("%d", &x);
		if (x > 0)
			break;
	} while (x <= 0);

	FILE* ffnumber;
	fopen_s(&ffnumber, "out.txt", "w");
	fprintf_s(ffnumber, "%d의 배수: ", x);
	printf("%d의 배수: ", x);
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