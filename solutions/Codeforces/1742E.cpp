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
    int n, q;
    cin >> n >> q;
    vll a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }
    vll req(n);
    ll mx = a[0];
    for(int i=0; i < n; i++){
        mx = max(mx, a[i]);
        req[i] = mx;
    }
    vll queries(q);
    for(int i=0; i < q; i++){
        cin >> queries[i];
    }
    vll ans;

    vll pfix;
    pfix.pb(0);
    for(int i=0; i < n; i++){
        pfix.pb(pfix[i] + a[i]);
    }

    for(int k : queries){
        int l = -1, r = n;
        while(r - l > 1){
            int m = (l + r) / 2;
            int diff = 0;
            if(k >= req[m]){
                l = m;
            } else {
                r = m;
            }
        }
        ans.pb(pfix[l + 1]);
    }

    for(ll i : ans){
        cout << i << " ";
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