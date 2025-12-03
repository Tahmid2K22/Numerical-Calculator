#include "../../../include/regression.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long

regression::regression() {}

void regression::input_data(istream &inp)
{
    int n;
    inp >> n;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++)
        inp >> x[i];
    for (int i = 0; i < n; i++)
        inp >> y[i];
}

void regression::cal_sum(int ln)
{
    tx = ty = tx2 = txy = 0;
    for (ll i = 0; i < (ll)min(x.size(), y.size()); i++)
    {
        double x_val = x[i], y_val = y[i];
        if (ln == 1)
        {
            x_val = log(x[i]);
            y_val = log(y[i]);
        }
        else if (ln == 2)
        {
            y_val = log(y[i]);
        }

        tx += x_val;
        ty += y_val;
        tx2 += x_val * x_val;
        txy += x_val * y_val;
    }
}
double regression::linear_regress(double x_target, int ln)
{
    cal_sum(ln);
    ll n = min(x.size(), y.size());
    if ((n * tx2 - (tx) * (tx)) < 1e-9)
    {
        cout << "Division by zero in linear regression" << endl;
        return -1;
    }
    double b = (n * txy - tx * ty) / (n * tx2 - (tx) * (tx));
    double a = (ty - b * tx) / n;

    if (ln == 1)
    {
        a = exp(a);
        return a * pow(x_target, b);
    }
    else if (ln == 2)
    {

        a = exp(a);
        return a * exp(b * x_target);
    }
    return ((a + b * x_target));
}

double regression::transcen_regress_power(double x_target)
{
    return linear_regress(x_target, 1);
}

double regression::transcen_regress_exp(double x_target)
{
    return linear_regress(x_target, 2);
}

vector<double> regression::gauss_jordan(vector<vector<double>> &aug)
{
    ll n = aug.size();
    ll m = aug[0].size();
    for (ll i = 0; i < n; i++)
    {
        double pivot = aug[i][i];
        for (ll j = 0; j < m; j++)
            aug[i][j] /= pivot;

        for (ll k = 0; k < n; k++)
        {
            if (k == i)
                continue;
            double factor = aug[k][i];
            for (ll j = 0; j < m; j++)
                aug[k][j] -= factor * aug[i][j];
        }
    }
    vector<double> res;
    for (ll i = 0; i < n; i++)
        res.push_back(aug[i][n]);
    return res;
}
double regression::poly_regress(double x_target)
{
    ll degree = 2; 
    ll n = degree + 1;
    vector<vector<double>> aug(n, vector<double>(n + 1, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll k = 0; k < (ll)x.size(); k++)
            {
                aug[i][j] += pow(x[k], i + j);
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll k = 0; k < (ll)x.size(); k++)
        {
            aug[i][n] += (pow(x[k], i) * y[k]);
        }
    }
    auto res = gauss_jordan(aug);
    if (res.empty())
        return -1;

    double ans = 0;
    for (ll i = 0; i < (ll)res.size(); i++)
        ans += res[i] * pow(x_target, i);

    return ans;
}

