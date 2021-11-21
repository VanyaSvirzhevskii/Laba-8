#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
typedef double (*uf)(double, double, int&);
void tabl(double, double, double, double, uf);
double y(double, double, int&);
double s(double, double, int&);
double y(double x, double eps, int& k) {
	return (3.14 * (3.14 - 2 * fabs(x))) / 8;
}

void tabl(double a, double b, double h, double eps, uf fun) {
	int k = 0;
	double sum;
	for (double x = a; x < b; x += h) {
		sum = fun(x, eps, k);
		cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
	}

}

double s(double x, double eps, int& k)
{
	double a, c, sum;
	sum = a = c = x;
	k = 1;
	while (fabs(c) > eps)
	{
		c = (cos((2 * k - 1) * x)) / pow(2 * k - 1, 2);
		a = c;
		sum += a;
		k++;
	}
	return sum;
}

int main()
{
	cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
	tabl(-2, 2, 0.4, 0.0001, y);
	cout << endl;
	cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
	tabl(-2, 2, 0.4, 0.0001, s);
	return 0;

}