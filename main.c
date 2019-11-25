/*De acordo com as políticas de entrega de atividades repassadas pelo professor,
certifico que os algoritmos e programas que estou entregando são de minha autoria e
que não os repassei ou os recebi de qualquer outra pessoa. Amanda Jeniffer Pereira Nobre - 19/0124997 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.c"
#include "states-handler.c"
#include "courses-handler.c"
#include "people-handler.c"
#include "consults-handler.c"

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

//Print all the 8 options for user to choose
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

//Based on the user chose option this function will validate if the number gave by the user is between
//1 and 8, after that, will call and validate the procedure
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
        if (stateExists() && courseExists()) {
            registerPerson();
        } else {
            printf("Nao ha nenhum Estado ou curso cadastrado, tente cadastra-los antes de realizar essa operacao.\n");
            printf("\nAperte ENTER para voltar ao menu.\n");
            fgetc(stdin);
        }
        return 3;
    case 4:
        if (stateExists()) {
            listPersonByState();
        } else {
            printf("Nao ha nenhum Estado cadastrado, tente cadastrar um Estado antes de realizar essa operacao.\n");
            printf("\nAperte ENTER para voltar ao menu.\n");
            fgetc(stdin);
        }
        return 4;
    case 5:
        if (courseExists()) {
            listPersonByCourse();
        } else {
            printf("Nao ha nenhum curso cadastrado, tente cadastrar um curso antes de realizar essa operacao.\n");
            printf("\nAperte ENTER para voltar ao menu.\n");
            fgetc(stdin);
        }
        return 5;
    case 6:
        if (personExists()) {
            consultPerson();
        } else {
            printf("Nao ha nenhuma pessoa cadastrada, tente cadastrar uma pessoa antes de realizar essa operacao.\n");
            printf("\nAperte ENTER para voltar ao menu.\n");
            fgetc(stdin);
        }
        return 6;
    case 7:
        if (personExists()) {
            generateRelatory();
        } else {
            printf("Nao ha nenhuma pessoa cadastrada, tente cadastrar uma pessoa antes de realizar essa operacao.\n");
            printf("\nAperte ENTER para voltar ao menu.\n");
            fgetc(stdin);
        }
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
