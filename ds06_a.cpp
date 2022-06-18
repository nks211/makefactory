#define MAX_TERMS 100

#include <stdio.h>
#include <stdlib.h>

int COMPARE(int a, int b) {
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

typedef struct polynomial {
	float coef;
	int expon;
};

polynomial terms[MAX_TERMS];
int avail = 0;
int start = 0; int finish = 0;

void attach(float coefficient, int exponent)
{ /* add a new term to the polynomial */
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}


/* add A(x) and B(x) to obtain D(x) */
void padd(int startA, int finishA, int startB,
	int finishB) {
	float coefficient;
	start = avail;
	while (startA <= finishA && startB <= finishB)
		switch (COMPARE(terms[startA].expon,
			terms[startB].expon)) {
		case -1: /* a expon < b expon */
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0: /* equal exponents */
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1: /* a expon > b expon */
			attach(terms[startA].coef,
				terms[startA].expon);
			startA++;
		}
	/* add in remaining terms of A(x) */
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	/* add in remaining terms of B(x) */
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	finish = avail;
}

int main() {

	FILE* polynomialA;
	FILE* polynomialB;

	fopen_s(&polynomialA, "a.txt", "r");
	fopen_s(&polynomialB, "b.txt", "r");
	int Aterm, Bterm;
	fscanf_s(polynomialA, "%d", &Aterm);
	fscanf_s(polynomialB, "%d", &Bterm);

	float coefficient; int exponent;
	for (int i = 0; i < Aterm; i++) {
		fscanf_s(polynomialA, "%f", &coefficient);
		fscanf_s(polynomialA, "%d", &exponent);
		attach(coefficient, exponent);
	}
	float Coefficient; int Exponent;
	for (int j = 0; j < Bterm; j++) {
		fscanf_s(polynomialB, "%f", &Coefficient);
		fscanf_s(polynomialB, "%d", &Exponent);
		attach(Coefficient, Exponent);
	}
	
	int startA = 0; int startB = Aterm;
	padd(startA, Aterm - 1, startB, Aterm + Bterm - 1);
	
	printf("%d ", finish - start);
	for (int i = Aterm + Bterm; i < Aterm + Bterm + avail; i++) {
		printf("%.0f %d ", terms[i].coef, terms[i].expon);
	}

	return 0;

}