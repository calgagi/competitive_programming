/*
ID: calgagi1
LANG: C++
TASK: beads
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
    FILE *IN = freopen("beads.in", "r", stdin), *OUT = freopen("beads.out", "w", stdout); 

    // N^2 solution is trivial
    // N solution: prefix and suffix DP?
    int n;
    cin >> n;
    string beads;
    cin >> beads;

    beads += beads;
    n *= 2;

    int DPB[n], DPF[n];
    memset(DPB, 0, sizeof(DPF));
    for (int i = 0; i < n; i++) {

    int best = 0;


    return 0;
}
