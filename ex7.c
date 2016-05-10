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

int main(void)
{
    tipo_d *l1=NULL, *d=NULL, *afd=NULL;
    int c=0,s=0;
    char r;
    lista *l2=NULL, *k1=NULL, *k=NULL;
    k=malloc(sizeof(lista)); k->c=1; k->prox=NULL;

    d=malloc(sizeof(tipo_d));
    d->prox=NULL;

    tipo_c *pc=NULL,*a=NULL, *b=NULL;

    do
    {

    /*  if(c==0)
        printf("\n considerando qi -> estado inicial, qf ->estado final, tokken = t\nEscreva a trasicao na forma qi,t,qf\n");
      else
        printf("\ndigite a transicao\n");*/

      scanf("q%d,%d,q%d", &d->qi, &d->a,&d->qf);
      inserir(&l1,d );
     /* printf("\nexiste outra transicao\n");*/
      while((r = getchar()) == '\n');

      getchar();
      c++;

  }while(r == 's' || r == 'S');

  imprimir(l1);

  inserir1(&l2,s);

  BI(&l2, l1, 2);

  ordena(&l2);
  c=conta(l2);


 inserir_c(&pc, l2, c);



do
{
  a=transform(&pc, l1, 1);
  if(a!=NULL)
    printf("\nA!==NUL->\n");

  b=transform(&pc, l1, 0);
  if(b!=NULL)
    printf("\nB!==NUL->\n");

}
while(a==NULL  || b==NULL);


imprimir_c(pc);

k1=f_afd(pc, k);
imprimir1(k1);

afd=afd_l(pc,l1);
imprimir(afd);

imprimir_quintupla(pc, s, k1, afd);

    return 0;
}

/***************************************************************************************************/
void imprimir_quintupla(tipo_c *cabeca, int s, lista *cabeca1, tipo_d *cabeca2)
{
  tipo_c *pc=cabeca;
  lista *pl=cabeca1;
  tipo_d *pd=cabeca2;

  printf("\nAFD(Estados");
  /*para imprimir os estados*/
  imprimir_c1(pc);
  /*alfabeto*/
  printf("alfabeto{0,1};");
  printf("estado inicial{%d}",s);
  printf("estados finais");
  imprimir1(pl);
  printf("funcao de transicao");
  imprimir(pd);
  printf("\n");
}

/*************************************************************************************************/
tipo_d *afd_l (tipo_c *cabeca, tipo_d *cabeca1)
{

  int x=0, y, c=0, k, cont=0;
  tipo_c *pc=cabeca, *a=NULL;
  tipo_d *pd=cabeca1, *pdr=NULL, *t=NULL;
  lista *pl=NULL, *pl1=NULL;

  t=malloc(sizeof(tipo_d));
  while(pc!=NULL)
  {
    pd=cabeca1;


    while(pd!=NULL)
    {
      for(x=0; x < pc->c; x++)
      {
        if(pd->qi==pc->p[x] && pd->a==0)
        {
          y=buscar1(&pl, pd->qf);

          if(y==1)
          c++;
          }
          if(pd->qi==pc->p[x] && pd->a==1)
        {
          y=buscar1(&pl1, pd->qf);
          if(y==1)
          c++;
          }
      }

      pd=pd->prox;
    }
     if(pl!=NULL)
     {
        a=pc;
        pc=cabeca;
        pd=cabeca1;
        BI(&pl,pd,2);
        c=conta(pl);
        ordena(&pl);
        k=comp_afd1(pl,pc,c);
        if(k!=-1)
        {
          t->qi=cont;
          t->a=0;
          t->qf=k;
          inserir(&pdr,t );
        }
        pc=a;
     }

     if(pl1!=NULL)
     {
       a=pc;
       pc=cabeca;
       pd=cabeca1;
       BI(&pl1,pd,2);
       c=conta(pl1);
       ordena(&pl1);
       k=comp_afd1(pl1,pc,c);
       if(k!=-1)
       {
         t->qi=cont;
         t->a=1;
         t->qf=k;
         inserir(&pdr,t );
       }
      pc=a;
    }
    cont++;
    pc=pc->prox;
  }
  /*pd=cabeca1;
  BI(&pl,pd,2);

  ordena(&pl);
  c=conta(pl);
  pc=*cabeca;
  a=comp_afd(pl,pc,c);
  pc=*cabeca;
  pd=cabeca1;


  if(a==NULL)
      inserir_c(&pc,pl,c);

   free(pl);*/
  return pdr;
}

/***********************************************************/

lista *f_afd(tipo_c *cabeca, lista *cabeca1)
{
  int x, y=0;
  tipo_c *pc=cabeca;
  lista *pl=cabeca1, *k=NULL;

  while(pc!=NULL)
  {
    for(x=0; x<pc->c;x++)
    {
      pl=cabeca1;
      while(pl!=NULL)
      {
        if(pl->c==pc->p[x])
        {
          buscar1(&k,y);
          x=pc->c;
          break;
        }


        pl=pl->prox;
      }

    }
    y++;
    pc=pc->prox;
  }


return k;

}
tipo_c *transform (tipo_c **cabeca, tipo_d *cabeca1, int k)
{

  int x=0, y, c=0, t=0;
  tipo_c *pc=*cabeca, *a=*cabeca, *b=NULL;
  tipo_d *pd=cabeca1;
  lista *pl=NULL;


   while(pc!=NULL)
  {

   scanf("%d",&t);
    pd=cabeca1;
    free(pl);
    pl=NULL;
    while(pd!=NULL)
    {
      for(x=0; x < pc->c; x++)
      {
        if(pd->qi==pc->p[x] && pd->a==k)
          y=buscar1(&pl, pd->qf);
      }
      pd=pd->prox;
    }


    if(pl!=NULL)
    {

      b=pc;
      pc=*cabeca;
      pd=cabeca1;
      BI(&pl,pd,2);
      ordena(&pl);

      c=conta(pl);

      a=comp_afd(pl,pc,c);



      if(a==NULL)
      {
        inserir_c(&pc,pl,c);
        pc=*cabeca;
        return a;
      }

    }



    t++;
    if(t==10)
     break;
     pc=b;
    pc=pc->prox;

 }

  pc=*cabeca;
  return b;
}

int conta (lista *cabeca)
{
  int c=0;
  lista *pl=cabeca;
  while(pl!=NULL)
    {
    c++;
    pl=pl->prox;
    }
  return c;
}

tipo_c *comp_afd(lista *cabeca, tipo_c *cabeca1, int c)
{
  int x;
  lista *pl=cabeca;
  tipo_c *pc=cabeca1;
  if(pc==NULL)
    printf("pc esta apontando para NULL, precisa retornar um valor\n");

  while(pc!=NULL)
  {
    pl=cabeca;
    int x=0;
    if(c==pc->c)
    {
      while (pl != NULL)
      {
        if(pl->c==pc->p[x])
        return pc;
        pl=pl->prox;
        x++;
      }

    }
    pc=pc->prox;
  }
  return NULL;
}
void BI (lista **cabeca, tipo_d *cabeca1, int x)
{
  int r=0;
  lista *pl=*cabeca;
  tipo_d *pd=cabeca1;

  while(pd!=NULL)
  {

    pl=*cabeca;
    while(pl!=NULL)
    {
      if(pd->qi==pl->c && x==pd->a)
      { //printf("\npl->c=%d, qi=%d, pd->a=%d\n",pl->c,pd->qi,x);
        r=buscar1(&pl,pd->qf);
        if(r==1)
        {
          pd=cabeca1;
          BI (&pl, pd, 2);

        }
      }
      pl=pl->prox;
    }
    pd=pd->prox;
  }
}


void inserir (tipo_d **cabeca, tipo_d *d)
{
    tipo_d *pl=*cabeca;
    tipo_d *plant=NULL;
    while (pl != NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(tipo_d));
    pl->qi=d->qi;
    pl->a=d->a;
    pl->qf=d->qf;
    pl->prox=NULL;
    if(plant != NULL)
        plant->prox = pl;
    else
        *cabeca=pl;
}

void imprimir (tipo_d *cabeca)
{
  int c=0;
    tipo_d *pl=cabeca;
    printf("{(");
    while(pl!=NULL)
    {
        if(c>0)printf(" ), (");
        printf("q%d, %d, q%d", pl->qi, pl->a, pl->qf);
        pl=pl->prox;
        c++;
    }
    printf(")}");
}


int buscar(tipo_d *cabeca, int x, int a, lista **cabeca1)
{
  int c=-1;
  tipo_d *pl=cabeca;
  if(pl==NULL)
    {
    printf("\nERRO lista afnd vazia\n");
    return 0;
    }
  while (pl != NULL)
  {
    if(pl->qi==x && pl->a==a)
    {
     buscar1(cabeca1, pl->qf);
     c++;
    }
    pl=pl->prox;
  }
pl=cabeca;
return 0;
}
void inserir1 (lista **cabeca, int x)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    while (pl != NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(lista));
    pl->c=x;
    pl->prox=NULL;
    if(plant != NULL)
        plant->prox = pl;
    else
        *cabeca=pl;
}
void imprimir1 (lista *cabeca)
{
    lista *pl=cabeca;
    int y=0;
    while(pl!=NULL)
    {
      if(y==0)
        printf("{%d", pl->c);
      else
        printf("%d,",pl->c);
     pl=pl->prox;
    }
    printf("}");
}
/*insere x caso nao exista na lista*/
int buscar1(lista **cabeca, int x)
{
  int c = 0;
  lista *pl=*cabeca;

  while (pl != NULL)
  {
     if(pl->c==x)
       c++;

     pl=pl->prox;
  }

  if(c==0)
  {
    inserir1(cabeca, x);
    return 1;
  }
  return 0;

}

void ordena (lista **cabeca)
{
   lista *pl=*cabeca, *plprox=NULL;
   int t, a;


   do
   {
    pl=*cabeca;
    a=0;
    while(pl->prox!=NULL)
    {
     plprox=pl->prox;

     if(pl->c > plprox->c)
     {
       t=pl->c;
       pl->c=plprox->c;
       plprox->c=t;
       pl=pl->prox;
       a=1;
     }
     else
      pl=pl->prox;
    }
  }while(a!=0);

}



void imprimir_c (tipo_c *cabeca)
{
  int x, y=0;
  tipo_c *pc=cabeca;

  while(pc!=NULL)
  {
    printf("\np%d={",y);
    for(x=0; x < pc->c; x++)
    {
      if(x!=0)
        printf(",");
      printf("%d",pc->p[x]);
    }
    printf("}\n");
    pc=pc->prox;
    y++;
  }
}

void inserir_c (tipo_c **cabeca, lista *cabeca1, int c)
{
    int x=0;
    tipo_c *pc=*cabeca, *pcant=NULL;

    lista *pl=cabeca1;
     while (pc != NULL)
    {
        pcant=pc;
        pc=pc->prox;
    }

    pc=malloc(sizeof(lista));
    pc->p=(int *)calloc(c,sizeof(int));
    pc->c=c;
    while(pl!=NULL)
    {
     pc->p[x]=pl->c;
     pl=pl->prox;
     x++;
    }


    if(pcant != NULL)
      pcant->prox = pc;
    else
      *cabeca=pc;
}
int comp_afd1(lista *cabeca, tipo_c *cabeca1, int c)
{
  int x, y=0;
  lista *pl=cabeca;
  tipo_c *pc=cabeca1;
  if(pc==NULL)
    printf("pc esta apontando para NULL, precisa retornar um valor\n");

  while(pc!=NULL)
  {
    pl=cabeca;
    int x=0;
    if(c==pc->c)
    {
      while (pl != NULL)
      {
        if(pl->c==pc->p[x])
          return y;
        pl=pl->prox;
        x++;
      }

    }
    pc=pc->prox;
    y++;
  }
  return -1;
}

void imprimir_c1 (tipo_c *cabeca)
{
  int y=0;
  tipo_c *pc=cabeca;

  while(pc!=NULL)
  {

    if(y==0)
      printf("{p%d",y);
    else
      printf(",p%d",y);

    pc=pc->prox;
    y++;
  }
  printf("};");
}

