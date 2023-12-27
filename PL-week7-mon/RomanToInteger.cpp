// Solution to LeetCode problem #21 - Merge Two Sorted Lists

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        int retn = 0;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        for (int i = 0; i < s.length() - 1; i++) {
            char curChar = s.at(i);
            char nextChar = s.at(i + 1);
            if (m.at(curChar) < m.at(nextChar)) {
                retn -= m.at(curChar);
            } else {
                retn += m.at(curChar);
            }
        }
        retn += m.at(s.at(s.length() - 1));


        return retn;
    }

};