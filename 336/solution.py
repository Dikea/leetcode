class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def isPalindrome(word) :
            size = len(word)
            for i in xrange(size / 2) :
                if word[i] != word[size - 1 - i] : 
                    return False
            return True
        
        wmap = {y : x for x, y in enumerate(words)}
        ret = set()
        for idx, word in enumerate(words) :
            if '' in wmap and word != '' and isPalindrome(word) :
                bidx = wmap[""]
                ret.add((idx, bidx))
                ret.add((bidx, idx))
                
            rword = word[::-1]
            if rword in wmap and rword != word :
                bidx = wmap[rword]
                ret.add((idx, bidx))
                ret.add((bidx, idx))
            
            # print word, ' : '
            for i in xrange(1, len(word)) :
                # print word[:i], word[i:]
                if isPalindrome(word[:i]) and word[i:][::-1] in wmap :
                    bidx = wmap[word[i:][::-1]]
                    ret.add((bidx, idx))
                if isPalindrome(word[i:]) and word[:i][::-1] in wmap :
                    bidx = wmap[word[:i][::-1]]
                    ret.add((idx, bidx))
        
        return list(ret)
                
