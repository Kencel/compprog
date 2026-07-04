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

struct path{
    ll u, dist, slowness;

    path(): u(0), dist(0), slowness(0) {}

    path(ll u, ll dist, ll slowness): u(u), dist(dist), slowness(slowness) {}

    bool operator<(const path &other) const {
        if((this->dist * this->slowness) == (other.dist * other.slowness)) return this->slowness < other.slowness;
        return (this->dist * this->slowness) < (other.dist * other.slowness);
    }

    bool operator>(const path &other) const {
        if((this->dist * this->slowness) == (other.dist * other.slowness)) return this->slowness > other.slowness;
        return (this->dist * this->slowness) > (other.dist * other.slowness);
    }

    ll realDist() {
        return dist * slowness;
    }
};

bool tc = true;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> adj(n);
    vll s(n);
    for(int i=0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    for(int i=0; i < n; i++) cin >> s[i];
    priority_queue<path, vector<path>, greater<path>> pq;
    vector<path> dist(n);
    for(int i=0; i < n; i++){
        dist[i] = {i, INF, s[i]};
    }
    dist[0] = {0, 0, s[0]};
    pq.push(dist[0]);
    while(!pq.empty()){
        path curr = pq.top();
        curr.slowness = min(curr.slowness, s[curr.u]);
        pq.pop();
        if(dist[curr.u] < curr) continue;
        dist[curr.u] = curr;
        for(auto &e : adj[curr.u]){
            int v = e.first;
            ll w = e.second;
            if(dist[v] > (*new path(v, dist[curr.u].dist + w * curr.slowness, curr.slowness))){
                dist[v] = (*new path(v, dist[curr.u].dist + w * curr.slowness, curr.slowness));
                pq.push(dist[v]);
            }
        }
    }
    cout << dist[n - 1].dist << br;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if(!tc){
        solve();
        return 0;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}