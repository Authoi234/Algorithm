#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string ans;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i+=2)
        {
            char ch = s[i];
            int kotobar = s[i+1]-'0';
            if(kotobar > 0)
                ans.append(kotobar, ch);
        }
        cout << ans << endl;
    }
    return 0;
}