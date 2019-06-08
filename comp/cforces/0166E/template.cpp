// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	long long abc = 0;
	long long d = 1;
	long long MOD = 1000000007;
	for (int i = 1; i <= n; i++) {
		long long tabc = (2LL * abc + d) % MOD;
		long long td = (3LL * abc) % MOD;
		abc = tabc;
		d = td;	
	}
	cout << d << endl;

	return 0;
}
