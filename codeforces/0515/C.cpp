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

    vector<int> f(10);
    vector<string> r(10);
    r[2] = "2";
    r[3] = "3";
    r[4] = "322";
    r[5] = "5";
    r[6] = "53";
    r[7] = "7";
    r[8] = "7222";
    r[9] = "7332";
    string n, x;
    cin >> n >> x;
    n = "";
    for (char i : x) {
        n = n + r[i - '0'];
    }
    sort(n.begin(), n.end(), greater<char>());

    cout << n << endl;
    return 0;
}
