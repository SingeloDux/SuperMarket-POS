/*
 * -------------------------------------------------------------------------
 * Nome do Programa: Supermarket POS
 * Nome do Autor   : Singelo Dux
 * Data de Criação : 15 de Outubro de 2024
 * Versão          : 0.1
 * 
 * Descrição: 
 * Sistema de gestão de vendas em um supermercado, responsável por registrar 
 * compras, calcular o valor total, processar o pagamento e emitir um recibo final. 
 * Criado como projeto acadêmico de Programação Estruturada em C.
 * -------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5
#define TAXA_IMPOSTO 0.16  // 16% de imposto

// Estrutura para armazenar informações de cada produto
typedef struct {
    char nome[50];
    float preco;
} Produto;

// Exibe os produtos disponíveis para venda
void exibirProdutos(Produto produtos[], int tamanho) {
    printf("\n=============================================\n");
    printf("     *** BEM-VINDO AO SISTEMA DE CAIXA ***\n");
    printf("=============================================\n");
    printf("      Produtos disponíveis para venda\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < tamanho; i++) {
        printf("| %d. %-20s | %.2f MT \n", i + 1, produtos[i].nome, produtos[i].preco);
    }
    printf("---------------------------------------------\n\n");
    printf(" * Desenvolvido por [Eduardo Simião Come] *\n");
    printf("=============================================\n\n");
}

// Registra os produtos comprados pelo cliente
void registrarProdutos(Produto produtos[], int quantidade[]) {
    int codigo, qtd, maisProdutos;
    
    do {
        printf("Digite o codigo do produto que o cliente comprou (1-%d): ", MAX_PRODUTOS);
        scanf("%d", &codigo);

        if (codigo >= 1 && codigo <= MAX_PRODUTOS) {
            printf("Digite a quantidade comprada de %s: ", produtos[codigo - 1].nome);
            scanf("%d", &qtd);
            quantidade[codigo - 1] += qtd;
            
            printf("\n%d unidades de %s adicionadas ao carrinho.\n", qtd, produtos[codigo - 1].nome);
        } else {
            printf("Codigo invalido! Por favor, insira um codigo valido.\n");
        }

        printf("Deseja adicionar mais produtos? [1-Sim, 0-Nao]: ");
        scanf("%d", &maisProdutos);
        
    } while (maisProdutos != 0);
}

// Calcula e exibe o total da compra
float calcularTotal(Produto produtos[], int quantidade[], float *subtotal, float *imposto) {
    *subtotal = 0.0;
    
    printf("\n=============== Conta do cliente:===============\n");
    printf("------------------------------------------------\n");
    printf("%-4s  %-15s  %10s  %12s\n", "Qtd.", "Descricao", "Preco Un", "  Preco Total");

    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (quantidade[i] > 0) {
            float subtotalItem = produtos[i].preco * quantidade[i];
            printf("%-4d  %-15s  %10.2f  %10.2f MT\n", quantidade[i], produtos[i].nome, produtos[i].preco, subtotalItem);

            *subtotal += subtotalItem;
        }
    }

    *imposto = *subtotal * TAXA_IMPOSTO;
    float total = *subtotal + *imposto;

    printf("------------------------------------------------\n");
    printf("                    Subtotal     : %10.2f MT\n", *subtotal);
    printf("                    IVA (16%%)    : %10.2f MT\n", *imposto);
    printf("                    Total a pagar: %10.2f MT\n", total);
    
    return total;
}

// Calcula o troco
float calcularTroco(float total, float valorPago) {
    //float troco = valorPago - total;
    return valorPago - total;
}

// Emite o recibo final
void emitirRecibo(Produto produtos[], int quantidade[], float subtotal, float imposto, float total, float valorPago, float troco) {
    printf("\n================= Recibo Final =================\n");
    printf("------------------------------------------------\n");
    printf("%-4s  %-15s  %10s  %12s\n", "Qtd.", "Descricao", "Preco Un", "  Preco Total");

    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (quantidade[i] > 0) {
            float subtotal = produtos[i].preco * quantidade[i];
            printf("%-4d  %-15s  %10.2f  %10.2f MT\n", quantidade[i], produtos[i].nome, produtos[i].preco, subtotal);
        }
    }
    printf("------------------------------------------------\n");
    printf("                      Subtotal   : %10.2f MT\n", subtotal);
    printf("                      IVA (16%%)  : %10.2f MT\n", imposto);
    printf("                      Total      : %10.2f MT\n", total);
    printf("------------------------------------------------\n");
    printf("Valor pago: %.2f MT | Troco Recebido: %.2f \n", valorPago, troco);
    printf("------------------------------------------------\n");
    printf("Obrigado pela compra. Volte sempre!\n\n");
}

// Reinicializa o sistema para um novo cliente
void reinicializarSistema(int quantidade[]) {
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        quantidade[i] = 0;
    }
    printf("\nSistema reinicializado. Pronto para o próximo cliente.\n");
}

int main() {
    Produto produtos[MAX_PRODUTOS] = {
        {"Arroz 1kg", 60.00},
        {"Feijao 500g", 65.50},
        {"Leite 1L", 110.00},
        {"Acucar 1kg", 80.00},
        {"Sal 1kg", 35.00}
    };

    int quantidade[MAX_PRODUTOS] = {0}, continuar = 1;
    float subtotal, imposto;

    while (continuar) {
        exibirProdutos(produtos, MAX_PRODUTOS);
        
        registrarProdutos(produtos, quantidade);

        float total = calcularTotal(produtos, quantidade, &subtotal, &imposto);
        
        float valorPago;
        float troco;
        int opcao;

        do {
            printf("\nDigite o valor pago pelo cliente: ");
            scanf("%f", &valorPago);
            
            troco = calcularTroco(total, valorPago);
            
            if (troco >= 0) {
                printf("Troco a ser devolvido: %.2f MT\n", troco);
                emitirRecibo(produtos, quantidade, subtotal, imposto, total, valorPago, troco);
                break;
            } else {
                printf("O valor pago é insuficiente.\n");
                printf("1. Inserir novamente o valor.\n");
                printf("2. Cancelar a venda.\n");
                printf("\nEscolha uma opção: ");
                scanf("%d", &opcao);
                
                if (opcao == 2) {
                    printf("Venda cancelada.\n\n");
                    break; 
                }
            }
        } while (troco < 0);

        printf("Deseja atender o próximo cliente? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
        
        if (continuar) {
            reinicializarSistema(quantidade);
        }
    }

    printf("\nSISTEMA ENCERRADO.\n");

    return 0;
}
