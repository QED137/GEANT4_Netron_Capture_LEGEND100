#ifndef NeuActionInitialization_h
#define NueActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"


class NeuDetectorConstruction;

/// Action initialization class.
///

class NeuActionInitialization : public G4VUserActionInitialization
{
  public:
    NeuActionInitialization(NeuDetectorConstruction*);
    ~NeuActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;

  private:
    NeuDetectorConstruction* fDetector = nullptr;
};

#endif
