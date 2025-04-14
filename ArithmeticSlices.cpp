// Time Complexity: O(n)
// Space Complexity: O(n)
// Did you run the code? Yes

//Approach: 
// 1. We can create a dp array of size n, where dp[i] will store the number of arithmetic slices ending at index i.
// 2. We can iterate through the array from index 2 to n-1, and for each index i, we can check if the difference between nums[i] and nums[i-1] is equal to the difference between nums[i-1] and nums[i-2].
// 3. If it is, we can set dp[i] = dp[i-1] + 1, which means that we can extend the previous arithmetic slice by one element.
// 4. If it is not, we can set dp[i] = 0, which means that we cannot extend the previous arithmetic slice.
// 5. Finally, we can sum up all the values in the dp array to get the total number of arithmetic slices.

class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& nums) {
            int n = nums.size();
            if(n < 3){return 0;}
            vector<int> dp(n, 0);
            for(int i = 2; i < n; i++){
                if(nums[i - 2] - nums[i - 1] == nums[i - 1] - nums[i]){
                    dp[i] = dp[i - 1] + 1;
                }else{
                    dp[i] = 0;
                }
            }
            int res = 0;
            for(int i : dp){
                res += i;
            }
            return res;
        }
    };