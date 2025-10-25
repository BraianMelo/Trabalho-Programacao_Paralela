#ifndef CRIVO_DE_ERATOSTENES_H
#define CRIVO_DE_ERATOSTENES_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <mpi.h>
#include <string.h>

#include "Lista.h"

bool encontrar_primos(Lista *lista);
bool encontrar_primos_MPI(Lista *lista);

#endif
