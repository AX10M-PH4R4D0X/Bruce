#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "CharSet.h"
#define MAX_LEN 31


typedef struct {

    long double years;

    long double months;
    
    long double weeks;
    
    long double days;
    
    long double hours;
    
    long double mins;
    
    long double secs;    

}Crack_Time;


int Calculate_CharSet_Size(int HasNum, int HasUpper, int HasLower, int HasSymbol);

long double Combinations(int CharSet, int Len_Of_Password);

Crack_Time Estimated_Crack_Time(long double Combination_Count);


int main () {

    char Password[MAX_LEN];
    char choice;

    int Len_Of_Password = 0, CharSet = 0, HasNum = 0, HasUpper = 0, HasLower = 0, HasSymbol = 0;

    long double Combination_Count;


    puts("\n\nBruce| Password Strength Calculator | V.0.1\n**Note: Maximum password length is \"30 characters\" any extra characters will be ignored.\n");

    printf("\n\n------------------------------\n1-[Calculate Combinations]\n\n2-[Calculate Crack Time]\n\n3-[Calculate All & Print]\n\n4-[EXIT]\n------------------------------\n\n");
    scanf(" %c",&choice);
    getchar();


    Crack_Time ct;

    switch (choice) {
        
        case '1':
        
        printf("Please Enter Your Password:");
        fgets(Password, MAX_LEN, stdin);

        Password[strcspn(Password,"\n")] = 0;


        Len_Of_Password = strlen(Password);
        
    
        for(int i = 0; i < Len_Of_Password; i++) {

            char character = Password[i];

            if (isdigit(character)) {

                HasNum = 1;

            } else if (isupper(character)) {
                
                HasUpper = 1;

            } else if (islower(character)) {
                
                HasLower = 1;

            } else {
                
                HasSymbol = 1;

            }
            
            
        }


        CharSet = Calculate_CharSet_Size(HasNum, HasUpper, HasLower, HasSymbol);

        Combination_Count = Combinations(CharSet, Len_Of_Password);


        printf("\nYour Password ---> [%s]\nCombination Count ---> [%.0Lf]\n\n",Password,Combination_Count);
        break;
    

        case '2':
    
        printf("Please Enter Your Password:");
        fgets(Password, MAX_LEN, stdin);

        Password[strcspn(Password,"\n")] = 0;


        Len_Of_Password = strlen(Password);

        
        for(int i = 0; i < Len_Of_Password; i++) {
        
            char character = Password[i];
        
            if (isdigit(character)) {

                HasNum = 1;

            } else if (isupper(character)) {
                
                HasUpper = 1;

            } else if (islower(character)) {
                
                HasLower = 1;

            } else {
                
                HasSymbol = 1;

            }
    
        }
    

        CharSet = Calculate_CharSet_Size(HasNum, HasUpper, HasLower, HasSymbol);
    
        Combination_Count = Combinations(CharSet, Len_Of_Password);

        ct = Estimated_Crack_Time(Combination_Count); 


        printf("\nYour Password ---> [%s]\n\nEstimated Crack Time\n[%.0Lf Years %.0Lf Months %.0Lf Weeks %.0Lf Days %.0Lf Hours %.0Lf Mins %.0Lf Secs]\n\n",Password, ct.years, ct.months, ct.weeks, ct.days, ct.hours, ct.mins, ct.secs);
        break;
        
        case '3':

        printf("Please Enter Your Password:");
        fgets(Password, MAX_LEN, stdin);

        Password[strcspn(Password,"\n")] = 0;


        Len_Of_Password = strlen(Password);


        for(int i = 0; i < Len_Of_Password; i++) {

            char character = Password[i];

            if (isdigit(character)) {

                HasNum = 1;

            } else if (isupper(character)) {
                
                HasUpper = 1;

            } else if (islower(character)) {
                
                HasLower = 1;

            } else {
                
                HasSymbol = 1;

            }

        }


        CharSet = Calculate_CharSet_Size(HasNum, HasUpper, HasLower, HasSymbol);
    
        Combination_Count = Combinations(CharSet, Len_Of_Password);

        ct = Estimated_Crack_Time(Combination_Count); 


        printf("\nYour Password ---> [%s]\nCombination Count ---> [%.0Lf]\n\nEstimated Crack Time\n[%.0Lf Years %.0Lf Months %.0Lf Weeks %.0Lf Days %.0Lf Hours %.0Lf Mins %.0Lf Secs]\n\n",Password, Combination_Count, ct.years, ct.months, ct.weeks, ct.days, ct.hours, ct.mins, ct.secs);
        break;
        
        
        case '4':
        
        puts("[Good-Bye!]\n");
        break;


        default:
    
        puts("\n[Invalid Choice!]\n");
        break;
    
    }
    
    return 0;

}


int Calculate_CharSet_Size(int HasNum, int HasUpper, int HasLower, int HasSymbol) {

    int CharSet_Size = 0;

    CharSet_Size += (HasNum == 1 ? DIGIT_COUNT : 0);
    
    CharSet_Size += (HasUpper == 1 ? UPPERCASE_COUNT_LATIN : 0);

    CharSet_Size += (HasLower == 1 ? LOWERCASE_COUNT_LATIN : 0);
    
    CharSet_Size += (HasSymbol == 1 ? SYMBOL_COUNT : 0);

    return CharSet_Size;

}


long double Combinations(int CharSet, int Len_Of_Password) {

    long double Find_Combinations = pow((long double)CharSet, Len_Of_Password);

    return Find_Combinations;

}


Crack_Time Estimated_Crack_Time(long double Combination_Count) {

    Crack_Time result;

    const long double Attempts_per_sec = 1000000000000.0;
    long double Crack_Time = (Combination_Count/ Attempts_per_sec);


    result.years = floor(Crack_Time / 31536000);
    Crack_Time = fmod(Crack_Time, 31536000);

    result.months = floor(Crack_Time / 2592000);  
    Crack_Time = fmod(Crack_Time, 2592000);

    result.weeks = floor(Crack_Time / 604800);   
    Crack_Time = fmod(Crack_Time, 604800);

    result.days = floor(Crack_Time / 86400);
    Crack_Time = fmod(Crack_Time, 86400);

    result.hours = floor(Crack_Time / 3600);
    Crack_Time = fmod(Crack_Time,3600);
    
    result.mins = floor(Crack_Time / 60);

    result.secs = fmod(Crack_Time, 60);

    return result;

}
