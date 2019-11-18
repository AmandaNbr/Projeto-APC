#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int option;

    do {
        showMenu();
        printf("\n");
        option = chooseOption();
    } while (option != 8);

    return 0;
}

void showMenu()
{
    system("cls");
    printf("Escolha uma das opcoes abaixo:\n");
    printf("1 - Cadastrar Estado\n");
    printf("2 - Cadastrar curso\n");
    printf("3 - Cadastrar Pessoa\n");
    printf("4 - Listar pessoas por Estado\n");
    printf("5 - Listar pessoas por Curso Desejado\n");
    printf("6 - Consultar Pessoa por Nome\n");
    printf("7 - Gerar relatario demografico\n");
    printf("8 - Finalizar Programa\n");
}

int chooseOption()
{
    int option;

    scanf("%d", &option);
    fflush(stdin);
    system("cls");

    switch(option)
    {
    case 1:
        registerState();
        return 1;
    case 2:
        registerCourse();
        return 2;
    case 3:

        return 3;
    case 4:

        return 4;
    case 5:

        return 5;
    case 6:

        return 6;
    case 7:

        return 7;
    case 8:

        return 8;
    default:
        printf("Opcao invalida. (Aperte ENTER para voltar ao menu)\n");
        fgetc(stdin);
        fflush(stdin);
        return 0;;
    }
}

registerState()
{
    printf("Informe a sigla da Unidade Federativa a ser cadastrada:\n");

    char receivedState[3];
	fgets(receivedState, 5, stdin);
	fflush(stdin);

    if (lengthValidation(receivedState) == 1) {
        char state[3];
        state[0] = receivedState[0];
        state[1] = receivedState[1];
        state[2] = '\0';

        convertToLowercase(state);

        if (stateValidation(state) == 1) {
            storeState(state);
        } else {
            printf("\nO Estado informado nao existe.\n");
        }
    } else {
        printf("\nSigla de Estado invalida.\n");
    }

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}

void convertToLowercase(char text[]) {
   int c = 0;

   while (text[c] != '\0') {
      if (text[c] >= 'A' && text[c] <= 'Z') {
         text[c] = text[c] + 32;
      }
      c++;
   }
}

int stateValidation(char currentState[]) {
    char readState[3];
    FILE *validationFile;

    validationFile = fopen("statesValidation.txt", "r");
    if (validationFile == NULL) {
        printf("\nArquivo de validação de Estados não existe.\n");
        exit(1);
    }

    while(fgets(readState, sizeof(readState), validationFile) != NULL) {
        if (strcmp(readState, currentState) == 0) {
            return 1;
        } else {
            //Nada a fazer.
        }
    }
    return 0;
}

int lengthValidation(char currentState[]) {
	int receivedStateLength = strlen(currentState);

	if (receivedStateLength == 3){
        return 1;
	} else {
        return 0;
	}
}

void storeState (char currentState[]) {
    char readState[3];
    int alreadyRegistered = 0;

    FILE *statesFile;
    statesFile = fopen("states.txt", "a+");

    while(fgets(readState, sizeof(readState), statesFile) != NULL) {
        if (strcmp(readState, currentState) == 0) {
            alreadyRegistered = 1;
        } else {
            //Nada a fazer.
        }
    }

    if (alreadyRegistered) {
        printf("\nEste Estado ja esta cadastrado.\n");
    } else {
        fprintf(statesFile, "%s\n", currentState);
        printf("\nEstado cadastrado com sucesso!\n");
    }

    fclose(statesFile);
}

void registerCourse() {
    printf("Informe o curso a ser cadastrado:\n");

    char course[100];
	fgets(course, 100, stdin);
	fflush(stdin);

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
        if (strcmp(readCourse, currentCourse) == 0) {
            alreadyRegistered = 1;
        } else {
            //Nada a fazer.
        }
    }

    if (alreadyRegistered) {
        printf("\nEste curso ja esta cadastrado.\n");
    } else {
        fprintf(coursesFile, "%s", currentCourse);
        printf("\nCurso cadastrado com sucesso!\n");
    }

    fclose(coursesFile);
}
