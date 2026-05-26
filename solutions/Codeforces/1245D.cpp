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
    int ret = find(parent[u]);
    parent[u] = ret;
    return ret;
}

void unite(int u, int v, int n){
    int parent_u = find(u);
    int parent_v = find(v);
    if(parent_v != parent_u) {
        if(comp_size[parent_v] < comp_size[parent_u] && parent_v != n) swap(parent_u, parent_v);
        parent[parent_u] = parent_v;
        comp_size[parent_v] += comp_size[parent_u];
    }
}

ll dist(pi a, pi b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    int n;
    cin >> n;
    vector<pi> city(n);
    for(int i=0; i < n; i++){
        int u, v;
        cin >> u >> v;
        city[i] = mp(u, v);
    }
    vll c(n);
    vll k(n);
    for(int i=0; i < n; i++){
        cin >> c[i];
    }
    for(int i=0; i < n; i++){
        cin >> k[i];
    }

    parent.resize(n + 1);
    for(int i=0; i < n + 1; i++){
        parent[i] = i;
    }
    comp_size.resize(n + 1);
    fill(comp_size.begin(), comp_size.end(), 1);

    vector<tuple<ll, int, int> > edge;
    for(int i=0; i < n; i++){
        for(int j=i + 1; j < n; j++){
            edge.pb({(k[i] + k[j]) * dist(city[i], city[j]), i, j});
        }
    }
    for(int i=0; i < n; i++){
        edge.pb({c[i], i, n});
    }

    sort(all(edge));

    ll cost = 0;
    vector<pi> connected;
    vi stations;
    for(auto &e : edge){
        int u, v;
        ll d;
        tie(d, u, v) = e;
        int parent_u = find(u);
        int parent_v = find(v);
        if(parent_u == parent_v) continue;
        unite(u, v, n);
        cost += d;
        if(v == n){
            stations.pb(u + 1);
        } else {
            connected.pb(mp(u + 1, v + 1));
        }
    }

    cout << cost << br;
    cout << sz(stations) << br;
    for(auto &s : stations){
        cout << s << " ";
    }
    cout << br;
    cout << sz(connected) << br;
    for(auto &e : connected){
        cout << e.first << " " << e.second << br;
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