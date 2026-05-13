class Solution {
public:

    int dfs(vector<int> & nums,int i){
        if(i >= nums.size()){
            return 0;
        }

        return max(nums[i] + dfs(nums,i+2),dfs(nums,i+1));
    }
    
    int rob (vector<int>& nums){


        int i = 2;
        vector<int> cache(nums.size());
        cache[0] = nums[0];
        cache[1] = max(nums[0],nums[1]);
        while(i < nums.size()) {

            int next = max(nums[i]+cache[i-2], cache[i-1]);
            cache[i] = next;

            i++;
        }


        return cache[nums.size()-1];
    }
};
