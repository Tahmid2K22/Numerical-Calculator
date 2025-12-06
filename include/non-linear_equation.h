#include <bits/stdc++.h>
using namespace std;

class Bisection
{
private:
    double a, b;
    double tol;
    int maxIter;
    int degree;
    vector<double> coef;

public:
    Bisection(double a = 0, double b = 0, double tol = 1e-6, int maxIter = 1000);

    void input_data(istream &inp);
    double function(double x, int d);
    void biSection();
    void display_save(ostream &out);
};

class Falsi
{
private:
    double a, b;
    double tol;
    int maxIter;
    int degree;
    vector<double> coef;

public:
    Falsi(double a = 0, double b = 0, double tol = 1e-6, int maxIter = 1000);

    void input_data(istream &inp);
    double function(double x, int d);
    void falsePosition();
    void display_save(ostream &out);
};
