#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int operations = 0;

        while (!s.empty()) {
            string new_s;
            operations++;
            for (int i = 0; i < s.size(); i++) {
                if (i % 2 == 0) continue;
                new_s += s[i];
            }
            s = new_s;
        }

        cout << operations << endl;
    }
    return 0;
}