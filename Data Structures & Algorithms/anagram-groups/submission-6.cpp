class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> solutions;
        


        for(int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(),copy.end());
            solutions[copy].push_back(strs[i]);
        }

        for(auto & [key, value] : solutions) {
            anagrams.push_back(value);
        }

        return anagrams;
        
    }
};
