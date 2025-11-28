#pragma once
#include <bits/stdc++.h>
using namespace std;

class Interpolation
{
private:
    long long n;
    vector<double> x;
    vector<double> y;
    double result;
    double target;
    string method;

public:
    Interpolation(long long n, vector<double> &x, vector<double> &y, double target, string method="NONE") : n(n), x(x), y(y), target(target), method(method) {};
    Interpolation();

    vector<double> cal_diff(vector<double> &y, long long diff = 0, long long it = 0);
    double f_interpolation();
    void input_data(ifstream &inp);
    void display_save(ofstream &out);
};