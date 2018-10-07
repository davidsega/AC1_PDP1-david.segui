#ifndef _LLISTABIDORD_H

	#define _LLISTABIDORD_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>


  typedef struct N{
    int e;
    struct N* seg;
    struct N* ant;
  }Node;

  typedef struct{
    Node* pri;
    Node* ult;
    Node* pdi;
  }LlistaBIDord;

LlistaBIDord LlistaBIDord_Crea();
void LlistaBIDord_Insereix(LlistaBIDord*l,int e);
int LlistaBIDord_Consulta(LlistaBIDord l);
void LlistaBIDord_Esborra(LlistaBIDord*l);
void LlistaBIDord_Avansa(LlistaBIDord*l);
void LlistaBIDord_Retrocedeix(LlistaBIDord*l);
void LlistaBIDord_VesInici(LlistaBIDord*l);
void LlistaBIDord_VesFi(LlistaBIDord*l);
int LlistaBIDord_Inici(LlistaBIDord l);
int LlistaBIDord_Fi(LlistaBIDord l);
int LlistaBDIord_Buida(LlistaBIDord l);
void LlistaBIDord_Destrueix(LlistaBIDord* l);
#endif
