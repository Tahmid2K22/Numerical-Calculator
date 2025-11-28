#pragma once
#include <bits/stdc++.h>
using namespace std;

class inverse
{
private:
    vector<vector<double>> mat;
    long long n;

public:
    inverse();
    inverse(vector<vector<double>> &mat, long long size);

    void input_data(istream &inp);
    vector<vector<double>> cofact(long long x, long long y, vector<vector<double>> &mat);
    double determinant(vector<vector<double>> &m);
    vector<vector<double>> adjoint();
    void naive_inversion();
    void display_save(ostream &out);
};
