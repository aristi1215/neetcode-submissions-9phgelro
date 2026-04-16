class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> prefixProduct(nums.size(),1);
        vector<int> postfixProduct(nums.size(),1);
        vector<int> solution(nums.size());
        int currentProduct = 1;

        for(int i = 1; i < nums.size(); i++){
            currentProduct *= nums[i-1];
            prefixProduct[i] = currentProduct;
        }

        for(int i = 0; i < nums.size()-1;i++) {
            int currentProduct = 1;
            for(int j = i+1; j < nums.size();j++){
                currentProduct *= nums[j];
            }
            postfixProduct[i] = currentProduct;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            solution[i] = postfixProduct[i] * prefixProduct[i];
        }

    return solution;

    }
};
