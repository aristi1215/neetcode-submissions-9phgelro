class Solution {
public:

    int climbStairs(int n) {
        vector<int> cache = {1,1};
        int i = 2; 

        while(i <= n){
            cache[i] = cache[i-1] + cache[i-2];
            i++;
        }
        return cache[n];
    }
};
