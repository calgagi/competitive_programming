// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (!a && !b) cout << "NO" << endl;
    else if (abs(a-b) <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
