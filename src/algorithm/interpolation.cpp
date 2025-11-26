#include <bits/stdc++.h>
using namespace std;

class Interpolation
{
    long long n;
    vector<double> x;
    vector<double> y;

public:
    Interpolation(long long n, vector<double> &x, vector<double> &y) : n(n), x(x), y(y) {}

    vector<double> cal_diff(vector<double> &y, long long diff = 0, long long it = 0)
    {
        vector<double> res;
        for (long long i = 1; i < (long long)y.size(); i++)
        {
            res.push_back(y[i] - y[i - 1]);
            if (diff)
                res.back() /= (x[i + it] - x[i - 1]);
        }
        return res;
    }

    double f_interpolation(double val, string method)
    {
        vector<double> ndel_y = y;
        double coef = 1.0;
        double h = x[1] - x[0];
        double v;
        long long diff = 0;
        if (method == "backward")
            v = (val - x[n - 1]) / h;
        if (method == "forward")
            v = (val - x[0]) / h;
        if (method == "div_diff")
            diff = 1;

        double res = 0, it = 0;
        for (long long i = 0; i < n; i++)
        {
            if (method == "forward" || method == "div_diff")
                res += (coef * ndel_y[0]);
            else if (method == "backward")
                res += (coef * ndel_y[ndel_y.size() - 1]);
            ndel_y = cal_diff(ndel_y, diff, it);
            if (method == "forward")
                coef *= ((v - i) / (i + 1));
            else if (method == "backward")
                coef *= ((v + i) / (i + 1));
            else if (method == "div_diff")
            {
                coef *= (val - x[i]);
                it++;
            }
        }

        return res;
    }
};

int main()
{
    long long n;
    cin >> n;
    vector<double> x(n), y(n);
    for (long long i = 0; i < n; i++)
        cin >> x[i];
    for (long long i = 0; i < n; i++)
        cin >> y[i];
    double val;
    cin >> val;
    Interpolation interp(n, x, y);
    double result = interp.f_interpolation(val, "forward");
    cout << result << endl;
    result = interp.f_interpolation(val, "backward");
    cout << result << endl;
    result = interp.f_interpolation(val, "div_diff");
    cout << result << endl;
    return 0;
}