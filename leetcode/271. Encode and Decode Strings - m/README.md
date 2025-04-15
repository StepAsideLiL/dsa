# 271. [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/) or [Here](https://neetcode.io/solutions/encode-and-decode-strings)

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement `encode` and `decode`

**Example 1:**

> **Input:** `["neet", "code", "love", "you"]`
>
> **Output:** `["neet", "code", "love", "you"]`

**Example 2:**

> **Input:** `["we","say",":","yes"]`
>
> **Output:** `["we","say",":","yes"]`

**Constraints:**

- `0 <= strs.length < 100`
- `0 <= strs[i].length < 200`
- `strs[i]` contains only UTF-8 characters.

---

### Solutions are in JavaScript

**Solution 1**

```js
function encode(strs) {
  if (strs.length === 0) {
    return "";
  }

  const sizes = [];
  for (let s of strs) {
    sizes.push(s.length);
  }

  let res = "";
  for (let sz of sizes) {
    res += sz + ",";
  }

  res += "#";

  for (let s of strs) {
    res += s;
  }

  return res;
}

function decode(str) {
  if (str.length === 0) {
    return [];
  }

  const sizes = [];
  let i = 0;

  while (str[i] !== "#") {
    let cur = "";
    while (str[i] !== ",") {
      cur += str[i];
      i++;
    }
    sizes.push(parseInt(cur));
    i++;
  }

  i++;

  const res = [];
  for (let sz of sizes) {
    res.push(str.slice(i, i + sz));
    i += sz;
  }

  return res;
}
```

- Time Complexity: `O(m)` for each `encode()` and `decode()` function call.
- Space Complexity: `O(m + n)` for each `encode()` and `decode()` function call.

> Where `m` is the sum of lengths of all the strings and `n` is the number of strings.

**Solution 2**

```js
function encode(strs) {
  let res = "";

  for (let s of strs) {
    res += s.length + "#" + s;
  }

  return res;
}

function decode(str) {
  const res = [];
  let i = 0;

  while (i < str.length) {
    let j = i;

    while (str[j] !== "#") {
      j++;
    }

    let length = parseInt(str.substring(i, j));

    i = j + 1;
    j = i + length;

    res.push(str.substring(i, j));

    i = j;
  }

  return res;
}
```

- Time Complexity: `O(m)` for each `encode()` and `decode()` function call.
- Space Complexity: `O(m + n)` for each `encode()` and `decode()` function call.

> Where `m` is the sum of lengths of all the strings and `n` is the number of strings.
