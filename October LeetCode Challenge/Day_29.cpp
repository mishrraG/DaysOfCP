class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int longest = 0, beginning = 0, i = 0;
        while (seats[i] == 0) {
            beginning++;
            i++;
        }
        int count = beginning;
        for (; i < seats.size(); i++) {
            if (seats[i] == 0)
                count++;
            else {
                longest = std::max({count, longest});
                count = 0;
            }
        }
        longest = longest % 2 == 0 ? longest / 2 : longest / 2 + 1;
        return std::max({longest, count, beginning});
    }
};