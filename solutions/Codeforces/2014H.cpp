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

void solve() {
    int n , q;
    cin >> n >> q;
    vll a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    vector<tuple<int, int, int>> queries(q);
    for(int i=0; i < n; i++){
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r, i};
    }
    sort(all(queries));

    int l = 0, r = 0;
    ll rh = a[0], sh = 0;
    ordered_multiset os;
    os.insert(a[0]);
    vector<string> ans(q);


    for(int i=0; i < q; i++){
        cout << ans[i] << br;
    }

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

}