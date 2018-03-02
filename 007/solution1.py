class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        str_x = str(x)
        flag = None
        if str_x[0] == '-':
            flag = True
            str_x = str_x[1:]
        str_x = str_x[::-1]
        if flag:
            str_x = '-' + str_x
        ret_num = int(str_x)
        if ret_num >= (1 << 31) or ret_num < -(1 << 31): 
            ret_num = 0
        return ret_num
        
