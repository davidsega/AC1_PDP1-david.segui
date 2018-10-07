#ifndef _LLISTABIDORD_H

	#define _LLISTABIDORD_H

//------------------- Llibreries ----------------
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>


/**
 * Struct Node format  per l'element de la llisita
 * i conte un punter que apunta al següent struct
 * de tipus Node i té un altre punter que apunta
 * a l'element anterior
 */
  typedef struct N{
    int e;
    struct N* seg;
    struct N* ant;
  }Node;

/**
 * Struct que conte els 3 punters que formen la LlistaBIDord
 * el pri es un punter que apunta a l'estructura node i apuntara
 * al element "fantasma" primer de la LlistaBIDord.
 * El segon punter, ult apunta a l'estructura node i apuntara al element fantasma
 * que indica el final de la LlistaBIDord
 * El tercer punter apunta a l'estructura Node i es el nostre pdi mitjansant el
 * qual ens desplasarem per la LlistaBIDord
 */
  typedef struct{
    Node* pri;
    Node* ult;
    Node* pdi;
  }LlistaBIDord;

/**
 * Funcio que inicialitza la LlistaBIDord, afegeix els Nodes de pri i ult i
 * deixa la Llista llesta per ser utilitzada
 * @return LlistaBIDord l;
 */
LlistaBIDord LlistaBIDord_Crea();
/**
 * Procediment que insereix un element en la llista ordenat de menor a major
 * @param l punters a la Llista pasats per referencia
 * @param e element a inserir en la Llsita
 */
void LlistaBIDord_Insereix(LlistaBIDord*l,int e);
/**
 * Funcio que consulta l'element on es troba el pdi i el retorna
 * @param  l punters a la Llista passats per referencia
 * @return  int e element de la llista on es troba el pdi
 */
int LlistaBIDord_Consulta(LlistaBIDord l);
/**
 * Procediment que Borra l'element on es troba el pdi
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_Esborra(LlistaBIDord*l);
/**
 * Procediment que avansa una posicio el pdi en la llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_Avansa(LlistaBIDord*l);
/**
 * Procediment que retrocedeix un element el pdi en la llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_Retrocedeix(LlistaBIDord*l);
/**
 * Procediment que situa el pdi en el primer element de la Llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_VesInici(LlistaBIDord*l);
/**
 * Procediment que situa el pdi en l'ultim element de la llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_VesFi(LlistaBIDord*l);
/**
 * Funcio que consulta si la llista es troba en l'inici
 * @param  l Llista passada per valor
 * @return  comprova si la llsita es a l'inici
 */
int LlistaBIDord_Inici(LlistaBIDord l);
/**
 * Funcio que consulta si la llista es troba en l'ultim element
 * @param  l Llista passada per valor
 * @return comprova si la llsita es troba al final
 */
int LlistaBIDord_Fi(LlistaBIDord l);
/**
 * Funcio que retorna cert si la llista es buida
 * @param  l Llista passada per valor
 * @return int comprova si la llsita es buida
 */
int LlistaBIDord_Buida(LlistaBIDord l);
/**
 * Procediment que destrueix la Llista
 * @param l punters a la Llista passats per referencia
 */
void LlistaBIDord_Destrueix(LlistaBIDord* l);
#endif
