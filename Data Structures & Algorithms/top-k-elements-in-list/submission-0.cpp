class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> pq;
        vector<int> topk;

        for(int i = 0; i < nums.size();i++) {
            freq[nums[i]]++;
        }

        for(auto & [key, value] : freq) {
            pq.push( {value, key} );

        }

        for(int i = 0; i < k;i++) {
            topk.push_back(pq.top().second);
            pq.pop();
        }

        return topk;


        
    }
};
