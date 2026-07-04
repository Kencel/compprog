#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
    ordered_multiset o;
    for(int i=1; i <=n; i++){
        o.insert(i);
    }
    int curr = k % sz(o);
    while(true){
        cout << (*o.find_by_order(curr)) << " ";
        o.erase(o.find_by_order(curr));
        if(o.empty()) break;
        curr = (curr + k) % sz(o);
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