class Solution:
    def eat(self, piles:List[int], h:int, curr: int) ->bool:
        a=len(piles)
        count=0
        for i in range(a):
            count+=int(math.ceil(piles[i]/curr))            
            if count >h :
                return False
        if count <=h:
            return True
        return False
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if h==len(piles):
            return max(piles)
        a=max(piles)
        ret=a
        low=1
        high=a
        while low<=high:
            temp=piles.copy()
            mid=low+(high-low)//2
            if self.eat(temp, h, mid):
                ret=mid
                high=mid-1
            else :
                low=mid+1
        return ret