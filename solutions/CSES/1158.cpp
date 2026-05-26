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

void solve() {
    int n, x;
    cin >> n >> x;
    vi price(n);
    vi pages(n);
    for(int i=0; i < n; i++){
        cin >> price[i];
    }
    for(int i=0; i < n; i++){
        cin >> pages[i];
    }

    vi dp(x + 1);
    for(int i=1; i < n + 1; i++){
        for(int j=x; j > price[i - 1] - 1; j--){
            dp[j] = max(dp[j], dp[j - price[i - 1]] + pages[i - 1]);
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