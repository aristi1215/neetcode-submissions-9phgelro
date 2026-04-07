class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]] = i;
        }

        for(int i = 0; i < nums.size();i++) {
            int complement = target - nums[i];
            if(freq[complement] && freq[complement] != i) {
                return {i,freq[complement]};
            }

        }

        return {};
        
    }
};
