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

bool tc = false;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vll> g(n, vll(m, 0));
    for(int i=0; i < k; i++){
        int r, c, v;
        cin >> r >> c >> v;
        g[--r][--c] = v;
    }
    vector<vector<pair<vll, ll>>> dp(2, vector<pair<vll, ll>>(m, {vll(3, 0), 0}));
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            vll down_values = dp[(i + 1) % 2][j].first;
            ll down_sum = dp[(i + 1) % 2][j].second;
            down_values.pb(-g[i][j]);
            down_sum += g[i][j];
            sort(all(down_values));
            down_sum += down_values[3];
            down_values.pop_back();
            if(j == 0){
                dp[i % 2][j] = mp(vll(3, 0), down_sum);
                continue;
            }
            vll right_values = dp[i % 2][j - 1].first;
            ll right_sum = dp[i % 2][j - 1].second;
            right_values.pb(-g[i][j]);
            right_sum += g[i][j];
            sort(all(right_values));
            right_sum += right_values[3];
            right_values.pop_back();
            if(right_sum > down_sum){
                dp[i % 2][j] = mp(right_values, right_sum);
            } else {
                dp[i % 2][j] = mp(vll(3, 0), down_sum);
            }
        }
    }
    cout << dp[(n + 1) % 2][m - 1].second << br;
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