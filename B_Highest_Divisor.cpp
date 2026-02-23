#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int d = 10; d >= 1; d--) {
        if (N % d == 0) {
            cout << d << endl;
            break;
        }
    }

    return 0;
}