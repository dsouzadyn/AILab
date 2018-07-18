#include <bits/stdc++.h>

using namespace std;

void astar(vector<pair<int, int>> adj[], int s, int t, map<int, int> h) {
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
        visited[p] = true;
        char o = p + 'A';
        cout << o << endl;
        if(p == t) break;
        for(auto u: adj[p]) {
            int v = u.first;
            int cost = u.second;
            if(distance[p] + cost < distance[v]) {
                int heu = u.second;
                int priority = cost + (h[t] + heu);
                distance[v] = distance[p] + cost;
                pq.push({-priority, v});
            }
        }
    }
    cout << "Heuristics: " << endl;
    for(int i = 0; i < 27; i++) {
        if(distance[i] != INT_MAX) {
            char o = i + 'A';
            cout << o << " - distance: " << distance[i] << ", heuristic: " << distance[i] + h[i] << endl;
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
    map<int, int> h;
    for(int i = 0; i < n; i++) {
        cin >> u >> cost;
        h[u-'A'] = cost;
    }
    astar(adj, start - 'A', end - 'A', h);
    return 0;
}
