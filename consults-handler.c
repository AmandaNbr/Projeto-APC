#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listPersonByState() {
    int stringIsEmptyValidation = 0, alreadyExistsValidation = 0;
    char readState[3];

    printf("Informe o Estado: ");

    fgets(readState, 3, stdin);
    fflush(stdin);

    convertToLowercase(readState);
    trim(readState, NULL);

    stringIsEmptyValidation = stringIsEmpty(readState);
    if (stringIsEmptyValidation){
        printf("Estado nulo, informe um Estado valido.\n");
    } else {
        alreadyExistsValidation = alreadyRegisteredStateValidation(readState);
        if (alreadyExistsValidation){
            printf("Estado nao cadastrado.\n");
        } else {
            //Nothing to do
        }
    }

    printf("\nAperte ENTER para voltar ao menu.\n");
    fgetc(stdin);
}
