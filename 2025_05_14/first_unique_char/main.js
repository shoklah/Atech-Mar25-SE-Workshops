// function allUniqueCharacters(s){
//     const charCount = {};

//     for (let char of s) {
//         if (charCount[char]) {
//             return false;
            
//         }
//         charCount[char] = 1;
//     }
// return true;
// }

function isUnique(s, c) {
    let count = 0;

    for (let char of s) {
        if (char == c) {
            count++;
        }
    }

    if (count > 1)
        return false;
    else
        return true;
}

function findUniqueCharacter(s) {
    for (let i = 0; i < s.length; i++) {
        if (isUnique(s, s[i]) == true) {
            return i;
        }
    }
    return -1;
}

console.log(findUniqueCharacter('foo'));
console.log(findUniqueCharacter('ggfoo'));
console.log(findUniqueCharacter('aabb'));