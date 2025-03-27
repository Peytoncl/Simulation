#ifndef ORGANISMS

#define ORGANISMS

#include "brain/brain.h"

typedef struct
{
    Brain brain;
    
    double size; // total size value of organism, determines many factors such as brain size, and memory capacity
} Organism;

#endif