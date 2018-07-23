#include <bits/stdc++.h>

using namespace std;

void ucs(vector<pair<int, int>> adj[], int s) {
    bool visited[27];
    int distance[27];
    memset(visited, false, sizeof visited);
    for(int i =0; i < 27; i++) distance[i] = INT_MAX;
    priority_queue<pair<int, int>> pq;
    distance[s] = 0;
    pq.push({0, s});
    cout << "Route: " << endl;
    while(!pq.empty()) {
        int p = pq.top().second;
        pq.pop();
        if(visited[p]) continue;
        char o = p + 'A';
        cout << o << endl;
        visited[p] = true;
        for(auto u: adj[p]) {
            int v = u.first;
            int cost = u.second;
            if(distance[p] + cost < distance[v]) {
                distance[v] = distance[p] + cost;
                pq.push({-distance[v], v});
            }
        }
    }
    cout << "Costs: " << endl;
    for(int i = 0; i < 26; i++) {
        if(distance[i] != INT_MAX) {
            char o = i + 'A';
            cout << o << " : " << distance[i] << endl;
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
    ucs(adj, start - 'A');
    return 0;
}
