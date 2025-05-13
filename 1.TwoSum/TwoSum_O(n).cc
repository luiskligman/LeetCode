class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store previously seen numbers and their indicies
        unordered_map<int, int> numMap;

        // Iterate through the input array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement (target - current number)
            int complement = target - nums[i];

            // If the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // If key exists, numMap.find(complement) will point to its index value
                // else it will point to numMap.end()

                // Return the indicies of the two numbers that add up to the target
                return {numMap[complement], i};
            }

            // Add the current number and its index to the map
            numMap[nums[i]] = i;
        }

        // No solution found, return an empty vector
        return {};
    }
};
