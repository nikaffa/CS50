#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Input one command-line argument\n");
        return 1;
    }
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if ((argv[1][i] < 48) || (argv[1][i] > 57))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    int k = atoi(argv[1]); 
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i]))
        {
            int c = (p[i] - 65 + k) % 26;
            printf("%c", c + 65);    
        }
        else if (islower(p[i]))
        {
            int c = (p[i] - 97 + k) % 26;
            printf("%c", c + 97);    
        }
        else
        {
            printf("%c", p[i]); 
        }
    }
    printf("\n");
    return 0;
}  


     

    


    
