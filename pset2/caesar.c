#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Caesar cypher implementation. Enter the key to offset the letters by, then the message when prompted.

int main(int argc, string argv[])
{
    if (argc > 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    else if (argc < 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Use long in case of integer overflow
    long k = atol(argv[1]);

    if (k < 0)
    {
        eprintf("Usage: ./caesar k\n");
        return 1;
    }

    // Modulo the large number, so it will work if k entered is higher than 26
    k = k % 26;

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char character = plaintext[i];

        if (character >= 'a' && character <= 'z')
        {
            // Offset the character by the value of a, before adding k to get the correct value to modulo by.
            //Finally restore back to ASCII alphabet range
            character = ((character - 'a' + k) % 26) + 'a';
        }
        else if (character >= 'A' && character <= 'Z')
        {
            character = ((character - 'A' + k) % 26) + 'A';
        }

        printf("%c", character);
    }

    printf("\n");

}
