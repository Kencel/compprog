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

const int MAXN = sqrt(1e9) + 1;
vector<int> p;
vector<bool> np;

bool tc = true;
void solve() {
    int n;
    cin >> n;
    if(n == 1){
        cout << "FastestFinger" << br;
        return;
    }
    if(n == 2){
        cout << "Ashishgup" << br;
        return;
    }
    int count = 0, curr = n;
    while(curr % 2 == 0) curr /= 2;
    for(int i=1; i < sz(p); i++){
        while(curr % p[i] == 0){
            curr /= p[i];
            count++;
        }
    }
    if(curr > 1) count++;
    if(n % 2 == 1){
        cout << "Ashishgup" << br;
        return;
    }
    if(count == 0){
        cout << "FastestFinger" << br;
        return;
    }
    if(count == 1){
        if(n % 4 == 2){
            cout << "FastestFinger" << br;
            return;
        }
        cout << "Ashishgup" << br;
        return;
    }
    cout << "Ashishgup" << br;
    return;

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if(!tc){
        solve();
        return 0;
    }

    np.resize(MAXN);
    for(int i=2; i < MAXN; i++){
        if(np[i]) continue;
        p.pb(i);
        int curr = i * 2;
        while(curr < MAXN){
            np[curr] = true;
            curr += i;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}