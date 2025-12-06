#include "../../../include/non-linear_equation.h"
#include <bits/stdc++.h>
using namespace std;

Bisection::Bisection(double a, double b, double step, double tol, int maxIter)
    : a(a), b(b), step(step), tol(tol), maxIter(maxIter) {}

void Bisection::input_data(istream &inp)
{
    inp >> degree;
    coef.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
        inp >> coef[i];
    inp >> a >> b >> step >> tol >> maxIter;
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
    double c;
    iter = 0;

    while (1)
    {
        iter++;
        c = (a + b) / 2.0;
        double fc = function(c, degree);

        if (fabs(fc) < tol || fabs(b - a) < tol)
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

        if (iter >= maxIter)
        {
            a = b = c;
            return;
        }
    }
}

void Bisection::display_save(ostream &out)
{
    out << "[" << a << " " << b << "]" << endl;
    out << (a + b) / 2.0 << endl;
}
