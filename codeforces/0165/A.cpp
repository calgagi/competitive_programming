// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int a[200][2];
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];

	int c = 0;
	for (int i = 0; i < n; i++) {
		int l = 0, r = 0, b = 0, u = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][1] == a[j][1]) {
				if (a[i][0] < a[j][0]) l++;
				else if (a[i][0] > a[j][0]) r++;
			} else if (a[i][0] == a[j][0]) {
				if (a[i][1] < a[j][1]) b++;
				else if (a[i][1] > a[j][1]) u++;
			}
		}
		if (l && r && b && u) c++;
	}
	cout << c << endl;

	return 0;
}
