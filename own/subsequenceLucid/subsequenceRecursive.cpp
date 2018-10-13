#include <cstdio>
#include <limits>
#include <vector>
#include <iostream>
#include <cmath> // For absolute value

using namespace std;

/**
 * Take a rectangular grid of numbers and find the length
 * of the longest sub-sequence.
 * Return the length as an integer.
 */

int exploreNeighbors(vector< vector<int> > grid, vector< vector<int> > currentPath){
    // ============== PLAN =============
    // 1. Loop through each connnection
    // 2. While finding connections to current connection that isn't going back to a previous connection
    //      Push node to
    // 3. If size is greater than currentLongest, set size to currentLongest

    // loop through each connection
    for(int i = 0; i < connectionList.size(); i++){
        // Create empty vector
        vector< vector<int> > currentSubSequence;
        while(true){
            // Search fo r
            for(int j = 0; j < connectionList.size; j++){

            }
        }
    }
}

int longest_subsequence(vector< vector<int> > grid) {
    // TODO: Complete this function
    // Name: Calvin Gagliano

    // ============= NEW PLAN ==============
    // 1. For each node, recursively call all neighbors that have diff > 3
    // 2. Inside recursive function,
    //     a. find all neighbors with diff > 3
    //     b. Check to see if we've been through those neighbors already
    //     c. If not, add node to currentPath
    //     d. Loop through each node and <return> call recursive function with that node
    //     e. Keep track of the largest int returned
    //     f. If yes, return int

    // 1
    // Loop through each node and call recursive func
    int longestSS = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            int temp = exploreNeighbors(grid, i, j);
            if(temp > longestSS){
                longestSS = temp;
            }
        }
    }
    return longestSS;
}

int main() {
    int res;

    int num_rows = 0;
    int num_cols = 0;
    cin >> num_rows;
    cin >> num_cols;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector< vector<int> > grid;
    int grid_item;
    for (int row = 0; row < num_rows; row++) {
        vector<int> grid_row;

        for (int col = 0; col < num_cols; col++) {
            cin >> grid_item;
            grid_row.push_back(grid_item);
        }
        grid.push_back(grid_row);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    res = longest_subsequence(grid);
    cout << res << endl;

    return 0;
}
