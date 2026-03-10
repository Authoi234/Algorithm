#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;
    int mul = n * factorial(n-1);
    return mul;
}

int main()
{
    cout << factorial(5);
    return 0;
}