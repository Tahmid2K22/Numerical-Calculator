#include "../include/interpolation.h"
#include "../include/inversion.h"
#include "../include/regression.h"
#include "../include/non-linear_equation.h"
#include "../include/linear.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inp("../tests/input.txt");
    ofstream out("../tests/output.txt");
    string operation;
    string method;
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
            // Optional method token: regression [linear|power|exponential|polynomial]
            // If omitted, defaults to linear regression.
            method = "linear";
            {
                streampos pos = inp.tellg();
                string maybeMethod;
                if (inp >> maybeMethod)
                {
                    if (maybeMethod == "linear" || maybeMethod == "power" || maybeMethod == "exponential" || maybeMethod == "polynomial")
                    {
                        method = maybeMethod;
                    }
                    else
                    {
                        inp.clear();
                        inp.seekg(pos);
                    }
                }
                else
                {
                    inp.clear();
                }
            }
            regression reg;
            reg.input_data(inp);
            double x_target;
            inp >> x_target;
            if (method == "linear")
            {
                out << "Linear Regression: " << reg.linear_regress(x_target) << endl;
            }
            else if (method == "power")
            {
                out << "Power Transcendental Regression: " << reg.transcen_regress_power(x_target) << endl;
            }
            else if (method == "exponential")
            {
                out << "Exponential Transcendental Regression: " << reg.transcen_regress_exp(x_target) << endl;
            }
            else if (method == "polynomial")
            {
                out << "Polynomial Regression: " << reg.poly_regress(x_target) << endl;
            }
        }
        else if (operation == "bisection")
        {
            Bisection bisec;
            bisec.input_data(inp);
            bisec.biSection();
            bisec.display_save(out);
        }
        else if (operation == "falsi")
        {
            Falsi falsi;
            falsi.input_data(inp);
            falsi.falsePosition();
            falsi.display_save(out);
        }
        else if (operation == "newtonraphson")
        {
            NewtonRaphson newton;
            newton.input_data(inp);
            newton.newton();
            newton.display_save(out);
        }
        else if (operation == "secant")
        {
            Secant sec;
            sec.input_data(inp);
            sec.secantMethod();
            sec.display_save(out);
        }
        else if (operation == "gaussjordan")
        {
            GaussJordan gaussjordan;
            gaussjordan.input_data(inp);
            gaussjordan.solve();
            gaussjordan.display_save(out);
        }
        else if (operation == "gausselimination")
        {
            GaussElimination gausselimination;
            gausselimination.input_data(inp);
            gausselimination.solve();
            gausselimination.display_save(out);
        }
        else if (operation == "ludecomposition")
        {
            LUDecomposition ludecomposition;
            ludecomposition.input_data(inp);
            ludecomposition.solve();
            ludecomposition.display_save(out);
        }
    }

    inp.close();
    out.close();
    return 0;
}
