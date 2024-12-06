#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca para localização por região
#include <string.h> //biblioteca para utilizar string

int registrar(){
	setlocale (LC_ALL, "Portuguese");
			
	char dex[40];
	char nome[40];
	char genero[10];
	char tipo[15];
	
	printf("Digite o nome do Pokémon descoberto: ");
	scanf("%s", nome); 
	
	strcpy(dex, nome); //Copiará a string inserida em "nome" em "dex"
	
	FILE *file; //Cria o arquivo
	file = fopen(dex, "w"); //(w) será utilizado para escrever um novo file
	fprintf(file, nome); //Salva o valor da variável "nome"
	fclose(file); //Fecha o arquivo
	
	file = fopen(dex, "a"); //(a) será utilizado para atualizar, ao invés de criar um novo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o gênero do Pokémon descoberto: ");
	scanf("%s", genero);
	
	file = fopen(dex, "a"); //(a) será utilizado para atualizar, ao invés de criar um novo
	fprintf(file, genero);
	fclose(file);
	
	file = fopen(dex, "a"); //(a) será utilizado para atualizar, ao invés de criar um novo
	fprintf(file, ", ");
	fclose(file);
	
	printf ("Digite o tipo do Pokémon descoberto: ");
	scanf("%s", tipo);
	
	file = fopen(dex, "a"); //(a) será utilizado para atualizar, ao invés de criar um novo
	fprintf(file, tipo);
	fclose(file);
}

int consultar(){
	setlocale (LC_ALL, "Portuguese");
	
	char nome[40];
	char conteudo[200];
	
	printf("Qual Pokémon você gostaria de ver?\n");
	scanf("%s",nome);
	
	FILE *file;
	file = fopen(nome,"r"); //(r) será utilizado com a função de leitura, de read.
	
	if(file == NULL){ //Caso o retorno seja nulo, não encontre a entrada, retornará a resposta abaixo
		printf("Não foi possível encontrar esse Pokémon\n"); 
	}
	
	while(fgets(conteudo, 200, file) !=NULL){ //Enquanto o retorno for diferente de nulo, retornar com o template abaixo
		printf("\nEssas são as informações do Pokémon: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar(){
    char nome[40];

    printf("Digite o Registro que você gostaria de apagar da Vinedex: ");
    scanf("%s", nome);

    // Verifica se o arquivo existe
    FILE *file = fopen(nome, "r");
    if (file == NULL) {
        printf("\nNão encontrei o Pokémon '%s'. \n\nCertifique-se de digitar o nome corretamente!\n\n", nome);
        system("pause");
        return 1; // Erro
    }

    // Fecha o arquivo após confirmar a existência
    fclose(file);

    // Remove o arquivo
    if (remove(nome) == 0) {
        printf("\nO registro do Pokémon '%s' foi removido com sucesso!\n", nome);
        system("pause");
        return 0; // Sucesso
    } else {
        return 1; // Erro
    }
}

int main (){
	int escolha = 0; //Define variável de escolha do Treinador Pokemon
	int repetidor = 1; //Variável para lógica do loop
	
	for (repetidor=1;repetidor=1;){ //Loop para sempre retornar ao menu
		
		system("cls"); //Limpa o console
	
		setlocale (LC_ALL, "Portuguese"); //Define linguagem para Português
		
		printf("## VINEDEX ##\n\n");
		printf("## Sistema de cadastro de Pokémons ##\n\n");
		printf("Abaixo, escolha o que gostaria de fazer!\n\n");
		printf("\t1 - Cadastrar Pokémon\n");
		printf("\t2 - Buscar Informações\n");
		printf("\t3 - Apagar Registro\n\n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &escolha); //Armazena escolha do usuário na variável "escolha"
		
		system ("cls"); //Limpa o console
		
		switch (escolha){ //Retorno de acordo com o valor atribuído a variável
			case 1: //Caso o treinador digite 1
				registrar();
				break;
			case 2: //Caso o treinador digite 2
				consultar();
				break;
			case 3: //Caso o treinador digite 3
				deletar();
				break;
			default: //Caso o treinador digite qualquer coisa que não seja 1, 2 ou 3.
				printf("Parece que você escolheu uma opção inválida, tente 1, 2 ou 3.\n\n");
				system("pause");
				break;
		}
	}
}
