#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//计算每条边的长度
double CalculateLength(double x1, double y1, double x2, double y2) {
	double Length = sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
	return Length;
}

//计算周长
double CalculatePerimeter(double Length1, double Length2, double Length3) {
	double perimeter = Length1 + Length2 + Length3;
	return perimeter;
}

//计算面积
double CalculateArea(double Length1, double Length2, double Length3) {
	double s = (Length1 + Length2 + Length3) / 2;
	double area = sqrt(s * (s - Length1)*(s - Length2)*(s - Length3));
	return area;
}

int main() {
	double x1, y1, x2, y2, x3, y3;
	printf("输入三个点的坐标：");
	scanf("(%lf,%lf) (%lf,%lf) (%lf,%lf)", &x1, &y1, &x2, &y2, &x3, &y3);
	if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
		printf("Impossible!\n");
	}
	else {
		double Length1 = CalculateLength(x1, y1, x2, y2);
		double Length2 = CalculateLength(x2, y2, x3, y3);
		double Length3 = CalculateLength(x3, y3, x1, y1);
		double perimeter = CalculatePerimeter(Length1, Length2, Length3);
		double area = CalculateArea(Length1, Length2, Length3);
		printf("三角形的周长是：%lf\n三角形的面积是：%lf\n", perimeter, area);
	}
	return 0;
}