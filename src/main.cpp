#include "../include/interpolation.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inp("../tests/input.txt");
    ofstream out("../tests/output.txt");
    string operation;

    while (inp >> operation)
    {
        if (operation == "interpolation")
        {
            Interpolation in;
            in.input_data(inp);
            in.f_interpolation();
            in.display_save(out);
        }
        else if (operation == "inverse")
        {
           
        }
    }

    inp.close();
    out.close();
    return 0;
}