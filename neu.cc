#include <iostream>
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"


// Include your detector and physics list
#include "NeuDetectorConstruction.hh"
#include "QBBC.hh" // Example physics list

#include "NeuPhysicsList.hh"
#include "NeuActionInitialization.hh"

int main(int argc, char** argv)
{
    // Create the run manager
    G4RunManager* runManager = new G4RunManager();

    // Create detector and physics list
    NeuDetectorConstruction* det = new NeuDetectorConstruction();
    runManager->SetUserInitialization(det);
    runManager->SetUserInitialization(new NeuPhysicsList());
    runManager->SetUserInitialization(new NeuActionInitialization(det));

    // Create visualization manager
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    // Initialize run manager
    runManager->Initialize();

    // Get the UI manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    // Check if running in interactive or batch mode
    G4UIExecutive* ui = nullptr;
    if (argc == 1) {
        // Interactive mode
        ui = new G4UIExecutive(argc, argv);
    }

    // Setup visualization commands
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    UImanager->ApplyCommand("/vis/scene/add/trajectories all");
    UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");


    UImanager->ApplyCommand("/vis/enable");
    UImanager->ApplyCommand("/vis/viewer/flush");
    

    if (ui) {
        // Interactive mode
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
        delete ui;
    } else {
        // Batch mode: Execute the provided macro file
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }

    // Cleanup
    delete visManager;
    delete runManager;

    return 0;
}


