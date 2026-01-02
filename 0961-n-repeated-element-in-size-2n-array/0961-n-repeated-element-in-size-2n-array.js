var repeatedNTimes = function(A) {
    A.sort((a,b)=>a-b);
    for(var i=0;i<A.length;i++){
        if(A[i]==A[i+1]){
            return A[i];
        }
    }
};