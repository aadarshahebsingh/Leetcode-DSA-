class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        // Make the largest number (replace some digit with 9)
        string s_max = s;
        char to_replace_max = '\0';
        for (char c : s) {
            if (c != '9') {
                to_replace_max = c;
                break;
            }
        }
        if (to_replace_max != '\0') {
            for (char &c : s_max) {
                if (c == to_replace_max) c = '9';
            }
        }
        int max_num = stoi(s_max);

        // Make the smallest number (replace some digit with 0 or 1)
        string s_min = s;
        char to_replace_min = '\0';
        char replace_with = '1';
        if (s[0] != '1') {
            to_replace_min = s[0];
        } else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    to_replace_min = s[i];
                    replace_with = '0';
                    break;
                }
            }
        }
        if (to_replace_min != '\0') {
            for (char &c : s_min) {
                if (c == to_replace_min) c = replace_with;
            }
        }
        int min_num = stoi(s_min);

        return max_num - min_num;
    }
};