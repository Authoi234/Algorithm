#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    long long int adj_matrix[n+1][n+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = LLONG_MAX;
        }
    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        adj_matrix[a][b] = min(adj_matrix[a][b], w);
    }

    for (int ironman = 1; ironman <= n; ironman++)
        for (int captainAmerica = 1; captainAmerica <= n; captainAmerica++)
            for (int thor = 1; thor <= n; thor++)
                if (adj_matrix[captainAmerica][ironman] != LLONG_MAX && adj_matrix[ironman][thor] != LLONG_MAX && (adj_matrix[captainAmerica][ironman] + adj_matrix[ironman][thor]) < adj_matrix[captainAmerica][thor])
                    adj_matrix[captainAmerica][thor] = adj_matrix[captainAmerica][ironman] + adj_matrix[ironman][thor];

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (adj_matrix[x][y] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_matrix[x][y] << endl;
    }

    return 0;
}