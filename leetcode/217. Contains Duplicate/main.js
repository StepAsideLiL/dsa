/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
  // Solution 3 (hash table): Time Complexity: O(n) | Space Complexity: O(n)
  const hashTable = {};
  for (let i = 0; i < nums.length; i++) {
    if (!hashTable[nums[i]]) {
      hashTable[nums[i]] = true;
    } else {
      return true;
    }
  }
  return false;

  // Solution 2 (sort first): Time Complexity: O(n log n) | Space Complexity: O(n)
  // nums.sort((a, b) => a - b);
  // for (let i = 0; i < nums.length - 1; i++) {
  //   if (nums[i] === nums[i + 1]) {
  //     return true;
  //   }
  // }
  // return false;

  // Solution 1 (brute checking): Time Complexity: O(n^2) | Space Complexity: O(1)
  // for (let i = 0; i < nums.length - 1; i++) {
  //   for (let j = i + 1; j < nums.length; j++) {
  //     if (nums[i] === nums[j]) {
  //       return true;
  //     }
  //   }
  // }
  // return false;
};

console.log(containsDuplicate([1, 2, 3, 1]));
console.log(containsDuplicate([1, 2, 3, 3]));
console.log(containsDuplicate([1, 2, 3, 4]));
console.log(containsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]));
