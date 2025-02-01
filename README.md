# Geant4 Neutron Capture Simulation 
This project simulates neutron capture using Geant4 for LEGEND-4 experiments. It models neutron interactions with different materials and analyzes the results using ROOT. This work was part of my research assistant role at the University of Tübingen.



## Getting Started

### Prerequisites

*   **Geant4:** You need to have Geant4 installed on your system. Follow the [Geant4 installation guide](https://geant4.web.cern.ch/docs/getting-started).
*   **CMake:** Ensure that CMake is installed on your system.
*   **ROOT:** (Optional) Required for viewing the output ROOT file. [ROOT Installation](https://root.cern/install/)

### Installation and Compilation

1.  **Clone the repository:**

    ```bash
    git clone [repository URL]
    cd neutron_capture_project
    ```
2.  **Create a build directory:**

    ```bash
    mkdir build
    cd build
    ```
3.  **Run CMake:**

    ```bash
    cmake ../
    ```
4.  **Compile the code:**

    ```bash
    make -j4 # Use number of threads to make faster
    ```

### Running the Simulation

1.  **Execute the simulation:**

    ```bash
    ./neutron_capture_project
    ```
2.  **Visualization**
    *  Create `init_vis.mac` in same directory of executable.
    ```
        /control/verbose 2
        /run/verbose 2
        /vis/open OGL
        /vis/drawVolume
        /vis/viewer/set/autoRefresh true
        /vis/viewer/set/viewpointVector 1 1 1
        /vis/viewer/zoom 1.5
    ```
    *   Run:
  ```bash
    ./neutron_capture_project
   ```

### Analyzing Results

*   The simulation results are saved in a `neutron_capture.root` file.
*   Use `root neutron_capture.root` to open it.
*   In `root`, you can view the histograms with `TBrowser b`. Click on the root file, `Histo`, `GdCapture`, and `WaterCapture`.
*   The `GdCapture` histogram shows the number of neutron capture events in the Germanium volume, while `WaterCapture` shows captures in the water.
*   You can use the analysis to compare the neutron captures to verify the 90% capture claim for Gadolinium.

# GEANT4 Neutron Capture Simulation

This project simulates neutron capture using **Geant4** for **LEGEND-4** experiments. It models interactions of neutrons with different materials and analyzes results using ROOT.

## 🚀 Features
- Simulates neutron capture using **GEANT4**
- Supports materials like **Water (H₂O), Heavy Water (D₂O), and Gadolinium Sulphate**
- Data analysis with **ROOT and Python**
- Monte Carlo simulations for nuclear interactions

## 📦 Installation
 **Clone this repository**
   ```bash
   git clone git@github.com:QED137/GEANT4_Netron_Capture_LEGEND4.git
   cd GEANT4_Netron_Capture_LEGEND4
```


[ MIT License]

