#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[1005][1005];
bool vis[1005][1005];

// ! tiring biring changing variable !
int tmp_room_cnt = 0;
//

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    tmp_room_cnt++;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    vector<int> rooms_cnt;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                tmp_room_cnt = 0;
                dfs(i, j);
                rooms_cnt.push_back(tmp_room_cnt);
            }
        }
    }
    if (rooms_cnt.empty())
    {
        cout << 0;
        return 0;
    }
    sort(rooms_cnt.begin(), rooms_cnt.end());
    for (int i : rooms_cnt)
        cout << i << " ";
    return 0;
}