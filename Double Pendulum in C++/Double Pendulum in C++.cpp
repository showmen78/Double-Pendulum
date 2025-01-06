#include "raylib.h"
#include <cmath>

// Constants for the double pendulum
const float g = 10.0f; // Gravitational acceleration
float m1 = 5.0f, m2 = 5.0f; // Masses of the bobs
float l1 = 200.0f, l2 = 150.0f; // Lengths of the strings
float theta1 = PI / 2.0f, theta2 = -PI / 2.0f; // Initial angles
float theta1dot = 0.0f, theta2dot = 0.0f; // Angular velocities
float dt = 0.001f; // Time step
float timeScale = 200; 
const Color backgroundColor = { 8, 159, 164, 0.8 };


// Screen dimensions
const int screenWidth = 800;
const int screenHeight = 600;

int main() {
    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Double Pendulum - Showmen Dey");
    SetTargetFPS(60);

    // Pivot point
    Vector2 pivot = { screenWidth / 2.0f, screenHeight / 4.0f };

    // Simulation loop
    while (!WindowShouldClose()) {
        // Calculate angular accelerations
        float theta1ddot = (-0.5f * g * m1 * sin(theta1)
            - 0.25f * g * m2 * sin(theta1 - 2 * theta2)
            - 0.25f * g * m2 * sin(theta1)
            - 0.25f * l1 * m2 * sin(2 * theta1 - 2 * theta2) * theta1dot * theta1dot
            - 0.5f * l2 * m2 * sin(theta1 - theta2) * theta2dot * theta2dot)
            / (l1 * (0.5f * m1 - 0.25f * m2 * cos(2 * theta1 - 2 * theta2) + 0.25f * m2));

        float theta2ddot = (0.25f * g * m1 * sin(2 * theta1 - theta2)
            - 0.25f * g * m1 * sin(theta2)
            + 0.25f * g * m2 * sin(2 * theta1 - theta2)
            - 0.25f * g * m2 * sin(theta2)
            + 0.5f * l1 * m1 * sin(theta1 - theta2) * theta1dot * theta1dot
            + 0.5f * l1 * m2 * sin(theta1 - theta2) * theta1dot * theta1dot
            + 0.25f * l2 * m2 * sin(2 * theta1 - 2 * theta2) * theta2dot * theta2dot)
            / (l2 * (0.5f * m1 - 0.25f * m2 * cos(2 * theta1 - 2 * theta2) + 0.25f * m2));

        // Update angular velocities and positions
        theta1dot += theta1ddot * dt*timeScale  ;
        theta1 += theta1dot * dt *timeScale ;

        theta2dot += theta2ddot * dt * timeScale;
        theta2 += theta2dot *dt* timeScale;

        // Calculate bob positions
        Vector2 bob1 = { pivot.x + l1 * sin(theta1), pivot.y + l1 * cos(theta1) };
        Vector2 bob2 = { bob1.x + l2 * sin(theta2), bob1.y + l2 * cos(theta2) };

        // Drawing
        BeginDrawing();
        ClearBackground(backgroundColor);

        // Draw pivot
        DrawCircleV(pivot, 5, BLACK);

        // Draw strings
        DrawLineV(pivot, bob1, WHITE);
        DrawLineV(bob1, bob2, WHITE);

        // Draw bobs
        DrawCircleV(bob1, 10, WHITE);
        DrawCircleV(bob2, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
