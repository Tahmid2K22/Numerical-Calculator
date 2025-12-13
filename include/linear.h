#pragma once
#include <bits/stdc++.h>
using namespace std;

class GaussJordan
{
private:
    int n;
    vector<vector<double>> a;
    vector<double> x;

public:
    GaussJordan(int n = 0);

    void input_data(istream &inp);
    void solve();
    void display_save(ostream &out);
};

class GaussElimination
{
private:
    int n;
    vector<vector<double>> a;
    vector<double> x;

public:
    GaussElimination(int n = 0);

    void input_data(istream &inp);
    void solve();
    void display_save(ostream &out);
};

class LUDecomposition
{
private:
    int n;
    vector<vector<double>> a;
    vector<vector<double>> L;
    vector<vector<double>> U;
    vector<double> b;
    vector<double> x;

public:
    LUDecomposition(int n = 0);

    void input_data(istream &inp);
    void solve();
    void display_save(ostream &out);
};
