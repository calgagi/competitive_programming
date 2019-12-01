// Calvin Gagliano
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int x = 0;
	int n, k, s; cin >> n >> k >> s;
	for (int i = 0; i < k-1 && s > 0; i++) {
		x += 1;
		cin >> s;
	}
	int p = s;
	while (p == s && p > 0 && x < n) {
		x += 1;
		cin >> s;
	}
	cout << x << endl;
		
	return 0;
}
