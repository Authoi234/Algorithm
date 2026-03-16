#include <bits/stdc++.h>
using namespace std;

int par[100000];
int group_size[100000];
int cmp_cnt, mx;

int find(int node)
{
    if(par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int nd1,int nd2)
{
    int leader1=find(nd1);
    int leader2=find(nd2);
    if(leader1==leader2) return;
    if(group_size[leader1] >= group_size[leader2])
    {
        par[leader2]=leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx, group_size[leader1]);
    }
    else
    {
        par[leader1]=leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }
    cmp_cnt--;
}

int main()
{
    int n ,e;
    cin >> n >> e;
    cmp_cnt = n;
    mx=1;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
    
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        dsu_union(a,b);
        cout << cmp_cnt << " " << mx << endl;
    }
    
    return 0;
}