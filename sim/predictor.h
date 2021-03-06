///////////////////////////////////////////////////////////////////////
////  Copyright 2015 Samsung Austin Semiconductor, LLC.                //
/////////////////////////////////////////////////////////////////////////
//
#ifndef _PREDICTOR_H_
#define _PREDICTOR_H_

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include "utils.h"


/* FP: Nombre de bits de PC utilisés pour indexer la table, utilisé pour définir la taille de la table */
/* FP: Nombre de bits par entrée la table: 1 => last value, 2 => bimodal, 3 => ... */

//NOTE competitors are allowed to change anything in this file

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

class PREDICTOR {

 /* Exemple simple : prédicteurs à saturation
  *    une seule table indexée par une partie de pc
  *    valeur du compteur comprise entre 0 et countmax
  */
 private:
   uint32_t *table;   		// table contenant les valeurs TAKEN-NOT TAKEN
   uint32_t history_mask;   // masque pour n'accéder qu'aux bits significatifs
   uint32_t history;		// historique

 public:
	 uint32_t history_length;

   PREDICTOR(char *progname, int argc, char *argv[]);

   // The interface to the functions below CAN NOT be changed
	bool GetPrediction();
	void UpdatePredictor(bool resolveDir);
	void TrackOtherInst(UINT64 PC, OpType opType, bool branchDir, UINT64 branchTarget);

   // Contestants can define their own functions below
};
#endif
