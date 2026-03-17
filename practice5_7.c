#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

double Factorial(int num) {
	double result = 1;
	for (int i = 1;i <= num;i++) {
		result = result * i;
	}
	return result;
}

double funcos(double e, double x) {
	double LastItem = 1.0;
	int count = 0;
	double cosx = 1.0;
	while (LastItem >= e) {
		count++;
		double factorial = Factorial(2 * count);
		LastItem = pow(x, 2 * count) / factorial;
		cosx += pow(-1, count) * LastItem;
	}
	return cosx;
}

int main() {
	double e, x;
	printf("输入精度e和x：");
	scanf("%lf %lf", &e, &x);
	if (e > 1.0) {
		printf("Error!\n");
	}
	else {
		double cosx = funcos(e, x);
		printf("cos%lf = %lf", x, cosx);
	}
	return 0;
}