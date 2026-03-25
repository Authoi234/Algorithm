#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    map<long long int, pair<int, int>> mp;

    for (int i = 1; i <= n; i++)
    {
        if (mp.find(v[i]) == mp.end())
            mp[v[i]] = {i, i};
        else
            mp[v[i]].second = i;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second.first << " " << it->second.second << endl;
    return 0;
}