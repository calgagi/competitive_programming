// Calvin Gagliano
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n; cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.length() < 11)
			cout << s << endl;
		else
			cout << s[0] << s.length()-2 << s.back() << endl;
	}	
	return 0;
}
