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
    ll n, q;
    cin >> n >> q;
    for(ll i=0; i < q; i++){
        string query;
        cin >> query;
        if(query == "->"){
            ll x, y;
            cin >> y >> x;
            x--; y--;

            ll ans = 0, exp = 2 * n - 1;
            ll lx = -1, rx = 1 << n, ly = -1, ry = 1 << n;
            while(rx - lx > 1){
                ll mx = (lx + rx) / 2;
                ll my = (ly + ry) / 2;


                if(x <= mx && y <= my){
                    rx = mx;
                    ry = my;
                } else if(x <= mx && y > my){
                    ans += 1 << exp;
                    rx = mx;
                    ly = my;
                } else if(x > mx && y <= my){
                    ans += 1 << exp;
                    ans += 1 << (exp - 1);
                    lx = mx;
                    ry = my;
                } else {
                    ans += 1 << (exp - 1);
                    lx = mx;
                    ly = my;
                }

                exp -= 2;
            }

            cout << ans + 1 << br;
        } else {
            ll d;
            cin >> d;
            d--;

            ll exp = 2 * n - 1;
            ll lx = -1, rx = 1 << n, ly = -1, ry = 1 << n;
            while(rx - lx > 1){
                ll mx = (lx + rx) / 2;
                ll my = (ly + ry) / 2;

                bool first = false, second = false;
                if(d & (1ll << exp)) first = true;
                if(d & (1ll << (exp - 1))) second = true;

                if(!first && !second){
                    rx = mx;
                    ry = my;
                } else if(!first && second){
                    lx = mx;
                    ly = my;
                } else if(first && !second){
                    rx = mx;
                    ly = my;
                } else {
                    lx = mx;
                    ry = my;
                }

                exp -= 2;
            }

            cout << ly + 2 << " " << lx + 2 << br;
        }
    }
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