#include <cstdio>
#include <limits>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Take a rectangular grid of numbers and find the length
 * of the longest sub-sequence.
 * Return the length as an integer.
 */

int exploreNeighbors(vector< vector<int> > grid, int x, int y, vector<int>& currentPath){
    // 2. Inside recursive function,
    //     a. find all neighbors with diff > 3
    //     b. Check to see if we've been through those neighbors already
    //     c. If not, add node to currentPath
    //     d. Loop through each node and <return> call recursive function with that node
    //     e. Keep track of the largest int returned
    //     f. If yes, return int

    int longestSS = 0;
    // loop through each neighbor
    for(int k = x-1; k < x+2; k++){
        for(int l = y-1; l < y+2; l++){
            // If within bounds of grid
            cout << grid.size() << " " << grid[0].size();
            if(k >= 0 && l >= 0 && k < grid.size() && l < grid[0].size()){
                // If diff is > 3
                if(grid[x][y] - grid[k][l] > 3 || grid[k][l] - grid[x][y] > 3){
                    // Check to see if it's in the currentPath
                    bool inCurrentPath = false;
                    for(int m = 0; m < (currentPath.size() / 2); m++){
                        if(k == m*2 && l == (m*2)+1){
                            inCurrentPath = true;
                            break;
                        }
                    }
                    // If not in currentPath
                    if(inCurrentPath == false){
                        // Add it to currentPath
                        currentPath.push_back(x);
                        currentPath.push_back(y);
                        // Explore neighbors of it!
                        int x = exploreNeighbors(grid, k, l, currentPath);
                        // If the path it found is longer than
                        if(x > longestSS){
                            longestSS = x;
                        }
                        currentPath.pop_back();
                        currentPath.pop_back();
                    }
                }
            }
        }
    }
    return longestSS + 1;
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
            vector<int> g;
            g.push_back(i);
            g.push_back(j);
            int temp = exploreNeighbors(grid, i, j, g);
            if(temp > longestSS){
                longestSS = temp;
            }
        }
    }
    return longestSS + 1;
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
