#include <bits/stdc++.h>
using namespace std;

class inverse
{
    vector<vector<double>> mat;
    long long n;

public:
    inverse(vector<vector<double>> &mat, long long size) : mat(mat), n(size) {}

    vector<vector<double>> cofact(long long x, long long y)
    {
        vector<vector<double>> res(n - 1, vector<double>(n - 1));
        long long r = 0, c = 0;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                if (i != x && j != y)
                {
                    res[r][c] = mat[i][j];
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
    double determinant(vector<vector<double>> &m)
    {
        if (m.size() == 1)
            return m[0][0];
        if (m.size() == 2)
            return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
        long long sign = 1;
        double res = 0;
        long long n = m.size();
        for (long long i = 0; i < n; i++)
        {
            vector<vector<double>> cof = cofact(0, i);
            res += (sign * (m[0][i] * determinant(cof)));
            sign *= -1;
        }
        return res;
    }

    vector<vector<double>> adjoint()
    {
        vector<vector<double>> res(n, vector<double>(n, 0.0));
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                vector<vector<double>> cof = cofact(i, j);
                long long sign = ((i + j) % 2 == 0) ? 1 : -1;
                res[j][i] = sign * determinant(cof);
            }
        }
        return res;
    }

    vector<vector<double>> naive_inversion()
    {
        vector<vector<double>> res(n, vector<double>(n, 0.0));
        double det = determinant(mat);
        if (det == 0)
        {
            cout << "Inverse Doesn't Exists\n";
            return res;
        }

        vector<vector<double>> adj = adjoint();
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                res[i][j] = adj[i][j] / det;
            }
        }
        return res;
    }
};

// int main()
// {
//     long long n;
//     cin >> n;
//     vector<vector<double>> mat(n, vector<double>(n, 0.0));
//     for (long long i = 0; i < n; i++)
//     {
//         for (long long j = 0; j < n; j++)
//         {
//             cin >> mat[i][j];
//         }
//     }
//     inverse inv(mat, n);
//     vector<vector<double>> res = inv.naive_inversion();
//     for (long long i = 0; i < n; i++)
//     {
//         for (long long j = 0; j < n; j++)
//         {
//             cout << res[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }