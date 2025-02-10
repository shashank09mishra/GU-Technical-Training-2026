import java.util.HashMap;
import java.util.Map;

public class LongestSubstringWithoutRepeatingCharacters {

    public static int longestSubstringWithoutRepeatingCharacters(String s) {
        // Edge case: empty string
        if (s == null || s.isEmpty()) {
            return 0;
        }

        // Map to store the last index of each character
        Map<Character, Integer> charIndexMap = new HashMap<>();
        int maxLength = 0;
        int start = 0; // Start of the current substring

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s.charAt(end);

            // If the character is already in the map and its index is >= start,
            // move the start to the right of the previous occurrence
            if (charIndexMap.containsKey(currentChar) && charIndexMap.get(currentChar) >= start) {
                start = charIndexMap.get(currentChar) + 1;
            }

            // Update the last index of the character
            charIndexMap.put(currentChar, end);

            // Update the maximum length if the current substring is longer
            maxLength = Math.max(maxLength, end - start + 1);
        }

        return maxLength;
    }

    public static void main(String[] args) {
        // Test cases
        String[] testCases = {
            "abcabcbb", // Expected: 3 ("abc")
            "bbbbb",    // Expected: 1 ("b")
            "pwwkew",   // Expected: 3 ("wke")
            "",         // Expected: 0 (empty string)
            " ",        // Expected: 1 (" ")
            "abba"      // Expected: 2 ("ab" or "ba")
        };

        for (String s : testCases) {
            int result = longestSubstringWithoutRepeatingCharacters(s);
            System.out.println("Input: '" + s + "' -> Longest substring length: " + result);
        }
    }
}