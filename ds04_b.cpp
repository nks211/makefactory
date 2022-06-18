#include <stdio.h>

int Binary_Representation(int R) {
	if (R / 2 == 0) {
		return (R == 1) ? 1 : 0;
	}
	else {
		if (R % 2 == 0) {
			return Binary_Representation((int) (R / 2));
		}
		else {
			return Binary_Representation((int)(R / 2)) + 1;
		}
	}
}

int main() {

	int binary;
	printf("정수 입력: ");
	scanf_s("%d", &binary);

	while (binary != -1) {
		printf("%d\n", Binary_Representation(binary));
		printf("정수 입력: ");
		scanf_s("%d", &binary);
	}

	return 0;
}