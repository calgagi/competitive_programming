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

void getConnectionsList(vector< vector<int> > grid, vector< vector<int> > &connectionList){
    // ============== PLAN =============
    // 1. Loop through each element in grid
    // 2. If the element has a neighbor that's diff > 3
    //    and the connection is not already in connectionList,
    // 3. Add to connectionList

    // Loop through each element in grid (1)
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            // Look for neighbors that diffs > 3 (2)
            // Neighbors are defined as other items within the 3x3 square around the element
            for(int k = i-1; k < i+2; k++){
                for(int l = j-1; l < j+2; j++){
                    // If within bounds of grid
                    if(k >= 0 && l >= 0 && k < grid.size() && l < grid[i].size()){
                        // If diff is > 3
                        if(abs(grid[i][j] - grid[k][l]) > 3){
                            // Create new vector and add both element coordinates to it
                            vector<int> temp;
                            temp.push_back(i); temp.push_back(j);
                            tmep.push_back(k); temp.push_back(l);
                            // Push to connectionList
                            connectionList.push(temp);
                        }
                    }
                }
            }
        }
    }
}

int getLongestSS(vector< vector<int> > connectionList){
    // ============== PLAN =============
    // 1. Loop through each connnection
    // 2. While finding connections to current connection that isn't going back to a previous connection
    //      Push node to
    // 3. If size is greater than currentLongest, set size to currentLongest
    vector< vector<int> > currentSubSequence;
    for(int i = 0; i < connectionList.size(); i++){
        while()
    }
}

int longest_subsequence(vector< vector<int> > grid) {
    // TODO: Complete this function
    // Name: Calvin Gagliano
    // ============== PLAN ================
    // 1. Parse strings to create 2D vector
    // 2. Find connections (ints with neighbors w/ diff > 3)
    // 3. Make largest subsequence from connections list
    // 4. Return largest subsequence size

    // ============== #1 ==================
    // Already done via main function

    // ============== #2 ==================
    // Find connections and put them in connectionList
    vector< vector<int> > connectionList;
    getConnectionsList(grid, connectionList);

    // ============= #3 ===================
    // Find longest subsequence from connections
    int longestSS = getLongestSS(connectionList);

    // ============= #4 ===================
    // Return longestSS
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
