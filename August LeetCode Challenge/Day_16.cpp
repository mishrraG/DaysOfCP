class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> candiesDistributed(num_people, 0);
        int i = 0;
        while (candies > 0)
        {
            candiesDistributed[i % num_people] += i + 1;
            candies -= i + 1;
            i++;
        }
        candiesDistributed[(i - 1) % num_people] += candies;
        return candiesDistributed;

    }
};