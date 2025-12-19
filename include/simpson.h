#pragma once
#include <bits/stdc++.h>
using namespace std;

class SimpsonOneThird
{
private:
    double a, b;
    int n;
    int degree;
    double res;
    vector<double> coef;

    double function(double x);

public:
    SimpsonOneThird(double a = 0, double b = 0, int n = 2);

    void input_data(istream &inp);
    void solve();
    void display_save(ostream &out);
};

class SimpsonThreeEight
{
private:
    double a, b;
    int n;
    int degree;
    double res;
    vector<double> coef;

    double function(double x);

public:
    SimpsonThreeEight(double a = 0, double b = 0, int n = 3);

    void input_data(istream &inp);
    void solve();
    void display_save(ostream &out);
};
