#include <bits/stdc++.h>
using namespace std;
int val[1005];
int weight[1005];

int knapsack(int i, int mx)
{
    if (i < 0 || mx <= 0)
        return 0;
    if (weight[i] <= mx)
    {
        int opt1 = knapsack(i - 1, mx - weight[i]) + val[i];
        int opt2 = knapsack(i - 1, mx);
        return max(opt1, opt2);
    }
    else
    {
        return knapsack(i - 1, mx);
    }
}

int main()
{   
    int n, mx_weight;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cin >> mx_weight;
    cout << knapsack(n - 1, mx_weight);
    return 0;
}