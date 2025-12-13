#include "../../../include/linear.h"
#include <bits/stdc++.h>
using namespace std;

GaussJordan::GaussJordan(int n)
{
    this->n = n;
}

void GaussJordan::input_data(istream &inp)
{
    inp >> n;
    a.assign(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
            inp >> a[i][j];
    }
}

void GaussJordan::solve()
{
    for (int i = 0; i < n; i++)
    {
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(a[j][i]) > fabs(a[pivot][i])) pivot = j;

        if (pivot != i) swap(a[pivot], a[i]);

        double div = a[i][i];
        if (div == 0) return;

        for (int j = 0; j <= n; j++)
            a[i][j] /= div;

        for (int r = 0; r < n; r++)
        {
            if (r == i) continue;
            double factor = a[r][i];
            for (int c = 0; c <= n; c++)
                a[r][c] -= factor * a[i][c];
        }
    }

    x.resize(n);
    for (int i = 0; i < n; i++)
        x[i] = a[i][n];
}

void GaussJordan::display_save(ostream &out)
{
    for (int i = 0; i < n; i++)
        out << x[i] << " ";
    out << endl;
}
