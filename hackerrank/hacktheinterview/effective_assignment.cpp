#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minAccommodationFactor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY door
 *  2. INTEGER_ARRAY status
 */

int minAccommodationFactor(vector<int> door, vector<int> status) {
    sort(door.begin(), door.end(), greater<int>());
    sort(status.begin(), status.end(), greater<int>());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    door.push_back(-100);
    int res = 0;
    vector<int> counts(door.size(), 0);
    int j = 0;
    for (int i = 0; i < door.size()-1; i++) {
        q.push({0, i});
        while (j < status.size() && status[j] > door[i+1]) {
            pair<int,int> p = q.top();
            q.pop();
            counts[p.second]++;
            q.push({counts[p.second], p.second});
            j++;
        }
    }
    
    for (auto& i : counts) {
        res = max(i, res);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string door_temp_temp;
    getline(cin, door_temp_temp);

    vector<string> door_temp = split(rtrim(door_temp_temp));

    vector<int> door(n);

    for (int i = 0; i < n; i++) {
        int door_item = stoi(door_temp[i]);

        door[i] = door_item;
    }

    string status_temp_temp;
    getline(cin, status_temp_temp);

    vector<string> status_temp = split(rtrim(status_temp_temp));

    vector<int> status(m);

    for (int i = 0; i < m; i++) {
        int status_item = stoi(status_temp[i]);

        status[i] = status_item;
    }

    int ans = minAccommodationFactor(door, status);

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

