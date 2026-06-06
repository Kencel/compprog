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
    vi a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }
    set<int> seen;
    for(int t : a){
        if(seen.contains(t)){
            cout << "NO" << br;
            return;
        }
        seen.insert(t);
    }
    cout << "YES" << br;
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