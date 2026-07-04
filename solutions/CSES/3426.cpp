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

bool tc = false;
void solve() {
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    deque<ll> window;
    ll curr = x;
    ll xor_sum = 0;
    for(int i=0; i < k; i++){
        window.pb(curr);
        xor_sum ^= curr;
        curr = (a * curr + b) % c;
    }
    ll ans = xor_sum;
    for(int i=k; i < n; i++){
        window.pb(curr);
        xor_sum ^= window[0];
        window.pop_front();
        xor_sum ^= curr;
        ans ^= xor_sum;
        curr = (a * curr + b) % c;
    }
    cout << ans;

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