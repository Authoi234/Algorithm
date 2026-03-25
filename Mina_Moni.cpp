#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> coins;
int total_sum;
int min_diff;

void dfs(int idx, int count, int sum, int targetSize)
{
    if (count > targetSize)
        return;
    if (idx == n)
    {
        if (count == targetSize)
        {
            min_diff = min(min_diff, abs(total_sum - 2 * sum));
        }
        return;
    }

    dfs(idx + 1, count + 1, sum + coins[idx], targetSize);
    dfs(idx + 1, count, sum, targetSize);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        coins.resize(n);
        total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
            total_sum += coins[i];
        }
        min_diff = total_sum; 
        dfs(0, 0, 0, n / 2);
        if (n % 2)
            dfs(0, 0, 0, n / 2 + 1);

        cout << min_diff << endl;
    }
}