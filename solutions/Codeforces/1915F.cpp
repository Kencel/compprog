#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
    vector<pi> a(n);
    for(int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(all(a));
    ll ans = 0;
    ordered_multiset o;
    for(int i=0; i < n; i++){
        ans += o.order_of_key(a[i].second);
        o.insert(a[i].second);
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