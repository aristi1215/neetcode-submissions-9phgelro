class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
          int left = 0;
        int right = nums.size()-1; 


        while(left <= right) {
            
            while(!nums.empty() && nums[right] == val) {
                nums.pop_back();
                right--;
            }

            if(left <= right && nums[left] == val){
                swap(nums[left],nums[right]);
            }

            left++;
        }

        return nums.size();
        
    }
};