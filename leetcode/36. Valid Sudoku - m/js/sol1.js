/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
  // Solution 1 (brute force): Time Complexity: O(n^2) | Space Complexity: O(n^2)
  for (let row = 0; row < 9; row++) {
    let seen = new Set();
    for (let col = 0; col < 9; col++) {
      if (board[row][col] === ".") {
        continue;
      }

      if (seen.has(board[row][col])) {
        return false;
      }

      seen.add(board[row][col]);
    }
  }

  for (let col = 0; col < 9; col++) {
    let seen = new Set();
    for (let row = 0; row < 9; row++) {
      if (board[row][col] === ".") {
        continue;
      }

      if (seen.has(board[row][col])) {
        return false;
      }

      seen.add(board[row][col]);
    }
  }

  for (let square = 0; square < 9; square++) {
    let seen = new Set();
    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 3; j++) {
        let row = Math.floor(square / 3) * 3 + i;
        let col = (square % 3) * 3 + j;
        if (board[row][col] === ".") {
          continue;
        }

        if (seen.has(board[row][col])) {
          return false;
        }

        seen.add(board[row][col]);
      }
    }
  }

  return true;
};

console.log(
  isValidSudoku([
    ["5", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"],
  ])
); // true
console.log("===");
console.log(
  isValidSudoku([
    ["8", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"],
  ])
); // false
console.log("===");
console.log(
  isValidSudoku([
    [".", "9", ".", ".", "4", ".", ".", ".", "."],
    ["1", ".", ".", ".", ".", ".", "6", ".", "."],
    [".", ".", "3", ".", ".", ".", ".", ".", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    [".", ".", ".", "7", ".", ".", ".", ".", "."],
    ["3", ".", ".", ".", "5", ".", ".", ".", "."],
    [".", ".", "7", ".", ".", "4", ".", ".", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    [".", ".", ".", ".", "7", ".", ".", ".", "."],
  ])
); // true
