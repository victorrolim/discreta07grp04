/*Exercicio 7: Automato Finito Determinado
 * Authors: Victor Rolim Costa
            Rajiv Machado
 * 
 * Profº.: Ruben C. Benante.
 *
 * Descricao: 
 *
 * This program is protceted by GNU LICENSE v3.0; for more legal information, check the LICENSE file.            
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct st_lista
{
    int c;
   struct st_lista *prox;
}lista;


typedef struct  d
{
  int qi;//estado inicial
  int a;//alfabeto
  int qf;/*estado final*/
  struct d *prox;
}tipo_d;

typedef struct c
{
 int c;
 int *p;
 struct c *prox;
}tipo_c;

/*inseri afnd na lista tipo_d*/
void inserir (tipo_d **cabeca, tipo_d *d);

/*entra e_i e tokken, sai e_f*/
int buscar(tipo_d *cabeca, int x, int a, lista **cabeca1);

/*imprime toda a lista tipo d*/
void imprimir (tipo_d *cabeca);

/*não utilizado*/
tipo_d trans (tipo_d *l);

/*ordena em ordem crescente a lista*/
void ordena (lista **cabeca);
/*inseri elemento na lista*/
void inserir1 (lista **cabeca, int x);

/*caso não exista inseri um inteiro x na lista*/
int buscar1(lista **cabeca, int x);

/*imprime lista*/
void imprimir1 (lista *cabeca);
/*afd*/
void inserir_c (tipo_c **cabeca, lista *cabeca1, int x);
/*imprime afd*/
void imprimir_c (tipo_c *cabeca);
/*inseri estado afnd na lista p/ estado afd*/
void BI (lista **cabeca, tipo_d *cabeca1, int x);
/*compara lista com afd, caso nao exista inclue*/
tipo_c *comp_afd (lista *cabeca, tipo_c *cabeca1, int c);
/*conta a quantidade de elemento na lista(tipo_l*/
int conta (lista *cabeca);
/*recebe afd, trasicao -> afd*/
tipo_c *transform (tipo_c **cabeca, tipo_d *cabeca1, int k);

/*entra lista com estados finais afnd, lista afd, out lista estados finais afd*/
lista *f_afd(tipo_c *cabeca, lista *cabeca1);
/*cria lista de delta afd*/
tipo_d *afd_l (tipo_c *cabeca, tipo_d *cabeca1);
/*compara lista com afd, caso exista retorna o numero de ordem, caso contrario -1*/
int comp_afd1 (lista *cabeca, tipo_c *cabeca1, int c);
/*imprime conjunto de estados afd*/
void imprimir_c1 (tipo_c *cabeca);
void imprimir_quintupla(tipo_c *cabeca, int s,lista *cabeca1, tipo_d *cabeca2);
