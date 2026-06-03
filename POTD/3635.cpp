class Solution {
public:
    int findFinishTime(vector<int>& startTime1, vector<int>& duration1, vector<int>& startTime2, vector<int>& duration2) {
            int n = startTime1.size();
            int m = startTime2.size();

            int finish1 = INT_MAX;

            for (int i = 0; i < n; i++) {
                finish1 = min(finish1, startTime1[i] + duration1[i]);
            }

            int finish2 = INT_MAX;
            for(int i = 0; i < m; i++) {
                int start2 = max(finish1, startTime2[i]);
                finish2 = min(finish2, start2 + duration2[i]);
            }
            return finish2;
        }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int landToWater = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);

        int waterToLand = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(landToWater, waterToLand);
    }
};