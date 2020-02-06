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
    
    int n, q;
    cin >> n >> q;

    vector<char> balls;
    balls.push_back('A');

    for (int i = 1; i < n; i++) {
        int l = 0, r = i-1, m;
        char ball = 'A'+i, less_than;
        while (l <= r) {
            m = (l+r) / 2; 
            cout << "? " << ball << " " << balls[m] << endl;
            cin >> less_than;
            if (less_than == '<') {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        m = (r+l)/2;
        if (less_than == '>' && m == i-1) {
            balls.push_back(ball);
        } else {
            balls.insert(balls.begin()+m, ball);
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << balls[i];
    }
    cout << endl; 
    

    return 0;
}
