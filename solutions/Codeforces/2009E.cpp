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

ll s(ll a, ll b){
    return ((a + b) * (a + b + 1) - a * (a - 1)) / 2;
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = INF;
    ans = min(ans, abs(-s(k, k + n - 1)));
    for(int i=0; i < n - 1; i++){
        ans = min(ans, abs(s(k, k + i) - s(k + i + 1, k + n - 1)));
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