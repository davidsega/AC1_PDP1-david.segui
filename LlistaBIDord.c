// Programa:		LlistaBIdord
// Descripción:		EX1 LlistaBIDord
// Autor:			David Seguí
// Fecha ult. modifcación: 07/10/2018
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "LlistaBIDord.h"
//--------------------- CONSTANTS DE LA LLISTA  ------------------------------
#define VALOR_INDEFINIT -12345;


//----------------------------------------------------------------------------
/**
 * Funcio que inicialitza la LlistaBIDord, afegeix els Nodes de pri i ult i
 * deixa la Llista llesta per ser utilitzada
 * @return LlistaBIDord l;
 */
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
/**
 * Procediment que insereix un element en la llista ordenat de menor a major
 * @param l punters a la Llista pasats per referencia
 * @param e element a inserir en la Llsita
 */
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
      while((e<aux2->e) ^ (aux2->seg != NULL)){
        aux2 = aux2->seg;
      }
      aux->seg = aux2;
      aux->ant = aux2->ant;
      aux2->ant->seg= aux;
      aux2->ant = aux;
    }
  }
}
/**
 * Funcio que consulta l'element on es troba el pdi i el retorna
 * @param  l punters a la Llista passats per referencia
 * @return  int e element de la llista on es troba el pdi
 */
int LlistaBIDord_Consulta(LlistaBIDord l){
  if(l.pdi != l.ult || l.pdi != l.pri){
    return l.pdi->e;
}else{
    printf("La llista es troba buida\n");
    return l.pdi->e; // Sera el noste VALOR_INDEFINIT
  }
}

/**
 * Procediment que Borra l'element on es troba el pdi
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_Esborra(LlistaBIDord*l){
  if((l->pdi != l->ult) || (l->pdi != l->pri)){
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
/**
 * Procediment que avansa una posicio el pdi en la llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_Avansa(LlistaBIDord*l){
  if(l->pdi->seg != l->ult){
      l->pdi = l->pdi->seg;
  }else{
    printf("No es pot avançar en la llista, aquesta es troba al final");
  }
}
/**
 * Procediment que retrocedeix un element el pdi en la llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_Retrocedeix(LlistaBIDord*l){
  if(l->pdi->ant != l->pri){
      l->pdi= l->pdi->ant;
    }else{
      printf("No es pot retrocedir en la llista, aquesta es troba al inici");
    }
}
/**
 * Procediment que situa el pdi en el primer element de la Llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_VesInici(LlistaBIDord*l){
  l->pdi =l->pri->seg;
}
/**
 * Procediment que situa el pdi en l'ultim element de la llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_VesFi(LlistaBIDord*l){
  l->pdi= l->ult->ant;
}
/**
 * Funcio que consulta si la llista es troba en l'inici
 * @param  l Llista passada per valor
 * @return  comprova si la llsita es a l'inici
 */
int LlistaBIDord_Fi(LlistaBIDord l){
  return (l.ult == l.pdi->seg);
}
/**
 * Funcio que consulta si la llista es troba en l'ultim element
 * @param  l Llista passada per valor
 * @return comprova si la llsita es troba al final
 */
int LlistaBIDord_Inici(LlistaBIDord l){
    return (l.pri == l.pdi->ant);
}
/**
 * Funcio que retorna cert si la llista es buida
 * @param  l Llista passada per valor
 * @return int comprova si la llsita es buida
 */
int LlistaBIDord_Buida(LlistaBIDord l){
  if(l.ult != NULL){
    if((l.pri->seg ==l.ult)){
      return 0;
    }
  }else{
    return 1;
  }
}

/**
 * Procediment que destrueix la Llista
 * @param l punters a la Llista passats per referencia
 */
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
