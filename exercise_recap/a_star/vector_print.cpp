#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Helper function to print a 2D vector
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // 1x1 vector
    vector<vector<int>> mat1x1 = {
        {1}
    };

    // 2x2 vector
    vector<vector<int>> mat2x2 = {
        {1, 2},
        {3, 4}
    };

    // 3x3 vector
    vector<vector<int>> mat3x3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print them
    cout << "1x1 Matrix:" << endl;
    printMatrix(mat1x1);

    cout << "2x2 Matrix:" << endl;
    printMatrix(mat2x2);

    cout << "3x3 Matrix:" << endl;
    printMatrix(mat3x3);

    return 0;
}
