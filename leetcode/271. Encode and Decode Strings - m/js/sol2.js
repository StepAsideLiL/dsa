/**
 * @param {string[]} strs
 * @returns {string}
 */
function encode(strs) {
  let res = "";

  for (let s of strs) {
    res += s.length + "#" + s;
  }

  return res;
}

const encodeString1 = encode(["leet", "code", "love", "you"]);
const encodeString2 = encode(["we", "say", ":", "yes"]);

/**
 * @param {string} str
 * @returns {string[]}
 */
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

const decodeArr1 = decode(encodeString1);
const decodeArr2 = decode(encodeString2);

console.log(encodeString1, decodeArr1);
console.log("===");
console.log(encodeString2, decodeArr2);
