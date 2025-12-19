#include "non-linear_equation.h"
#include <bits/stdc++.h>
using namespace std;

NewtonRaphson::NewtonRaphson(double a, double tol, int maxIter)
    : a(a), tol(tol), maxIter(maxIter) {}

void NewtonRaphson::input_data(istream &inp)
{
    inp >> degree;
    coef.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
        inp >> coef[i];
    inp >> a >> tol >> maxIter;
}

double NewtonRaphson::function(double x)
{
    double res = 0;
    for (int i = 0; i <= degree; i++)
        res += coef[i] * pow(x, degree - i);
    return res;
}

double NewtonRaphson::derivative(double x)
{
    double res = 0;
    for (int i = 0; i < degree; i++)
        res += coef[i] * (degree - i) * pow(x, degree - i - 1);
    return res;
}

void NewtonRaphson::newton()
{
    int iter = 0;
    double x0 = a, x1;

    while (iter < maxIter)
    {
        double df = derivative(x0);
        if (fabs(df) < 1e-12)
            break;

        x1 = x0 - function(x0) / df;

        if (fabs(x1 - x0) < tol || fabs(function(x1)) < tol)
        {
            a = x1;
            return;
        }

        x0 = x1;
        iter++;
    }

    a = x0;
}

void NewtonRaphson::display_save(ostream &out)
{
    out << fixed << setprecision(6) << a << endl;
}
