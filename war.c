#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 5

struct Territorio{ // definindo uma struct chamada Territorio
	int tropas; 	// Variavel inteiro chamada tropas
	char cor [10];  // Variavel tipo char para armazenar texto chamada cor
	char nome[30]; // Variavel tipo char para armazenar texto chamada nome
};

typedef struct Territorio Territorio; // Esta função vai rescrever a struct agora vai ser chamada apenas de "Territorio"

//---- Função para limpar o buffer de entrada
void limparBufferEntrada(){
	int ch;
	while((ch = getchar()) != '\n'&& ch != EOF);
}

int main(){ 	//Função Principal
	setlocale(LC_ALL, "Portuguese"); //usar biblioteca na liguagem portugues para palavras com acento
	
	Territorio lista[TAM]; // Usar um vetor junto com as Struct
	int i;
	
	for(i=0;i<TAM;i++){ // repetir 5 vez o cadastro do exercicitos
				
		printf("Informe o Exercito (%d): \n", i+1); // Informar na tela
			printf("Nome do Territorio: "); //puts 
			scanf("%30[^\n]", &lista[i].nome); //[^\n] scanf vai ler os espaços o total 50 caracteres
			limparBufferEntrada();
		
			printf("Cor do Exercito: ");
			scanf("%10[^\n]s", &lista[i].cor);
			limparBufferEntrada();
			
			printf("Numero de Tropas: ");
			scanf("%d", &lista[i].tropas);
			limparBufferEntrada();
	}
system("cls"); // limpa todos os campos que foram escritos deixando a tela preta
	
	puts("Seus dados:\n");
	
	for(i=0;i<TAM;i++){ // Mostrar na tela os 5 exercitos cadastrados
		
		printf("-----------Exercito %d ------------\n", i+1);
		printf("\tNome do Territorio: %s\n", lista[i].nome);
		printf("\tCor do Exercito: %s\n", lista[i].cor);
		printf("\tNUmero de Tropas: %d\n", lista[i].tropas);
	}
	printf("-------------------------------\n");

}