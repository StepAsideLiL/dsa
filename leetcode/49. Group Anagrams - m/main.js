/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
  // Solution 2 (array hash): Time Complexity: O(n * m) | Space Complexity: O(n)
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

  // Solution 1 (hash sort): Time Complexity: O(n log n) | Space Complexity: O(n)
  // if (strs.length === 1) {
  //   return [strs];
  // }
  // const hash = {};
  // for (let i = 0; i < strs.length; i++) {
  //   const sorted = strs[i].split("").sort().join("");
  //   if (!hash[sorted]) {
  //     hash[sorted] = [];
  //   }
  //   hash[sorted].push(strs[i]);
  // }
  // return Object.values(hash);
};

console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]));
// console.log(groupAnagrams(["a"]));
// console.log(groupAnagrams([""]));
