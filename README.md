# 🛒 Sistema de Gestão para Supermercado | 💻 Supermarket POS

O **Supermarket Point of Sale** (Ponto de Venda) é um sistema de gestão focado em operações de venda em supermercados. Ele registra os itens comprados, calcula o total a pagar, processa o pagamento, calcula o troco e emite um recibo. Em um contexto mais amplo, esse sistema poderia ser integrado a outros módulos, como gestão de estoque, cadastro de produtos, geração de relatórios financeiros e controle de clientes.

---

## 🛠️ Funcionalidades / Fluxo do programa

- 📦 Exibição dos produtos disponíveis para venda.
- 🛒 Registro dos produtos comprados.
- 💰 Cálculo do total a pagar com imposto aplicado.
- 🔄 Cálculo do troco com base no valor pago.
- 🧾 Emissão de recibo detalhado.
- 🔁 Reinicialização do sistema para novas compras.

---

## ⚙️ Como funciona?

1. **Tela inicial**: O sistema apresenta a lista de produtos e preços.
2. **Recebimento dos Produtos**: O vendedor registra os produtos comprados e suas quantidades.
3. **Cálculo do Valor Total**: O sistema calcula o valor total da compra.
4. **Recebimento do Pagamento**: O vendedor insere o valor pago e o sistema calcula o troco (se aplicável).
5. **Emissão do Recibo**: O sistema emite um recibo detalhado da compra.
6. **Reinicialização do Sistema**: Após finalizar a transação, o sistema retorna à tela inicial para a próxima compra.

---

## 📂 Estrutura do Projeto

- **supermarket-pos.c**: Código fonte principal.
- **README.md**: Documentação do projeto.

---

## 🚀 Requisitos para execução

- Um compilador C, como DevC++ ou VSCode.

## 🏗️ Compilação e Execução

1. Abra `supermarket-pos.c` na sua IDE.
2. Compile e execute o programa.

---

## 🎓 Sobre

Este programa foi criado como parte de um projeto acadêmico para aplicação dos conceitos de Programação Estruturada em C. Ele incorpora vários conceitos aprendidos, tais como:

- **Preprocessor** (`#include`, `#define`)
- **Entrada de dados** (`scanf()`)
- **Saída de dados** (`printf()`)
- **Estruturas de controle** (e.g., `while`, `if`)
- **Estruturas de Decisões** (`switch`)
- **Estruturas de Repetição** (`for`, `do-while`)
- **Funções** (modularização)
- **Macros** (simplificação)
- **Vetores** (armazenamento de produtos)
- **Ponteiros** (passagem de variáveis por referência)
