#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> w(n), x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> x[i];
    }
    long long int max_employees = 0;
    for (int g = 0; g < 24; g++)
    {
        long long int current_local_total_time = 0;
        for (int i = 0; i < n; i++) 
        {
            int local_start = (g + x[i]) % 24;
            int local_end = local_start + 1;

            if (local_start >= 9 && local_end <= 18)
                current_local_total_time += w[i];
        }
        max_employees = max(max_employees, current_local_total_time);
    }
    cout << max_employees << endl;
    return 0;
}