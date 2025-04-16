function  lengthLastWord(str) {
    if (str.length < 0){
        return 0
    }else {
    const words = str.split(' ')
    let lastWord = (words[words.length -1])
    return lastWord.length;
    }
    }
    console.log(lengthLastWord("DSADAS ASDASDas DASDASD dasdasdas")); // should return 3