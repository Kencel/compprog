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

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi dp(5005);
    set<int> seen;
    deque<int> q;
    fill(all(dp), INF);
    
    for(int i=0; i < n; i++){
        cin >> a[i];
        q.pb(a[i]);
        dp[a[i]] = 0;
    }

    int target = a[0];
    for(int i=0; i < n; i++){
        target = gcd(target, a[i]);
    }
    bool found = false;
    int count = 0;
    for(int i=0; i < n; i++){
        if(a[i] == target) found = true;
        if(a[i] != target) count++;
    }

    if(found){
        cout << count << br;
        return;
    }

    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        if(seen.contains(v)) continue;
        for(auto &u : seen){
            int g = gcd(u, v);
            dp[g] = min(dp[g], max(dp[u], dp[v]) + 1);
            q.pb(g);
        }
        seen.insert(v);
    }
    
    cout << dp[target] + n - 1 << br;
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