#include <stdio.h> // Biblioteca de comunica��o de ususario 
#include <stdlib.h> // Biblioteca de aloca��o de mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca responsavel por cuidar das strings

int registro()
{

setlocale(LC_ALL, "Portuguese");

	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{

setlocale(LC_ALL, "Portuguese");	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel encontrar o arquivo! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do Usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}
	
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sisitema\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguegem
	
		printf("### Cart�rio da EBAC###\n\n"); // inicio do menu
		printf("escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o:"); // final do menu
		
		scanf("%d", &opcao); // armazenando escolha do ususario
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
			break;
		
			
			default:
				printf("Essa op��o n�o est� disponivel!\n\n");
				system("pause");
			break;
		}   // fim da sele��o
		
	}
}
	
