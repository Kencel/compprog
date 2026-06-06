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

const ll INF = 1e18;



void solve(set<int>& prime) {
    int x, k;
    cin >> x >> k;

    if(x == 1 && k == 2){
        cout << "YES" << br;
        return;
    }

    if(k > 1 || x == 1){
        cout << "NO" << br;
        return;
    }

    if(prime.contains(x)){
        cout << "YES" << br;
        return;
    }
    
    for(auto p : prime){
        if(x % p == 0){
            cout << "NO" << br;
            return;
        }
    }

    cout << "YES" << br;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> prime, np;
    for(int i=2; i < 1e5; i++){
        if(np.contains(i)) continue;
        prime.insert(i);
        int temp = i * 2;
        while(temp < 1e5){
            np.insert(temp);
            temp += i;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve(prime);
    }

    // solve();

}