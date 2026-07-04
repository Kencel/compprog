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
const ll MOD = 1e9 + 7;
 
ll mod(ll x, ll m){
    if(m == 0) return 0;
    if(m < 0) m *= -1;
    return (x % m + m) % m;
}
 
ll extended_euclid(ll a, ll b, ll &x, ll &y){
    if (b == 0) {x = 1; y = 0; return a;}
    ll g = extended_euclid(b, a % b, x, y);
    ll z = x - a / b * y;
    x = y; y = z; return g;
}
 
ll modinv(ll a, ll m){
    ll x, y; ll g = extended_euclid(a, m, x, y);
    if(g == 1 || g == -1) return mod(x * g, m);
    return 0;
}
 
bool tc = true;
void solve() {
    int n, m;
    cin >> n >> m;
    vll a(n);
    vll vals(n);
    map<int, int> count;
    for(int i=0; i < n; i++) {
        cin >> a[i];
        vals[i] = a[i];
        count[a[i]]++;
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    deque<ll> window;
    unsigned ll curr = 1;
    ll ans = 0;
    for(int i=0; i < sz(vals); i++){
        window.pb(vals[i]);
        curr *= count[vals[i]];
        curr %= MOD;
        while(window[0] < vals[i] - m + 1) {
            curr *= modinv(count[window[0]], MOD);
            curr %= MOD;
            window.pop_front();
        }
        if(sz(window) == m){
            ans += curr;
            ans %= MOD;
        }
    }
    cout << ans << br;
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