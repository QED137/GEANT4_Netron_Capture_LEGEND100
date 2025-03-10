#ifndef NEU_DETECTOR_CONSTRUCTION_HH
#define NEU_DETECTOR_CONSTRUCTION_HH

#include "G4SystemOfUnits.hh"

#include "G4VUserDetectorConstruction.hh"

#include "G4NistManager.hh"

#include "G4Material.hh"

#include "G4Box.hh"

#include "G4LogicalVolume.hh"

#include "G4VPhysicalVolume.hh"

#include "G4PVPlacement.hh"


class DetectorMessenger;

class NeuDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    NeuDetectorConstruction();
    virtual ~NeuDetectorConstruction();
public:    

    virtual G4VPhysicalVolume* Construct();
    G4Material* MaterialWithSingleIsotope(G4String, G4String, G4double, G4int, G4int);
    void SetRadius(G4double);
    void SetMaterial(G4String);
public:
    G4double GetRadius() { return fRadius; };
    G4Material* GetMaterial() { return fMaterial; };

    void PrintParameters();

private:
    G4double fRadius = 0.;
    G4Material* fMaterial = nullptr;
    G4LogicalVolume* fLAbsor = nullptr;

    G4double fWorldSize = 0.;
    G4Material* fWorldMat = nullptr;
    G4VPhysicalVolume* fPWorld = nullptr;

    DetectorMessenger* fDetectorMessenger = nullptr;

private:
    void DefineMaterials();
    G4VPhysicalVolume* ConstructVolumes();
};    
#endif

