#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair <int, pair <int, int > > > Edges;
int P[20000];
int Sz[20000];
int findSet(int v)
{
    if (P[v] == v)
    {
        return v;
    }
    else
    {
        P[v] = findSet(P[v]);
        return P[v];
    }
}
void unite (int u, int v)
{
    u = findSet(u);
    v = findSet(v);
    if (Sz[u] < Sz[v])
    {
        swap(u, v);
    }
    P[v] = u;
    return;
}
int main()
{
    int n, m, a, b, k;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> k;
        Edges.push_back(make_pair(k, make_pair(a, b)));
        Edges.push_back(make_pair(k, make_pair(b, a)));
    }
    for(int j = 0; j < n; ++j)
    {
        P[j] = j;
        Sz[j] = 1;
    }
    sort(Edges.begin(), Edges.end());
    long long ans;
    ans = 0;
    for (int g = 0; g < Edges.size(); ++g)
    {
        int c = Edges[g].second.first;
        int d = Edges[g].second.second;
        int len = Edges[g].first;
        if (findSet(c) != findSet(d))
        {
            unite (c, d);
            ans = ans + len;
        }
    }
    cout << ans;
    return 0;
}
