#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registerCourse() {
    printf("Informe o curso a ser cadastrado:\n");

    char course[100];
	fgets(course, 100, stdin);
	fflush(stdin);

	trim(course, NULL);

	convertToLowercase(course);

	storeCourse(course);

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

void storeCourse (char currentCourse[]) {
    char readCourse[100];
    int alreadyRegistered = 0;

    FILE *coursesFile;
    coursesFile = fopen("courses.txt", "a+");

    while(fgets(readCourse, sizeof(readCourse), coursesFile) != NULL) {
            printf("%s readcourse\n", readCourse);
            printf("%s current\n", currentCourse);
        if (strcmp(readCourse, currentCourse) == 0) {
            alreadyRegistered = 1;
        } else {
            //Nada a fazer.
        }
    }

    if (alreadyRegistered) {
        printf("\nEste curso ja esta cadastrado.\n");
    } else {
        fprintf(coursesFile, "\n%s", currentCourse);
        printf("\nCurso cadastrado com sucesso!\n");
    }

    fclose(coursesFile);
}
