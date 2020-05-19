/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

const int M = 26;
const char A = 'A';

void solve() {
    int r, c;
    cin >> r >> c;
    
    vector<vector<int>> w(r, vector<int>(c));
    set<int> letters;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char x;
            cin >> x;
            w[i][j] = x-A;
            letters.insert(x-A); 
        }
    }

    vector<set<int>> graph(M);
    vector<set<int>> backg(M);
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (w[i-1][j] != w[i][j]) {
                backg[w[i-1][j]].insert(w[i][j]);
                graph[w[i][j]].insert(w[i-1][j]);
            }
        }
    }

    // kahn's
    vector<int> fringe;
    for (int i = 0; i < c; i++) {
        if (backg[w[r-1][i]].size() == 0 && find(fringe.begin(), fringe.end(), w[r-1][i]) == fringe.end()) {
            fringe.push_back(w[r-1][i]);
        }
    }
    
    string ans = "";
    while (!fringe.empty()) {
        vector<int> new_fringe;
        for (int x : fringe) {
            ans += (x + A);
            for (int to : graph[x]) {
                backg[to].erase(x);
                if (backg[to].size() == 0) {
                    new_fringe.push_back(to);
                }
            } 
        }
        fringe = new_fringe;
    }     

    cout << (ans.size() == letters.size() ? ans : "-1") << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
