// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    // greedy
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> monsters(n);
    for (auto& i : monsters) {
       cin >> i; 
    }

    // Find monsters that are killed by opponent
    int ans = 0, c = a + b;
    vector<int> monsters_opp;
    for (int monster : monsters) {
        int hp_left = monster % (a + b);
        if (hp_left == 0) {
            hp_left = a+b;
        }
        if (hp_left > a) {
            monsters_opp.push_back(hp_left-a);
            //cout << monster << ": " << hp_left-a << endl;
        } else {
            // Else we killed the monster
            ans++;
        }
    } 

    // Monsters left will need to be sorted by hp_left
    sort(monsters_opp.begin(), monsters_opp.end());
    for (int hp : monsters_opp) {
        k -= (hp % a != 0) + (hp / a);
        if (k < 0) break;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
