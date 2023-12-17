/*
Para entregar esta atividade:

Crie um repositório no GitHub para esta atividade com o nome: LP-ATIVIDADE-V
Crie um arquivo com extensão .c para cada exercício
Faça upload dos arquivos no repositório 
Nesta atividade no Google Classroom, adicione o link para o repositório com os seus arquivos.

Objetivo: 
Crie um software com 4 funcionalidades para um sistema de gestão de vendas.

Equipe: Carlos Alexandre Barbosa dos Santos e Matheus Felipe Carvalho Souza
Turma: 88434
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Cliente
{
    char nome[200];
    float totaldecompra;
};

struct salgado
{
    char nome[200];
    float preco;
};

void exibirocard(struct salgado cardapio[], int tamanho)
{
    int i;
    printf("------ Card�pio ------\n");
    for (i = 0; i < tamanho; ++i)
    {
        printf("%d. %s - R$%.2f\n", i + 1, cardapio[i].nome, cardapio[i].preco);
    }
    printf("----------------------\n");
}

void cadasCliente(struct Cliente clientes[], int *numerosclientes)
{
    printf("Digite o nome do cliente que ser� cadastrado: ");
    scanf("%s", clientes[*numerosclientes].nome);
    clientes[*numerosclientes].totaldecompra = 0;
    (*numerosclientes)++;
    printf("Cliente cadastrado!\n");
}

void Vender(struct Cliente clientes[], int numerosclientes, struct salgado cardapio[], int tamanho)
{
    char nomedocliente[200];
    int icliente = -1;
    int i;

    printf("Digite o nome do cliente cadastrado: ");
    scanf("%s", nomedocliente);

    for (i = 0; i < numerosclientes; ++i)
    {
        if (strcmp(clientes[i].nome, nomedocliente) == 0)
        {
            icliente = i;
            break;
        }
    }

    if (icliente == -1)
    {
        printf("Cadastro n�o encontrado!\n");
        return;
    }

    int opcao;
    float total = 0;
    do
    {
        exibirocard(cardapio, tamanho);
        printf("Escolha o n�mero do salgado: ");
        printf("\nDigite 0 para sair do cadastro de vendas): ");
        scanf("%d", &opcao);

        if (opcao > 0 && opcao <= tamanho)
        {
            total += cardapio[opcao - 1].preco;
            printf("salgado %s adicionado ao carrinho.\n", cardapio[opcao - 1].nome);
        }
        else if (opcao != 0)
        {
            printf("Opc�o inv�lida!\n");
        }
    } while (opcao != 0);

    clientes[icliente].totaldecompra += total;
    printf("Venda realizada com sucesso!\n");
}

void exibirototaldecompras(struct Cliente clientes[], int numerosclientes)
{
    char nomedocliente[200];
    int i;
    printf("Digite o nome do cliente: ");
    scanf("%s", nomedocliente);

    for (i = 0; i < numerosclientes; ++i)
    {
        if (strcmp(clientes[i].nome, nomedocliente) == 0)
        {
            printf("Total de compras de %s: R$%.2f\n", clientes[i].nome, clientes[i].totaldecompra);
            return;
        }
    }

    printf("Cliente n�o encontrado!\n");
}

void exibirtotaldevendas(struct Cliente clientes[], int numerosclientes)
{
    float totaldevendas = 0;
    int i;
    for (i = 0; i < numerosclientes; ++i)
    {
        totaldevendas += clientes[i].totaldecompra;
    }
    printf("Total de vendas: R$%.2f\n", totaldevendas);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct salgado cardapio[3] = {
        {"Coxinha", 5.0},
        {"Quibe", 6.0},
        {"Empadinha", 7.5}};

    struct Cliente clientes[200];
    int numerosclientes = 0;
    int opcao;

    do
    {
        printf("\n .... Bem-vindo ao Salgado de salvador   ....\n");
        printf("|--------------------------------------------|");
        printf("\n|C�DGO |  MENU                               |\n");
        printf("|............................................|\n");
        printf("|   1   |  Mostrar Card�pio                  |\n");
        printf("|   2   |  Cadastrar cliente                 |\n");
        printf("|   3   |  Adicionar venda                   |\n");
        printf("|   4   |  Total das compras do cliente      |\n");
        printf("|   5   |  Total de vendas realizadas        |\n");
        printf("|   0   |  Sair                              |\n");
        printf("|--------------------------------------------|");
        printf("\nPor favor digite o c�dgo: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            exibirocard(cardapio, 3);
            break;
        case 2:
            cadasCliente(clientes, &numerosclientes);
            break;
        case 3:
            Vender(clientes, numerosclientes, cardapio, 3);
            break;
        case 4:
            exibirototaldecompras(clientes, numerosclientes);
            break;
        case 5:
            exibirtotaldevendas(clientes, numerosclientes);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opc�o inv�lida!\n");
        }

    } while (opcao != 0);

    return 0;
}