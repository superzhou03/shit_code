// Author: superzhou03
// Created time: 2023-12-24
class Solution {
public:
    bool isAnagram(string s, string t) {
        int flag[26] = {0};
        for (int i = 0; i < s.size(); i++) 
            flag[s[i] - 'a']++;
        
        for (int i = 0; i < t.size(); i++) 
            flag[t[i] - 'a']--;
        
        for (int i = 0; i < 26; i++) 
            if (flag[i] != 0) 
                return false;

        return true;
    }
};
