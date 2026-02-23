#include <bits/stdc++.h>
using namespace std;

int jogfol(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;

        int y = x;
        while (jogfol(y) % k != 0)
        {
            y++;
        }
        cout << y << endl;
    }
    return 0;
}