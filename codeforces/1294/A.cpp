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


    int t; cin >> t;
    while (t--) {
        vector<int> c(3);
        int n;
        for (auto& i : c) cin >> i;
        cin >> n;
        sort(c.begin(),c.end(),greater<int>());
        int diff = (c[0] - c[1]) + (c[0] - c[2]);
        int tot = n + c[0] + c[1] + c[2];
        
        cout << (diff<=n&&tot%3==0?"YES":"NO") <<endl;
    }
        

     

    return 0;
}
