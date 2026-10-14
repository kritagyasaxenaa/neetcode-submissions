class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        if(len(nums)<2):
            return False
        nums.sort()
        i=1
        while i<len(nums):
            if(nums[i]==nums[i-1]):
                return True
            i+=1

        return False