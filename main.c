#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LlistaBIDord.h"

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
void InsereixElement(LlistaBIDord* l,int valor){
	printf("Inserim %d\n",valor);
	LlistaBIDord_Insereix(l,valor);
}
