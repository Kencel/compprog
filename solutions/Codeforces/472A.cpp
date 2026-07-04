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
    int n;
    cin >> n;
    if(n % 4 == 0){
        cout << n / 2 << " " << n / 2;
    } else if(n % 4 == 2){
        cout << n / 2 + 1 << " " << n / 2 - 1;
    } else {
        int a, b;
        a = n / 2;
        b = n / 2 + 1;
        if(a % 2 == 0){
            swap(a, b);
        }
        while(a % 3 != 0){
            a += 2;
            b -= 2;
        }
        cout << a << " " << b;
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