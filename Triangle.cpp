// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// Did you run the code? Yes

// Approach:
// 1. We can create a dp array of size n*n, where dp[i][j] will store the minimum path sum from the top to the bottom of the triangle starting at index (i,j).
// 2. We can iterate through the triangle from the bottom to the top, and for each index (i,j), we can set dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j + 1]).
// 3. Finally, we can return dp[0][0], which will be the minimum path sum from the top to the bottom of the triangle.

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size();
            vector<vector<int>> dp(m, vector<int>(m, 0));
            //bottom row
            for(int j = 0; j < triangle[m - 1].size(); j++){
                dp[m - 1][j] = triangle[m - 1][j];
            }
            for(int i = m - 2; i >= 0; i--){
                for(int j = 0; j <= i; j++){
                    dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j + 1]);
                }
            }
            return dp[0][0];
        }
    };