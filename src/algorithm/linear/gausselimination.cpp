#include "../../../include/linear.h"
#include <bits/stdc++.h>
using namespace std;

GaussElimination::GaussElimination(int n)
{
    this->n = n;
}

void GaussElimination::input_data(istream &inp)
{
    inp >> n;
    a.assign(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            inp >> a[i][j];
}

void GaussElimination::solve()
{
    for (int i = 0; i < n; i++)
    {
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(a[j][i]) > fabs(a[pivot][i])) pivot = j;

        if (pivot != i) swap(a[pivot], a[i]);
        if (a[i][i] == 0) return;

        for (int j = i + 1; j < n; j++)
        {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++)
                a[j][k] -= factor * a[i][k];
        }
    }

    x.assign(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = a[i][n];
        for (int j = i + 1; j < n; j++)
            sum -= a[i][j] * x[j];
        x[i] = sum / a[i][i];
    }
}

void GaussElimination::display_save(ostream &out)
{
    for (int i = 0; i < n; i++)
        out << x[i] << " ";
    out << endl;
}
