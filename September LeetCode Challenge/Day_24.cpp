class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int>mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        char x;
        for (int i = 0; i < t.length(); i++)
        {
            if (!mp[t[i]]) {
                x = t[i];
                break;
            }
            else
                mp[t[i]]--;
        }
        return x;
    }
};