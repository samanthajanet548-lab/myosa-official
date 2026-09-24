
# GREEN HUNT

### Satellite-Guided Intelligence for Autonomous Harmful Algal Bloom Intervention

GREEN HUNT is an environmental intelligence and autonomous intervention concept designed to identify harmful algal bloom (HAB) hotspots in freshwater bodies and guide an underwater vehicle toward targeted intervention zones.

The project combines **multispectral remote sensing, spatial spectral analysis, mission planning, autonomous underwater vehicle (AUV) design, and ultrasound-based treatment** into a single workflow.

---

## Problem

Harmful algal blooms can significantly affect freshwater ecosystems and water quality. Conventional monitoring and treatment approaches may require extensive surveying, chemical intervention, or high energy consumption.

Deploying an underwater vehicle across an entire water body can also waste valuable onboard energy if the location of the bloom is unknown.

GREEN HUNT addresses this through a simple principle:

> **Detect the hotspot first. Then send the vehicle where intervention is required.**

---

## Our Approach

GREEN HUNT follows a four-stage workflow:

**OBSERVE → DETECT → PLAN → INTERVENE**

1. **Observe**  
   Satellite imagery provides spatial information about the target water body.

2. **Detect**  
   Multispectral information, particularly red and red-edge spectral responses, is analysed using the Normalized Difference Chlorophyll Index (NDCI) to identify chlorophyll-related hotspots.

3. **Plan**  
   The software identifies priority regions and generates an intervention route for the autonomous underwater vehicle.

4. **Intervene**  
   The proposed underwater vehicle carries an ultrasound-based treatment system to perform targeted intervention at the identified hotspot.

---

## Software Prototype

The GREEN HUNT Mission Control platform provides a unified interface for environmental analysis and AUV mission planning.

### Current software features

- Target water-body selection
- Satellite-based spatial visualization
- NDCI spectral analysis
- Spatial hotspot identification
- HAB risk visualization
- Automated mission/waypoint generation
- Virtual AUV intervention route
- Mission logs and telemetry
- Environmental parameter display
- Dark-mode mission-control interface

### Software workflow

```text
Target Water Body
        ↓
Satellite Multispectral Data
        ↓
Spectral Pre-processing
        ↓
NDCI Analysis
        ↓
Hotspot Identification
        ↓
Decision & Mission Planning
        ↓
Virtual AUV Route
        ↓
Targeted Intervention

