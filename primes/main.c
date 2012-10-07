//
//  main.c
//  primes
//
//  NOTES
//  40,000 elapsed: 13.410259 by skipping even numbers
//  40000 elapsed: 7.828817 by via checking only first half factors
//  40000 elapsed: 5.712772 by checking only first 1/3 factors
//  40000 elapsed: 3.643709 by checking only first 1/5 factors
//  40000 elapsed: 2.705176 by checking only first 1/7 factors
//  40000 elapsed: 0.960590 by checking using int instead of long
//
//  Created by Bosky <bosky101@gmail.com> on 10/7/12.
//  Copyright (c) 2012 Bosky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 40000
int bitmap[MAX];
int _index=0;

int
isPrime(int m){
    int res=1;
    for(int i=0;i<_index;i++){
        int n = bitmap[i];
        if(m % n == 0){
            //printf("\n\tis %lu %% %lu = %lu ? so %lu is not prime",m,bitmap[i], m % bitmap[i], m / bitmap[i]);
            res=0;break;
        }
        if(n > m/7){
            break;
        }
    }
    if(res){
        bitmap[_index++]=m;
    }
    return res;
}

void
calculatePrimes(){
    int ctr=0;
    printf("2");
    for(int i=3; ctr<MAX;i+=2){
        if(isPrime(i)){
            ++ctr;
            printf("%d ",i);
        }
    }
}

int main(int argc, const char * argv[]){
    clock_t start = clock() ;
    calculatePrimes();
    clock_t end = clock() ;
    double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC ;
    printf(" \n%d elapsed: %f",MAX, elapsed_time );
    return 0;
}
