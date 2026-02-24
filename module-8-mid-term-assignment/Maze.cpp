#include <bits/stdc++.h>
using namespace std;

int n, m, ri, rj, di, dj;
int level[1005][1005];
pair<int, int> parent[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
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
            if (grid[i][j] == '#')
                vis[i][j] = true;
            else if (grid[i][j] == '.')
                vis[i][j] = false;
            else if (grid[i][j] == 'D')
            {
                vis[i][j] = false;
                di = i;
                dj = j;
            }
            else if (grid[i][j] == 'R')
            {
                vis[i][j] = false;
                ri = i;
                rj = j;
            }
        }
    }

    memset(level, -1, sizeof(level));

    queue<pair<int, int>> q;
    q.push({ri, rj});
    vis[ri][rj] = true;
    level[ri][rj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int pi = par.first;
        int pj = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
                parent[ci][cj] = {pi, pj};
            }
        }
    }

    if (level[di][dj] == -1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << grid[i][j];
            cout << endl;
        }
        return 0;
    }

    vector<pair<int, int>> kothin;
    int ci = di;
    int cj = dj;
    while (!(ci == ri && cj == rj))
    {
        kothin.push_back({ci, cj});
        pair<int, int> p = parent[ci][cj];
        ci = p.first;
        cj = p.second;
    }

    kothin.push_back({ri, rj});
    reverse(kothin.begin(), kothin.end());

    for (auto rasta : kothin)
    {
        int i = rasta.first;
        int j = rasta.second;

        if (grid[i][j] != 'R' && grid[i][j] != 'D')
            grid[i][j] = 'X';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << endl;
    }
}