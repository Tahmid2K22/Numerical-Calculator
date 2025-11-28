#include "../../../include/interpolation.h"
#include <bits/stdc++.h>
using namespace std;


Interpolation::Interpolation() {
    method = "NONE";
}







vector<double> Interpolation::cal_diff(vector<double> &y, long long diff, long long it)
{
    vector<double> res;
    if (y.size() <= 1)
        return res;
    for (long long i = 1; i < (long long)y.size(); i++)
    {
        res.push_back(y[i] - y[i - 1]);
        if (diff)
            res.back() /= (x[i + it] - x[i - 1]);
    }
    return res;
}

double Interpolation::f_interpolation()
{
    vector<double> ndel_y = y;
    double coef = 1.0;
    double h = x[1] - x[0];
    double v;
    long long diff = 0;
    if (method == "backward")
        v = (target - x[n - 1]) / h;
    if (method == "forward")
        v = (target - x[0]) / h;
    if (method == "div_diff")
        diff = 1;

    double res = 0, it = 0;
    for (long long i = 0; i < n; i++)
    {
        if (method == "forward" || method == "div_diff")
            res += (coef * ndel_y[0]);
        else if (method == "backward")
            res += (coef * ndel_y[ndel_y.size() - 1]);
        ndel_y = cal_diff(ndel_y, diff, it);
        if (method == "forward")
            coef *= ((v - i) / (i + 1));
        else if (method == "backward")
            coef *= ((v + i) / (i + 1));
        else if (method == "div_diff")
        {
            coef *= (target - x[i]);
            it++;
        }
    }
    result = res;
    return res;
}



void Interpolation::input_data(ifstream &inp) {
   
    inp >> n;
    x.resize(n);
    y.resize(n);
   
    for (long long i = 0; i < n; i++) {
        inp >> x[i] >> y[i];
        //cout << "Data Point " << i + 1 << ": (" << x[i] << ", " << y[i] << ")\n";
    }
   
    inp >> target;
    inp >> method;
    if(method=="NONE") {
        dynamic_method_find();
    }
   
}

void Interpolation::display_save(ofstream &out) {
    out << "Data Points:\n";
    for (long long i = 0; i < n; i++) {
        //out << x[i] << " " << y[i] << "\n";
    }
    out << "Result: " << result << "\n";
    cout << "Result: " << result << "\n";

}

void Interpolation::dynamic_method_find()
{
    if(method!="NONE") return;
    double h = x[1]-x[0];
    for(int i=2;i<n;i++) {
        if(abs((x[i]-x[i-1])-h)>1e-9) {
            method="div_diff";
            return;
        }
    }
    if(abs(target-x[0])<=abs(target-x[n-1])) method="forward";
    else method="backward";
    
    return;
}