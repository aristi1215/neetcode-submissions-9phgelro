class Solution {
public:

    string encode(vector<string>& strs) {
        
        string encoded_string;

        for(int i = 0; i < strs.size();i++){
            encoded_string += to_string(strs[i].length()) + "#" + strs[i];
        }
        
        return encoded_string;
    }

    vector<string> decode(string s) {

        vector<string> solution;
        queue<char> q;

        for(int i = 0; i < s.length();i++) {
            q.push(s[i]);
        }

        while(!q.empty()) {

            string stringLength = "";
            while(isdigit(q.front())){
                stringLength+=q.front();
                q.pop();
            }
            //Popping the extra # character
            q.pop();

            int numLength = stoi(stringLength);          

            string currentString = "";

            while(numLength > 0){
                currentString += q.front();
                q.pop();
                numLength--;
            }
            solution.push_back(currentString);
        }

        return solution;

    }
};
