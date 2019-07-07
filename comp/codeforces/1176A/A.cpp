// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long x; cin >> x;
		long long j = 0;
		while (x != 1) {
			if (x % 2 == 0) x /= 2;
			else if (x % 3 == 0) x = 2 * (x / 3);
			else if (x % 5 == 0) x = 4 * (x / 5);
			else break;
			j++;
		}
		if (x == 1) cout << j << endl;
		else cout << -1 << endl;
	}

	return 0;
}
