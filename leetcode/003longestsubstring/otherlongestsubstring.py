class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = 0 # Lower bound
        u = 0 # Upper bound
        h = {} # Hash map
        longest = 0 # Keep track of highest length

        # While there is still string left
        while u < len(s):
            # If character hasn't been seen yet, set map to index+1 where it is
            if s[u] not in h:
                h[s[u]] = u
            # If character has been seen, set lower bound to it's last known appearance+1 (what's stored in dict)
            else:
                # Keep track of longest substring
                h[s[u]] = u
                if longest < u-l:
                    longest = u-l
                    print(str(longest) + " " + str(u) + " " + str(l))
                if l < h[s[u]]:
                    l = h[s[u]]
            u += 1

        if longest < u-l:
            longest = u-l
        return longest
            
