#pragma once
#include <bits/stdc++.h>
using namespace std;

class Bisection
{
private:
    double a, b;
    double tol;
    double step;
    int maxIter;
    int degree;
    vector<double> coef;

public:
    Bisection(double a = 0, double b = 0, double step = 0.2, double tol = 1e-6, int maxIter = 1000);

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
    double step;
    int maxIter;
    int degree;
    vector<double> coef;

public:
    Falsi(double a = 0, double b = 0, double step = 0.2, double tol = 1e-6, int maxIter = 1000);

    void input_data(istream &inp);
    double function(double x, int d);
    void falsePosition();
    void display_save(ostream &out);
};

class NewtonRaphson
{
private:
    double a;      
    double tol;
    int maxIter;
    int degree;
    vector<double> coef;
    double function(double x);
    double derivative(double x);

public:
    NewtonRaphson(double a = 0, double tol = 1e-6, int maxIter = 1000);

    void input_data(istream &inp);
    void newton();
    void display_save(ostream &out);
};

