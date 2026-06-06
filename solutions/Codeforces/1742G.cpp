#include <bits/stdc++.h>

using namespace std;

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
    int n;
    cin >> n;
    multiset<ll> a;
    for(int i=0; i < n; i++){
        ll t;
        cin >> t;
        a.insert(t);
    }
    vll ans;
    ll curr = 0;
    for(int i=0; i < 32; i++){
        if(a.empty()) break;
        ll mx = -1;
        for(ll x : a){
            if((x | curr) > (mx | curr)){
                mx = x;
            }
        }
        if(mx == -1) break;
        curr |= mx;
        a.erase(a.find(mx));
        ans.pb(mx);
    }

    for(ll num : a){
        ans.pb(num);
    }

    for(ll num : ans){
        cout << num << " ";
    }
    cout << br;
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