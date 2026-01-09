#include <stdio.h>

#define linha 10 // tamanho do tabuleiro, linhas
#define coluna 10 // tamanho do tabuleiro, colunas
#define tam_habilidade 5 // tamanho das matrizes de habilidades

void iniciartabuleiro(int tabuleiro[linha][coluna])
{ //Essa função iniciar o tabuleiro na tela com água (0)
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            tabuleiro[i][j] = 0;
        }
        
    }
    
}
// função para exibir o tabuleiro na tela
void exibirtabuleiro(int tabuleiro[linha][coluna])
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (tabuleiro[i][j] == 0) printf("~ "); //água
            else if (tabuleiro[i][j] == 3) printf("N "); //navio
            else if (tabuleiro[i][j] == 5) printf("* "); //área de habilidade
            
        }
        printf("\n");
    }
    
}
//Função para criar a matriz em forma de cone
void criarcone (int cone[tam_habilidade][tam_habilidade])
{
    for (int i = 0; i < tam_habilidade; i++)
    {
        for (int j = 0; j < tam_habilidade; j++)
        {
            if (j >= tam_habilidade/2 - i && j <= tam_habilidade/2 + i)
            {
            cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
            
        }
        
    }
    
}
//função para criar a matriz em forma de cruz
void criarcruz (int cruz [tam_habilidade][tam_habilidade])
{
    for (int i = 0; i < tam_habilidade; i++)
    {
        for (int j = 0; j < tam_habilidade; j++)
        {
            if (i == tam_habilidade/2 || j == tam_habilidade/2)
            {
            cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
            
        }
        
    }
    
}
//função para criar a matriz em forma de octaendro
void criaroctaendro (int octaendro [tam_habilidade][tam_habilidade]) {
    for (int i = 0; i < tam_habilidade; i++) {
        for (int j = 0; j < tam_habilidade; j++)
        {
            if (abs(i - tam_habilidade/2) + abs(j - tam_habilidade/2) <= tam_habilidade/2)
            {
                octaendro[i][j] = 1;
            } else {
                octaendro[i][j] = 0;
            }
            
        }
        
    }

}
// função para aplicar habilidade no tabuleiro
void aplicarhabilidade(int tabuleiro [linha][coluna], int habilidade [tam_habilidade {
    int offset = tam_habilidade / 2;;
    for (int i = 0; i < tam_habilidade; i++) {
        for (int j = 0; j < tam_habilidade; j++) {
            int linha = origemlinha + (i - offset);
            int coluna = origemcoluna + (j - offset);

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linha >= 0 && linha < linha && coluna >= 0 && coluna < coluna)
            {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != 3){
                    tabuleiro[linha][coluna] = 5; // Marca a área afetada pela habilidade   
                }
            }
        }
    }
}





int main() {
    char colunas [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
//criando tabuleiro 10x10
    int tabuleiro [10][10];

    printf(" Exibindo o tabuleiro:\n");

 // iniciar o tabuleiro com água 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // Inicializa todas as posições do tabuleiro com 0 (água)
        }
    }
// posiçionando navios no tabuleiro em diagonais tamanho 3
   for (int i = 0; i < 3; i++){
    tabuleiro[i][i] = 3;
   }
 // posiçionando navios no tabuleiro na diagonal tamanho 3  
   for (int i = 0; i < 3; i++){
    tabuleiro[i][9 - i] = 3;
   }
// posiçionando navios no tabuleiro horizontalmente tamanho 3
    for (int j = 4; j < 7; j++) {
        tabuleiro[2][j] = 3;
    }
 // posiçionando o navio na vertical tamanho 3
    for (int i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3;
    }
// aparecer cabeçalho da coluna
    printf("  ");
    for (int j = 0; j < 10; j++){
        printf(" %c ", colunas[j]);
    }
    printf("\n");


// aparecer o tabuleiro com números nas linhas
   for (int i = 0; i < 10; i++){
    printf("%d ", i);
   for (int j = 0; j < 10; j++) {
   printf("%2d ", tabuleiro[i][j]);
}
   printf("\n");
}
    return 0;
}
