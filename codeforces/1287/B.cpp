// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n, a; cin >> n >> a;
    vector<string> cards(n);
    for (auto& s : cards) cin >> s;

    long long ans = 0;
    map<string,int> m;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            string s;
            for (int k = 0; k < a; k++) {
                if (cards[i][k] == cards[j][k]) {
                    s += cards[i][k];
                } else {
                    if (cards[i][k] != 'S' && cards[j][k] != 'S')
                        s += 'S';
                    else if (cards[i][k] != 'E' && cards[j][k] != 'E')
                        s += 'E';
                    else if (cards[i][k] != 'T' && cards[j][k] != 'T')
                        s += 'T';
                }
            }
            ans += m[s];
        }
        m[cards[i]]++;
    }
    cout << ans << endl;

    return 0;
}
