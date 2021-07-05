#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <math.h>

struct calendario
{
	int dia;
	int mes;
	int ano;
};
typedef struct calendario data;

struct cad
{
	char anuncio[100];
	char cliente[100];
	data inicio;
	data termino;
	float investimento;
	float investimento_total;
	float total_visua;
	float total_cliques;
	float total_compart;
};
typedef struct cad cadastro;

cadastro receber(void);
void mostrar(cadastro a);
int dif_dias(cadastro a);
cadastro calculo(cadastro a);

int main(void)
{
	// Declaração da variável do tipo cadastro
	cadastro pessoa;
	int i = 1;
	
	while(!i==0)
	{
		system("cls");
		printf("\nMENU\n\n");
		printf("1 - Cadastrar Novo Anuncio.\n");
		printf("2 - Exibir Relatorio.\n");
		printf("0 - Sair.\n");
		printf("Opcao Escolhida: ");
		fflush(stdin);
		scanf("%d",&i);
		printf("\n");
		
		if(i==1)
		{
			pessoa = receber();
		}
		
		if(i==2)
		{
			system("cls");
			mostrar(pessoa);
			printf("\n");
			system("pause");
		}
			
		
		pessoa.investimento_total = pessoa.investimento*dif_dias(pessoa);
		pessoa = calculo(pessoa);
		
	}
		
	
	printf("\n\n");
	system("pause");
	return 0;
}

cadastro receber(void)
{
	// Declaração da variável do tipo cadastro
	cadastro a;
	
	printf("Insira o nome do anuncio: ");
	fflush(stdin);
	gets(a.anuncio);
	
	printf("Insira o nome do Cliente: ");
	fflush(stdin);
	gets(a.cliente);
	
	printf("Insira a data inicial da campanha no formato DD/MM/AAAA: ");
	fflush(stdin);
	scanf("%d/%d/%d",&a.inicio.dia,&a.inicio.mes,&a.inicio.ano);
	
	while(!(a.inicio.dia>=1&&a.inicio.dia<=31&&a.inicio.mes>=1&&a.inicio.mes<=12&&a.inicio.ano>=2021&&a.inicio.ano<=2030))
	{
		printf("Data inicial invalida!\n");
		printf("Insira Novamente a data inicial da campanha no formato DD/MM/AAAA: ");
		fflush(stdin);
		scanf("%d/%d/%d",&a.inicio.dia,&a.inicio.mes,&a.inicio.ano);
	}
	
	printf("Insira a data  final  da campanha no formato DD/MM/AAAA: ");
	fflush(stdin);
	scanf("%d/%d/%d",&a.termino.dia,&a.termino.mes,&a.termino.ano);
	
	while(!(a.termino.dia>=1&&a.termino.dia<=31&&a.termino.mes>=1&&a.termino.mes<=12&&a.termino.ano>=2021&&a.termino.ano<=2030))
	{
		printf("Data inicial invalida!\n");
		printf("Insira Novamente a data final da campanha no formato DD/MM/AAAA: ");
		fflush(stdin);
		scanf("%d/%d/%d",&a.termino.dia,&a.termino.mes,&a.termino.ano);
	}
	
	printf("Insira seu Investimento diario: R$ ");		
	fflush(stdin);
	scanf("%f",&a.investimento);
	
	return a;
}

void mostrar(cadastro a)
{
	printf("Anuncio: %s\n",a.anuncio);
	printf("Cliente: %s\n",a.cliente);
	printf("Data Inicial: %02d/%02d/%d\n",a.inicio.dia,a.inicio.mes,a.inicio.ano);
	printf("Data  Final : %02d/%02d/%d\n",a.termino.dia,a.termino.mes,a.termino.ano);
	printf("Investimento Diario: R$%.2f\n",a.investimento);
	printf("Investimento Total : R$%.2f\n",a.investimento_total);
	printf("Quantidade Maxima de  Visualizacoes  : %.0f\n",a.total_visua);
	printf("Quantidade Maxima de     Cliques     : %.0f\n",a.total_cliques);
	printf("Quantidade Maxima de Compartilhamento: %.0f\n",a.total_compart);
}

int dif_dias(cadastro a)
{
	int total1, total2, total;
	int i;
	int aux[12];
	
	aux[0] = 31; // Janeiro
	aux[1] = 28; // Fevereiro
	aux[2] = 31; // Março
	aux[3] = 30; // Abril
	aux[4] = 31; // Maio
	aux[5] = 30; // Junho
	aux[6] = 31; // Julho
	aux[7] = 31; // Agosto
	aux[8] = 30; // Setembro
	aux[9] = 31; // Outubro
	aux[10] = 30; // Novembro
	aux[11] = 31; // Dezembro
	
	total1 = a.inicio.ano*365 + a.inicio.dia;
	total2 = a.termino.ano*365 + a.termino.dia;
	
	for(i=0;i<(a.inicio.mes-1);i++)
	{
		total1 = total1 + aux[i];
	}
	
	for(i=0;i<(a.termino.mes-1);i++)
	{
		total2 = total2 + aux[i];
	}
	
	total = total2-total1;
	
	return total;
}

cadastro calculo(cadastro a)
{
	// Declaração das Variáveis
	float visua;
	float cliques;
	float compart;
	float compart_seq;
	float visua_compart;
	float total;
	cadastro b;
	b = a;
	
	
	// Cálculos	
	visua = 30*b.investimento_total;	
	cliques = trunc(visua/100)*12;	
	compart = trunc(cliques/20)*3;	
	compart_seq = compart*4;	
	visua_compart = 40*compart_seq;	
	total = visua + visua_compart;
	
	b.total_cliques = cliques;
	b.total_compart = compart_seq;
	b.total_visua = total;
	
	// Variável que será retornada
	return b;
}
