#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() - 1, nums, target);
    }

    bool binary_search(int l, int r, const vector<int> &nums, int target) {
        if (l > r) return false;
        int mid = ((r - l) >> 1) + l;
        cout << "nums[" << mid << "]" << ", ";
        if (nums[mid] == target) {
            return true;
        }
        return binary_search(l, mid - 1, nums,target) || binary_search(mid + 1, r, nums,target);
    }
};


int main() {
  Solution s;
  vector<int> v{9,8,0,1,2,3,4,5,6,7};
  s.search(v,0);
  return 0;
}
