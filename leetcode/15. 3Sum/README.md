# 15. [3Sum](https://leetcode.com/problems/3sum/)

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

**Example 1**:

> **Input**: `nums = [-1,0,1,2,-1,-4]`
>
> **Output**: `[[-1,-1,2],[-1,0,1]]`
>
> **Explanation**:
>
> `nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0`.
>
> `nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0`.
>
> `nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0`.
>
> The distinct triplets are `[-1,0,1]` and `[-1,-1,2]`.
>
> Notice that the order of the output and the order of the triplets does not matter.

**Example 2**:

> **Input**: `nums = [0,1,1]`
>
> **Output**: `[]`
>
> **Explanation**: The only possible triplet does not sum up to `0`.

**Example 3**:

> **Input**: `nums = [0,0,0]`
>
> **Output**: `[[0,0,0]]`
>
> **Explanation**: The only possible triplet sums up to `0`.

**Constraints**:

- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`

---

### Solutions are in JavaScript

**Solution 1: (Brute force)**

> [!WARNING]
>
> This solution hit _Time Limit Exceeded_.

```js
var threeSum = function (nums) {
  if (nums.length < 3) return [];

  const result = {};
  nums.sort((a, b) => a - b);

  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        if (
          nums[i] + nums[j] + nums[k] === 0 &&
          !result[`${nums[i]}-${nums[j]}-${nums[k]}`]
        ) {
          result[`${nums[i]}-${nums[j]}-${nums[k]}`] = [
            nums[i],
            nums[j],
            nums[k],
          ];
        }
      }
    }
  }

  return Object.values(result);
};
```

- Time Complexity: `O(n^3)`, here n is the length of nums.
- Space Complexity: `O(m)`, here m is the number of unique triplets.
