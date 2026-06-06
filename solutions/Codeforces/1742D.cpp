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
    vi a;
    set<int> seen;
    map<int, int> idx;
    for(int i=0; i < n; i++){
        int t;
        cin >> t;
        if(!seen.contains(t)){
            a.pb(t);
        }
        idx[t] = i + 1;
        seen.insert(t);
    }
    int ans = -1;
    for(int i=0; i < sz(a); i++){
        for(int j=i; j < sz(a); j++){
            if(gcd(a[i], a[j]) > 1) continue;
            ans = max(ans, idx[a[i]] + idx[a[j]]);
        }
    }
    cout << ans << br;
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