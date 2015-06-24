/**************************************
* Trabalho 3 - AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Luiz Felipe Teixeira Assumpção - matricula: 0050008552
* Fila - Quiz
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fila.h"
int main()
{
	int op=0,i,j;
	char nome[50],insere[50];
	int pergunta,jogadores=0;
	char resp;
	Fila* n;
	char perguntas[3][100] = { {"Quem e o professor de Estrutrura de Dados I?\na)Fabio\nb)Marcia\nc)Alex\nd)Mario Joao\n"},
						{"Quem e o professor de Calculo Numerico?\na)Alexandre\nb)Elseclever\nc)Robaina\nd)Thiago\n"},
						{"Quem e o nome Coordenador adjunto da Lasalle Rj?\na)Alexandre\nb)Alex\nc)Mario Joao\nd)Fabio\n"}};
	char gabarito[3][2] = { {"c"},
							{"c"},
							{"d"} };
	printf("%c",gabarito[0][1]);
	n=fila_cria();
	do
	{
		puts("\nInforme o que deseja fazer!");
		puts("1- Inserir participantes.\n2- Comecar jogo!\n3- Sair");
		scanf("%d",&op);
		switch(op)
		{
		case 1:
			do
			{
				printf("Informe o nome do participante. Digite 'sair' quando acabar os participantes.\n");
				scanf("%s",&nome);
				fflush(stdin);
			
				if(strcmp(nome,"sair")==0)
					break;
				else	
				{
					jogadores++;
					fila_insere(n,nome);
				}
			}while(1);
			break;
		case 2:
			if(fila_vazia(n))
			{
				puts("Nao existe participante");
				exit(1);
			}
			else
			{
				while(jogadores!=1)
				{
					printf("Jogadores restantes: %d\n",jogadores);
					fila_retira(n,nome);
					jogadores--;
					printf("%s, responda a pergunta.",nome);
					pergunta= rand() % 3;
					
					for (j=0;perguntas[pergunta][j]!='\0';j++)
						printf("%c",perguntas[pergunta][j]);
					scanf("%s",&resp);
					fflush(stdin);
					
					if(gabarito[pergunta][0]==resp)
					{
						strcpy(insere,nome);
						puts("Resposta correta!");
						fila_insere(n,insere);
						jogadores++;
					}
					else
						puts("Resposta Errada!");
					
					if(jogadores==1)
					{
						jogadores=0;
						fila_retira(n,nome);
						printf("Parabens %s, você foi o vencedor do nosso QUIZ!!!",nome);
						break;
					}
					
				}
					
			}
				break;
		case 3:
			fila_libera(n);
			return 0;
		}//Switch fim
	}while(1);
	
fila_libera(n);
system("pause");
return 0;
}
