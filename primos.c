#include<stdio.h>
#include<conio.h>
#include <math.h>
int main (void )
{
  int primeiro, ultimo, contador;
  float div;

  printf ("\nDigite o valor inicial do intervalo: ");
  scanf("%d", &primeiro);
  printf ("\nDigite o valor final do intervalo:");
  scanf("%d", &ultimo);


  for (int i= primeiro; i < ultimo; i++ ){
      contador = 0;
        for (int c = i; c > 0; c--){
            if (i%c == 0){
                contador ++;
            };
        };
        if (contador == 2){
                
            printf("%d ", i);
        }
    };

  return(0);
}
