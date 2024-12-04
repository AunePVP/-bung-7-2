/*#include <stdio.h>


int main(void)
{
    int num, check, ziffer;
    char term;
    printf("Gib eine positive ganze Zahl mit maximal 20 Stellen ein.\n");
    do {
        check = 1;
        if (scanf("%d%c", &num, &term) != 2 || term != '\n') { // Get Input and check if input is int.
            check = 0;
            printf("Fehlerhafte Eingabe!\n"); 
            while (getchar() != '\n');
        } else if (num < 0) {
            check = 0;
            printf("Negative Zahlen sind nicht erlaubt!\n"); 
        } else if (num == 0) {
            check = 0;
            printf("Eingabe benötigt mehr als 0;\n"); 
        }
        
    } while (check == 0);


     while (num > 0) {
        ziffer = num % 10; //Letzte Ziffer
        
        num /= 10; //Letzte Zahl entfernen
        printf("%d", ziffer);
    }


}
*/
#include <stdio.h>
#include <string.h>
//#include <ctype.h>
int main(void)
{
    
    char num[22]; // Etwas grösser, damit das Programm erkennt, wenn zu viele Zahlen eingegeben worden sind und es zu keinem Buffer Overflow kommt
    int check, length, i, p;
    printf("Gib eine positive ganze Zahl mit maximal 20 Stellen ein.\n");
    do {
        check = 1;
        scanf("%21s", num); // Get Input
        
        length = strlen(num); // Länge der Zahl
        //printf("%d", length);
        if (length > 20) {
            check = 0;
            printf("Maximal 20 Zahlen erlaubt!\n");
            //while (getchar() != '\n');
        }

        // Überprüfe ob alles Zahlen sind
        for (i = 0; i < length; i++) {
            // Negative Zahlen rausfiltern
            if (num[0] == '-') {
                check = 0;
                printf("Negative Zahlen sind nicht erlaubt\n");
                //while (getchar() != '\n');
                break;
            }
            if (num[i] < '0' || num[i] > '9') {
                check = 0;
                printf("%c ist Keine Zahl\n", num[i]);
                //while (getchar() != '\n');
                break;
            }
        }
        while (getchar() != '\n');
        
    } while (check == 0);
    p = 0;
    for (i = length -1;i >= 0; i--) { //Zahlen von hinten abarbeiten
        if (p != 0 || num[i] != '0') { // Nullen werden weggelassen, bis die erste Zahl die ungleich Null ist an der Reihe ist
            p = 1;
            printf("%c", num[i]);
        }
    }
}
