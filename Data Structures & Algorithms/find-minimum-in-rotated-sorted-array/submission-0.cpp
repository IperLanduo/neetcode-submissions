class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1; // 修正 1：陣列最後一個元素的索引

        // 修正 4：使用 left < right，當兩者相遇時就代表找到了
        while(left < right){
            int mid = left + (right - left) / 2; // 避免整數溢位的寫法

            // 情況 A：mid 站在左半的高地，最小值一定在它右邊
            if(nums[mid] > nums[right]){
                left = mid + 1; 
            }
            // 情況 B：mid 踩在右半的低谷，最小值可能是 mid 或在它左邊
            else {
                right = mid; // 修正 3：不能 -1，要把 mid 保留下來
            }
        }
        
        // 當迴圈結束時 left == right，這個位置就是最小值
        return nums[left]; // 修正 2：直接回傳該位置的數值
    }
};