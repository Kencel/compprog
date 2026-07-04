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
    vector<pair<string, string>> songs;
    for(int i=0; i < n; i++){
        string genre, writer;
        cin >> genre >> writer;
        songs.pb(mp(genre, writer));
    }

    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for(int i=0; i < n; i++){
        for(int j=i + 1; j < n; j++){
            if(songs[i].first == songs[j].first || songs[i].second == songs[j].second){
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }

    int keep = 1;
    vector<vector<bool>> dp((1 << n), vector<bool>(n, false));
    for(int i=0; i < n; i++){
        dp[1 << i][i] = true;
    }

    vector<int> masks((1 << n));
    for(int i=0; i < (1 << n); i++) masks[i] = i;
    sort(all(masks), [](const int &a, const int &b){
        return __builtin_popcount(a) < __builtin_popcount(b);
    });
    for(int i=0; i < (1 << n); i++){
        int mask = masks[i];
        if((int)__builtin_popcount(mask) < 2) continue;
        for(int j=0; j < n; j++){
            int curr_j = 1 << j;
            if(!(mask & curr_j)) continue;
            for(int k=0; k < n; k++){
                int curr_k = 1 << k;
                if(j == k || !(mask & curr_k)) continue;
                if(dp[mask ^ curr_j][k] && adj[k][j]) {
                    dp[mask][j] = true;
                    keep = max(keep, (int)__builtin_popcount(mask));
                }
            }
        }
    }
    cout << (n - keep) << br;
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