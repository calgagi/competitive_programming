// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

#define div second
#define node first

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 


    // s = 0
    // w = 1
    // t = 2
    // x = 3
    // y = 4
    // z = 5
    vector<vector<int>> graph = {{1}, {2,4}, {}, {0}, {3,5}, {2}};
    // vector<vector<int>> graph = {{1}, {2,4}, {}, {0}, {3,5}, {2}};
    // vector<vector<int>> graph = {{1}, {2}, {0}};

    stack<pair<int,int>> st;

    int marked[6][3] = {0};

    st.emplace(0, 0);

    while (!st.empty()) {
        pair<int,int> state = st.top();
        st.pop();
        if (marked[state.node][state.div] == 1) {
            continue;
        }
        marked[state.node][state.div] = 1;
        // If found t at 1
        if (state.node == 2 && state.div == 0) {
            cout << "FOUND" << endl;
            break;
        }
        for (auto& neighbor : graph[state.node]) {
            st.emplace(neighbor, (state.div + 1) % 3);
        }
    }

    return 0;
}
