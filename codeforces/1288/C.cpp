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

    // solution I can think of is O(n^m), it's too slow though
    // Basically assign each spot of a a value, then I think you can find the number of arrays pretty easily using factorials
    // I think you can make it O(n(m^2)) by looping through each spot of ai, then each value of n.
    //
    // For i = [0, m-1]: 
    //  Calculate:
    //      a_LHS: (i)! + (i-1)! + ... until you reach either i = 0 or n = 1
    //      a_RHS: (i+1)! + (i+2)! + ... until you reach either i = m or n = max
    //
    //      For generating all b's, I'm not sure how to do it. The number of ways =  v 

    return 0;
}
