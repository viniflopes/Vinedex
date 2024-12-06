#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca para localiza��o por regi�o
#include <string.h> //biblioteca para utilizar string

int registrar(){
	setlocale (LC_ALL, "Portuguese");
			
	char dex[40];
	char nome[40];
	char genero[10];
	char tipo[15];
	
	printf("Digite o nome do Pok�mon descoberto: ");
	scanf("%s", nome); 
	
	strcpy(dex, nome); //Copiar� a string inserida em "nome" em "dex"
	
	FILE *file; //Cria o arquivo
	file = fopen(dex, "w"); //(w) ser� utilizado para escrever um novo file
	fprintf(file, nome); //Salva o valor da vari�vel "nome"
	fclose(file); //Fecha o arquivo
	
	file = fopen(dex, "a"); //(a) ser� utilizado para atualizar, ao inv�s de criar um novo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o g�nero do Pok�mon descoberto: ");
	scanf("%s", genero);
	
	file = fopen(dex, "a"); //(a) ser� utilizado para atualizar, ao inv�s de criar um novo
	fprintf(file, genero);
	fclose(file);
	
	file = fopen(dex, "a"); //(a) ser� utilizado para atualizar, ao inv�s de criar um novo
	fprintf(file, ", ");
	fclose(file);
	
	printf ("Digite o tipo do Pok�mon descoberto: ");
	scanf("%s", tipo);
	
	file = fopen(dex, "a"); //(a) ser� utilizado para atualizar, ao inv�s de criar um novo
	fprintf(file, tipo);
	fclose(file);
}

int consultar(){
	setlocale (LC_ALL, "Portuguese");
	
	char nome[40];
	char conteudo[200];
	
	printf("Qual Pok�mon voc� gostaria de ver?\n");
	scanf("%s",nome);
	
	FILE *file;
	file = fopen(nome,"r"); //(r) ser� utilizado com a fun��o de leitura, de read.
	
	if(file == NULL){ //Caso o retorno seja nulo, n�o encontre a entrada, retornar� a resposta abaixo
		printf("N�o foi poss�vel encontrar esse Pok�mon\n"); 
	}
	
	while(fgets(conteudo, 200, file) !=NULL){ //Enquanto o retorno for diferente de nulo, retornar com o template abaixo
		printf("\nEssas s�o as informa��es do Pok�mon: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar(){
    char nome[40];

    printf("Digite o Registro que voc� gostaria de apagar da Vinedex: ");
    scanf("%s", nome);

    // Verifica se o arquivo existe
    FILE *file = fopen(nome, "r");
    if (file == NULL) {
        printf("\nN�o encontrei o Pok�mon '%s'. \n\nCertifique-se de digitar o nome corretamente!\n\n", nome);
        system("pause");
        return 1; // Erro
    }

    // Fecha o arquivo ap�s confirmar a exist�ncia
    fclose(file);

    // Remove o arquivo
    if (remove(nome) == 0) {
        printf("\nO registro do Pok�mon '%s' foi removido com sucesso!\n", nome);
        system("pause");
        return 0; // Sucesso
    } else {
        return 1; // Erro
    }
}

int main (){
	int escolha = 0; //Define vari�vel de escolha do Treinador Pokemon
	int repetidor = 1; //Vari�vel para l�gica do loop
	
	for (repetidor=1;repetidor=1;){ //Loop para sempre retornar ao menu
		
		system("cls"); //Limpa o console
	
		setlocale (LC_ALL, "Portuguese"); //Define linguagem para Portugu�s
		
		printf("## VINEDEX ##\n\n");
		printf("## Sistema de cadastro de Pok�mons ##\n\n");
		printf("Abaixo, escolha o que gostaria de fazer!\n\n");
		printf("\t1 - Cadastrar Pok�mon\n");
		printf("\t2 - Buscar Informa��es\n");
		printf("\t3 - Apagar Registro\n\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &escolha); //Armazena escolha do usu�rio na vari�vel "escolha"
		
		system ("cls"); //Limpa o console
		
		switch (escolha){ //Retorno de acordo com o valor atribu�do a vari�vel
			case 1: //Caso o treinador digite 1
				registrar();
				break;
			case 2: //Caso o treinador digite 2
				consultar();
				break;
			case 3: //Caso o treinador digite 3
				deletar();
				break;
			default: //Caso o treinador digite qualquer coisa que n�o seja 1, 2 ou 3.
				printf("Parece que voc� escolheu uma op��o inv�lida, tente 1, 2 ou 3.\n\n");
				system("pause");
				break;
		}
	}
}
