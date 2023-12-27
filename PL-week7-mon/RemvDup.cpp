// Solution to LeetCode problem #26 - Remove Duplicates from Sorted Array

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i - 1) != nums.at(i)) {
                nums.at(k) = nums.at(i);
                k++;
            }
        }
        return k;

        // 1 2 2 2 3 3 4

        // 1 2(k)(i) 2 2 3 3 4
        
        // 1 2 3 4
    }
};