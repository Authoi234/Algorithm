#include <bits/stdc++.h>
using namespace std;
int val[1005];
int weight[1005];
int dp[1005][1005];

int knapsack(int i, int mx)
{
    if (i < 0 || mx <= 0)
        return 0;
    if (dp[i][mx] != -1)
        return dp[i][mx];
    if (weight[i] <= mx)
    {
        int opt1 = knapsack(i - 1, mx - weight[i]) + val[i];
        int opt2 = knapsack(i - 1, mx);
        dp[i][mx] = max(opt1, opt2);
        return dp[i][mx];
    }
    else
    {
        dp[i][mx] = knapsack(i - 1, mx);
        return dp[i][mx];
    }
}

int main()
{
    int n, mx_weight;
    cin >> n >> mx_weight;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1;
    cout << knapsack(n - 1, mx_weight);
    return 0;
}