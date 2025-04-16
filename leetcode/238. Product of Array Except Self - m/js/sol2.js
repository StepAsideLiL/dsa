/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  // Solution 2 (product division): Time Complexity: O(n), Space Complexity: O(1)
  let prod = 1;
  let zeroCount = 0;

  for (let num of nums) {
    if (num !== 0) {
      prod *= num;
    } else {
      zeroCount++;
    }
  }

  if (zeroCount > 1) {
    return Array(nums.length).fill(0);
  }

  const answer = new Array(nums.length);

  for (let i = 0; i < nums.length; i++) {
    if (zeroCount > 0) {
      answer[i] = nums[i] === 0 ? prod : 0;
    } else {
      answer[i] = prod / nums[i];
    }
  }

  return answer;
};

console.log(productExceptSelf([1, 2, 3, 4]));
console.log(productExceptSelf([-1, 1, 0, -3, 3]));
