#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        long long int current_sum = 0;
        for (int i = 0; i < n - 2; i++)
        {
            long long int x;
            cin >> x;
            current_sum += x;
        }
        long long int original_sum;
        cin >> original_sum;

        long long harano_sum = original_sum - current_sum;

        long long charidike_sum_by_the_way_ways_of_sum = harano_sum + 1;

        cout << charidike_sum_by_the_way_ways_of_sum << endl;
    }

    return 0;
}