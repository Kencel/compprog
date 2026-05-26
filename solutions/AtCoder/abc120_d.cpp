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

vll parent;
vll comp_size;
 
int find(int u){
    if(parent[u] == u) return u;
    int ret = find(parent[u]);
    parent[u] = ret;
    return ret;
}
 
ll unite(int u, int v){
    int parent_u = find(u);
    int parent_v = find(v);
    if(parent_v == parent_u) return 0;
    if(comp_size[parent_v] < comp_size[parent_u]) swap(parent_u, parent_v);
    parent[parent_u] = parent_v;
    ll ret = comp_size[parent_v] * comp_size[parent_u];
    comp_size[parent_v] += comp_size[parent_u];
    return ret;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> edge;
    comp_size.resize(n);
    fill(all(comp_size), 1);
    for(int i=0; i < n; i++) parent.pb(i);
    vll ans;
    ll curr = (n * (n - 1)) / 2;
    ans.pb(curr);
    for(int i=0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge.pb(mp(u - 1, v - 1));
    }

    for(int i=m-1; i > 0; i--){
        curr -= unite(edge[i].first, edge[i].second);
        ans.pb(curr);
    }

    for(int i=m-1; i > -1; i--){
        cout << ans[i] << br;
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