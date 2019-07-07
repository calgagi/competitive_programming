// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


	unsigned long long a[5];
	for (int i = 0; i < 5; i++) cin >> a[i];
	unsigned long long l = max(a[0], a[2]);
	unsigned long long r = min(a[1], a[3]);
	if (a[1] < a[2]) cout << 0 << endl;
	else if (a[0] > a[3]) cout << 0 << endl;
	else {
		unsigned long long x = 1;
		if (a[4] <= r && l <= a[4]) {
			x -= 1;
		}
		x += (r - l);
		cout << x << endl;
	}

	return 0;
}
