#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long Fibonacci_recursion(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return Fibonacci_recursion(n - 1) + Fibonacci_recursion(n - 2);
	}
}


int main() {
	clock_t start, finish;
	double elapsed;

	int n;
	printf("숫자 입력: ");
	scanf_s("%d", &n);
	while (n >= 0 && n <= 40) {
		start = clock();
		long* Fibonacci = (long*)malloc(sizeof(long) * (n + 1));
		for (int i = 0; i < n + 1; i++) {
			if (i == 0) {
				Fibonacci[i] = 0;
			}
			else if (i == 1) {
				Fibonacci[i] = 1;
			}
			else {
				for (int j = 2; j <= i; j++) {
					Fibonacci[j] = Fibonacci[j - 1] + Fibonacci[j - 2];
				}
			}
		}
		printf("%d번째 피보나치 수: %lu\n", n, Fibonacci[n]);
		finish = clock();
		elapsed = ((double)finish - (double)start) / CLOCKS_PER_SEC;
		printf("iteration 계산시간: %f ms\n", elapsed * 1000);
		start = clock();
		printf("%d번째 피보나치 수: %lu\n", n, Fibonacci_recursion(n));
		finish = clock();
		elapsed = ((double)finish - (double)start) / CLOCKS_PER_SEC;
		printf("recursion 계산시간: %f ms\n", elapsed * 1000);
		free(Fibonacci);
		printf("숫자 입력: ");
		scanf_s("%d", &n);
		if (n < 0 || n > 40)
			break;
	}

	return 0;
}