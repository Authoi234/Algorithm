#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, h;
    if (!(cin >> n >> h)) return 0;
    vector<long long int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<long long int>());

    long long int max_hp = a[0];
    long long int current_monster_idx = 0;
    
    for(long long int bullets = 1; bullets < max_hp; bullets++) {
        while(current_monster_idx < n && a[current_monster_idx] - bullets <= 0) {
            current_monster_idx++;
        }
        if(current_monster_idx >= n) break;

        h -= (a[current_monster_idx] - bullets);

        if(h < 1) {
            cout << "Dablu\n";
            return 0;
        }
    }

    cout << "Hablu\n";
    return 0;
}