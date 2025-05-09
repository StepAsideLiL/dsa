# 125. [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/)

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` _if it is a **palindrome**_, _or_ `false` _otherwise_.

**Example 1:**

> **Input**: `s = "A man, a plan, a canal: Panama"`
>
> **Output**: `true`
>
> Explanation: "amanaplanacanalpanama" is a palindrome.

**Example 2:**

> **Input**: `s = "race a car"`
>
> **Output**: `false`
>
> Explanation: "raceacar" is not a palindrome.

**Example 3:**

> **Input**: `s = " "`
>
> **Output**: `true`
>
> Explanation: s is an empty string "" after removing non-alphanumeric characters.
>
> Since an empty string reads the same forward and backward, it is a palindrome.

**Constraints:**

- `1 <= s.length <= 2 * 10^5`
- `s` consists only of printable ASCII characters.

---

### Solutions are in JavaScript

**Solution 1: Replace and Match**

> Replace all non-alphanumeric characters with an empty string and then check if the string is equal to its reverse.

```js
var isPalindrome = function (s) {
  let str = s.toLowerCase().replace(/[^a-z0-9]/g, "");

  for (let i = 0; i < str.length; i++) {
    if (str[i] !== str[str.length - 1 - i]) {
      return false;
    }
  }

  return true;
};
```

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`
