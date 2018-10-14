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

void createConnectionList(vector< vector<int> >& grid, int x, int y, vector< vector<int> >& connectionList){
    // loop through each neighbor
    for(int k = x-1; k < x+2; k++){
      for(int l = y-1; l < y+2; l++){
          // If within bounds of grid
          if(k >= 0 && l >= 0 && k < grid.size() && l < grid[0].size() && !(y == l && x == k)){
              // If diff is > 3
              if(grid[x][y] - grid[k][l] > 3 || grid[k][l] - grid[x][y] > 3){
                  vector<int> temp;
                  temp.push_back(k);
                  temp.push_back(l);
                  connectionList.push_back(temp);
              }
          }
      }
    }
}

int getLongestSubsequence(vector< vector< vector< vector<int> > > >& connectionsLists, vector< vector<int> >& path){
  int longestSubSS = 0;
  int lastNodeX = path.back()[0];
  int lastNodeY = path.back()[1];
  int numConnections = connectionsLists[lastNodeX][lastNodeY].size();
  // Return condition: If there are no connections, return 1
  if(numConnections == 0){
    return 1;
  }else{
    // If there are connections, go to each one!
    for(int i = 0; i < numConnections; i++){
      // Figure out if we've been there already
      bool alreadyThere = false;
      for(int j = 0; j < path.size(); j++){
        if(path[j][0] == connectionsLists[lastNodeX][lastNodeY][i][0] && path[j][1] == connectionsLists[lastNodeX][lastNodeY][i][1]){
          alreadyThere = true;
        }
      }
      // If haven't been there, explore that path!
      if(!alreadyThere){
        vector<int> coordsOfNextNode;
        // Add coordinates of node about to explore to path
        coordsOfNextNode.push_back(connectionsLists[lastNodeX][lastNodeY][i][0]);
        coordsOfNextNode.push_back(connectionsLists[lastNodeX][lastNodeY][i][1]);
        path.push_back(coordsOfNextNode);
        // Get longest subsequence from that node
        int x = getLongestSubsequence(connectionsLists, path);
        if(longestSubSS < x){
          longestSubSS = x;
        }
        // Pop the last node we added so that we can explore another connection
        path.pop_back();
      }
    }
  }
  return longestSubSS + 1;
}

int longest_subsequence(vector< vector<int> > grid) {
    // TODO: Complete this function
    // Name: Calvin Gagliano

    // ============= PLAN ==============
    // 1. For each node, create connections list for that node
    // 2. Find the longest subsequence using a recursive function.
    //    ** Have to keep track of nodes we've already visited.

    // 1
    // Loop through each node and find connections
    // Create a vector of vectors of vectors of ints
    // For each element in grid, create a vector that holds vectors of coordinates for each neighbor connection
    vector< vector< vector< vector<int> > > > connectionsLists;
    for(int i = 0; i < grid.size(); i++){
      vector< vector< vector<int> > > row;
      for(int j = 0; j < grid[i].size(); j++){
          vector< vector<int> > x;
          createConnectionList(grid, i, j, x);
          row.push_back(x);
      }
      connectionsLists.push_back(row);
    }

    // 2
    // Recursive function to find longest path
    // Pass in ConnectionsLists and currentPath
    int longestSS = 0;
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[i].size(); j++){
        // Create path and add start node to it
        vector< vector<int> > path;
        vector<int> temp;
        temp.push_back(i);
        temp.push_back(j);
        path.push_back(temp);
        // Keep track of longest subsequence
        int longestFromNode = getLongestSubsequence(connectionsLists, path);
        if(longestFromNode > longestSS){
          longestSS = longestFromNode;
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
