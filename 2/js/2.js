function prodArray(input) {
    // declare arrays
    let left = [];
    let right = [];
    let prod = [];

    let n = input.length;

    // leftmost element is always one
    left[0] = 1;

    // rightmost element is always one
    right[n - 1] = 1;

    // construct left array
    for (let i = 1; i < n; i++) {
        left[i] = input[i - 1] * left[i - 1];
    }

    // construct right array
    for (let i = n - 2; i >= 0; i--) {
        right[i] = input[i + 1] * right[i + 1];
    }

    // construct product array
    for (let i = 0; i < n; i++) {
        prod[i] = left[i] * right[i];
    }

    return prod;
}

let input = [3, 2, 1]
console.log(prodArray(input));