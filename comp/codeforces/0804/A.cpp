// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	if (n == 1) cout << 0 << endl;
	else {
		n -= 2;
		cout << n / 2 + (n % 2) << endl;
	}
	return 0;
}
