# 242. [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

**Example 1:**

> Input: s = "anagram", t = "nagaram"
>
> Output: true

**Example 2:**

> Input: s = "rat", t = "car"
>
> Output: false

**Constraints:**

- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

**Follow up:** What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

---

### Solutions are in JavaScript

**Solution 1: Compare after sort**

> Sort the strings and then compare them.

```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }

  let sSort = s.split("").sort().join("");
  let tSort = t.split("").sort().join("");

  return sSort === tSort;
};
```

- Time Complexity: `O(n log n)`
- Space Complexity: `O(1)`

**Solution 2: Compare hash value**

> Create two hash tables with the characters of the strings as keys and the number of occurrences as values then compare the values of the hash tables.

```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }

  const sHash = {};
  const tHash = {};

  for (let i = 0; i < s.length; i++) {
    sHash[s[i]] = (sHash[s[i]] || 0) + 1;
    tHash[t[i]] = (tHash[t[i]] || 0) + 1;
  }

  for (const key in sHash) {
    if (sHash[key] !== tHash[key]) {
      return false;
    }
  }
  return true;
};
```

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

**Solution 3: Array hash**

> Create an array with 26 element of 0, then increment and decrement the value of the element of the array corresponding to the character of the string.

```js
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }
  const count = new Array(26).fill(0);
  for (let i = 0; i < s.length; i++) {
    count[s.charCodeAt(i) - "a".charCodeAt(0)]++;
    count[t.charCodeAt(i) - "a".charCodeAt(0)]--;
  }
  return count.every((val) => val === 0);
};
```

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
