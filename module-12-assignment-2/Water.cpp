#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<long long int> H(N);

        int max1 = -1, max2 = -1;
        int i1 = -1, i2 = -1;

        for (int i = 0; i < N; i++)
        {
            cin >> H[i];

            if (H[i] > max1)
            {
                max2 = max1;
                i2 = i1;

                max1 = H[i];
                i1 = i;
            }
            else if (H[i] > max2)
            {
                max2 = H[i];
                i2 = i;
            }
        }

        if (i1 < i2)
            cout << i1 << " " << i2 << "\n";
        else
            cout << i2 << " " << i1 << "\n";
    }
    return 0;
}