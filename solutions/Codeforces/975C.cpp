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
    int n, q;
    cin >> n >> q;
    vll a(n);
    vll pfix = {0};
    for(int i=0; i < n; i++) {
        cin >> a[i];
        pfix.pb(pfix[i] + a[i]);
    }
    ll k, delta = 0;
    for(int i=0; i < q; i++){
        cin >> k;
        int defeated = upper_bound(all(pfix), k + delta) - pfix.begin() - 1;
        delta += k;
        if(defeated == n){
            delta = 0;
            cout << n << br;
            continue;
        }
        cout << (n - defeated) << br;
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