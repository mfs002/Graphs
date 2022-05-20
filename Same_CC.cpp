#include <bits/stdc++.h>
using namespace std;

int cnt;

void bfs(int x, vector<int> G[], vector<int> &vis, vector<int> &ans)
{
    queue<int> qu;
    qu.push(x); vis[x] = 1;
    ans[x] = cnt;

    while(not qu.empty())
    {
        int c_n = qu.front();
        qu.pop();

        for (auto nb : G[c_n])
        {
            if (vis[nb]) continue;
            vis[nb] = 1; qu.push(nb);
            ans[nb] = cnt;
        }
    }
}

signed main()
{
    int n, m; cin >> n >> m;
    vector<int> G[n+1];

    for (int i=0; i<m; i++)
    {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    queue<int> qu;
    vector<int> vis(n+1, 0), ans(n+1);

    for (int i=1; i<=n; i++)
    {
        cnt++;
        if (not vis[i]) bfs(i, G, vis, ans);
    }

    int q; cin >> q;
    while(q--)
    {
        int x, y; cin >> x >> y;
        if (ans[x] == ans[y]) cout << "Yes\n";
        else cout << "No\n";
    }
}