---
publishDate: 2025-12-29
title: MYOSA EBAFS – Ergonomic Biomechanics and Active Feedback System
excerpt: A multi-sensor ergonomic system combining fitness gamification, posture enforcement, and environment monitoring.
tags: ["ergonomics", "fitness", "health-tech", "myosa", "EBAFS"]
---
<p align="center">
  <img src="images/cover-image.png" width="800"><br/>
  <i>cover image</i>
</p>

## MYOSA EBAFS

The **MYOSA Ergonomic Biomechanics and Active Feedback System (EBAFS)** integrates three modules — active posture compliance, gamified exercise, and environmental monitoring — into a unified platform.

## Acknowledgements

We would like to express our sincere gratitude to **MYOSA** and the **IEEE Sensors Council** for providing the essential mini‑kit and technical resources that enabled us to successfully complete the MYOSA EBAFS project. Their support has been invaluable in turning the concept into a working prototype. We are deeply thankful to **Arun Mathiyalagan Sir** for his constant encouragement, and to the **HOD of the ECE Department of Panimalar Engineering College Dr. Rajakumar Sir** for his guidance. Finally, we extend our heartfelt thanks to our **family**, whose motivation and support made this project possible.  
This project would not have been possible without the combined support of these mentors and institutions, whose contributions ensured that MYOSA EBAFS could evolve from an idea into a practical, interactive, and impactful ergonomics system.

## Overview

* **Posture Module:** Enforces active compliance by blacking out the laptop screen and sounding a buzzer when slouching is detected. User needs to sit back straight to be able to resume work.
* **Fitness Module:** Gamifies exercise through a custom developed game where the NemoBird character jumps to avoid tree obstacles when a bicep curl is performed.
* **Environment Module:** Monitors ambient light, pressure, and temperature, issuing warnings via buzzer and OLED display in low-light conditions.

## Features
### 1. Posture Correction 
- An accelerometer sensor is strapped to the user's shoulder and the system calibrates when the user sits with the correct posture.
- If slouching is detected: buzzer sounds and the **laptop screen blacks out**. The user can resume their laptop work only if they return to correct posture.
- Unlike mobile‑notification systems, the user must physically sit back straight for the buzzer to stop and the screen to become normal again.
- Ensures **active compliance** rather than passive reminders.
- Targets **freelancers and laptop users** to help prevent **lumbar spine pain** and **cervicogenic headaches**
<p align="center">
  <img src="images/active-posture-correction.png" width="800"><br/>
  <i>active posture correction</i>
</p>


https://github.com/user-attachments/assets/66c64479-a4fb-4934-b4fe-21787e479275

### 2. Fitness Game Integration 
- A **custom game** was built in Unityhub.
- Accelerometer attached to a dumbbell detects bicep curls (0° → 90°).
- When the user performs one full lift and the threshold is reached, the **NemoBird character jumps to avoid tree obstacles**.
- Next jump is not initiated unless user moves dumbell to resting position to **prevent false jumps**.
- The game accesses the sensors signals in the serial monitor via **serial communication** and sends the jump signal from the sensor to the player, gamifying exercise in real time.
<p align="center">
  <img src="images/gliding-nemobird-game.png" width="800"><br/>
  <i>gamified exercise</i>
</p>

