// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    // Akin to find # of Connected components in graph
    int n; cin >> n;
    vector<vector<bool>> graph(26, vector<bool>(26, false));
    vector<bool> see(26, false);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < (int) s.length(); j++) {
            see[s[j]-'a'] = true;
            for (int k = j+1; k < (int) s.length(); k++) {
                graph[s[j]-'a'][s[k]-'a'] = true;
                graph[s[k]-'a'][s[j]-'a'] = true;
            }
        }
    }
    
    int ans = 0;
    vector<bool> seen(26, false);
    for (int i = 0; i < 26; i++) {
        if (seen[i]) continue;
        if (see[i]) ans++;
        for (int j = 0; j < 26; j++) {
            if (graph[i][j]) {
                stack<int> s;
                s.push(i);
                while (!s.empty()) {
                    int cur = s.top();
                    s.pop();
                    if (seen[cur]) continue;
                    seen[cur] = true;
                    for (int k = 0; k < 26; k++)
                        if (graph[cur][k] && !seen[k])
                            s.push(k);
                }
                break;
            }
        }
    }
        
    cout << ans << endl;


    return 0;
}
