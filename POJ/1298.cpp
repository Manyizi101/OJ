#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p, cipher[128];
    gets(cipher);
    while (strcmp(cipher, "ENDOFINPUT"))
    {
        if (!strcmp(cipher, "START"))
        {
            gets(cipher);
            while (strcmp(cipher, "END"))
            {
                for (p = cipher; *p; ++p)
                {
                    if ('A' <= *p && *p <= 'Z')
                    {
                        *p = *p < 'F' ? 21 + *p : *p - 5;
                    }
                    putchar(*p);
                }
                gets(cipher);
            }
            putchar('\n');
        }
        gets(cipher);
    }
    return 0;
}