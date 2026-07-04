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
vll p;
vector<bool> np;

bool tc = true;
void solve() {
    ll n;
    cin >> n;
    n++;
    for(;;n++){
        if(n < 2) continue;
        bool found = true;
        for(ll prime : p){
            if(prime * prime > n) break;
            if(n == prime) break;
            if(n % prime == 0){
                found = false;
                break;
            }
        }
        if(found){
            cout << n << br;
            break;
        }

    }
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    np.resize(2e6);
    for(ll i=2; i < 2e6; i++){
        if(np[i]) continue;
        p.pb(i);
        ll curr = i * 2;
        while(curr < 2e6){
            np[curr] = true;
            curr += i;
        }
    }
    
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