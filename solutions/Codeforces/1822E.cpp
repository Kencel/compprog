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
    int n, b;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2 == 1){
        cout << -1 << br;
        return;
    }
    b = n / 2;
    map<char, int> count;
    for(int i=0; i < n; i++){
        count[s[i]]++;
        if(count[s[i]] > b){
            cout << -1 << br;
            return;
        }
    }
    int c = 0, mx = 0;
    map<char, int> dupe;
    for(int i=0; i < b; i++){
        if(s[i] == s[n - i - 1]){
            c++;
            dupe[s[i]]++;
            mx = max(mx, dupe[s[i]]);
        }
    }
    cout << (c + 1) / 2 + max(0, mx - (int)((c + 1) / 2)) << br;
    count.clear();
    dupe.clear();
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