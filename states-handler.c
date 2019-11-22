#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registerState();
int stateValidation(char currentState[]);
int lengthValidation(char currentState[]);
void storeState(char currentState[]);


void registerState() {
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

void storeState(char currentState[]) {
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
