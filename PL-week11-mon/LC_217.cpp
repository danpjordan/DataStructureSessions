// Solution to LeetCode Question 217 - Contains Duplicate

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {

    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      m[nums.at(i)]++;
    }

    for (auto kv : m) {
      if (kv.second >= 2) {
        return true;
      }
    }

    return false;
  }
};