#ifndef NeuTrackingAction_h
#define NeuTrackingAction_h 1

#include "G4UserTrackingAction.hh"
#include "globals.hh"

class NeuEventAction;
class TrackingMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class NeuTrackingAction : public G4UserTrackingAction
{
  public:
    NeuTrackingAction(NeuEventAction*);
    ~NeuTrackingAction() override;

    void PreUserTrackingAction(const G4Track*) override;
    void PostUserTrackingAction(const G4Track*) override;

    void SetParticleCount(G4bool flag) { fParticleCount = flag; };
    void SetKillNeutrons(G4bool flag) { fKillNeutron = flag; };

  private:
    NeuEventAction* fEventAction = nullptr;
    TrackingMessenger* fTrackMessenger = nullptr;

    G4bool fParticleCount = true;
    G4bool fKillNeutron = false;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
