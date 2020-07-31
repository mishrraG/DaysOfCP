class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode *> children;
    TrieNode() {
        isEnd = false;
    }
};
class Solution {
public:
    TrieNode *root;


    void buildTrie(string s) {
        TrieNode *curr = root;
        for (char &c : s) {
            if (curr->children.find(c) == curr->children.end())
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }


    vector<string> DFS(string s, int index, unordered_map<int, vector<string>> &um) {
        vector<string> ans;
        if (index == s.size()) {
            ans.push_back("");
            return ans;
        }
        if (um.find(index) != um.end())
            return um[index];

        TrieNode *curr = root;
        for (int i = index; i < s.size(); i++) {
            if (curr->children.find(s[i]) == curr->children.end())
                break;
            curr = curr->children[s[i]];
            if (curr->isEnd) {
                int length = i - index + 1;
                string temp = s.substr(index, length);
                if (i < s.size() - 1) {
                    temp += " ";
                }
                vector<string> next = DFS(s, i + 1, um);
                for (string &str : next) {
                    string t = temp + str;
                    ans.push_back(t);
                }
            }
        }

        return um[index] = ans;
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        for (string &str : wordDict) {
            buildTrie(str);
        }
        unordered_map<int, vector<string>> um;
        return DFS(s, 0, um);
    }
};