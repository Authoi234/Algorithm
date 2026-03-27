#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    int q;
    cin >> n >> q;

    vector<long long int> v(n, 0);
    vector<long long int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        prefix[i + 1] = prefix[i] + v[i];
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        long long int ans = prefix[y] - prefix[x - 1];
        cout << ans << endl;
    }

    return 0;
}