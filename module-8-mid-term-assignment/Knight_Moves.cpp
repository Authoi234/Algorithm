#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[105][105];

vector<pair<int, int>> d = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int bfs(int si, int sj, int di, int dj)
{
    queue<pair<pair<int,int>, int>> q;


    //  Queue ta erokom:
    // ___________________________
    // | INT | INT | INT | INT |            
    // |-----------|-----------|
    // |    INT    |    INT    |
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    

    q.push({{si, sj}, 0});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<pair<int,int>, int> par = q.front();
        q.pop();

        int par_i = par.first.first;
        int par_j = par.first.second;
        int the_number_of_steps = par.second;

        if (par_i == di && par_j == dj)
            return the_number_of_steps;

        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({{ci, cj}, the_number_of_steps + 1});
                vis[ci][cj] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        // I call the knight - Ghora (horse) , I call the queen - Montri (Minister)
        int Gi, Gj, Mi, Mj;
        cin >> Gi >> Gj;
        cin >> Mi >> Mj;

        memset(vis, false, sizeof(vis));

        cout << bfs(Gi, Gj, Mi, Mj) << endl;
    }

    return 0;
}