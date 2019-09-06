// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.find("++") != string::npos)
            x++;
        else
            x--;
    }
    cout << x << endl;

    return 0;
}
