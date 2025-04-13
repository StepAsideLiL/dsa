# 347. [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/)

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in any order.

**Example 1:**

> **Input:** `nums = [1,1,1,2,2,3]`, `k = 2`
>
> **Output:** `[1,2]`

**Example 2:**

> **Input:** `nums = [1]`, `k = 1`
>
> **Output:** `[1]`

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `k` is in the range `[1, the number of unique elements in the array]`.
- It is **guaranteed** that the answer is **unique**.

**Follow up:** Your algorithm's time complexity must be better than `O(n log n)`, where n is the array's size.

---

### Solutions are in JavaScript

**Solution 1: Hash sort**

> Create a hash table to store the frequency of each element. Then sort the hash table by the frequency and return the top `k` elements.

```js
var topKFrequent = function (nums, k) {
  const count = {};
  for (let i = 0; i < nums.length; i++) {
    count[nums[i]] = (count[nums[i]] || 0) + 1;
  }

  return Object.entries(count)
    .map(([num, f]) => [f, parseInt(num)])
    .sort((a, b) => b[0] - a[0])
    .slice(0, k)
    .map((p) => p[1]);
};
```

- Time Complexity: `O(n log n)`
- Space Complexity: `O(n)`

**Solution 2: Hash Min Heap**

> Create a hash table to store the frequency of each element. Then create a min heap and push the elements into the heap.

```js
const { MinPriorityQueue } = require("@datastructures-js/priority-queue");

var topKFrequent = function (nums, k) {
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
```

- Time Complexity: `O(n log k)`
- Space Complexity: `O(n + k)`

**Solution 3: Bucket sort**

> Create a hash table to store the frequency of each element. Then sort using bucket sort.

```js
var topKFrequent = function (nums, k) {
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
```

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`
