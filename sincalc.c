#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <inttypes.h>

double convertrad(int degin); //Forward definitions of functions
int64_t factorial (int64_t facnum);
float sine (double sinin);
double truncate(double truncin);

int main () {
    printf("Program to calculate the sin of an angle.");
    printf("\nEnter r for radian or d for degrees: ");
    char typein;
    scanf("%c", &typein);
    printf("\nEnter the angle: ");
    int angin;
    scanf("%d", &angin);
    if (typein == 'r') {
       
        printf("\nThe sine of %d degrees is %.1f", angin, truncate(sine(angin)));
        
    }
    else if (typein == 'd') {
       
        printf("\nThe sine of %d degrees is %.1f", angin, truncate(sine(convertrad(angin))));

    }

        
    
    else {
        printf("\n Invalid input"); //wrong input in first prompt
    }

    printf("\n");  
    printf("\n\nPress any key to exit...");
    getch();
    return 0;
}

double convertrad(int degin) {
    return (3.14 / (double) 180) * (double) degin; 
}

// Calculating sine using factorial();

float sine(double sinin) {
    int64_t i = 1;
    int a = 1;
    float sinresult = 0;
    int64_t final = 11;
    while (i<=final) { // calculating sine using Taylor's series
        int64_t fac = factorial(i);
        if (a%2 != 0) { 
            sinresult += (pow(sinin, (double) i)/fac); // adding odd terms in Taylor's series
        }
        else {
            sinresult -= (pow(sinin, (double) i)/fac); //subtracting even terms in Taylor's series
        }
        i+= 2;
        a++; //increment
    }
    return sinresult;
}

// Calculating the factorial of input

int64_t factorial(int64_t facnum) {
    int64_t i = 1;
    int64_t facresult = 1;
    while (i<=facnum) {
        facresult = i*facresult;
        i++;
    }
    return facresult;

}

// Truncate differently based on the sign of the integer

double truncate (double truncin) {
    if (truncin > 0) {
        return floorf(truncin * 10) / 10;
    }
    else if (truncin < 0) {
        return ceilf(truncin * 10) / 10;
    }
    else {
        return 0;
    }
}