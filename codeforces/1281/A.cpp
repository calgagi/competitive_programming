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


    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        if (s.substr(0, 2) == "op")
            cout << "FILIPINO" << endl;
        else if (s.substr(0, 4) == "usam" || s.substr(0, 4) == "used")
            cout << "JAPANESE" << endl;
        else if (s.substr(0, 5) == "adinm")
            cout << "KOREAN" << endl;
    }


    

    return 0;
}
