#pragma once
#include <bits/stdc++.h>
using namespace std;

class RKMethod
{
private:
    double x0, y0;
    double h;
    int n;
    function<double(double, double)> f;

public:
    RKMethod(double x0 = 0, double y0 = 0, double h = 0.1, int n = 10);

    void input_data(istream &inp);
    void input_function(function<double(double, double)> func);
    void rungeKutta();
    void display_save(ostream &out);
};
