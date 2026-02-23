#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int si, int sj)
{

    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            dfs(ci, cj);
    }
}
int main()
{
    int si, sj;
    int dsti, dstj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'B') {
                dsti = i;
                dstj = j;
            }
        }

    memset(vis, false, sizeof(vis));
    dfs(si, sj);
    if (!vis[dsti][dstj])
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    
    return 0;
}