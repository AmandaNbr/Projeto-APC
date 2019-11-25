void registerPerson();
void getName(struct Person *newPerson);
void getGender(struct Person *newPerson);
int genderValidation(char *gender);
void getBirthdate(struct Person *newPerson);
int birthdateValitation(int *birthdate);
void getWantedCourse(struct Person *newPerson);
int wantedCouseValidation(char *wantedCouse);
void getState(struct Person *newPerson);
int alreadyRegisteredStateValidation(char *state);
void storePerson(struct Person *newPerson);

//Print the informations and calls the related functions to validate the data
void registerPerson() {
    struct Person *newPerson;
    newPerson = (struct Person*) malloc(sizeof(struct Person));

    printf("Informe o nome completo:\n");
    getName(newPerson);

    printf("\nInforme o sexo (M/F):\n");
    getGender(newPerson);

    printf("\nInforme a data de nascimento:\n");
    getBirthdate(newPerson);

    printf("\nInforme o curso desejado:\n");
    getWantedCourse(newPerson);

    printf("\nInforme o Estado:\n");
    getState(newPerson);

    storePerson(newPerson);

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
    free(newPerson);;
}

//Read the name, convert to lower case, trim and check if it's empty
void getName(struct Person *newPerson) {
    int validation = 0;
    do{
        fgets(newPerson->fullName, 100, stdin);
        fflush(stdin);

        convertToLowercase(newPerson->fullName);
        trim(newPerson->fullName, NULL);

        validation = stringIsEmpty(newPerson->fullName);

        if (validation){
            printf("Nome nulo, informe um nome valido.\n");
        } else {
            // Nothing to do;
        }

    }while(validation);
}

//Read the gender, convert to lower case, trim and calls the validation function
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

//Validate if it's one of the characters asked
int genderValidation(char *gender) {
    int genderLenght = strlen(gender);

    if ((gender[0] != 'f' && gender[0] != 'm') || genderLenght > 1){
        return 1;
    } else {
        return 0;
    }
}

//Read the birth date and calls the validation function
void getBirthdate(struct Person *newPerson) {
    int validation = 0;
    do{
        printf("Dia: ");
        scanf("%d", &newPerson->birthdate[0]);
        fflush(stdin);

        printf("Mes: ");
        scanf("%d", &newPerson->birthdate[1]);
        fflush(stdin);

        printf("Ano: ");
        scanf("%d", &newPerson->birthdate[2]);
        fflush(stdin);

        validation = birthdateValitation(newPerson->birthdate);
        if (validation){
            printf("\nData invalida, informe uma data existente.\n");
        } else {
            // Nothing to do;
        }

    }while(validation);
}

//Validate if the date given is valid
int birthdateValitation(int *birthdate) {
    //Validate year
    if (birthdate[2] <= 1899 || birthdate[2] >= 2020){
        return 1;
    }

    //Validate month
    if (birthdate[1] <= 0 || birthdate[1] > 12) {
        return 1;
    }

    //Validate months with 31 days
    if (birthdate[1] == 1 || birthdate[1] == 3 || birthdate[1] == 5 ||
        birthdate[1] == 7 || birthdate[1] ==  8 || birthdate[1] == 10 || birthdate[1] == 12) {
        if (birthdate[0] <= 0 || birthdate[0] >31) {
            return 1;
        }
    }

    //Validate months with 30 days
    if (birthdate[0] == 4 || birthdate[0] == 6 || birthdate[0] == 9 || birthdate[0] == 11) {
        if (birthdate[1] <= 0 || birthdate[1] > 30) {
            return 1;
        }
    }

    //Validate leap year
    if (birthdate[1] == 2) {
        if ((birthdate[2] % 4 == 0 && birthdate[2] % 100 != 0) || birthdate[2] % 400 == 0) {
            if (birthdate[0] <= 0 || birthdate[0] > 29) {
                return 1;
            }
        } else {
            if (birthdate[0] <= 0 || birthdate[0] > 28) {
                return 1;
            }
        }
    }

    //It's all ok
    return 0;
}

//Read the name, convert to lower case, trim, check if it's empty and if already is registered
void getWantedCourse(struct Person *newPerson) {
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

//Opens the courses registered file and check if the given course is registered
int wantedCouseValidation(char *wantedCouse) {
    char readCourse[100];

    FILE *coursesFile;
    coursesFile = fopen("courses.txt", "r");

    while(fgets(readCourse, sizeof(readCourse), coursesFile) != NULL) {
        trim(readCourse, NULL);
        if (strcmp(readCourse, wantedCouse) == 0) {
            fclose(coursesFile);
            return 0;
        } else {
            //Nada a fazer.
        }
    }
    fclose(coursesFile);
    return 1;
}

//Read the state acronym, convert to lower case, trim, check the array length and if already is registered
void getState(struct Person *newPerson) {
    int stringLenghtValidation = 0, alreadyExistsValidation = 0;

	do {
        fgets(newPerson->state, 5, stdin);
        fflush(stdin);

        convertToLowercase(newPerson->state);
        trim(newPerson->state, NULL);

        stringLenghtValidation = stateLengthValidation(newPerson->state);
        if (!stringLenghtValidation){
            printf("Sigla de Estado invalida, informe uma sigla valida.\n");
        } else {
            alreadyExistsValidation = alreadyRegisteredStateValidation(newPerson->state);
            if (alreadyExistsValidation){
                printf("Estado nao cadastrado.\n");
            } else {
                //Nothing to do
            }
        }
	} while (alreadyExistsValidation || !stringLenghtValidation);
}

//Opens the states registered file and check if the given state is registered
int alreadyRegisteredStateValidation(char *state) {
    char readState[3];

    FILE *statesFile;
    statesFile = fopen("states.txt", "r");

    while(fgets(readState, sizeof(readState), statesFile) != NULL) {
        if (strcmp(readState, state) == 0) {
            fclose(statesFile);
            return 0;
        } else {
            //Nada a fazer.
        }
    }
    fclose(statesFile);
    return 1;
}

//After reading all the data will open or create a file and store a person
void storePerson(struct Person *newPerson) {
    FILE *personFile;
    personFile = fopen("people.txt", "a+");

    fprintf(personFile, "%s|%s|%d/%d/%d|%s|%s\n",
            newPerson->fullName,
            newPerson->gender,
            newPerson->birthdate[0],
            newPerson->birthdate[1],
            newPerson->birthdate[2],
            newPerson->wantedCourse,
            newPerson->state);

    printf("\nPessoa cadastrada com sucesso!\n");

    fclose(personFile);
}
