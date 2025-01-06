# Double Pendulum Simulation

This project implements a **double pendulum** simulation in C++ using the **raylib** graphics library. The double pendulum is a fascinating system in classical mechanics that exhibits chaotic behavior due to its sensitivity to initial conditions.

## Overview

A double pendulum consists of two pendulums attached end-to-end. The dynamics are governed by nonlinear equations of motion, which are influenced by gravity, the masses of the bobs, and the lengths of the strings.

This simulation visually represents the motion of the pendulum and calculates the positions of the bobs in real-time using numerical integration.

---

## Formulas for Motion

The equations of motion for the double pendulum are derived from Lagrangian mechanics:

1. **Angular Acceleration of the First Bob (θ₁''):**

   θ₁'' = 
   (-0.5 * g * m₁ * sin(θ₁) 
   0.25 * g * m₂ * sin(θ₁ - 2θ₂) 
   0.25 * g * m₂ * sin(θ₁) 
   0.25 * l₁ * m₂ * sin(2θ₁ - 2θ₂) * θ₁'² 
   0.5 * l₂ * m₂ * sin(θ₁ - θ₂) * θ₂'²) 
   ÷ 
   (l₁ * (0.5 * m₁ - 0.25 * m₂ * cos(2θ₁ - 2θ₂) + 0.25 * m₂))
   

2. **Angular Acceleration of the Second Bob (θ₂''):**

   θ₂'' = 
   (0.25 * g * m₁ * sin(2θ₁ - θ₂) 
    0.25 * g * m₁ * sin(θ₂) + 0.25 * g * m₂ * sin(2θ₁ - θ₂)0.25 * g * m₂ * sin(θ₂)  + 0.5 * l₁ * m₁ * sin(θ₁ - θ₂) * θ₁'² + 0.5 * l₁ * m₂ * sin(θ₁ - θ₂) * θ₁'² + 0.25 * l₂ * m₂ * sin(2θ₁ - 2θ₂) * θ₂'²) 
   ÷ 
   (l₂ * (0.5 * m₁ - 0.25 * m₂ * cos(2θ₁ - 2θ₂) + 0.25 * m₂)).
   

---

## Initial Parameters

The simulation starts with the following parameters:

- **Mass of the first bob (m₁):** 5.0 units
- **Mass of the second bob (m₂):** 5.0 units
- **Length of the first string (l₁):** 200.0 pixels
- **Length of the second string (l₂):** 150.0 pixels
- **Initial angle of the first bob (θ₁):** π/2 radians
- **Initial angle of the second bob (θ₂):** -π/3 radians
- **Gravitational acceleration (g):** 10.0 units
- **Time step (Δt):** 0.001 seconds

---

## Features

- **Real-time Simulation:** The pendulum motion is simulated and rendered in real-time.
- **Chaotic Behavior:** The system demonstrates chaotic motion sensitive to initial conditions.
- **Visuals:**
  - The pivot is represented by a green circle.
  - The bobs are represented by red and blue circles.
  - Strings connecting the pivot and bobs are drawn as white lines.

---


