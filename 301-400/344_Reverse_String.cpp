#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    string reverseString(string s) {
        int start = 0, end = s.length() - 1;
        while (start < end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            ++start;
            --end;
        }
        return s;
    }
};

int main() {
    Solution sol;
    std::cout << sol.reverseString("hello world") << std::endl;
    return 0;
}
