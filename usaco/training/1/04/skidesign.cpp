/*
ID: calgagi1
LANG: C++
TASK: skidesign
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
    FILE *IN = freopen("skidesign.in", "r", stdin), *OUT = freopen("skidesign.out", "w", stdout); 

    int N;    
    cin >> N;
    vector<int> hills(N);
    for (auto& h : hills) {
        cin >> h;
    }



    return 0;
}
