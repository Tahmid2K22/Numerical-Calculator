#include "linear.h"
#include <bits/stdc++.h>
using namespace std;

LUDecomposition::LUDecomposition(int n)
{
    this->n = n;
}

void LUDecomposition::input_data(istream &inp)
{
    inp >> n;
    a.assign(n, vector<double>(n));
    b.assign(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inp >> a[i][j];
    for (int i = 0; i < n; i++)
        inp >> b[i];
}

void LUDecomposition::solve()
{
    L.assign(n, vector<double>(n, 0));
    U.assign(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n; k++)
        {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];
            U[i][k] = a[i][k] - sum;
        }

        for (int k = i; k < n; k++)
        {
            if (i == k)
                L[i][i] = 1;
            else
            {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];
                L[k][i] = (a[k][i] - sum) / U[i][i];
            }
        }
    }

    vector<double> y(n);
    for (int i = 0; i < n; i++)
    {
        double sum = b[i];
        for (int j = 0; j < i; j++)
            sum -= L[i][j] * y[j];
        y[i] = sum;
    }

    x.assign(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = y[i];
        for (int j = i + 1; j < n; j++)
            sum -= U[i][j] * x[j];
        x[i] = sum / U[i][i];
    }
}

void LUDecomposition::display_save(ostream &out)
{
    for (int i = 0; i < n; i++)
        out << x[i] << " ";
    out << endl;
}
