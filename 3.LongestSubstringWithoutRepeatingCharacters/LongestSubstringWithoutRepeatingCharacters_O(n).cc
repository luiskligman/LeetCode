class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Create a map to store previously seen values and record their index
            // unordered_map<key_type, value_type>
        unordered_map<char, int> lastSeen;
        int maxLen = 0, start = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            // If the character was seen before and is within the current window
            if (lastSeen.count(c) && lastSeen[c] >= start)
                // Move the start to the right of the last occurrence of the repeating character
                start = lastSeen[c] + 1;
            // Update the last seen index for the character
            lastSeen[c] = i;
            
            // Update the max length of sustring without repeating characters
                // i - start + 1 is the length of the current valid with (inclusive)
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
