#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getStateToList(char* readState);
int validateStateToList(char* readState);
void printPersonByState(char *readState);

void listPersonByState() {
    char readState[3];

    getStateToList(readState);

    if(validateStateToList(readState)){
        printPersonByState(readState);
    }else{
        //Nothing to do
    }

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

void getStateToList(char* readState){
    printf("Informe o Estado: ");

    fgets(readState, 5, stdin);
    fflush(stdin);

    convertToLowercase(readState);
    trim(readState, NULL);
}

int validateStateToList(char* readState){
    int stringLengValidation = 0, alreadyExistsValidation = 0;

    stringLengValidation = stateLengthValidation(readState);
    if (stringLengValidation){
        printf("\nSigla de Estado invalida, informe uma sigla valida.\n");
        return 0;
    } else {
        alreadyExistsValidation = alreadyRegisteredStateValidation(readState);
        if (alreadyExistsValidation){
            printf("\nEstado nao cadastrado.\n");
            return 0;
        } else {
            return 1;
        }
    }
}

void printPersonByState(char *readState) {
    char line[256];
    int foundPerson = 0;
    struct Person *readPerson;
    readPerson = (struct Person*) malloc(sizeof(struct Person));

    FILE *personFile;
    personFile = fopen("people.txt", "r");

    while(fgets(line, sizeof(line), personFile) != NULL) {
        formatPersonStructData(readPerson, line);
        if (strcmp(readPerson->state, readState) == 0) {
            printPerson(readPerson);
            foundPerson = 1;
        }
    }
    if (!foundPerson) {
        printf("\nNao existe nenhuma pessoa cadastrada para esse Estado.\n");
    }
}
