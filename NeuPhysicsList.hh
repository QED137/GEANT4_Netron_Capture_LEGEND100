#ifndef NEU_PHYSICS_LIST_HH
#define NEU_PHYSICS_LIST_HH

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

// NeuPhysicsList class declaration
class NeuPhysicsList : public G4VModularPhysicsList
{
public:
    NeuPhysicsList();               // Constructor
    virtual ~NeuPhysicsList();      // Destructor

    void SetCuts() override;        // Override SetCuts
};

#endif

