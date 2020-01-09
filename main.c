#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int main(int argc, char *argv[]){

    printf("|===============================|\n");
    printf("|   Caeser Cipher Algorithm     |\n");
    printf("|===============================|\n");
    printf("\nEnter the line you want to encrypt: ");
    
    //Check if the input is correct
    if (argc != 3){
        printf("\nProgram must contain two arguments: \n");
        printf("Text file to be encrypted and \n");
        printf("shift value \n");
        exit(EXIT_FAILURE);
    }

    int shiftVal = atoi(argv[2]);
    int shiftLen = strlen(argv[2]);
    int textLen = strlen(argv[1]);
    char outFile[textLen + 10]; 
    strcpy(outFile, argv[1]);
    outFile[strlen(argv[1])] = '\0';
    strcat(outFile, ".enc");

    int i, c;
    char cc;

    // Check if the second argument contains only nondigits
    for (i = 0; i < shiftLen; i++){
        if (!isdigit(argv[2][i])){
            printf("\nShift value must be numeric \n");
            exit(EXIT_FAILURE);
        }
    }
    // Checks if the shift value is an integer between 1 and 25
    if (shiftVal < 1 || shiftVal > 25){
        printf("\nThe shift value must be an integer between 1 and 25 \n");
        exit(EXIT_FAILURE);
    }
    // Read the text to be encrypted 
    FILE *input, *output;
    input = fopen(argv[1], "r");
    output = fopen(outFile, "w");

    if (input == 0){
        printf("\n This text file does not exist in the current directory \n");
        exit(EXIT_FAILURE);

    // Cipher encryption algorithm
    }
    else {
        while ((c = getc(input)) != EOF){
            if (isalpha(c) == 0){
                cc = c;
            } 
            else if ((c <= 90) && (c + shiftVal > 90)){
                 cc = c + shiftVal - 26;
            } 
            else if ((97 <= c && c + shiftVal > 122)){
                 cc = c + shiftVal - 26;
            } 
            else {
                 cc = c + shiftVal;
            }
            fputc(cc, output);
        }

        fclose(input);
        fclose(output);
        printf("\nFile has been encrypted and saved in %s \n", outFile);
    }
    return 0;
}