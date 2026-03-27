#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;

        long long int cntX = 0;
        long long int cntXY = 0;
        long long int cntXYZ = 0;

        for (char c : s)
        {
            if (c == t[2])
                cntXYZ += cntXY;

            if (c == t[1])
                cntXY += cntX;

            if (c == t[0])
                cntX++;
        }

        cout << cntXYZ << endl;
    }

    return 0;
}