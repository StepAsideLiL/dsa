/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
  // Solution 3 (bucket sort): Time Complexity: O(n), Space Complexity: O(n)
  const count = {};
  const freq = Array.from({ length: nums.length + 1 }, () => []);

  for (const n of nums) {
    count[n] = (count[n] || 0) + 1;
  }
  for (const n in count) {
    freq[count[n]].push(parseInt(n));
  }

  const res = [];
  for (let i = freq.length - 1; i > 0; i--) {
    for (const n of freq[i]) {
      res.push(n);
      if (res.length === k) {
        return res;
      }
    }
  }
};

console.log(topKFrequent([1, 1, 1, 2, 2, 3], 2));
console.log("===");
console.log(topKFrequent([1, 1, 1, 6, 6, 6, 6, 2, 2, 3], 2));
console.log("===");
console.log(topKFrequent([1], 1));
