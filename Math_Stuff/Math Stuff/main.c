//
//  main.c
//  Math Stuff
//
//  Created by Barrett Stricklin on 3/11/19.
//  Copyright © 2019 Barrett Stricklin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);


//******************  MAIN  *****************************

int main () {
    
    
    int testNum;
    
    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);
    
    if (isPrime(testNum))
        printf("%d is prime\n",testNum);
    else
        printf("%d is not prime.", testNum);
    
    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);
    
    printPrimes(testNum);
    
    printf("\n");
    
    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);
    
    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum));
    
    printf("\n");
    
    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);
    
    findFactors(testNum);
    
    return 0;
}

bool isPrimeHelp(int n, int div){
    if(div==1)
        return true;
    if(n%div==0)
        return false;
    return isPrimeHelp(n, div-1);
}


//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
bool isPrime (int number) {
    if(number==1)
    return false;
    int div=number/2;
    return isPrimeHelp(number, div);
}


//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.
int min=1;
void printPrimes (int n) {
    if(n>=min){
        if(isPrime(min))
            printf("%d ", min);
        min++;
    }else
        return;
    printPrimes(n);
    
}



//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    if(n<=1)
        return n;
    return findFibo(n-2)+findFibo(n-1);
    
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
int count=0;
void findFactors (int number) {
    count++;
    if(count==1)
        printf("%d= ", number);
    if(number%2==0){
        printf("%d * ",2);
       findFactors(number/2);
    }
    if(count<=1){
        printf("prime");
        return;
    }
    if(isPrime(number))
    printf("%d ", number);
    
}
