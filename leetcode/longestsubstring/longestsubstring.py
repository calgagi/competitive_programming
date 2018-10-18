class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        substrings=[];
        longestSS = 0
        for i in range(len(s)):
            for x in range(len(substrings)):
                # check if character is in substring
                if s[i] not in substrings[x]:
                    substrings[x] += s[i]
                else:
                    substrings.pop(x)
            substrings.append(s[i]);

        for i in range(len(substrings)):
            if longestSS < len(substrings[i]):
                longestSS = len(substrings[i])
                print(substrings[i])
        return longestSS
