
#include "sort.h"

void BubbleSort::sort(int A[], int size)			// main entry point
{

    for(int k = 1; k < size; ++k)
    {
        
        for(int j = 0; j<(size - k); j++)
        {
            if(A[j+1]<A[j])
            {
                
                int tmp = A[j]; // swap elements
                A[j] = A[j+1];
                A[j+1] = tmp;
                
            }
            ++num_cmps;
            
        }
    }

    
    
	/* Complete this function with the implementation of bubble sort algorithm
     Record number of comparisons in variable num_cmps of class Sort*/
}
