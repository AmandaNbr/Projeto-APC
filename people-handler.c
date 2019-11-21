#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//nome completo, sexo, data de nascimento, curso desejado e unidade da federação

void registerPerson();
void nameValidation();

struct Person {
    char fullName[100];
    char gender;
    int birthDate[3];
    char wantedCourse[100];
    char state[3];
};

void getName(struct Person *);

void registerPerson() {
    struct Person *newPerson;
    newPerson = (struct Person*) malloc(sizeof(struct Person));

    getName(newPerson);
    printf("\n%s\n", newPerson->fullName);

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
    free(newPerson);
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
