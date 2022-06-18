#include <stdio.h>
#include <string.h>

void Palindrome_recursive(char* letter) {
	
	if (strlen(letter) <= 2) {
		if (letter[0] == letter[strlen(letter) - 1]) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	else {
		if (letter[0] == letter[strlen(letter) - 1]) {
			char* newletter = letter - letter[0];
			newletter = newletter -letter[strlen(letter) - 1];
			Palindrome_recursive(newletter);
		}
		else {
			printf("No\n");
		}
	}
}

int main() {

	char letter[20];
	printf("문자 입력: ");
	scanf_s("%s", letter, 20);

	while (letter != "#") {
		printf("%d\n", strlen(letter));
		int dex = 0;
		
		for (int i = 0; i < strlen(letter); i++) {
			if (letter[i] >= 'a' && letter[i] <= 'z') {
				dex++;
			}
			else {
				dex = i;
				break;
			}
		}
		if (dex != strlen(letter)) {
			break;
		}

		Palindrome_recursive(letter);
		gets_s(letter, 20);
		printf("문자 입력: ");
		scanf_s("%s", letter, 20);
	}

	return 0;
}