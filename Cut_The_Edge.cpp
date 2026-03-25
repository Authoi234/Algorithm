#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[200006];
bool vis[200006];
int khoroch[200006];
set<pair<int, int>> cut;

void dfs(int src, int depth)
{
    vis[src] = true;
    khoroch[src] = 2 * depth;

    for (int child : adj_list[src])
    {
        if (vis[child])
            continue;
        if (cut.count({src, child}))
            continue;

        dfs(child, depth + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    vector<bool> has_parent(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        has_parent[i] = false;
        vis[i] = false;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        edges.push_back({u, v});
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;

        cut.insert({u, v});
        cut.insert({v, u});
    }

    for (auto e : edges)
    {
        int u = e.first;
        int v = e.second;

        if (cut.count({u, v}))
            continue;

        has_parent[v] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!has_parent[i] && !vis[i])
        {
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << khoroch[i] << " ";
    cout << '\n';

    return 0;
}