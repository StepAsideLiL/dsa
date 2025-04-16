238. [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

Given an integer array `nums`, return _an array_ `answer` _such that_ `answer[i]` _is equal to the product of all the elements of_ `nums` _except_ `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

**Example 1:**

> **Input:** `nums = [1,2,3,4]`
>
> **Output:** `[24,12,8,6]`

**Example 2:**

> **Input:** `nums = [-1,1,0,-3,3]`
>
> **Output:** `[0,0,9,0,0]`

**Constraints:**

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The input is generated such that `answer[i]` is **guaranteed** to fit in a **32-bit** integer.

**Follow up:** Can you solve the problem in `O(1)` extra space complexity? (The output array **does not** count as extra space for space complexity analysis.)

---

### Solutions are in JavaScript

**Solution 1: Brute Force**

```js
var productExceptSelf = function (nums) {
  const answer = [];

  for (let i = 0; i < nums.length; i++) {
    let product = 1;
    for (let j = 0; j < nums.length; j++) {
      if (i !== j) {
        product = product * nums[j];
      }
    }
    answer.push(product);
  }

  return answer;
};
```

- Time Complexity: `O(n^2)`
- Space Complexity: `O(1)`

**Solution 2: Product Division**

> Get the product of all element in `nums`. The divide the product by each element in `nums` if the element is not zero.

```js
var productExceptSelf = function (nums) {
  let prod = 1;
  let zeroCount = 0;

  for (let num of nums) {
    if (num !== 0) {
      prod *= num;
    } else {
      zeroCount++;
    }
  }

  if (zeroCount > 1) {
    return Array(nums.length).fill(0);
  }

  const answer = new Array(nums.length);

  for (let i = 0; i < nums.length; i++) {
    if (zeroCount > 0) {
      answer[i] = nums[i] === 0 ? prod : 0;
    } else {
      answer[i] = prod / nums[i];
    }
  }

  return answer;
};
```

- Time Complexity: `O(n)`
- Space Complexity: for extra space `O(1)` | for output array `O(n)`
