class CombinationIterator {
    vector<char> vec;
    int n;
    vector<string> ans;
    int top;
public:
    CombinationIterator(string characters, int combinationLength) {
        for (auto ele : characters) vec.emplace_back(ele);
        n = combinationLength;
        top = -1;
        getCombinations("", n);
    }

    string next() {
        return ans[++top];
    }

    bool hasNext() {
        return top != ans.size() - 1;
    }

    void getCombinations(string str, int &n) {
        if (str.size() > 1 && str[str.size() - 2] >= str[str.size() - 1]) return;
        if (str.size() == n) ans.push_back(str);
        else if (str.size() < n) {
            for (int i{0}; i < vec.size(); i++) {
                getCombinations(str + vec[i], n);
            }
        }
    }
};
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */