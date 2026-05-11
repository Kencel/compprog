#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pb push_back
#define br "\n"
#define all(x) (x.begin(), x.end())
const ll INF = 1e18;

void solve() {
    int n, k;
    vll a(n);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pq.push(make_pair(a[i], i));
    }
    for(int i = 0; i < k; i++){
        pll pair = pq.top();
        pq.pop();
        a[pair.second] += pair.second + 1;
        pq.push(make_pair(a[pair.second], pair.second));
    }

    ll ans = INF;
    for(int i = 0; i < n; i++){
        ans = min(ans, a[i]);
        cout << a[i] << " ";
    }
    cout << br << ans << br;
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