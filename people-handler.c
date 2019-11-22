#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//nome completo, sexo, data de nascimento, curso desejado e unidade da federação

void registerPerson();
void nameValidation();

struct Person {
    char fullName[100];
    char gender[2];
    int birthdate[3];
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

    printf("\nInforme a data de nascimento:\n");
    getBirthdate(newPerson);

    printf("\nInforme o curso desejado:\n");
    getWantedCourse(newPerson);

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
    free(newPerson);;
}

void getName(struct Person *newPerson) {
    int validation = 0;
    do{
        fgets(newPerson->fullName, 100, stdin);
        fflush(stdin);

        convertToLowercase(newPerson->fullName);
        trim(newPerson->fullName, NULL);

        validation = stringIsEmpty(newPerson->fullName);

        if (stringIsEmpty(newPerson->fullName)){
            printf("Nome nulo, informe um nome valido.\n");
        } else {
            // Nothing to do;
        }

    }while(stringIsEmpty(newPerson->fullName));
}

void getGender(struct Person *newPerson) {
    int validation = 0;
    do{
        fgets(newPerson->gender, 50, stdin);
        fflush(stdin);

        convertToLowercase(newPerson->gender);
        trim(newPerson->gender, NULL);

        validation = genderValidation(newPerson->gender);

        if (validation){
            printf("Genero invalido, informe 'M' ou 'F'.\n");
        } else {
            // Nothing to do;
        }

    }while(validation);
}

int genderValidation (char *gender) {
    int genderLenght = strlen(gender);

    if ((gender[0] != 'f' && gender[0] != 'm') || genderLenght > 1){
        return 1;
    } else {
        return 0;
    }
}

void getBirthdate (struct Person *newPerson) {
    int validation = 0;
    do{
        printf("Dia: ");
        scanf("%d", &newPerson->birthdate[0]);
        fflush(stdin);
        printf("%d\n", newPerson->birthdate[0]);

        printf("Mes: ");
        scanf("%d", &newPerson->birthdate[1]);
        fflush(stdin);
        printf("%d\n", newPerson->birthdate[1]);

        printf("Ano: ");
        scanf("%d", &newPerson->birthdate[2]);
        fflush(stdin);
        printf("%d\n", newPerson->birthdate[2]);

        validation = birthdateValitation(newPerson->birthdate);
        if (validation){
            printf("\nData invalida, informe uma data existente.\n");
        } else {
            // Nothing to do;
        }

    }while(validation);
}

int birthdateValitation (int *birthdate) {

    printf("\n%d/%d/%d\n", birthdate[0], birthdate[1], birthdate[2]);

    //Validate year
    if (birthdate[2] <= 0 || birthdate[2] >= 2020){
        printf("\n1\n");
        return 1;
    }

    //Validate month
    if (birthdate[1] <= 0 || birthdate[1] > 12) {
        printf("\n2\n");
        return 1;
    }

    //Validate months with 31 days
    if (birthdate[1] == 1 || birthdate[1] == 3 || birthdate[1] == 5 || birthdate[1] == 7 || birthdate[1] ==  8 || birthdate[1] == 10 || birthdate[1] == 12) {
        if (birthdate[0] <= 0 || birthdate[0] >31) {
            printf("\n3\n");
            return 1;
        }
    }

    //Validate months with 30 days
    if (birthdate[0] == 4 || birthdate[0] == 6 || birthdate[0] == 9 || birthdate[0] == 11) {
        if (birthdate[1] <= 0 || birthdate[1] > 30) {
            printf("\n4\n");
            return 1;
        }
    }

    //Validate leap year
    if (birthdate[1] == 2) {
        if (birthdate[2] % 4 == 0 && birthdate[2] % 100 != 0 || birthdate[2] % 400 == 0) {
            if (birthdate[0] <= 0 || birthdate[0] > 29) {
                printf("\n5\n");
                return 1;
            }
        } else {
            if (birthdate[0] <= 0 || birthdate[0] > 28) {
                printf("\n6\n");
                return 1;
            }
        }
    }

    //It's all ok
    return 0;
}

void getWantedCourse(struct Person *newPerson){
    int stringIsEmptyValidation = 0, alreadyExistsValidation = 0;

	do {
        fgets(newPerson->wantedCourse, 100, stdin);
        fflush(stdin);

        convertToLowercase(newPerson->wantedCourse);
        trim(newPerson->wantedCourse, NULL);

        stringIsEmptyValidation = stringIsEmpty(newPerson->wantedCourse);
        if (stringIsEmptyValidation){
            printf("Curso nulo, informe um curso valido.\n");
        } else {
            alreadyExistsValidation = wantedCouseValidation(newPerson->wantedCourse);
            if (alreadyExistsValidation){
                printf("Curso nao cadastrado.\n");
            } else {
                //Nothing to do
            }
        }
	} while (alreadyExistsValidation || stringIsEmptyValidation);
}

int wantedCouseValidation (char *wantedCouse) {
    char readCourse[100];

    FILE *coursesFile;
    coursesFile = fopen("courses.txt", "r");

    while(fgets(readCourse, sizeof(readCourse), coursesFile) != NULL) {
        trim(readCourse, NULL);
        if (strcmp(readCourse, wantedCouse) == 0) {
            return 0;
        } else {
            //Nada a fazer.
        }
    }
    return 1;
}
