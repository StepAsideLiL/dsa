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
};

console.log(topKFrequent([1, 1, 1, 2, 2, 3], 2));
console.log("===");
console.log(topKFrequent([1, 1, 1, 6, 6, 6, 6, 2, 2, 3], 2));
console.log("===");
console.log(topKFrequent([1], 1));
