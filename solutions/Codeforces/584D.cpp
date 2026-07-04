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
const int MAX_N = 1e9;

ll good_bases[] = {2,325,9375,28178,450775,9780504,1795265022};

ll mod_mult(ll a, ll b, ll m){
    return (ll)((__int128)a * b % m);
}

ll mod_pow(ll a, ll b, ll m){
    ll ret = 1;
    a %= m;
    while(b > 0){
        if(b & 1) ret = mod_mult(ret, a, m);
        a = mod_mult(a, a, m);
        b >>= 1;
    }
    return ret;
}

bool witness(ll a, ll n) {
    if(a % n == 0) return false;
    ll t = 0, u = n - 1;
    while (u % 2 == 0) {
        u >>= 1;
        t += 1;
    }
    ll xp = 1, xi = mod_pow(a, u, n);
    for (int i = 0; i < t; i++) {
        xp = xi;
        xi = mod_mult(xi, xi, n);
        if (xi == 1 && xp != 1 && xp != n - 1) return true;
    }
    return xi != 1;
}

bool miller_rabin(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    for (ll x : good_bases) {
        if (n == x) return true;
        if (witness(x, n)) return false;
    }
    return true;
}


bool tc = false;
void solve() {
    int n;
    cin >> n;

    if(miller_rabin(n)){
        cout << 1 << br << n;
        return;
    }

    if(miller_rabin(n - 2)){
        cout << 2 << br << 2 << " " << n - 2;
        return;
    }

    cout << 3 << br << 3 << " ";
    n -= 3;

    for(int i=3; i <= n / 2; i += 2){
        if(miller_rabin(i) && miller_rabin(n - i)){
            cout << i << " " << n - i;
            return;
        }
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