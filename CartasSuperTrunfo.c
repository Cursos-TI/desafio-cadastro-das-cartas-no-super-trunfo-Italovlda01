#include <stdio.h>


// Estrutura para armazenar os dados de uma cidade
struct Cidade {
    char codigo[4];  // Ex: A01, A02
    char nome[50];
    long populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// Função para cadastrar as cidades
void cadastrarCidades(struct Cidade cidades[], char estado) {
    for (int i = 0; i < MAX_CIDADES; i++) {
        // Gera o código da carta automaticamente (ex: A01, A02...)
        sprintf(cidades[i].codigo, "%c%02d", estado, i + 1);

        printf("\n=== Cadastro da Cidade %s ===\n", cidades[i].codigo);
        
        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]s", cidades[i].nome);
        
        printf("Digite a populacao (em habitantes): ");
        scanf("%ld", &cidades[i].populacao);
        
        printf("Digite a area (em km²): ");
        scanf("%f", &cidades[i].area);
        
        printf("Digite o PIB (em bilhoes): ");
        scanf("%f", &cidades[i].pib);
        
        printf("Digite o numero de pontos turisticos: ");
        scanf("%d", &cidades[i].pontos_turisticos);
    }
}

// Função para exibir os dados das cidades
void exibirCidades(struct Cidade cidades[]) {
    printf("\n=== Dados das Cidades Cadastradas ===\n");
    for (int i = 0; i < MAX_CIDADES; i++) {
        printf("\nCarta: %s\n", cidades[i].codigo);
        printf("Nome: %s\n", cidades[i].nome);
        printf("Populacao: %ld habitantes\n", cidades[i].populacao);
        printf("Area: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhoes\n", cidades[i].pib);
        printf("Pontos Turisticos: %d\n", cidades[i].pontos_turisticos);
        printf("-------------------\n");
    }
}

int main() {
    int nivel;
    char estado;

    // Menu de escolha do nível
    printf("Bem-vindo ao Super Trunfo - Paises!\n");
    printf("Escolha o nivel de desafio:\n");
    printf("1 - Novato\n");
    printf("2 - Aventureiro (ainda nao implementado)\n");
    printf("3 - Mestre (ainda nao implementado)\n");
    printf("Digite o numero do nivel: ");
    scanf("%d", &nivel);

    if (nivel != 1) {
        printf("Desculpe, apenas o nivel Novato esta disponivel por enquanto!\n");
        return 0;
    }

    // Escolha do estado
    printf("\nEscolha o estado (A a H): ");
    scanf(" %c", &estado);
    if (estado < 'A' || estado > 'H') {
        printf("Estado invalido! Use letras de A a H.\n");
        return 0;
    }

    // Declaração do array de cidades
    struct Cidade cidades[MAX_CIDADES];

    // Cadastro das cidades
    cadastrarCidades(cidades, estado);

    // Exibição dos dados
    exibirCidades(cidades);

    printf("\nCadastro concluido! No proximo nivel, voce podera comparar as cartas.\n");

    return 0;
}
