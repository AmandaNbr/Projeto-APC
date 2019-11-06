#include <stdio.h>
#include <stdlib.h>

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
    printf("Escolha uma das opcoes abaixo:\n");
    printf("1 - Cadastrar Estado\n");
    printf("2 - Cadastrar curso\n");
    printf("3 - Cadastrar Pessoa\n");
    printf("4 - Listar pessoas por Estado\n");
    printf("5 - Listar pessoas por Curso Desejado\n");
    printf("6 - Consultar Pessoa por Nome\n");
    printf("7 - Gerar relatório demográfico\n");
    printf("8 - Finalizar Programa\n");
}

int chooseOption()
{
    int option;

    scanf("%d", &option);

    switch(option)
    {
    case 1:

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
    }
}
