#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//nome completo, sexo, data de nascimento, curso desejado e unidade da federação

struct Person {
    char fullName[100];
    char gender;
    int birthDate[3];
    char wantedCourse[100];
    char state[3];
};

void registerPerson() {
    struct Person newPerson;

    getName(&newPerson.state);

    printf("\n%s\n", newPerson.state);

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

void getName(char *state) {
    state = "df";
}

void nameValidation() {

}
