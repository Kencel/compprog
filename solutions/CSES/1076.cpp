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
    vi a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }
    deque<pair<int, int>> window;
    ordered_multiset os;
    for(int i=0; i < k; i++){
        window.pb(mp(a[i], i));
        os.insert(mp(a[i], i));
    }
    if(k % 2 == 1){
        cout << (*os.find_by_order(k / 2)).first << " ";
    } else {
        cout << (*os.find_by_order(k / 2 - 1)).first << " ";
    }
    for(int i=k; i < n; i++){
        window.pb(mp(a[i], i));
        os.insert(mp(a[i], i));
        os.erase(os.find_by_order(os.order_of_key(window[0])));
        window.pop_front();
        if(k % 2 == 1){
            cout << (*os.find_by_order(k / 2)).first << " ";
        } else {
            cout << (*os.find_by_order(k / 2 - 1)).first << " ";
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