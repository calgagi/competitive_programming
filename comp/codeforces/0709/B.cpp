// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n >> a;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    if (n == 1)
        cout << 0 << endl;
    else if (n == 2)
        cout << min(abs(a - arr[0]), abs(a - arr[1])) << endl;
    else if (a <= arr[0])
        cout << arr[n-2] - a << endl;
    else if (a >= arr[n-1])
        cout << abs(arr[1] - a) << endl;
    else {
        int r = abs(arr[n-1] - a);
        int l = abs(arr[0] - a);
        int rn = abs(arr[n-2] - a);
        int ln = abs(arr[1] - a);
        int x = min(min(r + 2*ln, 2*r + ln), min(l + 2*rn, 2*l + rn)); 
        int y = INT_MAX;
        if (a <= arr[1]) y = min(r, y);
        if (a >= arr[n-2]) y = min(l, y);
        cout << min(x, y) << endl;
    }
    return 0;
}
