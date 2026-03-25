#include <bits/stdc++.h>
using namespace std;

int dp[100000];

bool tagra_algorithm(int n, int x)
{
    if (x == n)
        return true;
    if (x > n)
        return false;
    if (dp[x] != -1)
        return dp[x];
    bool op1 = tagra_algorithm(n,x * 2);
    bool op2 = tagra_algorithm(n,x + 3);
    return dp[x] = (op1 || op2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 100000; i++)
        {
            dp[i] = -1;
        }
        
        int n;
        cin >> n;
        if (tagra_algorithm(n, 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}