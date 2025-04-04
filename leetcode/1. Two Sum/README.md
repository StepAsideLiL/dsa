# 1. [Two Sum](https://leetcode.com/problems/two-sum/description/)

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**Example 1:**

> **Input:** `nums = [2,7,11,15]`, `target = 9`
>
> **Output:** `[0,1]`
>
> **Explanation:** Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

**Example 2:**

> **Input:** `nums = [3,2,4]`, `target = 6`
>
> **Output:** `[1,2]`

**Example 3:**

> **Input:** `nums = [3,3]`, `target = 6`
>
> **Output:** `[0,1]`

**Constraints:**

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- **Only one valid answer exists.**

**Follow-up:** Can you come up with an algorithm that is less than `O(n^2)` time complexity?

---

### Solutions are in JavaScript

**Solution 1: Brute Force checking**

> Checking all the elements in the array by adding each element with each other using nested for loops.

```js
var twoSum = function (nums, target) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] + nums[j] === target) {
        return [i, j];
      }
    }
  }
  return [];
};
```

- Time Complexity: `O(n^2)`
- Space Complexity: `O(1)`

**Solution 2: Sorting with index info**

> First sort the array with index info then compare the sum of the two elements form the end with the target.

```js
var twoSum = function (nums, target) {
  const A = nums.map((a, i) => [a, i]).sort((a, b) => a[0] - b[0]);
  let i = 0,
    j = nums.length - 1;
  while (i < j) {
    let cur = A[i][0] + A[j][0];
    console.log(cur);
    if (cur === target) {
      return [Math.min(A[i][1], A[j][1]), Math.max(A[i][1], A[j][1])];
    } else if (cur < target) i++;
    else j--;
  }
  return [];
};
```

- Time Complexity: `O(n log n)`
- Space Complexity: `O(n)`

**Solution 3: Hash Table**

> Create a hash table, then iterate through the array and check if the difference between the target and the current element. Store the current element and its index if difference is not found in the hash.

```js
var twoSum = function (nums, target) {
  const hash = {};
  for (let i = 0; i < nums.length; i++) {
    const diff = target - nums[i];
    if (hash[diff] !== undefined && hash[diff] !== i) {
      return [i, hash[diff]];
    }
    hash[nums[i]] = i;
  }
  return [];
};
```

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`
