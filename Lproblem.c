int majorityElement(int* nums, int numsSize) {
    int sol = nums[0];
     int count = 0;
    for(int i = 0; i<numsSize; i++){
        if(count == 0)
        sol = nums[i];
    
    if(nums[i] == sol){
        count  = count + 1;
    }
    else{
        count = count - 1;
    }
}
return sol;
}
