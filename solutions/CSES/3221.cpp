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
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    deque<pi> m;
    ll curr = x % c;
    m.pb({curr, 0});
    for(int i = 1; i < k; i++){
        curr = (a * curr + b) % c;
        while(!m.empty() && m.back().first > curr) m.pop_back();
        m.pb({curr, i});
    }
    ll ans = m[0].first;
    for(int i = k; i < n; i++){
        curr = (a * curr + b) % c;
        while(!m.empty() && m.back().first > curr) m.pop_back();
        m.pb({curr, i});
        if(m.front().second == i - k) m.pop_front();
        ans ^= m[0].first;
    }
    cout << ans;
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