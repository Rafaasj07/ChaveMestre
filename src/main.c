#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

int main()
{
    /* Formata o terminal/console para que o mesmo tenha 80 colunas e 25 linhas (IBM),
    para o uso da funcao ir_para() e bordas()*/
    system("mode con:cols=80 lines=25");

    char menu_usuario;

    Cadastro dados; // Instancia da minha struct Cadastro. É aqui q tudo é salvo.

    // Opcoes do menu principal
    bordas();
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c          Menu Principal         %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

    ir_para(23, 9);
    printf("            1. MENU USUARIO            ");
    ir_para(23, 10);
    printf("         2. MENU ADMINISTRADOR         ");
    ir_para(23, 11);
    printf("                3. SAIR                ");
    ir_para(26, 13);
    printf("Digite a opcao que deseja: ");

    scanf("%c", &dados.menu_principal);
    apaga_buffer();
    switch (dados.menu_principal)
    {
    case '1': // Usuario
        // Opcoes do menu do usuario
        limpar();
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c           Menu Usuario          %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        ir_para(21, 9);
        printf("       1. CADASTRO            ");
        ir_para(21, 10);
        printf("       2. FAZER LOGIN          ");
        ir_para(21, 11);
        printf("       3. RECUPERACAO DE SENHA     ");
        ir_para(21, 12);
        printf("       4. SAIR    ");
        ir_para(26, 14);
        printf("Digite a opcao que deseja: ");
        scanf("%c", &menu_usuario);
        apaga_buffer();

        switch (menu_usuario)
        {
        case '1':
            inicializar_arquivo(dados.menu_principal);
            cadastro(&dados);
            incluir_dados(&dados); // Preenche os dados
            ir_para(33, 15);
            printf("\033[1;32mUsuario Cadastrado.\033[0m");

            char quer_login;
            do
            {
                ir_para(33, 17);
                printf("Deseja fazer login?");
                ir_para(30, 18);
                printf("[1] SIM ou [2] NAO : ");
                scanf("%c", &quer_login);
                apaga_buffer();
                switch (quer_login)
                {
                case '1':
                    login(&dados); // Se o usuario quiser login depois de cadastro, chama a funcao de login
                    break;
                case '2':
                    ir_para(32, 20);
                    printf("\033[1;31mSaindo do programa...\033[0m");
                    break;
                default:
                    ir_para(34, 20);
                    printf("\033[1;31mDIGITO INVALIDO!\033[0m");
                    break;
                }
            } while (quer_login != '1' && quer_login != '2');

            break;
        case '2':
            login(&dados);
            break;
        case '3':
            recuperar_senha(&dados);
            break;

        case '4':
            ir_para(32, 16);
            printf("\033[1;31mSaindo do programa...\033[0m");
            exit(0);
        default:
            ir_para(32, 16);
            printf("\033[1;31mDIGITO INVALIDO!\033[0m");
            break;
        }
        break;

    case '2': // Administrador
        // Opções do menu do administrador
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c        Menu Administrador       %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        ir_para(21, 9);
        printf("           1. CADASTRAR ADMINISTRADOR           ");
        ir_para(21, 10);
        printf("           2. LOGIN ADMINISTRADOR            ");
        ir_para(21, 11);
        printf("           3. RECUPERAR SENHA ADM          ");
        ir_para(21, 12);
        printf("           4. SAIR         ");
        ir_para(26, 13);
        printf("                                     ");
        ir_para(26, 14);
        printf("Digite a opcao que deseja: ");
        char menu_adm;
        scanf("%c", &menu_adm);
        apaga_buffer();

        switch (menu_adm)
        {
        case '1': // Cadastro adm
            inicializar_arquivo(dados.menu_principal);
            cadastro(&dados);
            incluir_dados(&dados); // Preenche os dados
            ir_para(31, 15);
            printf("\033[1;32mAdministrador Cadastrado.\033[0m\n");

            char quer_login;
            do
            {
                ir_para(33, 17);
                printf("Deseja fazer login?");
                ir_para(30, 18);
                printf("[1] SIM ou [2] NAO : ");
                scanf("%c", &quer_login);
                apaga_buffer();
                switch (quer_login)
                {
                case '1': // Login dentro de Cadastro de adm
                    login(&dados); // Se o administrador quiser login depois de cadastro, chama a funcao de login
                    adm_funcoes(&dados);
                    break;
                case '2': // Não quer fazer login agora
                    ir_para(32, 20);
                    printf("\033[1;31mSaindo do programa...\033[0m");
                    break;
                default:
                    ir_para(34, 20);
                    printf("\033[1;31mDIGITO INVALIDO!\033[0m");
                    break;
                }
            } while (quer_login != '1' && quer_login != '2');

            break;

        case '2': // Login adm
            login(&dados);
            adm_funcoes(&dados);
            break;

        case '3':
            recuperar_senha(&dados);
            break;
        case '4':
            ir_para(38, 17);
            printf("\33[2K\r");
            ir_para(32, 16);
            printf("\033[1;31mSaindo do programa...\033[0m");
            exit(0);
            break;
        default:
            ir_para(34, 15);
            printf("\033[1;31mDIGITO INVALIDO!\033[0m");
            break;
        }
        break;

    case '3': // Sair
        ir_para(32, 15);
        printf("\033[1;31mSaindo do programa...\033[0m");
        break;
    default:
        ir_para(34, 15);
        printf("\033[1;31mDIGITO INVALIDO!\033[0m");
        break;
    }
    return 0;
}
