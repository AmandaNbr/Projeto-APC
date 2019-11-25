void calculatePercentageGender(char *gender);
void calculatePercentageAge (int minAgeRange, int maxAgeRange);
void showOptionMenu();
void getOption();
void generateRelatory();
void showDeleteOption();
void getDeleteOption(char *lineToBeDeleted);
void printPersonByName(char* readName);
void getStateToList(char* readState);
int validateStateToList(char* readState);
void printPersonByState(char *readState);
void getCourseToList(char* readCourse);
void printPersonByCourse(char* readCourse);
void getNameToConsult(char* readName);
void listPersonByState();
void listPersonByCourse();
void consultPerson();

//It's the main procedure of the list by state function, organizing and calling other functions
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

//Read the given state and convert to lower case
void getStateToList(char* readState){
    printf("Informe o Estado: ");

    fgets(readState, 5, stdin);
    fflush(stdin);

    convertToLowercase(readState);
    trim(readState, NULL);
}

//Validate the length of the state array and if it's already registered
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

//Runs through the file comparing the given state and the registered state, printing the people with the
//same state or returning a validation message
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
        fclose(personFile);
}

//It's the main procedure of the list by course function, organizing and calling other functions
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

//Read the given course and convert to lower case
void getCourseToList(char* readCourse) {
    printf("Informe o curso: ");

    fgets(readCourse, 100, stdin);
    fflush(stdin);

    convertToLowercase(readCourse);
    trim(readCourse, NULL);
}

//Runs through the file comparing the given course and the registered course, printing the people with the
//same course or returning a validation message
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
    fclose(personFile);
}

//It's the main procedure of the consult person function, organizing, calling other functions and validating
void consultPerson(){
    char readName[100];

    getNameToConsult(readName);

    if(stringIsEmpty(readName)){
        printf("\nNome nao cadastrado.\n");
    }else{
        printPersonByName(readName);
    }

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

//Read the given person name and convert to lower case
void getNameToConsult(char* readName) {
    printf("Informe o Nome: ");

    fgets(readName, 100, stdin);
    fflush(stdin);

    convertToLowercase(readName);
    trim(readName, NULL);
}

//Runs through the file comparing the given name, printing the people with the same name or names inside other names
//it only find one registered person it will call the delete function
void printPersonByName(char* readName){
    char line[256];
    char lineToBeDeleted[256];
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
            strcpy(lineToBeDeleted, line);
            printPerson(readPerson);
            foundPerson++;
        }
    }
    fclose(personFile);

    if (!foundPerson) {
        printf("\nNome nao cadastrado.\n");
    } else if (foundPerson == 1) {
        showDeleteOption();
        getDeleteOption(lineToBeDeleted);
    }
}

//Print the question and the options to the user
void showDeleteOption() {
    printf("\nDeseja deletar esse cadastro?\n");
    printf("1 - Sim.\n");
    printf("2 - Nao.\n");
    printf("\n");
}

//Read the answer and calls what the user wants
void getDeleteOption(char *lineToBeDeleted) {
    int option;

    scanf("%d", &option);
    fflush(stdin);

    switch(option)
    {
    case 1:
        system("cls");
        deletePerson(lineToBeDeleted);
        break;
    case 2:
        //Nothing to do
        break;
    }
}

//It's the main procedure of the generate relatory function, organizing and calling other functions
void generateRelatory() {

    showOptionMenu();
    printf("\n");
    getOption();

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

////Print all the 6 options for user to choose
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

//Reads the option and calls the procedure based on what the user chose
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
        break;
    }
}

//Runs through the file counting the number of people with the age between the parameters and the total of registered people
//validating if there isn't people with the desired ages and calculating the percentage
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
    fclose(personFile);
}

//Runs through the file counting the number of people with the asked gender and the total of registered people
//validating if there isn't people with the desired gender and calculating the percentage
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
                if (strcmp(gender, "m") == 0) {
                    percentagePersonMale++;
                } else if (strcmp(gender, "f") == 0) {
                    percentagePersonFemale++;
                }
            }
        }
    }
    if (!percentagePersonMale && !percentagePersonFemale) {
        printf("\nNao existe pessoa cadastrada com esse sexo.\n");
    } else if (strcmp(gender, "m") == 0) {
        printf("A porcentagem de pessoas cadastradas de sexo masculino e de %.2f%%\n",  (percentagePersonMale / totalPerson)*100);
    } else if (strcmp(gender, "f") == 0) {
        printf("A porcentagem de pessoas cadastradas de sexo feminino e de %.2f%%\n",  (percentagePersonFemale / totalPerson)*100);
    }
    fclose(personFile);
}
