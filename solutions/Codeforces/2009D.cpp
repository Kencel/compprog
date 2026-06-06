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
    vector<bool> top(n + 1);
    vector<bool> bot(n + 1);
    for(int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(y == 1){
            top[x] = true;
        } else {
            bot[x] = true;
        }
    }
    ll ans = 0;
    if(top[0] && bot[0]) ans += (n - 2);
    if(top[n] && bot[0]) ans += (n - 2);
    for(int i=1; i < n; i++){
        if(top[i] && bot[i]) ans += (n - 2);
        if(top[i - 1] && bot[i] && top[i + 1]) ans++;
        if(bot[i - 1] && top[i] && bot[i + 1]) ans++;
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