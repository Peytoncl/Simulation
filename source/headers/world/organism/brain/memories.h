#ifndef MEMORIES

#define MEMORIES

typedef enum
{
    Food,
    Danger,
    Shelter,
    Water
} MemoryType;

typedef struct {
    int x, y;  // location of the memory
    float value;  // good/bad rating (-1 (bad) to 1 (good))
    MemoryType type;  // type of event (food, danger, shelter, etc.)
} Memory;

#endif