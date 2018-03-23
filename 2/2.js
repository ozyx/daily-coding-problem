function prodArray(input) {
    let newAr = []
    let init;
    let num;
    for(let i = 0; i < input.length; i++){
        init = false;
        for(let j = 0; j < input.length; j++){
            if(i !== j) {
                if(init === false){
                    num = input[j];
                    init = true;
                } else {
                    num *= input[j];
                }
            }
        }
        newAr.push(num);
    }
    return newAr;
}

let input = [1, 2, 3, 4, 5]
console.log(prodArray(input));