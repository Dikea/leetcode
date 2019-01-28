class Solution(object):
    
    def __init__(self):
        self.terms = ["1"]
        cnt = 1
        while cnt <= 30:
            last_term = self.terms[-1]
            new_term = ""
            c_cnt = 1
            term_len = len(last_term)
            for idx in range(1, term_len):
                if last_term[idx] != last_term[idx - 1]:
                    new_term += str(c_cnt)
                    new_term += last_term[idx - 1]
                    c_cnt = 1
                else:
                    c_cnt += 1
            new_term += str(c_cnt)
            new_term += str(last_term[-1])
            self.terms.append(new_term)
            cnt += 1
    
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        return self.terms[n-1]
