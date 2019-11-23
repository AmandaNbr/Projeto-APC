#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "states-handler.c"
#include "courses-handler.c"
#include "people-handler.c"
#include "consults-handler.c"
#include "utils.c"

void showMenu();
int chooseOption();

int main() {
    int option;

    do {
        showMenu();
        printf("\n");
        option = chooseOption();
    } while (option != 8);

    return 0;
}

void showMenu() {
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

int chooseOption() {
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
        registerPerson();
        return 3;
    case 4:
        listPersonByState();
        return 4;
    case 5:
        listPersonByCourse();
        return 5;
    case 6:
        consultPerson();
        return 6;
    case 7:

        return 7;
    case 8:
        //Nothing to do
        return 8;
    default:
        printf("Opcao invalida. (Aperte ENTER para voltar ao menu)\n");
        fgetc(stdin);
        fflush(stdin);
        return 0;;
    }
}
