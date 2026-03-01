#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, q;
    cin >> n >> e >> q;
    int adj_matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = INT_MAX;
        }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_matrix[a][b] = c;
        adj_matrix[b][a] = c;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(adj_matrix[i][k]!=INT_MAX && adj_matrix[k][j]!=INT_MAX && (adj_matrix[i][k] + adj_matrix[k][j]) < adj_matrix[i][j])
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];

    while (q--)
    {
        int s,d;
        cin >> s >> d;
        cout << ((adj_matrix[s][d] == INT_MAX) ? -1 : adj_matrix[s][d]) << endl;
    }
    return 0;
}