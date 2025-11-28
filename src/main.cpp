#include "../include/interpolation.h"
#include "../include/inversion.h"
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
        else if (operation == "inversion"){
            inverse inv;
            inv.input_data(inp);
            inv.naive_inversion();
            inv.display_save(out);
        }
        else {
            cout<<"Unknown Operation: "<<operation<<"\n";
        }
    }

    inp.close();
    out.close();
    return 0;
}