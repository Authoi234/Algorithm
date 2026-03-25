#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int tribo[n + 1];
    tribo[0] = 0;
    tribo[1] = 1;
    tribo[2] = 1;
    tribo[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        tribo[i] = tribo[i - 1] + tribo[i - 2] + tribo[i-3] + tribo[i-4];
    }
    cout << tribo[n];
    return 0;
}