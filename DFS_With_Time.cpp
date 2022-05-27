#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> vis, st_time, en_time;
int cnt_time;

void dfs(int x)
{
    vis[x] = 1;
    cnt_time++;
    st_time[x] = cnt_time;
    for (auto nb : G[x])
    {
        if (not vis[nb])
        {
            dfs(nb);
        }
    }
    cnt_time++;
    en_time[x] = cnt_time;
}

signed main()
{
    int n, m; cin >> n >> m;
    G.resize(n+1); vis.resize(n+1); st_time.resize(n+1); en_time.resize(n+1);

    while(m--)
    {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
    }

    for (int i=1; i<=n; i++)
    {
        if (not vis[i]) dfs(i);
    }

    for (int i=1; i<=n; i++)
    {
        cout << i << " : " << st_time[i] << ' ' << en_time[i] << endl;
    }
}