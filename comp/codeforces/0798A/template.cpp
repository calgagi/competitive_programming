// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s; cin >> s;
	int r = 2;
	for (int i = 0, j = (int)s.size()-1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			r--;
			if (!r) break;
		}
	}
	if (r == 1 || ((r == 2) && (int) s.size() % 2 == 1)) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
