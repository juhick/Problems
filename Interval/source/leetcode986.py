class Solution(object):
    def intervalIntersection(self, firstList, secondList):
        """
        :type firstList: List[List[int]]
        :type secondList: List[List[int]]
        :rtype: List[List[int]]
        """
        i, j = 0, 0
        res = []
        while i < len(firstList) and j < len(secondList):
            a0, a1 = firstList[i][0], firstList[i][1]
            b0, b1 = secondList[j][0], secondList[j][1]
            if b1 >= a0 and a1 >= b0:
                res.append([max(a0, b0), min(a1, b1)])
            if b1 < a1:
                j += 1
            else: i += 1
        return res
