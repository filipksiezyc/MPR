#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;    
    volatile int random;
    double start;
    double stop;
    double time[4];
    int random_numbers[1000000];    
    unsigned short tab[3];
    
    for(j = 1; j < 5; j++){	
    
    	start = omp_get_wtime();
    	
	#pragma omp parallel for private(i, tab, random) num_threads(j)
    	for(i = 0; i < 1000000; i++){
	    random = erand48(tab);
            random_numbers[i] = random;
	    //printf("Thread id: %d, num: %d\n", omp_get_thread_num(), rand());
    	}
    	stop = omp_get_wtime();
    
    	time[j - 1] = stop - start;
    }
   
    for(i = 0; i < 4; i++)
	printf("Thread number = %d, Time = %F\n", i+1, time[i]);
    
    return 0;
}

