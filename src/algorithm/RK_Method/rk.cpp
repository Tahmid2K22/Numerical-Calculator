#include "../../../include/rk_method.h"
#include <bits/stdc++.h>
using namespace std;

RKMethod::RKMethod(double x0, double y0, double h, int n)
{
    this->x0 = x0;
    this->y0 = y0;
    this->h = h;
    this->n = n;
}

void RKMethod::input_data(istream &inp)
{
    inp >> x0 >> y0 >> h >> n;
}

void RKMethod::input_function(function<double(double, double)> func)
{
    f = func;
}

void RKMethod::rungeKutta()
{
    double x = x0;
    double y = y0;

    for (int i = 0; i < n; i++)
    {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x += h;
    }

    y0 = y;
}

void RKMethod::display_save(ostream &out)
{
    out << y0 << endl;
}
