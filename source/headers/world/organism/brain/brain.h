#ifndef BRAIN

#define BRAIN

#include "memories.h"

#define MAX_MEMORIES 20

typedef struct
{
    Memory memories[MAX_MEMORIES];
    int memoryCount;
    int speciesMaxMemories;
} Brain;

#endif