#define MAX_SIZE 100

#include <stdio.h>
#include <stdlib.h>

char Stack[MAX_SIZE];
int top = -1;

void push(char letter) {
	if (top >= MAX_SIZE - 1) {
		printf("Full stack\n");
		exit(1);
	}
	else
		Stack[++top] = letter;
}

char pop() {
	if (top < 0) {
		printf("Empty stack\n");
		exit(1);
	}
	return Stack[top--];
}

char peek() {
	if (top < 0) {
		printf("Empty stack\n");
		exit(1);
	}
	return Stack[top];
}

int priority(char o) {
	switch (o) {
		case '(': case ')':
			return 0;
		case '+': case '-':
			return 1;
		case '*': case '/': case '%':
			return 2;
	}
	return -1;
}

void convert(char infix[]) {
	int i = 0;
	char letter, word;
	letter = infix[i];
	while (letter != NULL) {
		switch (letter) {
			case '+': case '-': case '*': case '/': case '%':
				while (top != -1 && (priority(letter) <= priority(peek()))) {
					printf("%c", pop());
				}
				push(letter);
				break;
			case '(':
				push(letter);
				break;
			case ')':
				word = pop();
				while (word != '(') {
					printf("%c", word);
					word = pop();
				}
				break;
			case '0': case '1': case '2':
			case '3': case '4': case '5':
			case '6': case '7': case '8': case '9':
				printf("%c", letter);
				break;
		}
		letter = infix[++i];
	}
	while (top >= 0) {
		printf("%c", pop());
	}
}

int main() {

	FILE* infixorder;
	fopen_s(&infixorder, "in.txt", "r");
	char infix[MAX_SIZE];
	char P; int i = 0;
	P = fgetc(infixorder);
	while (P != -1) {
		infix[i++] = P; P = fgetc(infixorder);
	}
	infix[i] = '\0';
	int t = 0;
	while (infix[t]) {
		printf("%c", infix[t++]);
	}
	printf("\n");
	convert(infix);
	fclose(infixorder);

	return 0;

}