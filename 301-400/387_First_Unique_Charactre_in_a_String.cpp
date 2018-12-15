#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    int firstUniqChar(string s) {
        int hashtable[256] = {0};
        for (auto c : s)
            ++hashtable[c];
        for (int i = 0; i < s.size(); ++i)
            if (hashtable[s[i]] == 1)
                return i;
        return -1;
    }
};

int main() {
    Solution sol;
    std::cout << sol.firstUniqChar("loveleetcode") << std::endl;
    return 0;
}
