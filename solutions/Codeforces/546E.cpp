#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pi pair<int, int>

#define mp make_pair
#define pb push_back
#define br "\n"

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const ll INF = 1e18;

ll bfs(int s, int t, vi& parent, vector<vi>& adj, vector<vll>& capacity) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(int s, int t, int n, vector<vi>& adj, vector<vll>& capacity) {
    ll flow = 0;
    vector<int> parent(n);
    ll new_flow;

    while (new_flow = bfs(s, t, parent, adj, capacity)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void add_edge(int u, int v, ll cap, vector<vi>& adj, vector<vll>& capacity) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = cap;   
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> adj(2 * n + 2); // undirected
    vector<vll> capacity(2 * n + 2); // directed
    fill(all(capacity), vll(2 * n  + 2));
    int a = 0,b = 0;
    for(int i=0; i < n; i++){
        int t; 
        cin >> t;
        add_edge(0, i + 1, t, adj, capacity);
        add_edge(i + 1, i + 1 + n, INF, adj, capacity);
        a += t;
    }
    for(int i=0; i < n; i++){
        int t;
        cin >> t;
        add_edge(i + n + 1, 2 * n + 1, t, adj, capacity);
        b += t;
    }
    for(int i=0; i < m; i++){
        int p, q;
        cin >> p >> q;
        add_edge(p, q + n, INF, adj, capacity);
        add_edge(q, p + n, INF, adj, capacity);
    }

    if (a != b){
        cout << "NO" << br;
        return;
    }

    int mx = maxflow(0, 2 * n + 1, 2 * n + 2, adj, capacity);
    if (mx != a){
        cout << "NO" << br;
    } else {
        cout << "YES" << br;
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                cout << capacity[j + n + 1][i + 1] << " ";
            }
            cout << br;
        }
    }
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

}