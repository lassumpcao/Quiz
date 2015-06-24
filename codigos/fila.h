/**************************************
* Trabalho 3 - AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Luiz Felipe Teixeira Assumpção - matricula: 0050008552
* Fila - Quiz
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
	char nome[50];
	struct lista* prox;
};

typedef struct lista Lista;

struct fila {
	Lista* ini;
	Lista* fim;
};

typedef struct fila Fila;


int fila_vazia(Fila* f)
{
  return f->ini == NULL;
}
Fila* fila_cria(void)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void fila_insere (Fila* f, char name[])
{
	Lista* n = (Lista*) malloc(sizeof(Lista));
	strcpy (n->nome,name);
	n->prox = NULL;
	
	if (f->fim != NULL)
		f->fim->prox = n;
	else 
		f->ini = n;
	f->fim = n; 
}

char fila_retira(Fila* f, char* vez)
{ 
	Lista* t;
	
	if (fila_vazia(f)) 
	{ 
		printf("Fila vazia.\n");
		exit(1); 
	} 
	
	t = f->ini;
	strcpy(vez,t->nome);
	f->ini = t->prox;
	
	if (f->ini == NULL) 
		f->fim = NULL;
		
	free(t);
}

void fila_libera(Fila* f)
{	
	Lista* t=f->ini;
	while(t!=NULL)
	{
		Lista* q=t->prox;
		free(t);
		t=q;
	}
	free(f);
}
void imprimir(Fila *f)
{
	Lista* q=f->ini;
    while (q!=NULL)
    {
        printf("%s\n",q->nome);
        q = q->prox;
    }

}
