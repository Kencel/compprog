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
    vi x(n);
    for(int i=0; i < n; i++){
        cin >> x[i];
    }
    ll ans = 0;
    multiset<int> c;
    set<int> s;
    deque<int> q;
    for(int i=0; i < n; i++){
        q.pb(x[i]);
        s.insert(x[i]);
        c.insert(x[i]);
        while(sz(s) > k){
            int temp = q.front();
            q.pop_front();
            c.erase(c.find(temp));
            if(c.count(temp) == 0){
                s.erase(temp);
            }
        }
        ans += sz(q);
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