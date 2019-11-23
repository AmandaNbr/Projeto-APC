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
    if (!stringLengValidation){
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

void listPersonByCourse() {
    char readCourse[100];

    getCourseToList(readCourse);

    if(stringIsEmpty(readCourse)){
        printf("\nNenhuma pessoa relacionada a esse curso.\n");
    }else{
        printPersonByCourse(readCourse);
    }

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

void getCourseToList(char* readCourse) {
    printf("Informe o curso: ");

    fgets(readCourse, 100, stdin);
    fflush(stdin);

    convertToLowercase(readCourse);
    trim(readCourse, NULL);
}

void printPersonByCourse(char* readCourse) {
    char line[256];
    int foundPerson = 0;
    struct Person *readPerson;
    readPerson = (struct Person*) malloc(sizeof(struct Person));

    FILE *personFile;
    personFile = fopen("people.txt", "r");

    while(fgets(line, sizeof(line), personFile) != NULL) {
        formatPersonStructData(readPerson, line);
        if (strcmp(readPerson->wantedCourse, readCourse) == 0) {
            printPerson(readPerson);
            foundPerson = 1;
        }
    }
    if (!foundPerson) {
        printf("\nNao existe nenhuma pessoa cadastrada para esse curso.\n");
    }
}

void consultPerson(){
    char readName[100];

    getNameToConsult(readName);

    if(stringIsEmpty(readName)){
        printf("Nome nao cadastrado.\\n");
    }else{
        printPersonByName(readName);
    }

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

void getNameToConsult(char* readName) {
    printf("Informe o Nome: ");

    fgets(readName, 100, stdin);
    fflush(stdin);

    convertToLowercase(readName);
    trim(readName, NULL);
}

void printPersonByName(char* readName){
    char line[256];
    int foundPerson = 0;
    struct Person *readPerson;
    readPerson = (struct Person*) malloc(sizeof(struct Person));

    FILE *personFile;
    personFile = fopen("people.txt", "r");

    while(fgets(line, sizeof(line), personFile) != NULL) {
        formatPersonStructData(readPerson, line);
        if (strcmp(readPerson->fullName, readName) == 0 || strstr(readPerson->fullName, readName) == 1) {
            printPerson(readPerson);
            foundPerson = 1;
        }
    }
    if (!foundPerson) {
        printf("\nNome nao cadastrado.\n");
    }
}
