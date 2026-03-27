#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    map<int, int> freq;
    priority_queue<pair<int, int>> pq;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;

            freq[x]++;
            pq.push({freq[x], x});
        } 
        else {
            bool found = false;

            while (!pq.empty()) {
                auto [count, id] = pq.top();     
                pq.pop();

                if (freq[id] == count && count > 0) {
                    cout << id << "\n";
                    freq[id] = 0;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "empty\n";
            }
        }
    }

    return 0;
}