class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }

        set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(),s.end());

        int largest = 1;
        int currSum = 1;


        for(int i = 0; i < nums.size()-1; i++) {
            int curr = nums[i];
            if(curr+1 == nums[i+1]){
                currSum++;
            }else {
                currSum = 1;
            }
            if(currSum > largest){
                largest = currSum;
            }
        }
                
        
        

        return largest;
        
    }
};
