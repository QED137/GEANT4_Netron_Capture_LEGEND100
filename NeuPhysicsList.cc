#include "NeuPhysicsList.hh"

// Include Geant4 headers
#include "ElectromagneticPhysics.hh"
#include "GammaNuclearPhysics.hh"
#include "GammaNuclearPhysicsLEND.hh"
#include "HadronElasticPhysicsHP.hh"
#include "RadioactiveDecayPhysics.hh"

#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4HadronElasticPhysicsXS.hh"
#include "G4HadronInelasticQBBC.hh"
#include "G4HadronPhysicsFTFP_BERT_HP.hh"
#include "G4HadronPhysicsINCLXX.hh"
#include "G4HadronPhysicsQGSP_BIC_AllHP.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"
#include "G4IonElasticPhysics.hh"
#include "G4IonINCLXXPhysics.hh"
#include "G4IonPhysicsXS.hh"
#include "G4NuclideTable.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4StoppingPhysics.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4OpticalPhysics.hh"

// Constructor definition
NeuPhysicsList::NeuPhysicsList()
    : G4VModularPhysicsList()  // Call base class constructor
{
    G4int verb = 1;
    SetVerboseLevel(verb);

    // Add new units
    new G4UnitDefinition("mm2/g", "mm2/g", "Surface/Mass", mm2 / g);
    new G4UnitDefinition("um2/mg", "um2/mg", "Surface/Mass", um * um / mg);

    // Set threshold for G4NuclideTable
    const G4double meanLife = 1 * nanosecond, halfLife = meanLife * std::log(2);
    G4NuclideTable::GetInstance()->SetThresholdOfHalfLife(halfLife);

    // Register physics processes
    RegisterPhysics(new HadronElasticPhysicsHP(verb));
    RegisterPhysics(new G4HadronPhysicsQGSP_BIC_HP(verb));
    RegisterPhysics(new G4IonElasticPhysics(verb));
    RegisterPhysics(new G4IonPhysicsXS(verb));
    RegisterPhysics(new G4StoppingPhysics(verb));
    RegisterPhysics(new GammaNuclearPhysics("gamma"));
    RegisterPhysics(new ElectromagneticPhysics());
    RegisterPhysics(new G4OpticalPhysics());
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new RadioactiveDecayPhysics());
}

// Destructor definition
NeuPhysicsList::~NeuPhysicsList() {}

// SetCuts implementation
void NeuPhysicsList::SetCuts()
{
    SetCutValue(0 * mm, "proton");
    SetCutValue(10 * km, "e-");
    SetCutValue(10 * km, "e+");
    SetCutValue(10 * km, "gamma");
}

