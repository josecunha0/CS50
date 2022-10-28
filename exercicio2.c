#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Usage: ./cesar key\n");
        return 1;
    }
    for (int i = 0, arg_len = strlen(argv[1]); i < arg_len; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf ("Usage: ./cesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string texto = get_string("Texto: ");
    string cifra = texto;
    int tamanho = strlen(texto);

    for (int i = 0; i < tamanho; i++)
    {
        if (isalpha(texto[i]) == 0)
        {
            cifra[i] = texto[i];
        }
        else if (islower(texto[i]))
        {
            cifra[i] -= 'a';
            cifra[i] = (cifra[i] + key) %26;
            cifra[i] += 'a';
        }
        else
        {
            cifra[i] -= 'A';
            cifra[i] = (cifra[i] + key) %26;
            cifra[i] += 'A';
        }
    }
    printf("Ciphertext: %s\n", cifra);
}
