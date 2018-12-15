#include <iostream>
#include <string>
using std::string;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int hashtable[256] = {0};
        for (int i = 0; i < s.length(); ++i) {
            ++hashtable[s[i]];
            --hashtable[t[i]];
        }
        for (int i = 0; i < s.length(); ++i)
            if (hashtable[s[i]] != 0)
                return false;
        return true;
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha << sol.isAnagram("anagram", "nagaram") << std::endl;
    return 0;
}
