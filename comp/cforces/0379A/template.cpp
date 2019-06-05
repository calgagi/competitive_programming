// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	double a, b; cin >> a >> b;
	double r = 0;

	do {
		r += a;
		a = a / b;
	} while (a > 0.01);
	cout << (int) r << endl;
	return 0;
}
