/*
ID: calgagi1
LANG: C++
TASK: crypt1
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


int solve(const vector<int>& n) {
    int res = 0;

    set<int> v;
    for (auto& i : n)
        v.insert(i);

    for (auto f1 : n) {
        for (auto f2 : n) {
            for (auto f3 : n) {
                int f = f1*100 + f2*10 + f3;
                for (auto s1 : n) {
                    for (auto s2 : n) {
                        string l1 = to_string(f * s1);
                        string l2 = to_string(f * s2); 
                        if (l1.length() != 3 || l2.length() != 3) continue;

                        bool valid = true;
                        for (auto c : l1) {
                            if (!v.count(c - '0')) {
                                valid = false;
                            }
                        }
                        for (auto c : l2) {
                            if (!v.count(c - '0')) {
                                valid = false;
                            }
                        }
                        if (!valid) continue;

                        string a = to_string(f * s1 * 10 + f * s2);
                        if (a.length() != 4) continue;
                        for (auto& c : a) {
                            if (!v.count(c - '0')) {
                                valid = false;
                            }
                        }
                        if (!valid) continue;
                        res++;
                    }
                }
            }
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("crypt1.in", "r", stdin), *OUT = freopen("crypt1.out", "w", stdout); 

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& i : nums)
        cin >> i;

    cout << solve(nums) << endl;

    return 0;
}
