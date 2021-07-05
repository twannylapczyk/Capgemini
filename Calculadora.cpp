#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <math.h>

float calculo(float investimento);

int main()
{
	// Declaração das Variáveis
	float invest;
	float total_visua;	
	
	// Recebendo Informação do Investimento
	printf("Insira seu Investimento Inicial: R$ ");		
	fflush(stdin);
	scanf("%f",&invest);
	
	total_visua = calculo(invest);
	
	// Apresentação do Resultado	
	printf("Total Visualizacoes = %.0f Pessoas\n",total_visua);
	
		
	printf("\n\n");
	system("pause");
	return 0;
}

float calculo(float investimento)
{
	// Declaração das Variáveis
	float visua;
	float cliques;
	float compart;
	float compart_seq;
	float visua_compart;
	float total;
	
	
	// Cálculos	
	visua = 30*investimento;	
	cliques = trunc(visua/100)*12;	
	compart = trunc(cliques/20)*3;	
	compart_seq = compart*4;	
	visua_compart = 40*compart_seq;	
	total = visua + visua_compart;
	
	// Variável que será retornada
	return total;
}
