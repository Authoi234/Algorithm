#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<ll, ll> freq;
    set<pair<ll, ll>> s;
    ll q;
    cin >> q;
    while (q--)
    {
        int query;
        cin >> query;
        ll x;

        if (query == 1)
        {
            cin >> x;
            if (freq[x] > 0)
                s.erase({freq[x], -x});
            freq[x]++;
            s.insert({freq[x], -x});
        }
        else if (query == 2)
        {
            if (freq.empty())
            {
                cout << "empty" << '\n';
                continue;
            }

            auto it = s.begin();
            ll f = it->first;
            ll x = -it->second;
            cout << x << '\n';
            s.erase(it);
            ll my1 = 1;
            ll removeCount = max(my1, freq[x] / 2);
            freq[x] -= removeCount;

            if (freq[x] == 0)
            {
                freq.erase(x);
            }
            else
            {
                s.insert({freq[x], -x});
            }
        }
    }

    return 0;
} 
