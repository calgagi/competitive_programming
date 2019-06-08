// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int d = 1;
	int abc = 0;
	long long MOD = 1000000007;
	for (int i = 1; i <= n; i++) {
		int x = abc * 3LL % MOD;
		int y = (abc * 2LL + d) % MOD;
		d = x;
		abc = y;
	}
	cout << x << endl;

	return 0;
}
