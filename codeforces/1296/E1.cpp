// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

map<char, vector<char>> graph;
vector<int> marked;

bool dfs(char cur, int color) {
    if (marked[cur-'a'] == -1) {
        marked[cur-'a'] = color;
    }
    int next_color = (color == 0 ? 1 : 0);
    for (auto& e : graph[cur]) {
        if (marked[e-'a'] == -1) {
            bool that = dfs(e, next_color);
            if (that == false) {
                return false;
            }
        } else if (marked[e-'a'] == marked[cur-'a']) {
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    string s, sorted;
    cin >> s;

    sorted = s;
    sort(sorted.begin(), sorted.end());
    marked.assign(26, -1);
    
    // Make undirected graph
    for (int i = 0; i < n; i++) {
        if (sorted[i] == s[i]) continue;
        if (i > 0 && s[i] != s[i-1]) {
            graph[s[i]].push_back(s[i-1]);
            graph[s[i-1]].push_back(s[i]);
        } 
        if (i < n-1 && s[i] != s[i+1]) {
            graph[s[i]].push_back(s[i+1]);
            graph[s[i+1]].push_back(s[i]);
        }
    }

    // Now, must color graph
    bool res = true;
    for (int i = 0; i < n; i++) {
        if (marked[s[i]-'a'] == -1) {
            res &= dfs(s[i], 1);
        }
    }
    if (res) {
        cout << "YES" << endl;
        for (auto& item : s) {
            cout << marked[item-'a'];
        } 
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
