#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>

enum precedence { lparenthese, rparenthese, plus, minus, times, divide, mod, eos, operand };
int Stack[MAX_STACK_SIZE];
char Expression[MAX_STACK_SIZE];
int top = -1;

void push(int number) {
	if (top >= MAX_STACK_SIZE - 1) {
		fprintf(stderr, "스택이 꽉찼습니다.\n");
		exit(EXIT_FAILURE);
	}
	Stack[++top] = number;
}

int pop() {
	if (top < 0) {
		fprintf(stderr, "스택에 저장된 값이 없습니다.\n");
		exit(EXIT_FAILURE);
	}
	return Stack[top--];
}

precedence gettoken(char expression, int n) {
	expression = Expression[(n)];
	switch (expression) {
	case '(':
		return lparenthese;
	case ')':
		return rparenthese;
	case '+':
		return plus;
	case '-':
		return minus;
	case '*':
		return times;
	case '/':
		return divide;
	case '%':
		return mod;
	case '\0':
		return eos;
	default:
		return operand;
	}
}

int evaluation() {
	int operand1, operand2;
	int n = 0;
	char letter = Expression[n];
	precedence token;
	token = gettoken(letter, n++);
	while (letter != NULL) {
		if (token == operand) {
			push(letter - '0');
		}
		else {
			operand2 = pop();
			operand1 = pop();
			switch (token) {
			case plus:
				push(operand1 + operand2);
				break;
			case minus:
				push(operand1 - operand2);
				break;
			case times:
				push(operand1 * operand2);
				break;
			case divide:
				push(operand1 / operand2);
				break;
			case mod:
				push(operand1 % operand2);
				break;
			}
			token = gettoken(letter, n++);
		}
	}
	return pop();
}

int main() {

	FILE* operation;

	fopen_s(&operation, "in.txt", "r");
	int index = 0;
	while (!feof(operation)) {
		fscanf_s(operation, "%c", &Expression[index]);
		index++;
	}
	fclose(operation);


	printf("%d\n", evaluation());

	return 0;

}