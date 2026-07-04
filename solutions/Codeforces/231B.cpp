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
    int n, d, l;
    cin >> n >> d >> l;
    if(n % 2 == 1) d -= 1;
    if(d >= 0){
        if((l - 1) * (int)((n + 1) / 2) < d){
            cout << -1;
            return;
        }
        for(int i=0; i < n; i++){
            if(i % 2 == 0){
                cout << 1 + max(0, min(l - 1, d)) << " ";
                d -= max(0, min(l - 1, d));
            } else {
                cout << 1 << " ";
            }
        }
    } else {
        d *= -1;
        if((l - 1) * (n / 2) < d){
            cout << -1;
            return;
        }
        for(int i=0; i < n; i++){
            if(i % 2 == 0){
                cout << 1 << " ";
            } else {
                cout << 1 + max(0, min(l - 1, d)) << " ";
                d -= max(0, min(l - 1, d));
            }
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