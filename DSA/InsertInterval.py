class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        final=[]
        i=0
        while i<len(intervals) and intervals[i][1]<newInterval[0] :
            final.append(intervals[i])
            i+=1
        while i<len(intervals) and intervals[i][0]<=newInterval[1]:
            newInterval[0]=(min(intervals[i][0],newInterval[0]))
            newInterval[1]=(max(intervals[i][1],newInterval[1]))
            i+=1
        final.append(newInterval)
        final+=intervals[i:]
        return final