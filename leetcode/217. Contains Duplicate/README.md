# 217. [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/)

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Example 1:**

> Input: nums = [1,2,3,1]
>
> Output: true
>
> Explanation:
>
> The element 1 occurs at the indices 0 and 3.

**Example 2:**

> Input: nums = [1,2,3,4]
>
> Output: false
>
> Explanation:
>
> All elements are distinct.

**Example 3:**

> Input: nums = [1,1,1,3,3,4,3,2,4,2]
>
> Output: true

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

### Solutions are in JavaScript

**Solution 1: Brute Force checking**

> Checking all the elements in the array with each other using nested for loops.

```js
var containsDuplicate = function (nums) {
  for (let i = 0; i < nums.length - 1; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] === nums[j]) {
        return true;
      }
    }
  }
  return false;
};
```

- Time Complexity: `O(n^2)`
- Space Complexity: `O(1)`

**Solution 2: Sorting the array first**

> First sort the array and then check for duplicates values one after another.

```js
var containsDuplicate = function (nums) {
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length - 1; i++) {
    if (nums[i] === nums[i + 1]) {
      return true;
    }
  }
  return false;
};
```

- Time Complexity: `O(n log n)`
- Space Complexity: `O(n)`

**Solution 3: Hash Table**

> Create a hash table and store the values in it.

```js
var containsDuplicate = function (nums) {
  const hashTable = {};
  for (let i = 0; i < nums.length; i++) {
    if (!hashTable[nums[i]]) {
      hashTable[nums[i]] = 1;
    } else {
      return true;
    }
  }
  return false;
};
```

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`
