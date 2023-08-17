//////////////////////////////////////////////////////////////////////////////
//  Project Euler problem 5 solution (Smallest Multiple)
// 
//   @ Author: Zahid Ari
// 
// Problem 5:
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ? 
//
// Solution:
// form 1 to 10 finding the primes 2,3,5,7. 
// Next check how many times appear primes in one number. 
// for example: 10 is come from 2 and 5. there is no more factor to separate the 10.
//              20 is also have the primes 2 and 5 , but 2 comes 2 times so its 2^2 and 5.
// add these in an vector.
// 
// search for the next number the primes again. count how many times the primes appear again.
// if needed add the remaining counts the primeNum to the vector 
// 
// at the and iterate trough the vector and multiply the numbers to find the solution.
// 
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;
#include <vector>

void solutionViaLogaritma();
void solutionViaQuestioningEveryPrimeForEveryNumberFrom1To20();
bool isPrime(int);
void searchAdd(vector<int>&,int PrimeNum, int howManyPrimes);//searching the number in the vector and if
void calculateResult(vector<int>);

std::vector<int> arr;


int main()
{
    //solutionViaQuestioningEveryPrimeForEveryNumberFrom1To20();
    solutionViaLogaritma();
}

void solutionViaQuestioningEveryPrimeForEveryNumberFrom1To20() {
    


    for (int i = 2; i <= 20; i++) { //for1


        cout << "for1, i: " << i << endl;
        // prime division
        for (int j = 2; j <= i; j++) {  //for2

            cout << "for1, i: " << i << "   for2, j: " << j << endl;
            int tempZahl = i;
            int howManyPrimes = 0;

            cout << "is " << j << " prime ?" << endl;
            if (!isPrime(j)) {
                cout << "no, continue der for2 for j:" << j << endl;
                cout << "for2 ende. j: " << j << endl << "*************************************" << endl;
                continue;
            }
            cout << "yes" << endl;

            while (1)
            {
                cout << "while anfang" << endl;

                if (tempZahl == 0 || tempZahl == 1)
                    break;
                cout << "no break" << endl;

                if (tempZahl % j == 0)
                {
                    tempZahl = tempZahl / j;
                    howManyPrimes++;
                    cout << "new tempZahl:     " << tempZahl << endl;
                    cout << "new howManyPrimes:" << howManyPrimes << endl;
                }
                else {
                    // prime dont exist in tempZahl, so move forward and skip the while loop.
                    cout << "prime dont exist in tempZahl, break" << endl;
                    break;
                }
            }
            cout << "out of while." << endl;
            if (howManyPrimes != 0)
                cout << "howManyPrimes is :" << howManyPrimes << endl;
            searchAdd(arr, j, howManyPrimes);


            cout << "for2 ende. j: " << j << endl << "*************************************" << endl;
        }//for2 end
        cout << "for1 ende. i:" << i << endl << "*************************************" << endl;
    }//for1 end
    cout << "raus aus for1." << endl;

    cout << "calculateResult" << endl;
    calculateResult(arr);
}
void solutionViaLogaritma() {

    int searchedNumber = 20;

    //calculate via logaritma !
    // if you divide a numbers logaritma to primes logaritma, 
    // it shows you how many times the prime number is in this number.
    // so the divison must be at least >=1 to include 1 time the pirme number  in that number.
    
              //index     0, 1, 2, 3, 4, 5, 6, 7    
    int primesArr[8]  = { 2, 3, 5, 7,11,13,17,19};
    int primesOccur[8]= { 0, 0, 0, 0, 0, 0, 0, 0};// how many times does prime numbers occur in the number 20. 1 by 1.
    int forExample = log(8) / log(2); // means that 2 is exact 3 times in the number 8. so 2^3 = 8
    
   
    for (int i = 0; i < 8; i++) 
    {
        //calculates how many times the prime number is in the number and floor it to naturalNum = howManyTimesOccurInIt. 
        int howManyTimesOccurInIt = floor(log(searchedNumber) / log(primesArr[i]));
        cout << "howManyTimesOccurInIt " << i << ":" << howManyTimesOccurInIt << endl;
        primesOccur[i] = howManyTimesOccurInIt; // adds to the occur array to the right place where the "i"th prime is.
    }

    int sum = 1;
    //calculate the product of all that primes that occured.
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < primesOccur[i];j++)
            sum = sum * primesArr[i];
    }


    cout << "the sum is:" << sum << endl;

}

/** @brief:   is the number x prime ?
*
*/
bool isPrime(int x) { 

    for (int i = 2; i <= x / 2; ++i)
        if (x % i == 0)
            return false;
    return true;
}

/**   @brief:  searches the prime in the array for howManyTimes and if needed adds in it.
* 
*       firstly search for the primeNum and count how many times is it in the vector. 
*       next adds the primeNum to the vector for n times if needed. 
*       
*       imagine 8. its is 2^3. so it has 3 times the prime number 2. 
*       howManyTimes is 3. the primeNum is 2. 
*       searchAdd funtion will add these twos in to the vector 3 times.
*       But it can have before that several times "2" so it counts and add if needed "2"s.
*   
*/
void searchAdd(vector<int>&arr, int primeNum, int howManyPrimes)
{
    cout << "***searchAdd function is called***" << endl;

    //search for the primeNum
    //iterator for navigate trough the vector
    vector<int>::iterator it;
    int count=0;

    cout << "control how many times is PrimeNum in the vector" << endl;
    //counts the primeNum in the vector.
    for (it = arr.begin(); it != arr.end(); it++) {
        
        if (primeNum == *it) {
            cout << "if called. primenum == *it true, count ++ " << endl;
            count++;
        }
    }
    


    //adds the primeNum to the vector for many times if needed.
    if (count< howManyPrimes) 
    {
        cout << "push_back(" << primeNum << ") "<< howManyPrimes - count <<" times.\n";
        
    
        cout << "howmany times :" << howManyPrimes - count << endl;
        for (int i = 0; i < howManyPrimes - count; i++) {
            cout << "in for fuer i :" << i << endl;
            
            arr.push_back(primeNum);
            cout << "pushback called" << endl;
        }
  
        
        cout << "Primes in arr: ";
        for (vector<int>::iterator it3 = arr.begin(); it3 != arr.end(); it3++) {
            
            cout << *it3<< " ";
        }
        cout << "\nende der for. end of searchAdd.***" << endl;

        return;
    }
}


//calculates the result via vector iterator and prints out.
void calculateResult(vector<int> arr) {

    int result=1;
    vector<int>::iterator it;

    for (it = arr.begin(); it != arr.end(); it++)
        result = *it * result;

    cout << "the result is: " << result << endl;
}