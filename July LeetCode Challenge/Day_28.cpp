class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>m;
        for (int i = 0 ; i <  tasks.size(); i++) {
            m[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto i = m.begin(); i != m.end(); i++) {
            pq.push(i->second);
        }
        int ans = 0 ;
        while (!pq.empty()) {
            vector<int> temp ;
            for (int i = 0 ; i <= n ; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            for (int i = 0 ; i < temp.size(); i++) {
                temp[i]--;
                if (temp[i] > 0) {
                    pq.push(temp[i]);
                }
            }

            ans += pq.empty() ? temp.size() : n + 1;
        }
        return ans;

    }
};