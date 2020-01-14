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

    string s, p;
    cin >> s >> p;

    // Sliding window
    int b = 0, e = 0, ans = 0;

    bool use[26];
    int need[26];
    memset(use, 0, sizeof(use));
    memset(need, 0, sizeof(need));
    
    for (auto& c : p) {
        use[c-'a'] = 1;
        need[c-'a']++;
    }
    int counter = p.length();

    for (int e = 0; e < (int) s.length(); e++) {
        if (s[e] == '?' || use[s[e]-'a']) {
            if (s[e] == '?' || need[s[e]-'a'] > 0) counter--;
            if (s[e] != '?') need[s[e]-'a']--;
        }
        while (counter == 0) {
            if (s[b] == '?' || use[s[b]-'a']) {
                if (s[b] == '?') counter++;
                else {
                    need[s[b]-'a']++;
                    if (need[s[b]-'a'] > 0)
                        counter++;
                }
            } 
            if (e-b+1 == (int) p.length()) {
                ans++; 
            }
            b++;
        }
    }
            
    cout << ans << endl;        

    return 0;
}
