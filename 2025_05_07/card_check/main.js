function checkCard(cardnumber_check) {
    if (cardnumber_check.length === 16) {
        for (let i = 0; i < cardnumber_check.length; i++) {
            let char = cardnumber_check[i];
            if (char < "0" || char > "9") {
                return console.log("Not valid");
            }
        }

        
        if (cardnumber_check[0] === "4") {
            return console.log("Visa");
        } else if (cardnumber_check[0] === "5") {
            return console.log("Mastercard");
        } else {
            return console.log("Not valid");
        }

    } else {
        return console.log("Card number must be 16 digits");
    }
}
