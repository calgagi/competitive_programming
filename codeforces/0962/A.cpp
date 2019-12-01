// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n; cin >> n;
	int a[n+1];
	int total = 0;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
		total += a[i];
		a[i] += a[i-1];
	}
	// Binary search
	int search = (total / 2) + total % 2;
	int l = 1, r = n;
	while (l <= r) {
		int m = l + (r-l)/2;
		if (a[m] == search) {
			cout << m << endl;
			return 0;
		} 
		if (a[m] < search)
			l = m + 1;
		else 
			r = m - 1;
	}
	while (a[l] < search) l++;
	cout << l << endl;
	return 0;
}
