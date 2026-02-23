#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<long long int> adj_list[n];
    while (e--)
    {
        long long int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    long long int q;
    cin >> q;
    while (q--)
    {
        long long int x;
        cin >> x;
        vector<long long int> connected_nodes;
        for (auto i : adj_list[x])
        {
            connected_nodes.push_back(i);
        }
        if(connected_nodes.empty()) {
            cout << -1 << endl;
            continue;
        }
        sort(connected_nodes.begin(), connected_nodes.end(), greater<long long int>());
        for (auto i : connected_nodes){
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}