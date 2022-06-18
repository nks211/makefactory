#define MAX_NUMBER 100
#include <stdio.h>
#include <stdlib.h>

void Radix16Sort(char Number[MAX_NUMBER][4], int link[], int digit, int radix, int n) {
	int* front = (int*)malloc(sizeof(int) * (radix));
	int* rear = (int*)malloc(sizeof(int) * (radix));
	link[0] = NULL;
	int firstindex, lastindex, currentindex, a;

	firstindex = 1;

	for (int index = digit - 1; index >= 0; index--) {
		for (a = 0; a < radix; a++)
			front[a] = 0;

		for (currentindex = firstindex; currentindex; currentindex = link[currentindex]) {
			if (Number[currentindex][index] <= '9')
				a = Number[currentindex][index] - '0';
			else if (Number[currentindex][index] >= 'A')
				a = Number[currentindex][index] - 55;
			if (front[a] == 0)
				front[a] = currentindex;
			else
				link[rear[a]] = currentindex;
			rear[a] = currentindex;
		}

		for (a = 0; !front[a]; a++);

		firstindex = front[a];
		lastindex = rear[a];

		for (a++; a < radix; a++) {
			if (front[a]) {
				link[lastindex] = front[a];
				lastindex = rear[a];
			}
		}
		link[lastindex] = 0;
	}

	int result = firstindex;
	while (result != 0) {
		for (int k = 0; k < 4; k++)
			printf("%c", Number[result][k]);
		printf("\n");
		result = link[result];
	}

}

int main() {

	FILE* Radix16Number;

	fopen_s(&Radix16Number, "in.txt", "r");
	char Numberset[MAX_NUMBER][4] = { NULL };
	int i = 1; int digit = 0;
	while (!feof(Radix16Number)) {
		char number = fgetc(Radix16Number);
		if (number != '\n') {
			Numberset[i][digit] = number;
			if (digit == 3) {
				i++; digit = 0;
			}
			else
				digit++;
		}
	}
	fclose(Radix16Number);

	int* link = (int*)malloc(sizeof(int) * (i));
	for (int d = 1; d < i - 1; d++) {
		link[d] = d + 1;
	}
	link[i - 1] = 0;

	Radix16Sort(Numberset, link, 4, 16, i - 1);

	return 0;

}