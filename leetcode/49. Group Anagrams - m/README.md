# 1. [Group Anagrams](https://leetcode.com/problems/group-anagrams/description/)

Given an array of strings `strs`, group the [anagrams](## "An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.") together. You can return the answer in **any order**.

**Example 1:**

> **Input:** `strs = ["eat","tea","tan","ate","nat","bat"]`
>
> **Output:** `[["bat"],["nat","tan"],["ate","eat","tea"]]`
>
> **Explanation:**
>
> - There is no string in strs that can be rearranged to form `"bat"`.
>
> - The strings `"nat"` and `"tan"` are anagrams as they can be rearranged to form each other.
>
> - The strings `"ate"`, `"eat"`, and `"tea"` are anagrams as they can be rearranged to form each other.

**Example 2:**

> **Input:** `strs = [""]`
>
> **Output:** `[[""]]`

**Example 3:**

> **Input:** `["a"]`
>
> **Output:** `[["a"]]`

**Constraints:**

- `2 <= nums.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

---

### Solutions are in JavaScript

**Solution 1: Hash sort**

> Sort each string and put them in a hash table.

```js
var groupAnagrams = function (strs) {
  if (strs.length === 1) {
    return [strs];
  }

  const hash = {};
  for (let i = 0; i < strs.length; i++) {
    const sorted = strs[i].split("").sort().join("");
    if (!hash[sorted]) {
      hash[sorted] = [];
    }
    hash[sorted].push(strs[i]);
  }
  return Object.values(hash);
};
```

- Time Complexity: `O(n log n)`
- Space Complexity: `O(n)`

**Solution 2: Sorting with index info**

> First sort the array with index info then compare the sum of the two elements form the end with the target.

```js
var groupAnagrams = function (strs) {
  if (strs.length === 1) {
    return [strs];
  }
  const hash = {};
  for (let i = 0; i < strs.length; i++) {
    const count = Array(26).fill(0);
    for (let j = 0; j < strs[i].length; j++) {
      count[strs[i][j].charCodeAt(0) - "a".charCodeAt(0)] += 1;
    }
    console.log(count);

    const key = count.join(",");
    if (!hash[key]) {
      hash[key] = [];
    }
    hash[key].push(strs[i]);
  }
  return Object.values(hash);
};
```

- Time Complexity: `O(n * m)`
- Space Complexity: `O(n)`
