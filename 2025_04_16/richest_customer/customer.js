function richestCustomer(accounts){

  let maxSum = 0
  let tempSum = 0
   for (i = 0; i < accounts.length; i++) {
       tempSum = 0;
     
   for (j = 0; j < accounts[i].length; j++) {
         tempSum +=  accounts[i][j] 

   }
   if (tempSum > maxSum) {
       maxSum = tempSum
       
   }
 
   }
   
   return  maxSum


}