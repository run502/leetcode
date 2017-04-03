/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
   static int num[2];
   for (int i = 0; i < numsSize-1; i++) {
   		for (int j = i+1; j < numsSize; j++) {
			if (nums[j] == target - nums[i]) {
				num[0] = i;
				num[1] = j;	
			}	   
		}
   }
   return num;
}
