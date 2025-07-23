#include <stdio.h>

int main() {
    // Declaração do mapa como uma matriz 1001x1001 de caracteres
    char mapa[1001][1001];
    // P: número de pessoas, inicio_i/inicio_j: coordenadas do ponto inicial 'S'
    int P, inicio_i, inicio_j;

    // Lê o número de pessoas (P)
    scanf("%d", &P);
    // Guarda o valor inicial de P para comparação posterior
    int Pinicial = P;

    // Variáveis para percorrer o mapa durante a leitura
    int i = 0, j = 0;
    
    // Loop para ler o mapa caractere por caractere até o final do arquivo (EOF)
    while (scanf("%c", &mapa[i][j]) != EOF) {
        // Ignora caracteres de nova linha ('\n')
        if (mapa[i][j] != '\n') {
            // Se encontrar o ponto inicial 'S', guarda suas coordenadas
            if (mapa[i][j] == 'S') {
                inicio_i = i;
                inicio_j = j;
            }
            j++; // Avança para a próxima coluna
        }
        else {
            // Quando encontrar nova linha, vai para a próxima linha e reseta a coluna
            i++;
            j = 0;
        }
    }

    // Posiciona no ponto inicial 'S' para começar a navegação
    i = inicio_i;
    j = inicio_j;
    
    // Loop de navegação: continua até encontrar o ponto de saída 'E'
    while (mapa[i][j] != 'E') {
        // Se encontrar um item 'o', decrementa o contador de pessoas
        if (mapa[i][j] == 'o') P--;
        
        // Marca a posição atual como visitada (com '#')
        mapa[i][j] = '#';
        
        // Lógica de movimento (prioridade: cima, esquerda, baixo, direita)
        if (i > 0 && mapa[i-1][j] != '#') i--;         // Tenta mover para cima
        else if (j > 0 && mapa[i][j-1] != '#') j--;     // Tenta mover para esquerda
        else if (i <= 1000 && mapa[i+1][j] != '#') i++; // Tenta mover para baixo
        else if (j <= 1000 && mapa[i][j+1] != '#') j++; // Tenta mover para direita
    }

    // Verifica o resultado final e imprime a mensagem correspondente
    if (P == 0) printf("Todos morreram :)\n");          // Todos pegaram itens
    else if (P == Pinicial) printf("Nenhum morreu :(\n"); // Ninguém pegou itens
    else printf("%d encontraram o vovo\n", P);          // Alguns pegaram itens

    return 0;
}