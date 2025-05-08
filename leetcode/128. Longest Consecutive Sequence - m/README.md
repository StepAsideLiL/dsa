# 128. [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/)

Given an unsorted array of integers `nums`, return _the length of the longest consecutive elements sequence_.

You must write an algorithm that runs in `O(n)` time.

**Example 1:**

> **Input**: `nums = [100,4,200,1,3,2]`
>
> **Output**: `4`
>
> **Explanation**: `The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4`.

**Example 2:**

> **Input**: `nums = [0,3,7,2,5,8,4,6,0,1]`
>
> **Output**: `9`

**Example 3:**

> **Input**: `nums = [1,0,1,2]`
>
> **Output**: `3`

**Constraints:**

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

### Solutions are in JavaScript

**Solution 1: Sort and Set**

> Create a `sorted array` then a `set` from the `sorted array`. Then take `start` as the first element of the `sorted array`, `longest` as the length of the longest consecutive sequence, and `currentLongest` as the length of the current longest consecutive sequence while iterating through the `set`. Now iterate through the `set` and check if the current element (`num`) is equal to `start`. When it is equal, increment `currentLongest` and `start` by `1`. Otherwise, set `start` to the next element (`num + 1`) in the `set` and set `currentLongest` to `1`. Then take the maximum value between `longest` and `currentLongest` and set to `longest`.

```js
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
```

- Time Complexity: `O(n log n)`
- Space Complexity: `O(n)`
