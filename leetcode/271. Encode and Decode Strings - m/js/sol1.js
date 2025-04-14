/**
 * @param {string[]} strs
 * @returns {string}
 */
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

const encodeString1 = encode(["leet", "code", "love", "you"]);
const encodeString2 = encode(["we", "say", ":", "yes"]);

/**
 * @param {string} str
 * @returns {string[]}
 */
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

const decodeArr1 = decode(encodeString1);
const decodeArr2 = decode(encodeString2);

console.log(encodeString1, decodeArr1);
console.log("===");
console.log(encodeString2, decodeArr2);
