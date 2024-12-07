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

// Function to update the particle's position and apply gravity and damping
void update_particle(Particle* ball) {
    // Update velocity with gravity
    ball->vy -= GRAVITY * TIME_STEP;  // vy decreases (falling down)

    // Update position based on velocity
    ball->x += ball->vx * TIME_STEP;  // Horizontal movement
    ball->y += ball->vy * TIME_STEP;  // Vertical movement

    // Check if the ball hits the ground
    if (ball->y <= 0) {
        ball->y = 0;  // Set y to 0 to prevent going below ground level
        ball->vy *= -DAMPING;  // Reverse vertical velocity and apply damping
    }
}

int main() {
    // Starting at (x=0, y=10), with velocity vx=2 m/s, vy=5 m/s
    Particle ball = {0.0, 10.0, 2.0, 5.0}; 

    // Print initial details
    printf("Starting particle simulation...\n");
    printf("Initial Position: (%.2f, %.2f)\n", ball.x, ball.y);
    printf("Initial Velocity: (%.2f, %.2f)\n", ball.vx, ball.vy);

    // Run the simulation for 100 steps
    for (int i = 0; i < 100; i++) {
        update_particle(&ball);  // Update particle properties

        // Print updated position and velocity
        printf("Step %d: Position = (%.2f, %.2f), Velocity = (%.2f, %.2f)\n", 
               i+1, ball.x, ball.y, ball.vx, ball.vy);

        // Stop the simulation if the ball's movement becomes insignificant
        if (ball.vy > -0.1 && ball.y == 0) {
            printf("Ball has stopped bouncing.\n");
            break;
        }
    }

   
    return 0;
}
