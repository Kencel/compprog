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

vi parent;
vi comp_size;
vll m;
 
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
    comp_size.resize(n);
    m.resize(n);
    for(int i=0; i < n; i++) parent[i] = i;
    fill(all(comp_size), 1);
    for(int i=0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;

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