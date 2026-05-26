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

#define all(x) (x.begin(), x.end())
#define sz(x) (int)(x).size()

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vi c(n);
    for(int i=0; i < n; i++){
        cin >> c[i];
    }
    vi dp(x + 1);
    dp[0] = 1;
    for(int i=1; i < x + 1; i++){
        for(int j=0; j < n; j++){
            if(i - c[j] < 0) continue;
            dp[i] += dp[i - c[j]];
            dp[i] %= MOD;
        }
    }
    cout << dp[x];
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

}