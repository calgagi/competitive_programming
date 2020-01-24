/*
ID: calgagi1
TASK: test
LANG: C++
*/
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
    freopen("test.in", "r", stdin); freopen("test.out", "w", stdout); 

    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
     

    return 0;
}
