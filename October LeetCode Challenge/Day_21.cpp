class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;

        stack<int> left, right;

        for (auto i : asteroids) {
            if (i <= 0 ) {
                if (!right.empty()) {

                    while (!right.empty() && (-i) > right.top())right.pop();

                    if (!right.empty() && right.top() == (-i)) {
                        right.pop();
                        continue;
                    }

                }

                if (right.empty()) {
                    left.push(-i);
                    v.push_back(i);
                }
            }

            else right.push(i);


        }

        vector<int>temp;
        while (!right.empty()) {
            temp.push_back(right.top());
            right.pop();
        }
        v.insert(v.end(), temp.rbegin(), temp.rend());
        return v;
    }
};