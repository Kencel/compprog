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

bool tc = false;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<bool>> g;
    for(int i=0; i < n; i++){
        string s;
        cin >> s;
        vector<bool> row;
        for(char c : s){
            row.pb(c == '*');
        }
        g.pb(row);
    }
    vector<vi> pfix;
    vi z(n + 1, 0);
    pfix.pb(z);
    for(int i=0; i < n; i++){
        vi row = {0};
        for(int j=0; j < n; j++){
            row.pb(g[i][j] + pfix[i][j + 1] + row[j] - pfix[i][j]);
        }
        pfix.pb(row);
    }
    for(int i=0; i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pfix[x2][y2] - pfix[x1 - 1][y2] - pfix[x2][y1 - 1] + pfix[x1 - 1][y1 - 1] << br;
    }
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