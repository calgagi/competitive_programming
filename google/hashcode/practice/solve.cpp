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
    
    int N, M;
    cin >> N >> M;
    vector<int> s(M);
    for (auto& i : s) {
        cin >> i;
    }

    // Obvious answers: 
    //  DFS = O(2^M)
    //  0-1 Knapsack = O(M^2), but requires O(M^2) memory as well which is too much

    // We probably need some sort of approximation algorithm
    // Simple: Greedy. O(MlogM)
    sort(s.begin(), s.end(), greater<int>()); 
    vector<int> ans;
    for (int i = 0; i < M; i++) {
        if (s[i] < N) {
            ans.push_back(i);
            N -= s[i];
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << (i == (int)ans.size()-1 ? "\n" : " ");
    }

    return 0;
}
