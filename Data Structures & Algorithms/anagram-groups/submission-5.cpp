class Solution {
public:

    bool isAnagram (string &one, string &two) {
        unordered_map<char,int> count1;
        unordered_map<char,int> count2;
        if(one.length() != two.length()){
            return false;
        }

        for(int i = 0; i < one.length();i++) {
            count1[one[i]]++;
            count2[two[i]]++;
        }

        for(int i = 0 ; i < one.length();i++) {
            if(count1[one[i]] != count2[one[i]]){
                return false;
            }
        }
        return true;


    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> anagrams;
        unordered_map<string,bool> used;
        


        for(int i = 0; i < strs.size(); i++) {
            vector<string> currentAnagrams;
            if(used[strs[i]]){
                continue;
            }
            currentAnagrams.push_back(strs[i]);
            used[strs[i]] = true;
            for(int j = i+1; j < strs.size();j++) {
                if(isAnagram(strs[i],strs[j]) && i != j) {
                    currentAnagrams.push_back(strs[j]);
                    used[strs[j]] = true;
                }
            }
            anagrams.push_back(currentAnagrams);
        }

        return anagrams;
        
    }
};
