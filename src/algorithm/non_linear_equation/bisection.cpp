#include "../../../include/non-linear_equation.h"
#include <bits/stdc++.h>
using namespace std;

Bisection::Bisection(double a, double b, double tol, int maxIter)
    : a(a), b(b), tol(tol), maxIter(maxIter) {}

void Bisection::input_data(istream &inp)
{
    inp >> degree;
    coef.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
        inp >> coef[i];
    inp >> a >> b >> tol >> maxIter;
}

double Bisection::function(double x, int d)
{
    double result = 0;
    for (int i = 0; i <= d; i++)
        result += coef[i] * pow(x, d - i);
    return result;
}

void Bisection::biSection()
{
    double fa = function(a, degree);
    double fb = function(b, degree);

    if (fa * fb > 0)
        return;

    int iter = 0;
    double c;

    while (iter < maxIter)
    {
        c = (a + b) / 2.0;
        double fc = function(c, degree);

        if (fabs(fc) < tol || (b - a) / 2.0 < tol)
            break;

        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }

        iter++;
    }

}

void Bisection::display_save(ostream &out)
{
    out << "[" << a << " " << b << "]" << endl;
    out << (a + b) / 2.0 << endl;
}
