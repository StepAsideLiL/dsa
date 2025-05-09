/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  // Solution 1 (replace and match): Time Complexity: O(n) | Space Complexity: O(n)
  let str = s.toLowerCase().replace(/[^a-z0-9]/g, "");

  for (let i = 0; i < str.length; i++) {
    if (str[i] !== str[str.length - 1 - i]) {
      return false;
    }
  }

  return true;
};

console.log(isPalindrome("A man, a plan, a canal: Panama")); // true
console.log("===");
console.log(isPalindrome("race a car")); // false
console.log("===");
console.log(isPalindrome(" ")); // true
