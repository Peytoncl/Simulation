#ifndef BRAIN

#define BRAIN

#include "memories.h"

#define MAX_MEMORIES 20

typedef struct
{
    Memory shortTermMemories[MAX_MEMORIES / 2];
    Memory longTermMemories[MAX_MEMORIES];

    int longTermMemoryCount, shortTermMemoryCount; // amount of memories in each section

    int speciesMaxMemories; // this is the long term memories value, and short term memories max is this divided by 2, i also think that this should be determined by the size of the organisms brain and the size of the brain is determined by the organisms size

    double size; // size of brain, based on organism size, determines memory capacity
} Brain;

#endif