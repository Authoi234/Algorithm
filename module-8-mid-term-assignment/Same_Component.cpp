#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj, char grid[1005][1005])
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj, grid);
    }
}

int main()
{
    cin >> n >> m;
    char grid[1005][1005];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int Si, Sj, Di, Dj;
    cin >> Si >> Sj >> Di >> Dj;

    if (!valid(Si, Sj) || !valid(Di, Dj) || grid[Si][Sj] != '.' || grid[Di][Dj] != '.')
    {
        cout << "NO\n";
        return 0;
    }

    dfs(Si, Sj, grid);

    cout << (vis[Di][Dj] ? "YES\n" : "NO\n");
    return 0;
}