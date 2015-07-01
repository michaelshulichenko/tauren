int * shellsort (int *a, int n) {    
    // assign  - 0
    // comparsion - 1
    int *result = (int *) malloc(sizeof(int) * 2);

    result[0] = 0;
    result[1] = 0;

    int h, i, j, t;

    for (h = n; h /= 2;) {
        
        result[0] += 2 ;

        for (i = h; i < n; i++) {

            result[1]++;
 
            t = a[i];
            result[0] += 3;

            for (j = i; j >= h && t < a[j - h]; j -= h) {
                a[j] = a[j - h];

                result[1] += 2;
                result[0] += 4;
            }

            a[j] = t;
            result[0]++;
        }
    }

    return result;
}