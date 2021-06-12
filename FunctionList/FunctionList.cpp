#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cstdio>
#include <cmath>
#include <math.h>

using namespace std;

const int n = 100;
const auto pi = 3.1415926535897932384626433832795;

double my_exp(double x)
{
    double s = 0, q = 1;
    for (int k = 0; k <= n; k++)
    {
        s += q;
        q *= x / (double(k) + 1.);
    }
    return s;
}

double my_sin(double x)
{
    double s = 0, q = x;
    for (int k = 0; k <= n; k++)
    {
        s += q;
        q *= (-1.) * x * x / (2. * double(k) + 2.) / (2. * double(k) + 3.);
    }
    return s;
}

double my_cos(double x)
{
    double s = 0, q = 1;
    for (int k = 0; k <= n; k++)
    {
        s += q;
        q *= (-1.) * x * x / (2. * double(k) + 1.) / (2. * double(k) + 2.);
    }
    return s;
}

int main()
{
    string names[3] = { "exp", "sin", "cos" };
    double x[6] = { 0, pi / 6., pi / 4., pi / 3., 1, pi / 2. };

    vector < function<double(double)>> dFunc;
    dFunc.push_back(my_exp);
    dFunc.push_back(my_sin);
    dFunc.push_back(my_cos);

    for (int i = 0; i < 3; i++)
    {
        cout << names[i] << "\t";
        for (int j = 0; j < 6; j++)
        {
            printf("%f", dFunc[i](x[j]));
            printf("%s", "\t");
        }
        cout << endl;
    }
    return 0;
}