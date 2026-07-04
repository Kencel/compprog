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
ll ans = 0;
vector<bool> x(8), pos(15), neg(15);
vector<vector<bool>> reserved(8, vector<bool>(8));

void place(int row){

    if(row == 8){
            ans++;
            return;
        }

    for(int i=0; i < 8; i++){
        if(x[i]) continue;
        if(pos[row + i]) continue;
        if(neg[row - i + 7]) continue;
        if(reserved[row][i]) continue;
        x[i] = true;
        pos[row + i] = true;
        neg[row - i + 7] = true;
        place(row + 1);
        x[i] = false;
        pos[row + i] = false;
        neg[row - i + 7] = false;
    }
    
}

bool tc = false;
void solve() {
    for(int i=0; i < 8; i++){
        string s;
        cin >> s;
        for(int j=0; j < 8; j++){
            if(s[j] == '*'){
                reserved[i][j] = true;
            }
        }
    }
    place(0);
    cout << ans;
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