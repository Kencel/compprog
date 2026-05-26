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