class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = 0;
        for (int x : cardPoints)
            total += x;

        if (k == n)
            return total;

        int windowSize = n - k;

        int windowSum = 0;
        for(int i=0;i<windowSize;i++){
            windowSum+=cardPoints[i];
        }
         int minWindow = windowSum;
         int left=0;
        for(int i=windowSize;i<n;i++){
            windowSum+=cardPoints[i];
            windowSum-=cardPoints[left];
            left++;
            minWindow=min(minWindow,windowSum);
        }
        return total-minWindow;
    }
};