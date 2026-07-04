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
    int n;
    cin >> n;
    vll a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }
    vll width(n, 1);

    vi curr;
    for(int i=0; i < n; i++){
        while(!curr.empty()){
            int last = (*curr.rbegin());
            if(a[i] >= a[last]) break;
            width[last] += abs(i - last) - 1;
            curr.pop_back();
        }
        curr.pb(i);
    }
    for(int x : curr){
        width[x] += abs(x - n) - 1;
    }
    curr.clear();
    for(int i=n - 1; i > -1; i--){
        while(!curr.empty()){
            int last = (*curr.rbegin());
            if(a[i] >= a[last]) break;
            width[last] += abs(i - last) - 1;
            curr.pop_back();
        }
        curr.pb(i);
    }
    for(int x : curr){
        width[x] += x;
    }

    ll mx = 0;
    for(int i=0; i < n; i++){
        mx = max(mx, width[i] * a[i]);
    }
    cout << mx;
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