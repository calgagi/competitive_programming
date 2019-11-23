// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> ans(6, 0);
	
    unordered_set<int> s = {4,8,15,16,23,42};
    vector<unordered_map<int,int>> possibles(6);
    int queryone, queryfour;
    forn(i, 4) { 
        cout<<"? "<<i+1<<" "<<i+2<<endl, cout.flush();
        int query; cin >> query;
        if (i == 0) queryone = query;
        if (i == 3) queryfour = query;
        for (auto& j : s) {
            if (query % j == 0 && s.find(query / j) != s.end() && possibles[i].find(j) == possibles[i].end()) {
                possibles[i][j]++;
                possibles[i][query / j]++;
                possibles[i+1][query / j]++;
                possibles[i+1][j]++;
            }
        }
    }
    fore(i, 1, 5) {
        for(auto j : possibles[i]) {
            if (j.second == 2) {
                ans[i] = j.first;
                cout << ans[i] << endl;
            }
        }
    }

    ans[0] = queryone / ans[1];
    ans[4] = queryfour / ans[3];    
     
    cout << "! ";
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << " ";
        s.erase(ans[i]);
    }
    cout << *(s.begin()) << endl;

    return 0;
}
