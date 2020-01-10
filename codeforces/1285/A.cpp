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

    int n; cin >> n;
    int max_pos = 0;
    int min_pos = 0;
    for (int i = 0; i < n; i++) {
        char s; cin >> s;
        if (s == 'R') max_pos++;
        else if (s == 'L') min_pos++;
    }
    cout << max_pos+min_pos+1 << endl; 

    return 0;
}
