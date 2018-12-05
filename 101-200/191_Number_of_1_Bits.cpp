#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int result;
    result = sol.hammingWeight(10);
    std::cout << result << std::endl;
    return 0;
}
