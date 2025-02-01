# Geant4 Neutron Capture Simulation with WLGD Geometry
This project simulates neutron capture using Geant4 for LEGEND-4 experiments. It models neutron interactions with different materials and analyzes the results using ROOT. This work was part of my research assistant role at the University of Tübingen.

## Features

*   **Accurate Physics:** Employs the `G4NeutronHP` physics constructor for high-precision neutron transport and interaction modeling.
*   **Neutron Capture Analysis:** Tracks neutron capture events in Germanium (`Ge_phys`) and water (`Water_phys`), allowing for a comparison of capture rates.
*   **Flexible Source:** Simulates a neutron source with configurable energy in thermal region.
*   **Root Output:** Stores simulation results in a ROOT file for easy analysis using ROOT.
*   **Bias Option**: The project allows the user to bias the neutron capture using the command `/WLGD/bias/setNeutronBias` to enhance the neutron capture probability.


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

### Configuration

*   **Geometry:**
    *   Set the desired geometry using the command `/WLGD/detector/setGeometry [baseline|alternative|hallA]` (e.g., `/WLGD/detector/setGeometry baseline` in a macro file or interactive session).
    *   The default geometry is `baseline` if not set.
*   **Neutron Biasing:**
     *   You may need to use the neutron biasing feature in `WLGDDetectorConstruction` by calling the command, `/WLGD/bias/setNeutronBias` with a higher number.
*   **Number of Events:**
    *   Change the number of events in `neutron_capture.cc` by modifying the variable `numberOfEvents`.
*   **Neutron Source:**
    *   The neutron source position and energy can be modified in `PrimaryGeneratorAction.cc`.

## Contributing

Contributions to this project are welcome! If you'd like to contribute:

1.  Fork the repository.
2.  Create a branch for your feature/bug fix.
3.  Make your changes and test thoroughly.
4.  Submit a pull request with a clear explanation of your changes.

## License

[Specify your license here, e.g., MIT License]

## Acknowledgments

*   This project builds upon the existing `WLGDDetectorConstruction` class, designed for the Water-based Liquid Gadolinium Detector.

---

This `README.md` file provides a good overview of your project and should help other developers or users understand its purpose and how to use it. Remember to replace `[repository URL]` and `[Specify your license here]` with the appropriate information for your project. Let me know if you have any other questions.
