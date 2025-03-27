#ifndef MEMORIES

#define MEMORIES

typedef enum
{
    Food,
    Water,
    Shelter,
    Danger,
} MemoryType;

typedef struct {
    int x, y;  // location of the memory
    float importance;  // importance rating (-1 to 1)
    MemoryType type;  // type of event (food, danger, shelter, etc.)
} Memory;

#endif