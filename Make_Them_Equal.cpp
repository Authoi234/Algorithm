#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        int parthokko = 0;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                parthokko++;
        if(parthokko<=k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}