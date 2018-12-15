#include <iostream>
#include <algorithm>
class Solution {
public:
    int nthUglyNumber(int n) {
        int *uglynums = new int[n];
        uglynums[0] = 1;
        int *p2 = uglynums;
        int *p3 = uglynums;
        int *p5 = uglynums;
        int i = 1;
        while (i < n) {
            int minnum = std::min(std::min(*p2 * 2, *p3 * 3), *p5 * 5);
            uglynums[i] = minnum;
            while (*p2 * 2 == minnum) ++p2;
            while (*p3 * 3 == minnum) ++p3;
            while (*p5 * 5 == minnum) ++p5;
            ++i;
        }
        return uglynums[n - 1];
    }
};

int main() {
   Solution sol;
   std::cout << sol.nthUglyNumber(1500) << std::endl;
   return 0;
}
