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
    vi a(n + 1);
    a[1] = 1;
    set<int> visited;
    for(int i=2; i <= n; i++){
        if(visited.contains(i)) continue;
        if(i * 2 > n) {
            a[i] = i;
            continue;
        }
        a[i] = n - (n % i);
        for(int j=i * 2; j <= n - (n % i); j += i){
            a[j] = j - i;
        }
    }
    for(int i=1; i <= n; i++) cout << a[i] << " ";
    cout << br;
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