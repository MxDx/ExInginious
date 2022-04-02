#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * @pre str!=NULL, old!=NULL, new!=NULL, res!=NULL et pointe vers
 *      une zone mémoire de taille suffisante
 * @ret place dans ret la chaîne de caractères correspondant à str dans laquelle 
 * toutes les occurences de la chaîne old sont remplacées par la chaîne new
 */
void replace(char *str, char *old, char *new, char *res) {
    int n = 0;
    for(int i = 0; i < strlen(str); i++) {
        if (str[i] == old[0]) {
            int same = 1;
            for (int j = 0; j < strlen(old); j++) {
                if (str[i+j] != old[j]) {
                    same = 0;
                    break;
                }
            }
            if (same == 1) {
                for (int l = 0; l < strlen(new);l++) {
                    res[n] = new[l];
                    n++;
                }
                i += strlen(old)-1;
            } else {
                res[n] = str[i];
                n++;
            }
        } else {
            res[n] = str[i];
            n++;
        }
    }
    res[n] = '\0';
}

int main() {
    char* str = "Vive la France. Vive la France.";
    char* old = "France";
    char* new = "Belgique";
    char* res = malloc(strlen(str)+strlen(new)+1);

    //char* testIndex = (char*) str[8+strlen(old)];
    //printf("%d \n", (str[8] == old[0]));
    //printf("%s \n", str);

    replace(str,old,new,res);
    
    printf("%s \n", str);
    printf("%s \n", res);

    char* str2 = "abbbcdef";
    char* old2 = "bb";
    char* new2 = "BBB";
    char* res2 = malloc(strlen(str2)+strlen(new2)+1);

    //char* testIndex = (char*) str[8+strlen(old)];
    //printf("%d \n", (str[8] == old[0]));
    //printf("%s \n", str);

    replace(str2,old2,new2,res2);

    printf("%s \n", str2);
    printf("%s \n", res2);
}