function  powerofthree(n) {
    if(n<1){
        return false;
    }
    i = 0;
    while(i<n){
        if((i*i*i)==n){
            return true;
        }
        i++;
    }
    return false;      
    }
    
    console.log(powerofthree(0));

    