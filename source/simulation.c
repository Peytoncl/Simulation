#include "headers/simulation/simulation.h"

#include <stdio.h>

double CurrentWorldTime = 12.0; // current world time
double fixedTimeStep = 0.1; // amount of time that ticks up on the clock
double accumulator = 0.0; // builds up time

void TickTime(double amount) // Ticks the world clock up each frame based on deltaTime
{
    CurrentWorldTime += amount;
    
    if (CurrentWorldTime >= 24.0) CurrentWorldTime = 0.0;
}

void Update(double deltaTime) // Runs each frame
{
    accumulator += deltaTime * 10; // "accumulate" deltaTime for fixed time steps

    while (accumulator >= fixedTimeStep) 
    {
        TickTime(fixedTimeStep);  // tick by 0.1 each second (roughly)

        accumulator -= fixedTimeStep;  // subtract the time we've "ticked"
    }

    printf("Time: %.2f\n", CurrentWorldTime);
}

void Start() // Runs when program starts or is reset
{
    CurrentWorldTime = 12.0;
}
