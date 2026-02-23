#include <bits/stdc++.h>
using namespace std;

void direction_changee(int &direction){
    if(direction == 1){
        direction = 2;
    }
    else if(direction == 2){
        direction = 3;
    }
    else if(direction == 3){
        direction = 4;
    }
    else if(direction == 4){
        direction = 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int direction = 1;
        while (n--)
        {
            direction_changee(direction);
        }
        switch (direction)
        {
        case 1:
            cout << "North" << endl;
            break;
        case 2:
            cout << "East" << endl;
            break;
        case 3:
            cout << "South" << endl;
            break;
        case 4:
            cout << "West" << endl;
            break;
        
        default:
            break;
        }        
    }
    return 0;
}