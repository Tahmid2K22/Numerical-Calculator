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
