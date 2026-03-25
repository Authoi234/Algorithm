#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    bool lucky = false;
    while(n>0){
        if(n%10 == 7){
            lucky=true;
            break;
        }
        n/=10;
    }
    cout << (lucky?"Lucky":"Not Lucky");
    return 0;
}