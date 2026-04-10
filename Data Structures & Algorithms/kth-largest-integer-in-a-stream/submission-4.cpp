class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        
        for(int i = 0; i < nums.size();i++){
            pq.push(nums[i]);
        }

        kLarge = k;
    }
    
    int add(int val) {
        pq.push(val);
        vector<int> arr;
        for(int i = 0; i < kLarge; i++){
            arr.push_back(pq.top());
            pq.pop();
        }
        int third = arr[arr.size()-1];
        
        for(int i = 0; i < arr.size();i++){
            pq.push(arr[i]);
        }
        return third;
    }
private:
    priority_queue<int> pq;
    int kLarge = 0;
};
