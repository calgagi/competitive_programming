class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        output = ""
        print(ord(str[0]))
        if (ord(str[0]) < 48 or ord(str[0]) > 57) or '-' != str[0]:
            return 0
        for i in str:
            if ord(i) >= 48 and ord(i) <= 57:
                output += i

        return int(output)
