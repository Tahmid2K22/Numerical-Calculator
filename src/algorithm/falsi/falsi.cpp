#include "non-linear_equation.h"
#include <bits/stdc++.h>
using namespace std;

Falsi::Falsi(double a, double b, double step, double tol, int maxIter)
    : a(a), b(b), step(step), tol(tol), maxIter(maxIter) {}

void Falsi::input_data(istream &inp)
{
    inp >> degree;
    coef.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
        inp >> coef[i];
    inp >> a >> b >> step >> tol >> maxIter;
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
    int iter = 0;
    double al = a, ar = a;

    while (iter < maxIter)
    {
        al -= step;
        ar += step;

        if (fa * function(al, degree) < 0)
        {
            b = al;
            break;
        }
        if (fa * function(ar, degree) < 0)
        {
            b = ar;
            break;
        }

        iter++;
    }

    if (iter == maxIter)
        return;

    double fb = function(b, degree);
    double c, fc, temp = 1e18;
    iter = 0;

    while (1)
    {
        iter++;
        c = (a * fb - b * fa) / (fb - fa);
        fc = function(c, degree);

        if (fabs(fc - temp) <= tol || fabs(fc) < tol)
        {
            a = b = c;
            return;
        }

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

        temp = fc;

        if (iter >= maxIter)
        {
            a = b = c;
            return;
        }
    }
}

void Falsi::display_save(ostream &out)
{
    out << "[" << a << " " << b << "]" << endl;
    out << fixed << setprecision(6) << a << endl;
}
