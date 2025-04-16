function unique_character(string){
    for (let i = 0; i < string.length; i++) {
        var is_duplicate = false

        for (let j = 0; j < string.length; j++) {
            if (j == i)
                continue
            if (string[i] == string[j]) {
                is_duplicate = true
                break
            }
        }

        if (!is_duplicate) {
            return i
        }
    }

    return -1
}


console.log(unique_character("ggffoo")) // should return 2