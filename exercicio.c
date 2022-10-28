#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main (void)
{
    int letras = 0;
    int palavras = 1;
    int sentenças = 0;

    string t = get_string("Texto: \n");
    int t_len = strlen(t);

    for (int i = 0; i < t_len; i++)
    {
        if (isalpha(t[i]))
        {
            letras++;
        }
        else if (t[i] == ' ')
        {
            palavras++;
        }
        else if ((t[i] == '!')  (t[i] == '?')  (t[i] == '.'))
        {
            sentenças++;
        }
    }

    float L = ((float)letras/palavras)100;
    float S = ((float)sentenças/palavras)100;
    float indice = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(indice);

    if (grade < 1)
    {
        printf ("Before grade 1\n");
    }
    else if (grade >= 16)
    {
        printf ("Grade 16+\n");
    }
    else
    {
        printf ("Grade %i\n", grade);
    }
}
