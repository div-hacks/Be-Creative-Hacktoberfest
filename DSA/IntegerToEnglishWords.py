class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num==0:
            return "Zero"
        ans=""
        d=["Trillion", "Billion", "Million", "Thousand", ""]
        x={1:"One", 2:"Two", 3:"Three", 4:"Four", 5:"Five", 6:"Six", 7:"Seven", 8:"Eight", 9:"Nine", 10:"Ten", 11:"Eleven", 12:"Twelve", 13:"Thirteen", 14:"Fourteen", 15:"Fifteen", 16:"Sixteen", 17:"Seventeen", 18:"Eighteen", 19:"Nineteen", 20:"Twenty", 30:"Thirty", 40:"Forty", 50:"Fifty", 60:"Sixty", 70:"Seventy", 80:"Eighty", 90:"Ninety", 100:"Hundred", 0:""}
        while num>0:
            a=""
            n=num%1000
            num=num//1000
            o=n%10
            n=n//10
            t=n%10
            n=n//10
            h=n%10
            if h!=0:
                a=x[h]+" Hundred"
            if t==1:
                a+=" "+x[10+o]
            elif t==0:
                a+=" "+x[o]
            else:
                a+=" "+x[10*t]+" "+x[o]
            a=a.strip()
            if a=="":
                d.pop()
                continue
            ans=a+" "+d.pop()+" "+ans
            ans=ans.strip()
        return ans.strip()