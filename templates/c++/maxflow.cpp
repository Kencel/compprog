#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

void add_edge(int u, int v, ll cap, vector<vi>& adj, vector<vll>& capacity) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = cap;   
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n); // undirected
    vector<vll> capacity(n); // directed
    fill(all(capacity), vll(n));
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