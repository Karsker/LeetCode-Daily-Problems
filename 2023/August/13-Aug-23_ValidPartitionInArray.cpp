/*Problem: Find valid partitions in array
Divide the array in such a way that both sides of the division are valid paritions
A valid parition satisfies any one of the following criteria:
1. The size is 2 and both the elements are equal
2. The size is 3 and all the three elements are equal
3. The size is 3 and the elements are in consecutive (+1) order

Approach: Dynamic programming with sliding window
The structure used for memoization is an array of size 3; since at a time we need to know the validity status till last two elements only
The first element of the array tells whether the partition is valid UPTO that index (not inclusive)
Similarly for the second and third elements.
The minimum size of the input array is 2. So base case of checking for 1 element is not required.

Initializing for 0-2 index.
For initializing, dp[0] is set to true, since before index 0 there are no elements.
At dp[1], there is only one element before index 1, so it cannot be partitioned. Hence, dp[1] is false.
The value of dp[2] depends on the equality of first and second elements. If equal, then by the rules of the problem, till index 2 we have a valid partition and hence we set dp[2] to true, otherwise false.
Then we start scanning from index 2
We need to check three cases:
1. If till dp[1] the partitions are valid (true), then we compare the current value to previous value; if false, we check the next possibility (2)
2. If till dp[0] the partitions are valid, we can compare the the current and previous two values for the following cases:
2A. The numbers are equal
2B. The numbers are consecutive
For each of the above cases, if the result is true, then we set the value of dp[2] to true [later]
Before setting the value of dp[2], we must shift the values of old values dp[1] and dp[2] to avoid overwriting values.
Once we have iterated through the entire array, if dp[2] is true, it means that valid partitions can be created for the complete array. Hence the result is dp[2].
*/

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp = {true, false, (nums[0] == nums[1])};
        bool update;
        for (int i = 2; i < nums.size(); i++) {
            if (dp[1] && nums[i] == nums[i-1]) {
                update = true;
            } else if (dp[0] && ((nums[i] == nums[i-1] && nums[i-1] == nums[i-2])||(nums[i] == nums[i-1]+1 && nums[i-1] == nums[i-2]+1))) {
                update = true;
            } else {
                update = false;
            }
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = update;  
        }
        return dp[2];

    }
};