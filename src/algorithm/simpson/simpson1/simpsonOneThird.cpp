#include "../../../include/simpson.h"
#include <bits/stdc++.h>
using namespace std;

SimpsonOneThird::SimpsonOneThird(double a, double b, int n)
{
    this->a = a;
    this->b = b;
    this->n = n;
    res = 0;
    degree = 0;
}

void SimpsonOneThird::input_data(istream &inp)
{
    inp >> a >> b >> n;
    inp >> degree;
    coef.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
        inp >> coef[i];
}

double SimpsonOneThird::function(double x)
{
    double result = 0;
    for (int i = 0; i <= degree; i++)
        result += coef[i] * pow(x, degree - i);
    return result;
}

void SimpsonOneThird::solve()
{
    if (n % 2 != 0) return;

    double h = (b - a) / n;
    double sum = function(a) + function(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * function(x);
        else
            sum += 4 * function(x);
    }

    res = (h / 3.0) * sum;
}

void SimpsonOneThird::display_save(ostream &out)
{
    out << res << endl;
}
