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

bool tc = true;
void solve() {
    int n;
    cin >> n;
    vll a(n), pfix = {0};
    for(int i=0; i < n; i++) {
        cin >> a[i];
        pfix.pb(pfix[i] + a[i]);
    }
    ll ans = 0, first = n;
    for(int i=0; i < n; i++){
        if(a[i] == 0){
            first = i;
            break;
        }
        if(pfix[i + 1] == 0) ans++;
    }
    map<ll, ll> count;
    ll mx = 1;
    for(int i=first; i < n; i++){
        if(a[i] == 0){
            ans += mx;
            count.clear();
            count[pfix[i + 1]] += 1;
            mx = 1;
            continue;
        }
        count[pfix[i + 1]] += 1;
        mx = max(mx, count[pfix[i + 1]]);
    }
    ans += mx;
    cout << (ans - 1) << br;
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