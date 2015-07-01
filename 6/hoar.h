void _hoarsort(int *a, int first, int last, int *result) {
	int i = first, j = last; 
	double tmp, x = a[(first + last) / 2];   
	result[0] += 3;

	do {   
		result[1]++;

		while (a[i] < x) {
			i++; 
			result[0]++;
			result[1]++;
		}
		
		while (a[j] > x) {      
			j--;
			result[0]++;
			result[1]++;
		}

		if (i <= j) {
			
			result[1]++;

			if (i < j) {        
				tmp=a[i];        
				a[i]=a[j];        
				a[j]=tmp;

				result[0] += 3;
				result[1]++;      
			}      
			i++;      
			j--;
			result[0] += 2;
		} 
	}  while (i <= j);   

	if (i < last) {
		result[1]++; 
		_hoarsort(a, i, last, result); 
	}
	
	if (first < j) {
		result[1]++;
		_hoarsort(a, first,j, result); 
	}
}

int * hoar_sort(int *a, int first, int last) {
	// assign  - 0
    // comparsion - 1
    int *result = (int *) malloc(sizeof(int) * 2);

    result[0] = 0;
    result[1] = 0;
    last--;

    _hoarsort(a, first, last, result);

    return result;
}