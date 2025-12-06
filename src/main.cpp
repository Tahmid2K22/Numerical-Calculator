#include "../include/interpolation.h"
#include "../include/inversion.h"
#include "../include/regression.h"
#include "../include/non-linear_equation.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inp("../tests/input.txt");
    ofstream out("../tests/output.txt");
    string operation;
    out << fixed << setprecision(8);

    while (inp >> operation)
    {
        if (operation == "interpolation")
        {
            Interpolation in;
            in.input_data(inp);
            in.f_interpolation();
            in.display_save(out);
        }
        else if (operation == "inversion")
        {
            inverse inv;
            inv.input_data(inp);
            inv.naive_inversion();
            inv.display_save(out);
        }
        else if (operation == "regression")
        {
            inp >> operation;
            regression reg;
            reg.input_data(inp);
            double x_target;
            inp >> x_target;
            if (operation == "linear")
            {
                out << "Linear Regression: " << reg.linear_regress(x_target) << endl;
            }
            else if (operation == "power")
            {
                out << "Power Transcendental Regression: " << reg.transcen_regress_power(x_target) << endl;
            }
            else if (operation == "exponential")
            {
                out << "Exponential Transcendental Regression: " << reg.transcen_regress_exp(x_target) << endl;
            }
            else if (operation == "polynomial")
            {
                out << "Polynomial Regression: " << reg.poly_regress(x_target) << endl;
            }
        }

        else if(operation=="bisection")
        {
            Bisection bisec;
            bisec.input_data(inp);
            bisec.biSection();
            bisec.display_save(out);

        }
        else if(operation=="falsi")
        {
            Falsi falsi;
            falsi.input_data(inp);
            falsi.falsePosition();
            falsi.display_save(out);
        }
    }

    inp.close();
    out.close();
    return 0;
}