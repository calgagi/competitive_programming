/*
 * author: calgagi
 *         Calvin Gagliano 
 */
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
    
    int a, b;
    do {
        int res = 0;
        cin >> a >> b;
        unordered_set<int> n, m;
        for (int i = 0; i < a; i++) {
            int x;
            cin >> x;
            n.insert(x);
        }
        for (int i = 0; i < b; i++) {
            int x;
            cin >> x;
            if (n.find(x) != n.end() && m.find(x) == m.end()) {
                res++;
            }
            m.insert(x);
        }
        if (a || b) {
            cout << res << endl;
        }
    } while (a != 0 && b != 0);

    return 0;
}
