class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long finalAns = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i > 2 * limit) {
                continue;
            }
            int remaining = n - i;
            int minToGiveToSecondGuy = max(0, remaining - limit); // so that the third guy dosnet have to get beyond his limits 
            int maxToGiveToSecondGuy = min(limit, remaining); // so that we get the max estimate about how much we can give to the second guy 
            if (minToGiveToSecondGuy <= maxToGiveToSecondGuy) { // so that we check if the max we can give to second guy is sitting right with the limits of the third guy
                finalAns += maxToGiveToSecondGuy - minToGiveToSecondGuy + 1; // one is for getting inclsive range since we want the count of valid distributions
            }
        }
        return finalAns;
    }
};
