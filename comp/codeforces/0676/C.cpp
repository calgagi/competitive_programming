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

    string s;
    int n, k;
    cin >> n >> k >> s;
    int r = 0;
    for (char a = 'a'; a <= 'b'; a++) {
        queue<int> q;
        int c = 0, j = 0;
        for (int i = 0; i < s.length(); i++) {
            c++;
            j++;
            if (s[i] != a) {
                q.push(j);
                j = 0;
                if (q.size() > k) {
                    c -= q.front();
                    q.pop();
                }
            } 
            r = max(c, r);
        } 
    }
    cout << r << endl;


    return 0;
}
