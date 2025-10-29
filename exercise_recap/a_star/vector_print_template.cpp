#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;

// Template function that accepts a matrix of ANY type
template <typename T>
void printMatrix(const vector<vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Integer matrix
    vector<vector<int>> intMat = {
        {1, 2},
        {3, 4}
    };

    // String matrix
    vector<vector<std::string>> strMat = {
        {"hello", "world"},
        {"foo", "bar"}
    };

    cout << "Integer matrix:" << endl;
    printMatrix(intMat);

    cout << "String matrix:" << endl;
    printMatrix(strMat);

    return 0;
}
