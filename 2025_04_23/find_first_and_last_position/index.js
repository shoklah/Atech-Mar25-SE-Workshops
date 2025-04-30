function searchRange(nums, target){
    let resultArray = [];
    let foundTarget = false;

    for (let index = 0; index < nums.length; index++){
        if (nums[index] == target){
            resultArray[0] = index
            foundTarget = true;
            while (nums[index] == target) {
                resultArray[1] = index
                index++;
            }
        }
    }
    if (foundTarget == false){
        resultArray = [-1, -1];
    }
    console.log(resultArray);
}

searchRange([5,7,7,8,8,10], 8)
// [3, 4]
searchRange([5,7,7,8,8,10], 6)
// [-1, -1]
searchRange([], 0)
// [-1, -1]
searchRange([5,7,7,8,8,8,10], 8)
// [3, 5]
searchRange([5,7,7,8,8,8,10], 5)
// [0, 0]
searchRange([5,7,7,8,8,8,10], 10)
// [6, 6]