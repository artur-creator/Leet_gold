// leet_golg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> roww = { 1, -1, 0, 0 };
vector<int> coll = { 0, 0, -1, 1 };
int maxGold = 0;

int dfs(vector<vector<int>>& grid, int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;

    int curr = grid[x][y];
    grid[x][y] = 0;
    int localMaxGold = curr;

    for (int i = 0; i < 4; i++) {
        int newX = x + roww[i];
        int newY = y + coll[i];
        localMaxGold = max(localMaxGold, curr + dfs(grid, newX, newY, n, m));
    }

    grid[x][y] = curr;
    return localMaxGold;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) {
                maxGold = max(maxGold, dfs(grid, i, j, n, m));
            }
        }
    }

    return maxGold;
}
int main()
{
    vector<vector<int>>mine =
    {
        {0,6,0},
        {5,8,7},
        {0,9,0}
    };
    cout << getMaximumGold(mine);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
