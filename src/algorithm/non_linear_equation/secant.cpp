#include "../../../include/non-linear_equation.h"
#include <bits/stdc++.h>
using namespace std;

Secant::Secant(double a, double b, double tol, int maxIter)
    : a(a), b(b), tol(tol), maxIter(maxIter) {}

void Secant::input_data(istream &inp)
{
    inp >> degree;
    coef.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
        inp >> coef[i];
    inp >> a >> b >> tol >> maxIter;
}

double Secant::function(double x)
{
    double result = 0;
    for (int i = 0; i <= degree; i++)
        result += coef[i] * pow(x, degree - i);
    return result;
}

void Secant::secantMethod()
{
    double x0 = a, x1 = b, x2;
    int iter = 0;
    double f0 = function(x0), f1 = function(x1);

    while (iter < maxIter)
    {
        if (fabs(f1 - f0) < 1e-18) break;
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        double f2 = function(x2);
        if (fabs(x2 - x1) < tol && fabs(f2) < tol)
        {
            a = b = x2;
            return;
        }

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        iter++;
    }

    a = b = x2;
}

void Secant::display_save(ostream &out)
{
    out << "[" << a << " " << b << "]" << endl;
    out << fixed << setprecision(6) << a << endl;
}
