#include "differentiation.h"
#include <bits/stdc++.h>
using namespace std;

DifferentiationForward::DifferentiationForward(int n)
{
    this->n = n;
    derivative = 0;
}

double DifferentiationForward::fact(int n)
{
    double res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

void DifferentiationForward::input_data(istream &inp)
{
    inp >> n;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) inp >> x[i];
    for (int i = 0; i < n; i++) inp >> y[i];
    inp >> point;
}

void DifferentiationForward::compute()
{
    vector<vector<double>> diff(n, vector<double>(n));
    for (int i = 0; i < n; i++) diff[i][0] = y[i];

    for (int j = 1; j < n; j++)
        for (int i = 0; i + j < n; i++)
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

    double h = x[1] - x[0];
    double u = (point - x[0]) / h;
    derivative = (diff[0][1] + (2 * u - 1) / fact(2) * diff[0][2] + (3 * u * u - 6 * u + 2) / fact(3) * diff[0][3]) / h;
}

void DifferentiationForward::display_save(ostream &out)
{
    out << derivative << endl;
}
