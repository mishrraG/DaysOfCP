class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> graph;

    pair<bool, double> search(string &a, string &b, unordered_set<string> &vis, double val) {
        if (vis.count(a) == 0) {
            vis.insert(a);
            for (auto p : graph[a]) {
                double temp = val * p.second;
                if (p.first == b) { return make_pair(true, temp); }
                auto result = search(p.first, b, vis, temp);
                if (result.first) { return result; }
            }
        }
        return make_pair(false, -1.0);
    }

public:
    vector<double> calcEquation(vector<vector<string>> &eq, vector<double>& val, vector<vector<string>> q) {
        vector<double> ans;
        for (int i = 0; i < eq.size(); ++i) {
            graph[eq[i][0]].push_back(make_pair(eq[i][1], val[i]));
            graph[eq[i][1]].push_back(make_pair(eq[i][0], 1.0 / val[i]));
        }
        for (auto p : q) {
            unordered_set<string> vis;
            if (p[0] == p[1] && graph.count(p[0])) ans.push_back(1.0);
            else ans.push_back(search(p[0], p[1], vis, 1.0).second);
        }
        return ans;
    }
};