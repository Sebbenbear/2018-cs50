#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Vignere cypher implementation. Enter the capital case alphabetic key to offset the letters by, then the message when prompted.

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

    string key = argv[1];

    // check if it only contains alphabetic keys
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./caesar k\n");
            return 1;
        }
        key[i] = toupper(key[i]);
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    int index = 0;
    int offset = key[index] - 'A';

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char character = plaintext[i];

        // Only adjust the offset if it's a alphabetic character
        if (isalpha(character))
        {
            if (character >= 'a' && character <= 'z')
            {
                character = ((character - 'a' + offset) % 26) + 'a';
            }
            else if (character >= 'A' && character <= 'Z')
            {
                character = ((character - 'A' + offset) % 26) + 'A';
            }

            // Increment the counter on the string and modulo the result by the length of the string (so there's no overflow)
            // Get the actual value by offsetting from the ascii character A.
            // Assumes only capital case keys are entered as arguments.
            offset = key[++index % strlen(key)] - 'A';
        }

        printf("%c", character);
    }

    printf("\n");
}
