class Solution {
public:

    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.length();

        while(left <= right && left <= s.length() && right >= 0){
            while(!isalnum(s[left]) && left < s.length()){
                left++;
            }
            while(!isalnum(s[right]) && right >= 0){
                right--;
            }

            if(tolower(s[left]) != tolower(s[right]) ){
                cout << left << endl;
                cout << right << endl;
                cout << s[right] << endl;
                return false;
            }

            left++;
            right--;
        }

        return true;

    }
};
