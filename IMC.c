#include <stdio.h>
#include <stdlib.h>

struct Pessoa // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    float peso;   // define o campo Peso
    float altura;    // define o campo Altura
    char nome[255]; // define o campo Nome
} ; // Define o nome do novo tipo criado

void IMC(float altura, float peso){ // Função que irá calcular o IMC do usuário com base nos parâmetros informados
    float imc;
    imc = peso /(altura*altura);
    printf("Seu IMC é: %.2f", imc);
    if (imc < 17){
        printf("Você está MUITO ABAIXO DO PESO! Procure um nutricionista.");
    } else if (imc >= 17 && imc < 18.5) {
        printf("Você está ABAIXO DO PESO! Procure um nutricionista.");
    } else if (imc >= 18.5 && imc < 25) {
        printf("Você está NORMAL!Não se anime.");
    } else if (imc >= 25 && imc < 30) {
        printf("Você está ACIMA DO PESO!Procure um nutricionista.");
    } else if(imc >= 30 && imc < 35) {
        printf("Você está com OBESIDADE I!Procure um nutricionista.");
    } else if(imc >= 35 && imc < 40) {
        printf("Você está com OBESIDADE II!Procure um nutricionista.");
    } else {
       printf("Você está com OBESIDADE III!Procure um nutricionista.");
    };
}

int main()
{
    struct Pessoa usuario;

    printf("Boa Noite! Qual o seu nome? ");
    gets(usuario.nome);
    fflush(stdin);

    printf("Qual o seu altura %s? ", usuario.nome);
    scanf("%f", &usuario.altura);

    printf("Qual a sua peso %s? ", usuario.nome);
    scanf("%f", &usuario.peso);

    IMC(usuario.altura, usuario.peso);
    return 0;
}

