#ifndef _SWAP_
    #define _SWAP_
    
    /*** XOR Swap Function: uses the XOR bitwise operation to swap values ***/
    void xorSwap(int *x, int *y){
        if (x == y)                /* Equal adressess lead to `*x = *x ^ *x` x3, which is 0            */
            return;

        *x = *x ^ *y;              /* Combining xy ->  x = x ^ y                                       */
        *y = *x ^ *y;              /* Canceling  y ->  (x ^ y) ^ y  ->  x ^ (y ^ y)  ->  x ^ 0  ->  x  */
        *x = *x ^ *y;              /* Canceling xy ->  (x ^ y) ^ x  ->  y ^ (x ^ x)  ->  y ^ 0  ->  y  */
    }

    /*** Swap Function: uses call-by-reference to swap values ***/
    void swap(int *x, int *y){
        int temp = *x;         /* Saving `x` value in `temp`                        */
        *x = *y;               /* Setting `x` value to `y` value                    */
        *y = temp;             /* Setting `iterato` value to `temp` value (old `x`) */
    }

    #endif
