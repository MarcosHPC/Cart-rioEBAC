#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


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
		printf("N�o foi poss�vel localizar o arquivo! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nAqui est�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Voc� escolheu DELETAR!\n");
	printf("Digite o CPF a ser DELETADO: \n");
	scanf("%s",cpf);

	remove(cpf);
	
		
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("O usu�rio n�o existe no sistema! \n");
	}
	

	system("pause");
}


int main()
	{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem

		printf("###### Cart�rio da EBAC ######\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do MENU:\n\n");
		printf("\t1 - REGISTRAR nomes\n");
		printf("\t2 - CONSULTAR nomes\n");
		printf("\t3 - DELETAR nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
			
		printf("Op��o: "); //fim do menu
	
		scanf ("%d", &opcao); //armazenando a op��o escolhida pelo usuario
	
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
			printf("Voc� escolheu DELETAR nomes!\n");
			system("pause");
			break;		
		}	
	}	
	
}
