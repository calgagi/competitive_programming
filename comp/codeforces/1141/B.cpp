// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	int a[n];
	int r = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) { 
			r++;
			m = max(r, m);
		} else r = 0;
	}
	for (int i = 0; a[i]; i++) {
		r++;
		m = max(r, m);
	}
	cout << m << endl;

	return 0;
}
