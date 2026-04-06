class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> letters;

        if(s.length() != t.length()){
            return false;
        }

        for(int i = 0; i < s.length();i++) {
            letters[s[i]]++;
            letters[t[i]]--;
        }

        for(int i = 0; i < s.length();i++){
            if(letters[s[i]] != 0) {
                return false;
            }
        }
        return true;

    }
};
