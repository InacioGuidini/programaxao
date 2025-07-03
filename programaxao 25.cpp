#include <stdio.h>
#include <string.h>  // Para usar strcmp()

#define MAX 100  // Número máximo de contatos

// Estrutura que representa um contato
struct Contato {
    char nome[50];
    char telefone[15];
};

// Vetor de contatos
struct Contato contatos[MAX];
int qtd = 0;  // Quantidade atual de contatos

// Funcao para buscar contato pelo nome
int buscarPorNome(char nome[]) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;  // Não encontrado
}

// Cadastrar novo contato
void cadastrar() {
    if (qtd >= MAX) {
        printf("\nLimite de contatos atingido (%d)!\n", MAX);
        return;
    }

    printf("\n--- NOVO CONTATO ---\n");

    printf("Nome: ");
    scanf(" %49[^\n]", contatos[qtd].nome);

    // Verifica se o nome já existe
    if (buscarPorNome(contatos[qtd].nome) != -1) {
        printf("Erro: Já existe um contato com esse nome.\n");
        return;
    }

    printf("Telefone: ");
    scanf(" %14[^\n]", contatos[qtd].telefone);

    qtd++;
    printf("Contato cadastrado com sucesso!\n");
}

// Listar contatos
void listar() {
    printf("\n--- LISTA DE CONTATOS ---\n");
    printf("Total: %d\n\n", qtd);

    if (qtd == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("%-50s TELEFONE\n", "NOME");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < qtd; i++) {
        printf("%-50s %s\n", contatos[i].nome, contatos[i].telefone);
    }
}

// Editar contato
void editar() {
    char nome[50];
    printf("\n--- EDITAR CONTATO ---\n");
    printf("Digite o nome do contato a editar: ");
    scanf(" %49[^\n]", nome);

    int index = buscarPorNome(nome);
    if (index == -1) {
        printf("Contato não encontrado!\n");
        return;
    }

    printf("Nome atual: %s\n", contatos[index].nome);
    printf("Telefone atual: %s\n", contatos[index].telefone);

    printf("\nNovo nome: ");
    scanf(" %49[^\n]", contatos[index].nome);
    printf("Novo telefone: ");
    scanf(" %14[^\n]", contatos[index].telefone);

    printf("Contato atualizado com sucesso!\n");
}

// Excluir contato
void excluir() {
    char nome[50];
    char confirmacao;

    printf("\n--- EXCLUIR CONTATO ---\n");
    printf("Digite o nome do contato a excluir: ");
    scanf(" %49[^\n]", nome);

    int index = buscarPorNome(nome);
    if (index == -1) {
        printf("Contato nao encontrado!\n");
        return;
    }

    printf("\nContato encontrado:\n");
    printf("Nome: %s\n", contatos[index].nome);
    printf("Telefone: %s\n", contatos[index].telefone);
    printf("Tem certeza que deseja excluir? (s/n): ");
    scanf(" %c", &confirmacao);

    if (confirmacao == 's' || confirmacao == 'S') {
        for (int i = index; i < qtd - 1; i++) {
            contatos[i] = contatos[i + 1];  // Desloca os próximos
        }
        qtd--;
        printf("Contato excluído com sucesso!\n");
    } else {
        printf("Operacao cancelada.\n");
    }
}

// Função principal com menu
int main() {
    int op;

    printf("\n----------------------------------------");
    printf("\n           AGENDA TELEFÔNICA");
    printf("\n----------------------------------------\n");

    do {
        printf("\n----------- MENU PRINCIPAL -----------\n");
        printf("1. Cadastrar novo contato\n");
        printf("2. Listar todos os contatos\n");
        printf("3. Editar contato existente\n");
        printf("4. Excluir contato\n");
        printf("0. Sair do sistema\n");
        printf("--------------------------------------\n");
        printf("opcao: ");
        scanf("%d", &op);
        while (getchar() != '\n');  // Limpa buffer

        switch (op) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: editar(); break;
            case 4: excluir(); break;
            case 0: printf("\nEncerrando sistema...\n"); break;
            default: printf("Opcao inválida! Tente novamente.\n");
        }

    } while (op != 0);

    printf("\nObrigado por utilizar a agenda!\n");
    return 0;
}

