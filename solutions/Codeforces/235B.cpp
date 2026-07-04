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
    vector<double> p(n);
    for(int i=0; i < n; i++){
        cin >> p[i];
    }
    double score = 0, exp_length = 0;

    for(int i=0; i < n; i++){
        score += p[i] * (2 * exp_length + 1);
        exp_length = (exp_length + 1) * p[i];
    }

    cout << score;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    
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