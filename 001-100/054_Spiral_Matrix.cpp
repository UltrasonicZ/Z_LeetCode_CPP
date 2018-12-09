#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> result;
        if (rows <= 0 || columns <= 0)
            return result;
        int start = 0;
        while (columns > start * 2 && rows > start * 2) {
            matrixInCircle(matrix, columns, rows, start, result);
            ++start;
        }
        return result;
    }
    void matrixInCircle(vector<vector<int>>& matrix, int columns, int rows, int start, vector<int>& result) {
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;
        for (int i = start; i <= endX; ++i)
            result.push_back(matrix[start][i]);
        if (start < endY)
            for (int i = start + 1; i <= endY; ++i)
                result.push_back(matrix[i][endX]);
        if (start < endX && start < endY)
            for (int i = endX - 1; i >= start; --i)
                result.push_back(matrix[endY][i]);
        if (start < endX && start < endY - 1)
            for (int i = endY - 1; i >= start + 1; --i)
                result.push_back(matrix[i][start]);
    }
};

int main() {
    const int row = 5;
    const int col = 5;
    vector<vector<int>> matrix(row, vector<int>(col, 0));
    int k = 1;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = k;
            ++k;
        }
//    vector<vector<int>> matrix;
    Solution sol;
    vector<int> result;
    result = sol.spiralOrder(matrix);
    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << ' ';
    std::cout << std::endl;
    return 0;
}
