class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        output = ""
        for i in range(len(str)):
            if ord(str[i]) >= 48 and ord(str[i]) <= 57:
                output += str[i]

        return int(output)
