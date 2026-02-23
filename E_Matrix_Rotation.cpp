#include <bits/stdc++.h>
using namespace std;

bool is_beautiful(int a, int b, int c, int d)
{
    return (a < b && c < d && a < c && b < d);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            if (is_beautiful(a, b, c, d))
            {
                flag = true;
                break;
            }
            int temp = a;
            a = c;
            c = d;
            d = b;
            b = temp;
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    };
    return 0;
}