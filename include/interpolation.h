#pragma once
#include <vector>
#include <string>

class Interpolation
{
private:
    long long n;
    std::vector<double> x;
    std::vector<double> y;

public:
    Interpolation(long long n, std::vector<double> &x, std::vector<double> &y);

    std::vector<double> cal_diff(std::vector<double> &y, long long diff = 0, long long it = 0);
    double f_interpolation(double val, std::string method);
};