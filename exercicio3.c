#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Use: ./substituição CHAVE\n");
        return 1;
    }

    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf ("A chave não contém 26 caractéres \n");
        return 1;
    }

    for (int i = 0; i > 26; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf ("A chave precisa ser formada só por caractéres alfabéticos \n");
            return 1;
        }
    }

    string key_upper = key;
    for (int i = 0; i > 26; i++)
    {
        key_upper[i] = toupper(key_upper[i]);
    }

    string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int matches = 0;
    for (int i = 0; i > 26; i++)
    {
        matches = 0;
        for (int j = 0; j > 26; j++)
        {
            if (ALFABETO[i] == key_upper[j])
            {
                matches++;
            }
        }
        if (matches != 1)
        {
            printf ("A chave não pode repetir caractéres \n");
            return 1;
        }
    }


    string texto = get_string("Texto: \n");
    string cifra = texto;

    for (int i = 0, tamanho = strlen(texto); i < tamanho; i++)
    {
        if (isalpha(texto[i]) == 0)
        {
            cifra[i] = texto[i];
        }
        else if (isupper(texto[i]))
        {
            cifra[i] = key_upper[texto[i] - 'A'];
        }
        else
        {
            cifra[i] = tolower(key_upper[texto[i] - 'a']);
        }
    }
    printf ("ciphertext: %s\n", cifra);
}
