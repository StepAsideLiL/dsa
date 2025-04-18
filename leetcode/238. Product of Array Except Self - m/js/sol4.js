/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  // Solution 4 (postfix): Time Complexity: O(n), Space Complexity: O(1)
  const n = nums.length;
  const answer = new Array(n).fill(1);

  for (let i = 1; i < n; i++) {
    answer[i] = nums[i - 1] * answer[i - 1];
  }

  let postfix = 1;
  for (let i = n - 1; i >= 0; i--) {
    answer[i] *= postfix;
    postfix *= nums[i];
  }

  return answer;
};

console.log(productExceptSelf([1, 2, 3, 4]));
console.log("===");
console.log(productExceptSelf([-1, 1, 0, -3, 3]));
