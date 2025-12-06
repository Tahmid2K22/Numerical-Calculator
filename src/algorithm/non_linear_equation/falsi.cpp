#include "../../../include/non-linear_equation.h"
#include <bits/stdc++.h>
using namespace std;

Falsi::Falsi(double a, double b, double tol, int maxIter)
    : a(a), b(b), tol(tol), maxIter(maxIter) {}

void Falsi::input_data(istream &inp)
{
    inp >> degree;
    coef.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
        inp >> coef[i];
    inp >> a >> b >> tol >> maxIter;
}

double Falsi::function(double x, int d)
{
    double result = 0;
    for (int i = 0; i <= d; i++)
        result += coef[i] * pow(x, d - i);
    return result;
}

void Falsi::falsePosition()
{
    double fa = function(a, degree);
    double fb = function(b, degree);

    if (fa * fb > 0)
        return;

    int iter = 0;
    double c = 0;

    while (iter < maxIter)
    {
        c = (a * fb - b * fa) / (fb - fa);
        double fc = function(c, degree);

        if (fabs(fc) < tol)
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

void Falsi::display_save(ostream &out)
{
    out << "[" << a << " " << b << "]" << endl;
    out << (a * function(b, degree) - b * function(a, degree)) /(function(b, degree) - function(a, degree))<< endl;
}
