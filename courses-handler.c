void registerCourse();
void storeCourse(char currentCourse[]);

//It's the main procedure of the register course option, organizing and calling other functions and printing validations
void registerCourse() {
    printf("Informe o curso a ser cadastrado:\n");

    char course[100];
	fgets(course, 100, stdin);
	fflush(stdin);

	trim(course, NULL);

	convertToLowercase(course);

	if (stringIsEmpty(course)){
        printf("Curso nulo, informe um curso valido.\n");
	} else {
        storeCourse(course);
	}

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

//Opens an archive and store the given course if it isn't already registered
void storeCourse(char currentCourse[]) {
    char readCourse[100];
    int alreadyRegistered = 0;

    FILE *coursesFile;
    coursesFile = fopen("courses.txt", "a+");

    while(fgets(readCourse, sizeof(readCourse), coursesFile) != NULL) {
        trim(readCourse, NULL);
        if (strcmp(readCourse, currentCourse) == 0) {
            alreadyRegistered = 1;
        } else {
            //Nada a fazer.
        }
    }

    if (alreadyRegistered) {
        printf("\nEste curso ja esta cadastrado.\n");
    } else {
        fprintf(coursesFile, "%s\n", currentCourse);
        printf("\nCurso cadastrado com sucesso!\n");
    }

    fclose(coursesFile);
}
