/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  // Solution 3 (): Time Complexity: O(n), Space Complexity: O(1)
  const n = nums.length;
  const answer = new Array(n);
  const pref = new Array(n);
  const suff = new Array(n);

  pref[0] = 1;
  suff[n - 1] = 1;

  for (let i = 1; i < n; i++) {
    pref[i] = nums[i - 1] * pref[i - 1];
  }

  for (let i = n - 2; i >= 0; i--) {
    suff[i] = nums[i + 1] * suff[i + 1];
  }

  for (let i = 0; i < n; i++) {
    answer[i] = pref[i] * suff[i];
  }

  return answer;
};

console.log(productExceptSelf([1, 2, 3, 4]));
console.log("===");
console.log(productExceptSelf([-1, 1, 0, -3, 3]));
