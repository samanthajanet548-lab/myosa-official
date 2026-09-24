# 🌊 GREEN HUNT

### Autonomous Sensing and Low-Power Ultrasonic Control for Harmful Algal Blooms

> **A proposed autonomous underwater system for detecting and controlling harmful algal blooms using spectral sensing, discrete-time signal processing, and low-power ultrasonic actuation.**

---

## 📌 Overview

**GREEN HUNT** is a proposed autonomous underwater system designed to monitor freshwater bodies for **harmful algal blooms (HABs)** and provide a targeted, low-power approach for algae control.

The system combines:

- 🌿 Spectral sensing for algae detection
- 📡 Discrete-time signal processing for sensor data analysis
- 🔊 Low-power ultrasonic actuation
- 🤖 Autonomous underwater operation
- ⚙️ Mechanical propulsion using an elastic energy-storage mechanism
- 💾 Time-stamped data logging
- 🛰️ MATLAB-based signal and system simulations

The current work is a **CAD and simulation-based prototype study**. Physical fabrication and experimental water-body validation are planned as future work.

---

## 🎯 Problem Statement

Harmful algal blooms can occur when freshwater bodies experience conditions such as:

- Excess nutrient availability
- Increased water temperature
- Reduced water movement
- Favorable conditions for rapid algal growth

Large-scale monitoring and treatment can be expensive, energy-intensive, or dependent on chemical treatment.

GREEN HUNT explores a compact autonomous system that can **sense → process → respond**, while reducing dependence on continuous battery-powered propulsion and chemical intervention.

---

## 💡 Proposed Solution

GREEN HUNT follows a three-stage approach:

```text
       WATER BODY
           │
           ▼
   ┌─────────────────┐
   │  Spectral Sensing│
   │     AS7341       │
   └────────┬────────┘
            │
            ▼
   ┌─────────────────┐
   │ Signal Processing│
   │    & Analysis    │
   │     MATLAB       │
   └────────┬────────┘
            │
            ▼
   ┌─────────────────┐
   │ Algae Detection  │
   │  & Concentration │
   │     Estimation   │
   └────────┬────────┘
            │
            ▼
   ┌─────────────────┐
   │ Ultrasonic       │
   │ Control System   │
   └────────┬────────┘
            │
            ▼
   Pressure variation influences
   algal buoyancy and water-column
   distribution
