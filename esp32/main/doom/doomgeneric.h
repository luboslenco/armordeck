#ifndef DOOM_GENERIC
#define DOOM_GENERIC

#include <stdlib.h>
#include <stdint.h>

#ifndef DOOM_HALFRES
#define DOOMGENERIC_RESX 320
#define DOOMGENERIC_RESY 200
#else
#define DOOMGENERIC_RESX 160
#define DOOMGENERIC_RESY 100
#endif

uint32_t DG_GetTicksMs();
int DG_GetKey(int* pressed, unsigned char* key);

#endif //DOOM_GENERIC
