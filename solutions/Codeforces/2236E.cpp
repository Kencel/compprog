#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

bool tc = true;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    int l = 0, r = n / 2 + 1;
    while(r - l > 1){
        int m = (l + r) / 2;

        multiset<int> s;
        deque<int> window;
        vector<tuple<int, int, int>> sub;
        bool possible = false;
        int sum = 0;
        for(int i=0; i < m; i++){
            window.pb(a[i]);
            s.insert(a[i]);
            sum += a[i];
        }
        if(2 * sum == (*s.begin() + *s.rbegin()) * m && *s.rbegin() - *s.begin() == m - 1) sub.pb({0, *s.begin(), *s.rbegin()});
        for(int i=m; i < n; i++){
            sum -= window[0];
            s.erase(s.find(window[0]));
            window.pop_front();
            window.pb(a[i]);
            s.insert(a[i]);
            sum += a[i];
            if(2 * sum == (*s.begin() + *s.rbegin()) * m && *s.rbegin() - *s.begin() == m - 1) sub.pb({i - m + 1, *s.begin(), *s.rbegin()});
        }

        for(int i=0; i < sz(sub); i++){
            for(int j=i + 1; j < sz(sub); j++){
                if(get<0>(sub[j]) - get<0>(sub[i]) < m) continue;
                int la = get<1>(sub[i]), ra = get<2>(sub[i]);
                int lb = get<1>(sub[j]), rb = get<2>(sub[j]);
                if(ra + 1 == lb || rb + 1 == la){
                    possible = true;
                    break;
                }
            }
            if(possible) break;
        }

        if(possible){
            l = m;
        } else {
            r = m;
        }
    }
    
    cout << l << br;

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if(!tc){
        solve();
        return 0;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}