#include "differentiation.h"
#include <bits/stdc++.h>
using namespace std;

DifferentiationBackward::DifferentiationBackward(int n)
{
    this->n = n;
    derivative = 0;
}

double DifferentiationBackward::fact(int n)
{
    double res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

void DifferentiationBackward::input_data(istream &inp)
{
    inp >> n;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) inp >> x[i];
    for (int i = 0; i < n; i++) inp >> y[i];
    inp >> point;
}

void DifferentiationBackward::compute()
{
    vector<vector<double>> diff(n, vector<double>(n));
    for (int i = 0; i < n; i++) diff[i][0] = y[i];

    for (int j = 1; j < n; j++)
        for (int i = n - 1; i >= j; i--)
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];

    double h = x[1] - x[0];
    double u = (point - x[n - 1]) / h;
    derivative = (diff[n - 1][1] + (2 * u + 1) / fact(2) * diff[n - 1][2] + (3 * u * u + 6 * u + 2) / fact(3) * diff[n - 1][3]) / h;
}

void DifferentiationBackward::display_save(ostream &out)
{
    out << derivative << endl;
}
