/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  // Solution 3 (array hash): Time Complexity: O(n) | Space Complexity: O(1)
  if (s.length !== t.length) {
    return false;
  }
  const count = new Array(26).fill(0);
  for (let i = 0; i < s.length; i++) {
    count[s.charCodeAt(i) - "a".charCodeAt(0)]++;
    count[t.charCodeAt(i) - "a".charCodeAt(0)]--;
  }
  return count.every((val) => val === 0);

  // Solution 2 (compare hash value): Time Complexity: O(n) | Space Complexity: O(1)
  // if (s.length !== t.length) {
  //   return false;
  // }
  // const sHash = {};
  // const tHash = {};
  // for (let i = 0; i < s.length; i++) {
  //   sHash[s[i]] = (sHash[s[i]] || 0) + 1;
  //   tHash[t[i]] = (tHash[t[i]] || 0) + 1;
  // }
  // for (const key in sHash) {
  //   if (sHash[key] !== tHash[key]) {
  //     return false;
  //   }
  // }
  // return true;
  // Solution 1 (compare after sort): Time Complexity: O(n log n + m log m) | Space Complexity: O(1)
  // if (s.length !== t.length) {
  //   return false;
  // }
  // let sSort = s.split("").sort().join("");
  // let tSort = t.split("").sort().join("");
  // return sSort === tSort;
};

console.log(isAnagram("anagram", "nagaram"));
console.log(isAnagram("rat", "car"));
console.log(isAnagram("a", "aa"));
console.log(isAnagram("aacc", "ccac"));
