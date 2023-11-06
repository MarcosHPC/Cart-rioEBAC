#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copiar valores strings cpf para arquivo
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); 
	fprintf(file,cpf); //salva o valor da variavel cpf em file
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o PRIMEIRO NOME a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);

	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);

	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	
	char cpf[40];
	char conteudo [200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o arquivo! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nAqui estão as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Você escolheu DELETAR!\n");
	printf("Digite o CPF a ser DELETADO: \n");
	scanf("%s",cpf);

	remove(cpf);
	
		
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("O usuário não existe no sistema! \n");
	}
	

	system("pause");
}


int main()
	{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem

		printf("###### Cartório da EBAC ######\n\n"); //início do menu
		printf("Escolha a opção desejada do MENU:\n\n");
		printf("\t1 - REGISTRAR nomes\n");
		printf("\t2 - CONSULTAR nomes\n");
		printf("\t3 - DELETAR nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
			
		printf("Opção: "); //fim do menu
	
		scanf ("%d", &opcao); //armazenando a opção escolhida pelo usuario
	
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
			printf("Obrigado por utilizar nosso sistema\n");
			return 0;
			break;
					
			default:
			printf("Você escolheu DELETAR nomes!\n");
			system("pause");
			break;		
		}	
	}	
	
}
