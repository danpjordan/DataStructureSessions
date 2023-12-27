// Solution to LeetCode Question 242 - Valid Anagram

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> m;

        for (int i = 0; i < s.length(); i++) {
            // if (m.find(s.at(i)) == m.end()) {
                // pair<char,int> p(s.at(i), 1);
                // p.first = s.at(i);
                // p.second = 1;
                // m.insert(p);
                // m.emplace(s.at(i), 1);
            // } else {
                // m.at(s.at(i))++;
            // }
            m[s.at(i)]++;
        }
        
        for (int i = 0; i < t.length(); i++) {
            // auto it = m.find(t.at(i));
            unordered_map<char, int>::iterator it = m.find(t.at(i));

            if (it == m.end()) return false;
            
            it->second--;
            if (it->second == 0) {
                m.erase(it);
            }
        }
        return m.empty();
    }
};