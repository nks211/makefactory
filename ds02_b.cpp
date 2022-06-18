#include <stdio.h>
#include <stdbool.h>

bool prime(int x, int y) {
	if (x == 1 || y == 1) {
		return true;
	}
	else {
		if (x > y) {
			return prime(x-y, y);
		}
		else if (x < y) {
			return prime(x, y - x);
		}
		else {
			return false;
		}
	}
}

int main() {
	
	FILE* primefile;
	int x, y;

	fopen_s(&primefile, "in.txt", "r");
	fscanf_s(primefile, "%d", &x);
	fscanf_s(primefile, "%d", &y);
	printf("%s\n", prime(x, y)? "true" : "false");
	fclose(primefile);

}