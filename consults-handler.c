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
        if (strstr(readPerson->fullName, readName) == NULL) {
            //Nothing to do
        } else {
            printPerson(readPerson);
            foundPerson++;
        }
    }
    if (!foundPerson) {
        printf("\nNome nao cadastrado.\n");
    } else if (foundPerson == 1) {
        showDeleteOption();
        getDeleteOption();
    }
}

void showDeleteOption() {
    printf("\nDeseja deletar esse cadastro?\n");
    printf("1 - Sim.\n");
    printf("2 - Nao.\n");
    printf("\n");
}

void getDeleteOption() {
    int option;

    scanf("%d", &option);
    fflush(stdin);

    switch(option)
    {
    case 1:
        system("cls");
        break;
    case 2:
        //Nothing to do
        break;
    }
}

void generateRelatory() {

    showOptionMenu();
    printf("\n");
    getOption();

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

void showOptionMenu() {
    system("cls");
    printf("Escolha uma das opcoes abaixo:\n");
    printf("1 - Percentual de pessoas de 15 a 20 anos.\n");
    printf("2 - Percentual de pessoas de 21 a 25 anos.\n");
    printf("3 - Percentual de pessoas de 26 a 30 anos.\n");
    printf("4 - Percentual de pessoas acima de 30 anos.\n");
    printf("5 - Percentual de pessoas de sexo masculino.\n");
    printf("6 - Percentual de pessoas de sexo feminino.\n");
}

void getOption() {
    int option;

    scanf("%d", &option);
    fflush(stdin);
    system("cls");

    switch(option)
    {
    case 1:
        calculatePercentageAge(15, 20);
        break;
    case 2:
        calculatePercentageAge(21, 25);
        break;
    case 3:
        calculatePercentageAge(26, 30);
        break;
    case 4:
        calculatePercentageAge(31, 100);
        break;
    case 5:
        calculatePercentageGender("m");
        break;
    case 6:
        calculatePercentageGender("f");
        break;
    default:
        printf("Opcao invalida.\n");
        fflush(stdin);
        return 0;
    }
}

void calculatePercentageAge (int minAgeRange, int maxAgeRange) {
    char line[256];
    float totalPerson = 0, percentagePerson = 0;
    int age = 0;
    struct Person *readPerson;
    readPerson = (struct Person*) malloc(sizeof(struct Person));

    FILE *personFile;
    personFile = fopen("people.txt", "r");

    while(fgets(line, sizeof(line), personFile) != NULL) {
        if (strcmp(line,"\n") != 0) {
            totalPerson++;
            formatPersonStructData(readPerson, line);
            age = findAge(readPerson->birthdate);
            if (age >= minAgeRange && age <= maxAgeRange) {
                percentagePerson++;
            } else {
                //Nothing to do
            }
        }
    }
    if (!percentagePerson) {
        printf("\nNao existe pessoa cadastrada com esse intervalo de idades.\n");
    } else {
        printf("De um total de %.f cadastros, a porcentagem de pessoas cadastradas entre %d e %d anos e de %.2f%%\n", totalPerson, minAgeRange, maxAgeRange,(percentagePerson / totalPerson)*100);
    }
}

void calculatePercentageGender(char *gender) {
    char line[256];
    float totalPerson = 0, percentagePersonMale = 0, percentagePersonFemale = 0;
    struct Person *readPerson;
    readPerson = (struct Person*) malloc(sizeof(struct Person));

    FILE *personFile;
    personFile = fopen("people.txt", "r");

    while(fgets(line, sizeof(line), personFile) != NULL) {
        if (strcmp(line,"\n") != 0) {
            totalPerson++;
            formatPersonStructData(readPerson, line);
            if (strcmp(readPerson->gender, gender) == 0) {
                if (gender == "m") {
                    percentagePersonMale++;
                } else if (gender == "f") {
                    percentagePersonFemale++;
                }
            }
        }
    }
    if (!percentagePersonMale && !percentagePersonFemale) {
        printf("\nNao existe pessoa cadastrada com esse sexo.\n");
    } else if (gender == "m") {
        printf("A porcentagem de pessoas cadastradas de sexo masculino: %.2f%%\n",  (percentagePersonMale / totalPerson)*100);
    } else if (gender == "f") {
        printf("A porcentagem de pessoas cadastradas de sexo feminino: %.2f%%\n",  (percentagePersonFemale / totalPerson)*100);
    }
}
