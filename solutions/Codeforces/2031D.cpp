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

const int INF = 1e9 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    vi pfix;
    pfix.pb(0);
    deque<int> sfix;
    sfix.push_front(INF);
    for(int i=0; i < n; i++){
        pfix.pb(max(pfix[i], a[i]));
        sfix.push_front(min(sfix[0], a[n - i - 1]));
    }
    vector<pi> segments;
    int l = 0, r = 0;

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