// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    string s;
    cin >> s;
    int streak = 1, best = 1, n = s.length();

    for (int i = 1; i < n; i++) {
        if (s[i-1] == s[i]) {
            streak++;
        } else {
            streak = 1;
        }
        best = max(streak, best);
    }

    cout << best << endl;
    

    return 0;
}
