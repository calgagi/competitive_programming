/*
ID: calgagi1
LANG: C++
TASK: friday
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    freopen("friday.in", "r", stdin); freopen("friday.out", "w", stdout); 

    int n;
    cin >> n;
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ans[7];
    memset(ans, 0, sizeof(ans));

    long long day = 13;
    for (int year = 1900; year < 1900+n; year++) {
        for (int month = 0; month < 12; month++) {
            ans[(day-1) % 7]++;
            day += months[month];
            // leap year february
            if (month == 1 && ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0))) {
                day++;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        cout << ans[(i+5)%7] << " ";
    }
    cout << ans[(6+5)%7] << endl;

    return 0;
}
