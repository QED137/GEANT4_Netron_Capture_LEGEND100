#ifndef NeuSteppingAction_h
#define NeuSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class NeuEventAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class NeuSteppingAction : public G4UserSteppingAction
{
  public:
    NeuSteppingAction(NeuEventAction*);
    ~NeuSteppingAction() override = default;

    void UserSteppingAction(const G4Step*) override;

  private:
    NeuEventAction* fEventAction = nullptr;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
