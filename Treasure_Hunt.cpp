#include <bits/stdc++.h>
using namespace std;

int n, k, w;
int val[130];

int dp[130][10005][130];

int knapsack(int i, int mx, int k)
{
    if (i <= 0 || mx <= 0 || k == 0)
        return 0;

    if (dp[i][mx][k] != -1)
        return dp[i][mx][k];

    int ans;
    if (i <= mx)
    {
        int opt1 = knapsack(i - 1, mx - i, k - 1) + val[i];
        int opt2 = knapsack(i - 1, mx, k);
        ans = max(opt1, opt2);
    }
    else
        ans = knapsack(i - 1, mx, k);

    return dp[i][mx][k] = ans;
}

int main()
{
    cin >> n >> k >> k;

    for (int i = 1; i <= n; i++)
        cin >> val[i];

    memset(dp, -1, sizeof(dp));

    cout << knapsack(n, w, k) << endl;

    return 0;
}