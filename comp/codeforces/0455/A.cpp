// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	long long int n; cin >> n;
	long long int arr[100005], dp[100005];
	for (int i = 0; i < n; i++) {
		int r; cin >> r;
		arr[r]++;
	}

	dp[0] = 0;
	dp[1] = arr[1];
	for (long long int i = 2; i < 100005; i++)
		dp[i] = max(dp[i-1], dp[i-2] + i*arr[i]);
	cout << dp[100004] << endl;	

	return 0;
}
