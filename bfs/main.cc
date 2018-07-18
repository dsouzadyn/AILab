#include <bits/stdc++.h>

using namespace std;

void bfs(vector<pair<int, int>> adj[], int s, int t) {
    queue<int> q;
    bool visited[27];
    memset(visited, 0, false);
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int curr_node = q.front();
        char o = curr_node + 'A';
        cout << o << endl;
        if (curr_node == t) break;
        q.pop();
        for(auto u: adj[curr_node]) {
            if (!visited[u.first]) {
                q.push(u.first);
                visited[u.first] = true;
            }
        }
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
    bfs(adj, start - 'A', end - 'A');
    return 0;
}
