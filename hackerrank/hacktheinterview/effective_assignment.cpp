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
    // Minimize the number of people in each door
    // Allocate people with larger status first to doors
    int n = status.size(), nd = door.size();
    vector<int> counts(nd, 0);
    sort(status.begin(), status.end(), greater<int>());
    sort(door.begin(), door.end(), greater<int>());
    door.push_back(0);
    int j = 0;
    // Put people in smallest possible rooms first
    for (int i = 1; i <= nd; i++) {
        while (j < n && status[j] > door[i]) {
            counts[i-1]++;
            j++;
        }
        //cout << counts[i-1] << " ";
    }
    int res = counts[0], space = 0;
    // Fill up bigger rooms now that have less people
    for (int i = 1; i < nd; i++) {
        if (counts[i] <= res) {
            space += res-counts[i];
        } else {
            // Can put people in space
            if (counts[i] <= space+res) {
                space -= counts[i]-res;
            } else {
            // Cannot put people in space... need to increment rooms by 1
            // i rooms so far
                // first allocate all the space
                int num_rooms = i+1;
                counts[i] -= space;
                counts[i] -= res;
                // now all space is a giant rectangle (all rooms have equal amount of people)
                // Continually add rows
                int to_add = counts[i] / num_rooms;
                res += to_add;
                // new space = the number of rooms that don't reach res+to_add
                space = num_rooms - (counts[i] % num_rooms); 
            }
        }
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

