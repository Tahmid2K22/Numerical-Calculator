#pragma once
#include <bits/stdc++.h>
using namespace std;

class DifferentiationForward
{
private:
    int n;
    vector<double> x;
    vector<double> y;
    double point;
    double derivative;
    double fact(int n);

public:
    DifferentiationForward(int n = 0);
    void input_data(istream &inp);
    void compute();
    void display_save(ostream &out);
};

class DifferentiationBackward
{
private:
    int n;
    vector<double> x;
    vector<double> y;
    double point;
    double derivative;
    double fact(int n);

public:
    DifferentiationBackward(int n = 0);
    void input_data(istream &inp);
    void compute();
    void display_save(ostream &out);
};
