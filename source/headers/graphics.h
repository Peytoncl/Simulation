#ifndef GRAPHICS_H

#define GRAPHICS_H

#define WINDOW_W 800
#define WINDOW_H 600

#define TARGET_FPS 60
#define FRAME_TIME (1000.0 / TARGET_FPS) // 1000ms / 60fps = 16.67ms per frame

typedef struct 
{
    float x;
    float y;
} Vector2;

#endif