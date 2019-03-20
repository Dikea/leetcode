class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """     
        symbol_to_val = {
            "M": 1000, "CM": 900, "D": 500, "CD": 400,
            "C": 100, "XC": 90, "L": 50, "XL": 40,
            "X": 10, "IX": 9, "V": 5, "IV": 4, "I": 1
        }
        
        index, num = 0, 0
        
        while index < len(s):
            if index + 1 < len(s) and s[index: index + 2] in symbol_to_val:
                num += symbol_to_val[s[index: index + 2]]
                index += 2
            else:
                num += symbol_to_val[s[index]]
                index += 1
                
        return num
