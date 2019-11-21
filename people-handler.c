#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//nome completo, sexo, data de nascimento, curso desejado e unidade da federação

void registerPerson();
void nameValidation();

struct Person {
    char fullName[100];
    char gender[2];
    int birthDate[3];
    char wantedCourse[100];
    char state[3];
};

void getName(struct Person *);

void registerPerson() {
    struct Person *newPerson;
    newPerson = (struct Person*) malloc(sizeof(struct Person));

    printf("Informe o nome completo:\n");
    getName(newPerson);
    printf("\n%s\n", newPerson->fullName);

    printf("\nInforme o sexo (M/F):\n");
    getGender(newPerson);
    printf("\n%s\n", newPerson->gender);

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
    free(newPerson);;
}

void getName(struct Person *newPerson) {
    do{
        fgets(newPerson->fullName, 100, stdin);
        fflush(stdin);

        convertToLowercase(newPerson->fullName);
        trim(newPerson->fullName, NULL);

        if (stringIsEmpty(newPerson->fullName)){
            printf("Nome nulo, informe um nome valido.\n");
        } else {
            // Nothing to do;
        }

    }while(stringIsEmpty(newPerson->fullName));
}

void getGender(struct Person *newPerson) {
    do{
        fgets(newPerson->gender, 50, stdin);
        fflush(stdin);

        convertToLowercase(newPerson->gender);
        trim(newPerson->gender, NULL);

        if (genderValidation(newPerson->gender)){
            printf("Genero invalido, informe 'M' ou 'F'.\n");
        } else {
            // Nothing to do;
        }

    }while(genderValidation(newPerson->gender));
}

int genderValidation (char *gender) {
    int genderLenght = strlen(gender);

    if ((gender[0] != 'f' && gender[0] != 'm') || genderLenght > 1){
        return 1;
    } else {
        return 0;
    }
}
