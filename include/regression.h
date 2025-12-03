#ifndef REGRESSION_H
#define REGRESSION_H

#include <vector>
#include <iostream>

class regression
{

    double tx, ty, tx2, txy;
    std::vector<double> x, y;

public:
    regression();
    void input_data(std::istream &inp);
    void cal_sum(int ln = 0);
    double linear_regress(double x_target, int ln = 0);
    double transcen_regress_power(double x_target);
    double transcen_regress_exp(double x_target);
    std::vector<double> gauss_jordan(std::vector<std::vector<double>> &aug);
    double poly_regress(double x_target);
    void display_save(std::ostream &out);
};
#endif
