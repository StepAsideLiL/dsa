const { MinPriorityQueue } = require("@datastructures-js/priority-queue");

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
  // Solution 2 (min heap): Time Complexity: O(n log k), Space Complexity: O(n)
  const count = {};
  for (const num of nums) {
    count[num] = (count[num] || 0) + 1;
  }

  const heap = new MinPriorityQueue((x) => x[1]);
  for (const [num, f] of Object.entries(count)) {
    heap.enqueue([num, f]);
    if (heap.size() > k) {
      heap.dequeue();
    }
  }

  return heap.toArray().map((res) => parseInt(res[0]));

  // Solution 1 (hash sorting): Time Complexity: O(n log n), Space Complexity: O(n)
  // const count = {};
  // for (let i = 0; i < nums.length; i++) {
  //   count[nums[i]] = (count[nums[i]] || 0) + 1;
  // }
  // return Object.entries(count)
  //   .map(([num, f]) => [f, parseInt(num)])
  //   .sort((a, b) => b[0] - a[0])
  //   .slice(0, k)
  //   .map((p) => p[1]);
};

console.log(topKFrequent([1, 1, 1, 2, 2, 3], 2));
console.log("===");
console.log(topKFrequent([1, 1, 1, 6, 6, 6, 6, 2, 2, 3], 2));
console.log("===");
console.log(topKFrequent([1], 1));
