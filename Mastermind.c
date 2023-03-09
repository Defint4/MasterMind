#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char *generate() {
    srand(time(NULL));
    char tableau[6] = {'P', 'B', 'M', 'Y', 'O', 'G'};
    int secret[4];
    char *code = malloc(sizeof(char) * 4);
    for(int i = 0; i < 4; i++) {                   
        secret[i] =rand() % (5+1);
        do {                                                            //générer un tableau de 4 couleur aléatoire
            secret[i] =rand() % (5+1);
        } while (secret[i] == secret[i-1]);

        // printf("%d\n", secret[i]);
    }
    for(int j = 0; j < 4; j++){
        code[j] = tableau[secret[j]];
    }
    // printf("%c %c %c %c\n", code[0], code[1], code[2], code[3]);
    return code;
}

char *response() {
    char *response = malloc(sizeof(char) * 4);                   
    printf("\n Entrez les 4 couleur en maj(ex : P B M Y) : ");
    scanf("%c %c %c %c", &response[0], &response[1], &response[2], &response[3]); 
    printf("-----------\n");                                                                          // on demande à l'utilisateur de rentrer 4 couleurs
    printf("| %c %c %c %c |\n", response[0], response[1], response[2], response[3]);
    return response;
}

int verify() {
    char *secret = generate();
    for(int round = 0; round < 12; round++) {
        char *responseUser = response();
        int countRed = 0;
        int countWhite = 0;
        for(int i = 0; i < 4; i++) {
            if (responseUser[i] == secret[i]) {
                printf("W");                            // on test si ya des bien placé
                countWhite++;
            }
        }
                if(countWhite == 4 ){
                printf("\nBravo vous avez gagné");
                return 1;
                }
        for(int b = 0; b < 4; b++) {
            for(int j = 0; j < 4; j++) {
                if (responseUser[b] == secret[j]) {
                    printf("R");                    // on test si y'a des mal placé 
                    countRed++;
                }
            }
        }
        if(countRed + countWhite == 4) {
            printf("");
        }
        else if(countRed + countWhite == 3) {
            printf(".");
        } 
        else if(countRed + countWhite == 2) {
            printf("..");                            // si jamais y'a pas de mal placé ni de bien placé
        }
        else if(countRed + countWhite == 1) {
            printf("...");
        }
        else if(countRed + countWhite == 0) {
            printf("....");
        } 
    }
}

int main() {
    verify();
    return 0;
}




