// Programa:		main
// Descripción:		EX1 LlistaBIDord
// Autor:			David Seguí
// Fecha ult. modifcación: 07/10/2018
//--------------------  LLIBRERIES ------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------- LLIBRERIES PROPIES --------------------
#include "LlistaBIDord.h"


/**
 * El main del programa per fer el testing realitza el següent procediment
 * insereix elements en la llista, n'elimina 1 y la recorre consultant
 * si els elements es troben ordenaats i despres la recorre de final cap a inici
 * @param  argc,argv Parametres d'entrada (no s'ha utilitzat cap)
 * @return      int finalitza el main
 */
int main (int argc,char* argv[]){
  int i = 0;
  LlistaBIDord l;
  l= LlistaBIDord_Crea();
  InsereixElement(&l,1);
  InsereixElement(&l,10);
  InsereixElement(&l,4);
  InsereixElement(&l,8);
  LlistaBIDord_VesInici(&l);
  printf("Inici de la llista\n");
  printf("element esborrat: %d\n",LlistaBIDord_Consulta(l));
  LlistaBIDord_Esborra(&l);
  printf("element:%d\n",LlistaBIDord_Consulta(l));
  while(LlistaBIDord_Fi(l) != 1){
    LlistaBIDord_Avansa(&l);
    printf("avansa llista\nelement: %d\n",LlistaBIDord_Consulta(l));
  }
  LlistaBIDord_VesFi(&l);
  printf("element: %d\n",LlistaBIDord_Consulta(l));
  while(LlistaBIDord_Inici(l) != 1){
    LlistaBIDord_Retrocedeix(&l);
    printf("retrocedeix llista\nelement: %d\n",LlistaBIDord_Consulta(l));
  }
  LlistaBIDord_Destrueix(&l);
  if(LlistaBIDord_Buida(l)){
    printf("Procediment correcte\n" );
  }else{
    printf("Error en l'eliminació de la llista\n" );
  }
  return 0;
}
/**
 * Funcio que insereix elements en la LlistaBID
 * @param l     punters a la Llista passats per referencia
 * @param valor valor a inserir a la llista
 */
void InsereixElement(LlistaBIDord* l,int valor){
	printf("Inserim %d\n",valor);
	LlistaBIDord_Insereix(l,valor);
}
