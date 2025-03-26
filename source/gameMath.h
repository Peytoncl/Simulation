#ifndef GAMEMATH

#define GAMEMATH

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846

unsigned int seed;

void RandomInitialization()
{
    seed = time(NULL);
    srand(seed);
}

int RandomInt(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

float RandomFloat(float min, float max) 
{
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

float Lerp(int a, int b, float t) 
{
    return (float)a + t * ((float)b - (float)a);
}

#endif