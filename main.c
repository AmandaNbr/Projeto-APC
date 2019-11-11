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

    char state[3];
	fgets(state, 3, stdin);
	fflush(stdin);

	convertToLowercase(state);

	storeState(state);
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

void storeState (char currentState[]) {
    char readState[3];
    int alreadyRegistered = 0;

    FILE *statesFile;
    statesFile = fopen("states.txt", "a+");

    while(fgets(readState, sizeof(readState), statesFile) != NULL) {
        printf("%s", readState);
        if (strcmp(readState, currentState) == 0) {
            printf("\neh igual\n");
            alreadyRegistered = 1;
        } else {
            printf("\nn eh igual.\n");
            //Nada a fazer.
        }
    }

    if (alreadyRegistered) {
        printf("\nEste Estado ja cadastrado.\n");
    } else {
        // Escrever no arquivo
        printf("\nEstado cadastrado com sucesso!\n");
    }

    printf("\nAperte ENTER para voltar ao menu.\n");

    fgetc(stdin);
    fclose(statesFile);

}
