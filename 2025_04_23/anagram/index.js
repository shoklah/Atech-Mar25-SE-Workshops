// function anagram(s,t){
//     let list1 = s.split("");
//     let list2 = t.split("");
//     let length1 = list1.size();
//     let length2 = list2.size();
//     let count = 0;
//     let index = 0

//     if (length1 == length2){
//         outerloop:
//         for (i of list1){
//             for (j of list2){
//                 if (i == j){
//                     count++
//                     list2[index] =
//                     continue outerloop;
//                 }
//             }
//         }
//         if (count == length1 && count == length2)
//             return true;
//     }
//     else{
//         return false;
//     }



//     console.log(anagram("anagram","nagaram"));
// }

function anagram2(string, target) {
    if (string.length != target.length)
        return false

    let list1 = string.split("")
    let list2 = target.split("")

    for (let i = 0; i < list1.length; i++) {
        for (let j = 0; j < list2.length; j++) {
            if (list1[i] == list2[j]) {
                list2[j] = null
                break
            }
        }
    }

    for (let i = 0; i < list2.length; i++) {
        if (list2[i] != null) {
            return false
        }
    }
    return true
}

console.log(anagram2("sttr", "rstt"))