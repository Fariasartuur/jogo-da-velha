#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirJogo(char jogo[3][3])
{


    int i = 1;
    int l, c;

    printf("     1   2   3\n     %c   %c   %c\n", 25, 25, 25);
    for (l = 0; l < 3; l++)
    {
        printf("%d %c ", i, 26);
        for (c = 0; c < 3; c++) 
        {
            printf(" %c ", jogo[l][c]);
            if (c < 2){
                printf("|");
            }
        }
        if (l < 2){
            printf("\n    ---|---|---");
        }
        printf("\n");
        i++;
    }
}

int ver(char jogo[3][3])
{

    int l, c;
    int X = 0;
    int O = 0;

    // Verificar horizontal
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (jogo[l][c] == 'X')
            {
                X++;
            }
            else if (jogo[l][c] == 'O')
            {
                O++;
            }
        }
        if (X == 3 || O == 3)
        {
            return 1;
        }
        X = 0;
        O = 0;
    }

    // Verificar Vertical
    for (c = 0; c < 3; c++)
    {
        for (l = 0; l < 3; l++)
        {
            if (jogo[l][c] == 'X')
            {
                X++;
            }
            else if (jogo[l][c] == 'O')
            {
                O++;
            }
        }
        if (X == 3 || O == 3)
        {
            return 1;
        }
        X = 0;
        O = 0;
    }

    // Verificar Diagonal principal
    for (l = 0, c = 0; l < 3 && c < 3; l++, c++)
    {
        if (jogo[l][c] == 'X')
        {
            X++;
        }
        else if (jogo[l][c] == 'O')
        {
            O++;
        }
        if (X == 3 || O == 3)
        {
            return 1;
        }
    }

    // Verificar Diagonal secundaria
    X = 0;
    O = 0;
    for (l = 0, c = 2; l < 3 && c >= 0; l++, c--)
    {
        if (jogo[l][c] == 'X')
        {
            X++;
        }
        else if (jogo[l][c] == 'O')
        {
            O++;
        }
        if (X == 3 || O == 3)
        {

            return 1;
        }
    }
    return 0;
}

int main()
{
    system("chcp 437");

    int l, c;
    int jogadas = 0;

    int verificacao = 0;

    char jogo[3][3];

    memset(jogo, ' ', sizeof(jogo));

    imprimirJogo(jogo);
    while (verificacao == 0){
        // X
        while (l < 1 || l > 3 || c < 1 || c > 3 || jogo[l - 1][c - 1] != ' '){
            printf("\nX - Escolha uma linha e uma coluna.\n");
            scanf("%d", &l);
            scanf("%d", &c);
            if (l < 1 || l > 3 || c < 1 || c > 3)
            {
                printf("Posicao invalida, escolha outra.\n");
            }
            else if (jogo[l - 1][c - 1] != ' ')
            {
                printf("Posicao ocupada, escolha outra.\n");
            }
        }
        jogo[l - 1][c - 1] = 'X';
        imprimirJogo(jogo);
        verificacao = ver(jogo);
        if (verificacao == 1)
        {
            printf("\nParabens 'X' voce ganhou!!\n");
            break;
        }
        jogadas++;
        if (jogadas == 9)
        {
            printf("\nO Jogo empatou\n");
            break;
        }

        // O
        while (l < 1 || l > 3 || c < 1 || c > 3 || jogo[l - 1][c - 1] != ' '){
            printf("\nO - Escolha uma linha e uma coluna.\n");
            scanf("%d", &l);
            scanf("%d", &c);
            if (l < 1 || l > 3 || c < 1 || c > 3)
            {
                printf("Posicao invalida, escolha outra.\n");
            }
            else if (jogo[l - 1][c - 1] != ' ')
            {
                printf("Posicao ocupada, escolha outra.\n");
            }
        }
        jogo[l - 1][c - 1] = 'O';
        imprimirJogo(jogo);
        verificacao = ver(jogo);
        if (verificacao == 1)
        {
            printf("\nParabens 'O' voce ganhou!!\n");
            break;
        }
        jogadas++;
        printf("\n%d jogadas\n", jogadas);
    }

    return 0;
}
