#include "funcionario.h"

int verificar_funcionario(char *nome){
  FILE *cadastro;
  char linha[100];

  cadastro = fopen("..\\db\\funcionario.txt", "r");

  if(cadastro == NULL){
    printf("Erro ao abrir o arquivo");
    exit(EXIT_FAILURE);
  }

  while(fgets(linha, 100, cadastro) != NULL){
    if(strstr(linha, nome) != NULL){
      fclose(cadastro);
      return 1;
    }
  }

  fclose(cadastro);
  return 0;
}

