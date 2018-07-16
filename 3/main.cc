#include <bits/stdc++.h>

using namespace std;

bool visited[27];

void dfs(vector<pair<int, int>> adj[], int s, int t) {
    if(visited[s]) return;
    visited[s] = true;
    char o = s + 'A';
    cout << o << endl;
    if(s == t) return;
    for(auto u: adj[s]) {
        dfs(adj, u.first, t);
    }
}
int main(int argc, char *argv[])
{
    freopen("input.txt", "rt", stdin);
    int n, m, cost;
    char u, v;
    char start, end;
    cin >> n >> m;
    cin >> start >> end;
    int x, y;
    vector<pair<int, int>> adj[27];
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> u;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> cost;
        adj[u-'A'].push_back(make_pair(v-'A', cost));
    }
    memset(visited, 0, sizeof visited);
    dfs(adj, start - 'A', end - 'A');
    return 0;
}
