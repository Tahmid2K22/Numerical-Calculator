#include "../../../include/inversion.h"
#include <bits/stdc++.h>
using namespace std;


inverse::inverse(){}
inverse::inverse(vector<vector<double>> &mat, long long size) : mat(mat), n(size) {}

void inverse::input_data(istream &inp)
{
    inp >> n;
    mat.resize(n, vector<double>(n));
    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < n; j++)
            inp >> mat[i][j];
    return;
}

vector<vector<double>> inverse::cofact(long long x, long long y, vector<vector<double>> &m)
{
    long long n = m.size();
    vector<vector<double>> res(m.size() - 1, vector<double>(m.size() - 1));
    long long r = 0, c = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            if (i != x && j != y)
            {
                res[r][c] = m[i][j];
                c++;
                if (c >= n - 1)
                {
                    c = 0;
                    r++;
                }
            }
        }
    }
    return res;
}

double inverse::determinant(vector<vector<double>> &m)
{
    if (m.size() == 1)
        return m[0][0];
    if (m.size() == 2)
        return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
    long long sign = 1;
    double res = 0;
    long long n_size = m.size();
    for (long long i = 0; i < n_size; i++)
    {
        vector<vector<double>> cof = cofact(0, i, m);
        res += (sign * (m[0][i] * determinant(cof)));
        sign *= -1;
    }
    return res;
}

vector<vector<double>> inverse::adjoint()
{
    vector<vector<double>> res(n, vector<double>(n, 0.0));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            vector<vector<double>> cof = cofact(i, j, mat);
            long long sign = ((i + j) % 2 == 0) ? 1 : -1;
            res[j][i] = sign * determinant(cof);
        }
    }
    return res;
}

void inverse::naive_inversion()
{
    double det = determinant(mat);
    if (det == 0)
    {
        cout << "Inverse Doesn't Exist" << endl;
        return;
    }

    vector<vector<double>> adj = adjoint();
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            mat[i][j] = adj[i][j] / det;
        }
    }
}

void inverse::display_save(ostream &out)
{
    for (long long i = 0; i < n; i++){  
        for (long long j = 0; j < n; j++){
            out << mat[i][j] << " ";
            cout << mat[i][j] << " ";
        }
        out << endl;
        cout << endl;
    }
}

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<double>> matrix(n, vector<double>(n));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             cin >> matrix[i][j];
//     inverse inv(matrix, n);
//     inv.naive_inversion();
//     inv.display_save(cout);
    
//     return 0;
// }