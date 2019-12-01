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

    int n; cin >> n;
    vector<int> a(n);
    forn(i,n) cin >> a[i];

    unordered_map<int,bool> office;
    unordered_map<int,bool> seen;
    int office_count = 0;
    int prev = -1;
    vector<int> days;
    forn(i,n){
        if (seen.find(abs(a[i])) != seen.end() || (a[i] > 0 && office[abs(a[i])]) || (a[i] < 0 && office.find(abs(a[i])) == office.end())) {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] > 0) {
            office[a[i]] = true;
            office_count++;
        } else {
            office[abs(a[i])] = false;
            seen[abs(a[i])] = true;
            office_count--;
        }
        if(office_count == 0) {
            seen.clear();
            days.pb(i-prev);
            prev = i;
        }
    }
    if(office_count) {
        cout << -1 << endl;
        return 0;
    }
    cout << days.size() << endl;
    for(auto& x : days) cout << x << " ";
    cout << endl;

    return 0;
}
