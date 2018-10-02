#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "LlistaBIDord.h"
#define VALOR_INDEFINIT -12345;


LlistaBIDord LlistaBIDord_Crea(){
  Node * aux = NULL;
  LlistaBIDord l;
  l.pri=(Node*)malloc(sizeof(Node));
  if(l.pri == NULL){
    printf("Error al crear la LlistaBDIord en el malloc de l.pri\n");
  }else{
    l.ult=(Node*)malloc(sizeof(Node));
    if(l.ult== NULL){
      printf("Error al crearla LlistaBDIord en el malloc de l.ult\n");
      free(l.pri);
    }else{
      l.pri->e= VALOR_INDEFINIT;
      l.pri->seg = l.ult;
      l.pri->ant = NULL;
      l.ult->ant= l.pri;
      l.ult->seg= NULL;
      l.pdi = l.ult;
    }
  }
  return l;
}

void LlistaBIDord_Insereix(LlistaBIDord*l,int e){ //INSERCIO PER L'ESQUERRA
  Node* aux;
  aux = (Node*)malloc(sizeof(Node));
  if(aux == NULL){
    printf("Error al inserir l'eliement %d\n",e);
  }else{
    aux->e=e;
    if(l->pri == l->ult->ant ){
      l->pri->seg =aux;
      l->ult->ant = aux;
      aux->ant = l->pri;
      aux->seg = l->ult;
    }else{
      Node*aux2;
      aux2 = l->pri->seg;
      while(e>aux2->e || (aux2->seg != l->ult)){
        aux2 = aux2->seg;
      }
      aux->seg = aux2;
      aux->ant = aux2->ant;
      aux2->ant->seg= aux;
      aux2->ant = aux;
    }
  }
}

int LlistaBIDord_Consulta(LlistaBIDord l){
  if(l.pdi != l.ult || l.pdi != l.pri){
    return l.pdi->e;
}else{
    printf("La llista es troba buida\n");
    return l.pdi->e; // Sera el noste VALOR_INDEFINIT
  }
}

void LlistaBIDord_Esborra(LlistaBIDord*l){
  if((l->pdi != l->ult) ^ (l->pdi != l->pri)){
    Node* aux;
    aux = l->pdi;
    l->pdi->ant->seg= l->pdi->seg;
    l->pdi->seg->ant =l->pdi->ant;
    l->pdi = l->pdi->seg;
    aux->seg = NULL;
    aux->ant = NULL;
    free(aux);
  }else{
    printf("No s'ha pogut esborrar cap element, el pdi es troba a l'inici o al final de la llista \n");
  }
}
void LlistaBIDord_Avansa(LlistaBIDord*l){
  if(l->pdi->seg != l->ult){
      l->pdi = l->pdi->seg;
  }else{
    printf("No es pot avançar en la llista, aquesta es troba al final");
  }

}
void LlistaBIDord_Retrocedeix(LlistaBIDord*l){
  if(l->pdi->ant != l->pri){
      l->pdi= l->pdi->ant;
    }else{
      printf("No es pot retrocedir en la llista, aquesta es troba al inici");
    }
}
void LlistaBIDord_VesInici(LlistaBIDord*l){
  l->pdi =l->pri->seg;
}
void LlistaBIDord_VesFi(LlistaBIDord*l){
  l->pdi= l->ult->ant;
}
int LlistaBIDord_Fi(LlistaBIDord l){
  return (l.ult == l.pdi);
}
int LlistaBIDord_Inici(LlistaBIDord l){
    return (l.pri == l.pdi);
}

int LlistaBIDord_Buida(LlistaBIDord l){
  if(l.ult != NULL){
    if((l.pri->seg ==l.ult)){
      return 0;
    }
  }else{
    return 1;
  }
}

void LlistaBIDord_Destrueix(LlistaBIDord* l){
  Node* aux;
  l->pdi = l->pri;
  l->pri = NULL;
  while(l->pdi != l->ult){
    aux = l->pdi;
    l->pdi = l->pdi->seg;
    l->pdi->ant= NULL;
    aux->seg = NULL;
    free(aux);
  }
  aux = l->pdi;
  l->pdi = NULL;
  l->ult = NULL;
  free(aux);
}
