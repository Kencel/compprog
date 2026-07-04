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

vi parent;
vi comp_size;
vll total;
 
int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
 
void unite(int u, int v){
    int parent_u = find(u);
    int parent_v = find(v);
    if(parent_v != parent_u) {
        if(comp_size[parent_v] < comp_size[parent_u]) swap(parent_u, parent_v);
        parent[parent_u] = parent_v;
        comp_size[parent_v] += comp_size[parent_u];
        total[parent_v] += total[parent_u];
    }
}

bool tc = false;
void solve() {
    int n;
    cin >> n;
    parent.resize(n);
    for(int i=0; i < n; i++){
        parent[i] = i;
    }
    comp_size.resize(n);
    
    vi a(n);
    total.resize(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
        total[i] = a[i];
    }
    vi q(n);
    for(int i=0; i < n; i++){
        cin >> q[i];
        q[i]--;
    }
    vector<bool> added(n, false);
    vll ans;
    ll mx = 0;
    for(int i=n - 1;i > -1; i--){
        ans.pb(mx);
        added[q[i]] = true;
        if(q[i] != 0 && added[q[i] - 1]){
            unite(q[i] - 1, q[i]);
        }
        if(q[i] != n - 1 && added[q[i] + 1]){
            unite(q[i], q[i] + 1);
        }

        mx = max(mx, total[find(q[i])]);
    }

    for(int i = n - 1; i > -1; i--){
        cout << ans[i] << br;
    }
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