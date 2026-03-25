#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
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
            pq.push(x);
        }
        if (query == 2)
        {
            if (pq.empty())
            {
                cout << "empty" << '\n';
                continue;
            }
            else
            {
                ll mn = pq.top();
                cout << mn << '\n';
                while (!pq.empty() && pq.top() == mn)
                {
                    pq.pop();
                }
            }
        }
    }

    return 0;
}