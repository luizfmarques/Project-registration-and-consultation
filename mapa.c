#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
// STATUS
#define A_FAZER 1
#define FAZENDO 2
#define CONCLUIDO 3
// GERENTE
#define MARIA 1
#define MARCOS 2
#define JOANA 3
#define RODRIGO 4
// URGENCIA
#define URGENTE 1
#define N_URGENTE 2
// CIDADE
#define CURITIBA 1
#define PINHAIS 2
#define PIRAQUARA 3
#define ARAUCARIA 4

struct Projeto {
    int codigo;
    char titulo[255];
    char descricao[255];
    int ano;
    int status;
    int gerente;
    int urgencia;
    int cidade;
    float comissao;
};

typedef struct Projeto Projeto;
struct Projeto cadastro[MAX];

void print_status(int status) {
    if (status == 1) {
        printf("\nStatus: A fazer");
    } else if (status == 2) {
        printf("\nStatus: Fazendo");
    } else if (status == 3) {
        printf("\nStatus: Concluido");
    }
}

void print_gerente(int gerente) {
    if (gerente == 1) {
        printf("\nGerente: Maria");
    } else if (gerente == 2) {
        printf("\nGerente: Marcos");
    } else if (gerente == 3) {
        printf("\nGerente: Joana");
    } else if (gerente == 4) {
        printf("\nGerente: Rodrigo");
    }
}

void print_urgencia(int urgencia) {
    if (urgencia == 1) {
        printf("\nUrgencia: Urgente");
    } else if (urgencia == 2) {
        printf("\nUrgencia: Não ha urgencia");
    }
}

void print_cidade(int cidade) {
    if (cidade == 1) {
        printf("\nCidade: Curitiba");
    } else if (cidade == 2) {
        printf("\nCidade: Pinhais");
    } else if (cidade == 3) {
        printf("\nCidade: Piraquara");
    } else if (cidade == 4) {
        printf("\nCidade: Araucaria");
    }
}

void print_proj(Projeto cadastro) {
    printf("Codigo: \n%d", cadastro.codigo);
    printf("Titulo: \n%s", cadastro.titulo);
    printf("Descricao: \n%s", cadastro.descricao);
    printf("Ano: \n%d", cadastro.ano);
    print_status(cadastro.status);
    print_gerente(cadastro.gerente);
    print_urgencia(cadastro.urgencia);
    print_cidade(cadastro.cidade);
    printf("\n%.2f\n", cadastro.comissao);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int i = 0;
    int j = 0;
    int escolha;
    char resposta = 's';

    system("cls");
    do {
        system("cls");
        printf("\n***************************************************");
        printf("\n*****************MENU PRINCIPAL********************");
        printf("\n***************************************************");
        printf("\n 1 - Cadastro");
        printf("\n 2 - Impressao");
        printf("\n 3 - Sair");
        printf("\n Escolha uma opcao do menu: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                system("cls");
                printf("\n***************************************");
                printf("\n*************CADASTRO******************");
                printf("\n***************************************\n");
                resposta = 's';
                while (resposta == 's' && i < MAX) {
                    printf("Criando codigo do projeto...\n");
                    cadastro[i].codigo = i + 1;
                    printf("Informe o titulo: ");
                    fflush(stdin);
                    gets(cadastro[i].titulo);
                    printf("Informe a descricao: ");
                    fflush(stdin);
                    gets(cadastro[i].descricao);
                    printf("Informe o ano: ");
                    fflush(stdin);
                    scanf("%d", &cadastro[i].ano);
                    printf(
                        "Informe o status:\n1 para 'A fazer'\n2 para 'Fazendo'\n3 para "
                        "'Concluido'\n");
                    fflush(stdin);
                    scanf("%d", &cadastro[i].status);
                    printf(
                        "Informe o gerente: \n1 para Maria\n2 para Marcos\n3 para Joana\n4 para "
                        "Rodrigo\n");
                    fflush(stdin);
                    scanf("%d", &cadastro[i].gerente);
                    printf("Informe se ha urgencia:\n1 para 'Urgente'\n2 para 'Nao ha urgencia'\n");
                    fflush(stdin);
                    scanf("%d", &cadastro[i].urgencia);
                    printf(
                        "Informe a cidade:\n1 para Curitiba\n2 para Pinhais\n3 para Piraquara\n4 "
                        "para Araucaria\n");
                    fflush(stdin);
                    scanf("%d", &cadastro[i].cidade);
                    printf("Informe a comissao: ");
                    fflush(stdin);
                    scanf("%f", &cadastro[i].comissao);

                    printf("Deseja realizar mais um cadastro?\n [s] para Sim\n [n] para Não\n");
                    fflush(stdin);
                    scanf("%c", &resposta);
                    i++;
                    if (resposta == 's') {
                        if (i >= MAX) {
                            printf("Cadastro com limite atingido.");
                            system("pause");
                            resposta = 'n';
                        }
                    }
                }
                break;
            case 2:
                system("cls");
                do {
                    system("cls");
                    printf("\n***************************************************");
                    printf("\n********************IMPRESSAO**********************");
                    printf("\n***************************************************\n");
                    printf("\n 1 - Todos os projetos");
                    printf("\n 2 - A fazer");
                    printf("\n 3 - Fazendo");
                    printf("\n 4 - Concluido");
                    printf("\n 5 - Urgente");
                    printf("\n 6 - Voltar");
                    printf("\n Escolha uma opcao do menu: ");
                    scanf("%d", &escolha);

                    switch (escolha) {
                        case 1:
                            system("cls");
                            printf("\n***************************************");
                            printf("\n*********TODOS OS PROJETOS*************");
                            printf("\n***************************************\n");
                            j = 0;
                            while (j < i) {
                                print_proj(cadastro[j]);
                                j++;
                            }

                            break;
                        case 2:
                            system("cls");
                            printf("\n***************************************");
                            printf("\n**************A FAZER******************");
                            printf("\n***************************************\n");
                            j = 0;
                            while (j < i) {
                                if (cadastro[j].status == A_FAZER) {
                                    print_proj(cadastro[j]);
                                }
                                j++;
                            }
                            break;
                        case 3:
                            system("cls");
                            printf("\n***************************************");
                            printf("\n**************FAZENDO******************");
                            printf("\n***************************************\n");
                            j = 0;
                            while (j < i) {
                                if (cadastro[j].status == FAZENDO) {
                                    print_proj(cadastro[j]);
                                }
                                j++;
                            }
                            break;
                        case 4:
                            system("cls");
                            printf("\n***************************************");
                            printf("\n*************CONCLUIDO*****************");
                            printf("\n***************************************\n");
                            j = 0;
                            while (j < i) {
                                if (cadastro[j].status == CONCLUIDO) {
                                    print_proj(cadastro[j]);
                                }
                                j++;
                            }
                            break;
                        case 5:
                            system("cls");
                            printf("\n***************************************");
                            printf("\n**************URGENTES*****************");
                            printf("\n***************************************\n");
                            j = 0;
                            while (j < i) {
                                if (cadastro[j].urgencia == URGENTE) {
                                    print_proj(cadastro[j]);
                                }
                                j++;
                            }
                            break;
                        case 6:
                            break;
                    }
                    system("Pause");
                } while (escolha != 6);
            case 3:
                printf("\nSaindo da Aplicacao\n");
                system("Pause");
                break;
            default:
                printf("\nA opcao nao existe!\n");
                system("Pause");
        }
    } while (escolha != 3);
    return 0;
}