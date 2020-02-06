// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

map<int, vector<int>> graph;
vector<int> marked;

bool dfs(int cur, int color) {
    if (marked[cur] == -1) {
        marked[cur] = color;
    }
    int next_color = (color == 0 ? 1 : 0);
    for (auto& e : graph[cur]) {
        if (marked[e] == -1) {
            bool that = dfs(e, next_color);
            if (that == false) {
                return false;
            }
        } else if (marked[e] == marked[cur]) {
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
    string s; 
    cin >> s;

    marked.assign(n, -1);
    
    // Make undirected graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] < s[j]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            } 
        }
        for (int j = i+1; j < n; j++) {
            if (s[i] > s[j]) {
                graph[j].push_back(i);
                graph[i].push_back(j);
            }
        }
    }

    // Now, must color graph
    bool res = true;
    for (int i = 0; i < n; i++) {
        if (marked[i] == -1) {
            res &= dfs(i, 1);
        }
    }
    if (res) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << marked[i];
        } 
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
