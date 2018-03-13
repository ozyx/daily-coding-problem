function sumsToK(inputAr, k) {
    // sort array least to greatest (area of improvement)
    inputAr = inputAr.sort(function (a, b) {
        return a - b
    });

    let i = 0                  // set i to first element in array
    let j = inputAr.length - 1 // set j to last element in array

    while (i < j) {
        if (inputAr[i] + inputAr[j] < k) { i++ }
        if (inputAr[i] + inputAr[j] > k) { j-- }
        if (inputAr[i] + inputAr[j] == k) { return true }
    }
    return false
}

// true case
let input = [10, 15, 3, 7]
let k = 17
console.log(sumsToK(input, k))

// false case
input = [10, 15, 3, 7]
k = 27
console.log(sumsToK(input, k))