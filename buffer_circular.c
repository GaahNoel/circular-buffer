#include <stdio.h>
#include <stdlib.h>
int const TAM_MAX = 5;
typedef struct processo {
  char *nomeTarefa;
  int memoAloc;
  int tempoExec;
} Processo;

struct no {
  Processo processo;
  struct no *proximoNo;
};

int adiciona_processo(struct no **inicio_ptr, struct no **fim_ptr, int *tamanho_lista);
void imprime_lista(struct no *inicio_ptr, int tamanho_lista);
Processo remove_processo(struct no **inicio_ptr, struct no **fim_ptr, int *tamanho_lista);


void main() {
  struct no *inicio_ptr, *fim_ptr;
  int tamanho_lista = 0;
  int opcao=0;

  do{
    system("clear");
    printf("1 - Adicionar processo\n2 - Remover Processo\n3 - Listar processos\n6 - Sair\nDigite a opca que deseja: ");
    scanf("%d", &opcao);
    switch(opcao) {
      case 1: 
        int adicionado = adiciona_processo(&inicio_ptr, &fim_ptr, &tamanho_lista);
        system("pause");
        break;
      case 2:
        Processo processo_removido = remove_processo(&inicio_ptr, &fim_ptr, &tamanho_lista);
        system("pause");
        break;
      case 3:
        imprime_lista(inicio_ptr, tamanho_lista);
        system("pause");
        break;
      default: 
        opcao = 6;
    }
  }while(opcao!=6);
}

int adiciona_processo(struct no **inicio_ptr, struct no **fim_ptr, int *tamanho_lista) {
  system("clear");
  struct no *aux;
  struct no novoNo;
  Processo p;

  if(*tamanho_lista >= TAM_MAX) {
    printf("Erro, lista cheia!\n");
    return 0;
  }

  p.nomeTarefa = (char*) malloc(21);
  printf("Digite o nome da tarefa:\n");
  scanf("%s", p.nomeTarefa);
  fflush(stdin);

  printf("Digite a quantidade de memoria alocada:\n");
  scanf("%d", &(p.memoAloc));
  fflush(stdin);

  printf("Digite o tempo de execucao:\n");
  scanf("%d", &(p.tempoExec));
  fflush(stdin);

  novoNo.processo = p;

  if((*tamanho_lista) == 0 ) {
    *inicio_ptr = malloc(sizeof(struct no));
    **inicio_ptr = novoNo;
    *fim_ptr = malloc(sizeof(struct no));
    (*inicio_ptr)->proximoNo = *fim_ptr;
  } else {
    **fim_ptr = novoNo;
    aux = *fim_ptr;

    if ((*tamanho_lista) == TAM_MAX - 1) {
      (*fim_ptr) = (*inicio_ptr);
    } else {
      *fim_ptr = malloc(sizeof(struct no));
    }
    aux->proximoNo = *fim_ptr;
  }

  (*tamanho_lista)++;
  printf("Adicionado com sucesso!\n");
}

void imprime_lista(struct no *inicio_ptr, int tamanho_lista) {
  int i; 

  for(i = 0 ; i < tamanho_lista; i++) {
    printf("Nome: %s - Memoria Alocada: %d - Tempo de execucao: %d\n\n",(inicio_ptr->processo).nomeTarefa, (inicio_ptr->processo).memoAloc, (inicio_ptr->processo).tempoExec);
    inicio_ptr = (inicio_ptr->proximoNo);
  }
}

Processo remove_processo(struct no **inicio_ptr, struct no **fim_ptr, int *tamanho_lista){
  system("clear");
  if(*tamanho_lista == 0) {
    printf("Nao e possivel remover, lista vazia!\n");
  }
  Processo p = (*inicio_ptr)->processo;
  *inicio_ptr = (*inicio_ptr)->proximoNo;
  (*tamanho_lista)--;
  printf("Removido com sucesso!\n");
  return p;
}

