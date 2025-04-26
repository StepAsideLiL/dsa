# 36. [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note:**

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

**Example 1:**

![Sudoku Image](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

> **Input:** `board = [["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]`
>
> **Output:** `true`

**Example 2:**

> **Input:** `board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]`
>
> **Output:** `false`
>
> **Explanation:** Same as Example 1, except with the **5** in the top left corner being modified to **8**. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

**Constraints:**

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit `1-9` or `'.'`.

---

### Solutions are in JavaScript

**Solution 1: Brute Force**

> check every cell to see if it fulfills the validation rules.

```js
var isValidSudoku = function (board) {
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
```

- Time Complexity: `O(n^2)`
- Space Complexity: `O(n^2)`
