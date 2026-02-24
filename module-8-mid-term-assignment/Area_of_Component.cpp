#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, mn;
bool vis[1005][1005];
char grid[1005][1005];
vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    mn = INT_MAX;
    bool found = false;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt = 0;
                found = true;
                dfs(i, j);
                mn = min(cnt, mn);
            }
    if (!found)
        mn = -1;
    cout << mn << "\n";
    return 0;
}