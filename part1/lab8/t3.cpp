#include <iostream>
#include <vector>
using namespace std;

// Initialize the grid
char grid[10][10];

void initializeGrid() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = '.';
        }
    }
}

// Function to place ships on the grid
void placeShips(int shipSize, int numShips) {
    for (int k = 0; k < numShips; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                bool valid = true;
                if (grid[i][j] == '.') {
                    for (int x = i - 1; x < i + shipSize + 1; ++x) {
                        for (int y = j - 1; y < j + shipSize + 1; ++y) {
                            if (x >= 0 && x < 10 && y >= 0 && y < 10 && grid[x][y] == '#') {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) {
                            break;
                        }
                    }
                    if (valid) {
                        for (int x = i; x < i + shipSize; ++x) {
                            grid[x][j] = '#';
                        }
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    initializeGrid();

    // Place the four-cell ship at a random position
    grid[0][0] = '#';
    grid[0][1] = '#';
    grid[0][2] = '#';
    grid[0][3] = '#';

    // Place the ships on the grid
    placeShips(3, 2);
    placeShips(2, 3);
    placeShips(1, 4);

    // Print the grid
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
