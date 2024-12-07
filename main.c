#include <stdio.h>


#define GRAVITY 9.8    // m/s^2
#define TIME_STEP 0.1  // Time step for the simulation
#define DAMPING 0.8    // Energy lost on each bounce

// Particle (Ball) structure
typedef struct {
    double x;   // Horizontal position
    double y;   // Vertical position
    double vx;  // Horizontal velocity
    double vy;  // Vertical velocity
} Particle;

int main() {
    // Starting at (x=0, y=10), with velocity vx=2 m/s, vy=5 m/s
    Particle ball = {0.0, 10.0, 2.0, 5.0}; 
    
    // Print initial details
    printf("Starting particle simulation...\n");
    printf("Initial Position: (%.2f, %.2f)\n", ball.x, ball.y);
    printf("Initial Velocity: (%.2f, %.2f)\n", ball.vx, ball.vy);

   
    return 0;
}
