#include <bits/stdc++.h>
using namespace std;

long long int dis[1005];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<long long int, pair<int, int>>> edge_list;
    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        pair<long long int, pair<int, int>> x = {w, {a, b}};
        edge_list.push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    int src;
    cin >> src;
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++)
        for (auto edge : edge_list)
        {
            int a, b;
            long long int w;
            w = edge.first;
            a = edge.second.first;
            b = edge.second.second;
            if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
                dis[b] = dis[a] + w;
        }

    bool cycle = false;
    for (auto edge : edge_list)
    {
        int a, b;
        long long int w;
        w = edge.first;
        a = edge.second.first;
        b = edge.second.second;
        if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Negative Cycle Detected";
        return 0;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (dis[x] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dis[x] << endl;
    }

    return 0;
}