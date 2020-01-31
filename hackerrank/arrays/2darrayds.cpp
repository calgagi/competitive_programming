#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> a) {
    int m = a.size(), n = a[0].size();
    int res = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i-1 < 0 || i+1 >= m || j-1 < 0 || j+1 >= m) continue;
            res = max(res, a[i][j] + a[i+1][j+1] + a[i-1][j-1] + a[i+1][j-1] + a[i-1][j+1] + a[i+1][j] + a[i-1][j]);
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

