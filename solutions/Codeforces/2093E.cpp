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
    vi a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    int l = 0, r = n + 1;
    while(r - l > 1){
        int m = (l + r) / 2;

        vector<bool> seen(m, false);
        int count = 0, ptr = 0;
        for(int i=0; i < n; i++){
            if(a[i] >= m) continue;
            seen[a[i]] = true;
            while(seen[ptr]){
                ptr++;
                if(ptr == m) break;
            }
            if(ptr == m){
                count++;
                ptr = 0;
                for(int j=0; j < m; j++){
                    seen[j] = false;
                }
            }
        }

        if(count < k){
            r = m;
        } else {
            l = m;
        }
    }

    cout << l << br;
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