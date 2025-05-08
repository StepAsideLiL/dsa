/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
  const sorted = nums.sort((a, b) => a - b);
  const newNums = new Set(sorted);

  let start = sorted[0];
  let longest = 0;
  let currentLongest = 0;

  for (const num of newNums) {
    if (num === start) {
      currentLongest++;
      start++;
    } else {
      start = num + 1;
      currentLongest = 1;
    }
    longest = Math.max(longest, currentLongest);
  }

  return longest;
};

console.log(longestConsecutive([100, 4, 200, 1, 3, 2])); // 4
console.log("===");
console.log(longestConsecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1])); // 9
console.log("===");
console.log(longestConsecutive([1, 0, 1, 2])); // 3
console.log("===");
console.log(longestConsecutive([9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6])); // 3
