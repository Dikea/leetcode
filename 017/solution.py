class Solution(object):
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        self.num2letter = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        if digits == "":
            return []
        rets = self.get_combination("", digits, 0)
        return rets
        
    def get_combination(self, letters, digits, index):

        if index == len(digits):
            return [letters]
        
        rets = []
        digit = digits[index]
        for letter in self.num2letter[digit]:
            new_letters = letters + letter
            rets_ = self.get_combination(new_letters, digits, index + 1)
            rets.extend(rets_)
        return rets
