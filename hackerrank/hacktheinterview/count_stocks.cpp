#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countStocks' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY stocks as parameter.
 */

long long countStocks(vector<int> stocks) {
    long long a = 0, b = 0;
    int n = stocks.size();
    // Faster: preprocess
    sort(stocks.begin(), stocks.end(), greater<int>());
    while (true) {
        bool same = false;
        vector<int> stocks2 = stocks;
        for (int i = 1; i < n; i++) {
            if (stocks[i] == stocks[i-1] && stocks[i] != 0) {
                stocks2[i] = stocks2[i-1] / 2;
                same = true;
            }
        }
        stocks = stocks2;
        if (!same) break;
        sort(stocks.begin(), stocks.end(), greater<int>());
    }
    bool turn = 1;
    for (int i = 0; i < n; i++) {
        if (turn) {
            a += stocks[i];
        } else {
            b += stocks[i];
        }
        turn = !turn;
    }

    return b;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string stocks_count_temp;
    getline(cin, stocks_count_temp);

    int stocks_count = stoi(ltrim(rtrim(stocks_count_temp)));

    string stocks_temp_temp;
    getline(cin, stocks_temp_temp);

    vector<string> stocks_temp = split(rtrim(stocks_temp_temp));

    vector<int> stocks(stocks_count);

    for (int i = 0; i < stocks_count; i++) {
        int stocks_item = stoi(stocks_temp[i]);

        stocks[i] = stocks_item;
    }

    long long ans = countStocks(stocks);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
