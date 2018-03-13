function sumsToK(inputAr, k) {
    let length = inputAr.length
    for(let i = 0; i < length; i++){
        for(let j = 1; j < length; j++){
            if(inputAr[i] + inputAr[j] == k) {
                return true
            }
        }
    }
    return false
}

let input = [10, 15, 3, 7]
let k = 17

console.log(sumsToK(input, k))