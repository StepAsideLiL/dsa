/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  // Solution 3 (diff with hash): Time Complexity: O(n) | Space Complexity: O(1)
  const hash = {};
  for (let i = 0; i < nums.length; i++) {
    const diff = target - nums[i];
    if (hash[diff] !== undefined && hash[diff] !== i) {
      return [i, hash[diff]];
    }
    hash[nums[i]] = i;
  }
  return [];

  // Solution 2 (sorting with index info): Time Complexity: O(n log n) | Space Complexity: O(n)
  // const A = nums.map((a, i) => [a, i]).sort((a, b) => a[0] - b[0]);
  // let i = 0,
  //   j = nums.length - 1;
  // while (i < j) {
  //   let cur = A[i][0] + A[j][0];
  //   console.log(cur);
  //   if (cur === target) {
  //     return [Math.min(A[i][1], A[j][1]), Math.max(A[i][1], A[j][1])];
  //   } else if (cur < target) i++;
  //   else j--;
  // }
  // return [];

  // Solution 1 (brute force checking): Time Complexity: O(n^2) | Space Complexity: O(1)
  // for (let i = 0; i < nums.length; i++) {
  //   for (let j = i + 1; j < nums.length; j++) {
  //     if (nums[i] + nums[j] === target) {
  //       return [i, j];
  //     }
  //   }
  // }
  // return [];
};

console.log(twoSum([2, 7, 11, 15], 9));
console.log(twoSum([3, 2, 4], 6));
console.log(twoSum([3, 3], 6));
