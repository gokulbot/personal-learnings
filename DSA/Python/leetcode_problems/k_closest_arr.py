from typing import List
class Solution:
    def binary_search_(self, arr, low, high, target):

        while(low<=high):

            mid = int(low + (high-low)/2)

            if arr[mid] == target:
                return mid
            
            elif arr[mid] > target:
                high = mid - 1

            else:

                low = mid + 1

        return -1

    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        return 

if __name__ == "__main__":

    arr = [1,4,7,11,15]
    k = 3
    x = 7

    sol = Solution()

    sol.findClosestElements(arr,k,x)