#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int n = s.length();
    unordered_map<string, int> seen;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string cur = "";
        for (int j = i; j < n; j++) {  
            cur += s[j];
            sort(cur.begin(), cur.end());
            ans += seen[cur];
            seen[cur]++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

