#import <stdio.h>
#import <cs50.h>

/* Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm. */

long long getUserCreditCard();
bool hasValidChecksum(long long creditNumber);
int getCreditCardLength(long long creditNumber);
string getCreditCardBrand(int firstSignificantDigit, int secondSignificantDigit, int ccLength);
int getFirstMostSignificantDigit(long long creditNumber);
int getSecondMostSignificantDigit(long long creditNumber);

int main(void)
{
    // get credit card as input
    long long creditNumber = getUserCreditCard();

    string msg = "INVALID";

    if (hasValidChecksum(creditNumber))
    {
        // Get the first and second most significant digits of the credit card number
        int firstSigDigit = getFirstMostSignificantDigit(creditNumber);
        int secondSigDigit = getSecondMostSignificantDigit(creditNumber);

        // Get the length of the credit card
        int ccLength = getCreditCardLength(creditNumber);
        msg = getCreditCardBrand(firstSigDigit, secondSigDigit, ccLength);
    }

    printf("%s\n", msg);
}

// Gets the first two digits of the credit card number, used for determining the card's brand.
int getSecondMostSignificantDigit(long long creditNumber)
{
    int mostSignificantDigit = 0;
    int secondMostSignificantDigit = 0;

    do
    {
        mostSignificantDigit = secondMostSignificantDigit;
        secondMostSignificantDigit = creditNumber % 10;
        creditNumber /= 10;
    }
    while (creditNumber > 10);

    return secondMostSignificantDigit;
}

// Gets the first two digits of the credit card number, used for determining the card's brand.
int getFirstMostSignificantDigit(long long creditNumber)
{
    int firstSignificantDigit;

    do
    {
        firstSignificantDigit = creditNumber % 10;
        creditNumber /= 10;
    }
    while (creditNumber > 0);

    return firstSignificantDigit;
}

// Gets the credit card brand.
string getCreditCardBrand(int firstSignificantDigit, int secondSignificantDigit, int ccLength)
{
    string msg;

    if (ccLength == 15 && firstSignificantDigit == 3 && (secondSignificantDigit == 4
            || secondSignificantDigit == 7))
    {
        msg = "AMEX";
    }
    else if (ccLength == 16 && firstSignificantDigit == 5 && (secondSignificantDigit == 1
             || secondSignificantDigit == 2 || secondSignificantDigit == 3 || secondSignificantDigit == 4
             || secondSignificantDigit == 5))
    {
        msg = "MASTERCARD";
    }
    else if ((ccLength == 13 || ccLength == 16) && firstSignificantDigit == 4)
    {
        msg = "VISA";
    }
    else
    {
        msg = "INVALID";
    }

    return msg;
}

// Gets the length of the credit card number.
int getCreditCardLength(long long creditNumber)
{
    int numDigits = 0;

    do
    {
        creditNumber /= 10;
        numDigits++;
    }
    while (creditNumber > 0);

    return numDigits;
}

long long getUserCreditCard()
{
    // TODO: Check other input values here
    return get_long_long("Number: ");
}

// Checks whether the credit card has a valid checksum
bool hasValidChecksum(long long creditNumber)
{
    long long sumEven = 0;
    long long sumOdd = 0;
    int isOdd = 1;
    long long leftMostDigit;
    long long doubledDigit = 0;

    do
    {
        leftMostDigit = creditNumber % 10;

        if (isOdd)
        {
            sumOdd += leftMostDigit;

            // Flick it back to the even sum
            isOdd = 0;
        }
        else
        {
            // Since it's even digits, we double it and concatenate the digits
            doubledDigit = leftMostDigit * 2;

            // If it's greater than 10, we concatenate a 1, and concatenate the result of the modulo
            if (doubledDigit > 9)
            {
                sumEven += 1;
                doubledDigit %= 10;
            }
            sumEven += doubledDigit;

            // Flick it back to odd sum
            isOdd = 1;
        }
        // Divide the credit number by 10 to get the next digit in line
        creditNumber /= 10;
    }
    while (creditNumber > 0);

    return (sumEven + sumOdd) % 10 == 0;
}
