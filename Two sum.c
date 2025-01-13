int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *arr=calloc(sizeof(int),2);
    *returnSize=2;
    for(int i=0;i<numsSize-1;i++){
        int diff=target-nums[i];
        for(int j=i+1;j<numsSize;j++){
            if(diff==nums[j]){
                arr[0]=i;
                arr[1]=j;
                return arr;
            }
        }
    }
    return arr;
}
