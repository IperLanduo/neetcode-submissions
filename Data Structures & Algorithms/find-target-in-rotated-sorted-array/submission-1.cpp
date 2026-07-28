class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if (nums[mid] == target) {
                return mid; 
            }

            
            if (nums[left] <= nums[mid]) {
               
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1; 
                } else {
                    left = mid + 1; 
                }
            } 
           
            else {
                
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;  // target 在右半邊，往右找
                } else {
                    right = mid - 1; // 否則，往左找
                }
            }
        }
        return -1; 
    }
};