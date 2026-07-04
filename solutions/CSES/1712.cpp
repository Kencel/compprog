#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define ll unsigned long long
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

ll modexp(ll val, ll exp, ll mod){
    val %= mod;
    ll ret = 1;
    while(exp > 0){
        if(exp & 1)
            ret = ret * val % mod;
        val = val * val % mod;
        exp >>= 1;
    }
    return ret;
}

bool tc = true;
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << modexp(a, modexp(b, c, MOD - 1), MOD) << br;
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