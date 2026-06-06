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
    int n, s;
    cin >> n >> s;
    vi a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }
    vi pfix;
    pfix.pb(0);
    for(int i=0; i < n; i++){
        pfix.pb(pfix[i] + a[i]);
    }
    int target = pfix[n] - s;
    if(target < 0){
        cout << -1 << br;
        return;
    }
    int l = -1, r = n;
    while(r - l > 1){
        int m = (l + r) / 2;
        bool found = false;
        for(int i=0; i <= m; i++){
            if(pfix[m - i] + pfix[n] - pfix[n - i] >= target){
                r = m;
                found = true;
                break;
            }
        }
        if(!found) l = m;
    }
    cout << r << br;
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