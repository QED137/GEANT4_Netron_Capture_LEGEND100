#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "NeuEventAction.hh"
#include "Run.hh"
#include "HistoManager.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NeuEventAction::BeginOfEventAction(const G4Event*)
{
  fTotalEnergyDeposit = 0.;
  fTotalEnergyFlow = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NeuEventAction::AddEdep(G4double Edep)
{
  fTotalEnergyDeposit += Edep;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NeuEventAction::AddEflow(G4double Eflow)
{
  fTotalEnergyFlow += Eflow;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NeuEventAction::EndOfEventAction(const G4Event*)
{
  Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());

  G4double totalEnergy = fTotalEnergyDeposit + fTotalEnergyFlow;
  run->SumEnergies(fTotalEnergyDeposit, fTotalEnergyFlow, totalEnergy);
  G4AnalysisManager::Instance()->FillH1(1, fTotalEnergyDeposit);
  G4AnalysisManager::Instance()->FillH1(3, fTotalEnergyFlow);
  G4AnalysisManager::Instance()->FillH1(0, totalEnergy);
}
