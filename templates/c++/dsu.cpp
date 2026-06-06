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
    }
}

void solve() {
    int n;
    cin >> n;
    parent.resize(n);
    for(int i=0; i < n; i++){
        parent[i] = i;
    }
    comp_size.resize(n);
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