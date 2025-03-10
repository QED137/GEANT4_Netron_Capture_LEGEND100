
#include "NeuSteppingAction.hh"

#include "NeuEventAction.hh"
#include "HistoManager.hh"
#include "Run.hh"

#include "G4RunManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NeuSteppingAction::NeuSteppingAction(NeuEventAction* event) : fEventAction(event) {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NeuSteppingAction::UserSteppingAction(const G4Step* aStep)
{
  // count processes
  //
  const G4StepPoint* endPoint = aStep->GetPostStepPoint();
  const G4VProcess* process = endPoint->GetProcessDefinedStep();
  Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  run->CountProcesses(process);

  // energy deposit
  //
  G4double edepStep = aStep->GetTotalEnergyDeposit();
  if (edepStep <= 0.) return;
  fEventAction->AddEdep(edepStep);

  // longitudinal profile of deposited energy
  //
  G4ThreeVector prePoint = aStep->GetPreStepPoint()->GetPosition();
  G4ThreeVector postPoint = aStep->GetPostStepPoint()->GetPosition();
  G4ThreeVector point = prePoint + G4UniformRand() * (postPoint - prePoint);
  G4double r = point.mag();
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->FillH1(2, r, edepStep);
}
