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
const int MAX_N = 1e6;
vector<bool> np;

bool tc = false;
void solve() {
    int n;
    cin >> n;
    if(n < 3){
        cout << 1 << br;
    } else {
        cout << 2 << br;
    }
    for(int i=2; i <= n + 1; i++){
        cout << np[i] + 1 << " ";
    }
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    np.resize(MAX_N + 5);
    for(int i=2; i < MAX_N + 5; i++){
        if(np[i]) continue;
        int curr = i * 2;
        while(curr < MAX_N + 5){
            np[curr] = true;
            curr += i;
        }
    }
    
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