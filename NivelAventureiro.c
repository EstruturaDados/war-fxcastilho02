#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define TAM 5
//-------------------Struct----------------------------

typedef struct { // definindo uma struct chamada Territorio
	int tropas; 	// Variavel inteiro chamada tropas
	char cor [10];  // Variavel tipo char para armazenar texto chamada cor
	char nome[30]; // Variavel tipo char para armazenar texto chamada nome
}Territorio; // Esta função vai rescrever a struct agora vai ser chamada apenas de "Territorio"

//---- Função para limpar o buffer de entrada
void limparBufferEntrada(){
	int ch;
	while((ch = getchar()) != '\n'&& ch != EOF);
}

// -------------------- Cadastro --------------------
void cadastrarTerritorios(Territorio* lista, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\nCadastro do Território %d\n", i + 1);

        printf("Nome do Território: ");
        scanf("%30[^\n]", lista[i].nome);
        limparBufferEntrada();

        printf("Cor do Exército: ");
        scanf("%10[^\n]", lista[i].cor);
        limparBufferEntrada();

        printf("Número de Tropas: ");
        scanf("%d", &lista[i].tropas);
        limparBufferEntrada();
    }
}

// -------------------- Exibir --------------------
void exibirTerritorios(Territorio* lista, int qtd) {
    printf("\n======= Situação Atual =======\n");
    for (int i = 0; i < qtd; i++) {
        printf("Território %d\n", i + 1);
        printf("\tNome: %s\n", lista[i].nome);
        printf("\tCor: %s\n", lista[i].cor);
        printf("\tTropas: %d\n", lista[i].tropas);
        printf("-------------------------------\n");
    }
}

// --- Função atacar simular um ataque, utilizando numeros aleatórios como se fossem de batalha
void atacar(Territorio* atacante, Territorio* defensor){
	if(strcmp(atacante->cor, defensor->cor)==0){
		printf("\n  Não é permitido atacar territórios da mesma cor!\n");
		return;
	}
	if(atacante->tropas <= 1){
		printf("\n  O atacante não têm tropas suficientes!\n");
		return;
	}
	if(defensor->tropas <=0){
		printf("\n Territorio é conquistado!\n");
		return;
	}
	
	int dadoAtacante = rand() %6 + 1;
	int dadoDefensor = rand() %6 + 1;
	
	printf("\n Dados Atacante: %d | Dado Defensor: %d\n", dadoAtacante, dadoDefensor);
	
	if(dadoAtacante > dadoDefensor){
		printf("O atacante venceu a batalha!\n");
		defensor->tropas = defensor->tropas  - 1;
		
	}else if(dadoAtacante == dadoDefensor){
		printf("Houve um empate!\n");
		defensor->tropas = defensor->tropas  - 1;
		
	}else{
		printf("O defensor resistiu ao ataque!\n");
		atacante->tropas -=1;
	}
	
}

//--------------------Liberar Memoria------------------------------------------
void liberarMemoria(Territorio* lista){
	free (lista);
}

//---------------------------Main-----------------------------------------------
int main(){ 	//Função Principal
	setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // inicializa aleatoriedade

    int qtd;
    printf("Informe o número de territórios: ");
    scanf("%d", &qtd);
    limparBufferEntrada();

    Territorio* lista = (Territorio*) calloc(qtd, sizeof(Territorio));
    if (lista == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
	
    cadastrarTerritorios(lista, qtd);
    system("cls || clear");
    exibirTerritorios(lista, qtd);

    int opcao, at, def;
    do {
        printf("\nMenu de Ações:\n");
        printf("1 - Realizar Ataque\n");
        printf("2 - Exibir Territórios\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                exibirTerritorios(lista, qtd);
                printf("\nDigite o número do território atacante: ");
                scanf("%d", &at);
                printf("Digite o número do território defensor: ");
                scanf("%d", &def);
         		if (at >= 1 && at <= qtd && def >= 1 && def <= qtd) {
                    atacar(&lista[at - 1], &lista[def - 1]);
                } else {
                    printf("\n? Territórios inválidos!\n");
                }
                break;

            case 2:
                exibirTerritorios(lista, qtd);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\n? Opção inválida!\n");
        }
    } while (opcao != 0);

    liberarMemoria(lista);
    return 0;
}