#include<stdio.h>
#include<conio.h>
int main (void )
{
  int matriz[15][15],linha, coluna, maior, menor,  linhaMaior, colunaMaior;
  maior = 0;
  menor = 999;
  srand(time(NULL)); // Regenera o rand

  printf ("\nDigite valor para os elementos da matriz\n\n");

  for ( linha=0; linha<15; linha++ )
    for ( coluna=0; coluna<15; coluna++ )
    {
      matriz[ linha ][ coluna ] = rand() % 100; // Gera números entre 0 e 99

      if (matriz[ linha ][ coluna ] > maior){
            maior = matriz[ linha ][ coluna ];
            linhaMaior = linha;
            colunaMaior = coluna;
        };
    };
for ( linha=linhaMaior; linha < linhaMaior+1; linha++ )

    for ( coluna=0; coluna<15; coluna++ )
    {
      if (matriz[ linha ][ coluna ] < menor){
            menor = matriz[ linha ][ coluna ];
        };
    };

  printf("\n\n******************* Saida de Dados ********************* \n\n");


  for ( linha=0; linha<15; linha++ ){
    for ( coluna=0; coluna<15; coluna++ )
    {
        if ( matriz[ linha ][ coluna ] >= 0 && matriz[ linha ][ coluna ] < 10){
            if (linhaMaior == linha && matriz[ linha ][ coluna ] == menor){
                printf ("[%d] " ,matriz[ linha ][ coluna ]);
            } else {
            printf ("0%d " ,matriz[ linha ][ coluna ]);
            };
        } else {
            if (linhaMaior == linha && matriz[ linha ][ coluna ] == menor){
                printf ("[%d] ",matriz[ linha ][ coluna ]);
            } else {
            printf ("%d " ,matriz[ linha ][ coluna ]);
            };
        };

    };
    printf("\n");
    };

  getch();
  return(0);
}
