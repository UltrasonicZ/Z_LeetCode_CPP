#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int tmp = a ^ b;
            b = (a & b) << 1;
            a = tmp;
        }
        return a;
    }
};
int main() {
    Solution sol;
    std::cout << sol.getSum(-2, 3) << std::endl;
    return 0;
}
