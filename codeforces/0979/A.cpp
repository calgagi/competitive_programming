// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	long long n; cin >> n;
	n = n+1;
	if (n == 1) cout << 0 << endl;
	else if (n % 2 == 0) cout << n / 2 << endl;
	else cout << n << endl;

	return 0;
}
