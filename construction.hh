#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH



#include "G4VUserDetectorConstruction.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4GenericMessenger.hh"
#include "G4MaterialPropertiesTable.hh"


#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  MyDetectorConstruction();
  ~MyDetectorConstruction();

  G4LogicalVolume *GetScoringVolume_A() const {return fScoringVolume_A; }
  G4LogicalVolume *GetScoringVolume_B() const {return fScoringVolume_B; }

  virtual G4VPhysicalVolume *Construct();

private:

  virtual void ConstructSDandField();

  G4Box            *solidWorld;
  G4LogicalVolume  *logicWorld;
  G4VPhysicalVolume *physWorld;
  
  G4Box             *solidScintillator_A;
  G4LogicalVolume   *logicScintillator_A;
  G4VPhysicalVolume *physScintillator_A; 

  G4Box             *solidScintillator_B;
  G4LogicalVolume   *logicScintillator_B;
  G4VPhysicalVolume *physScintillator_B; 

  G4GenericMessenger *fMessenger;

  void DefineMaterials();
  void ConstructScintillator();

  G4Material *worldMat, *NaI;
  G4Element *Na, *I;

  G4double xWorld, yWorld, zWorld;
  G4double xA, yA, zA, xB, yB, zB;
  G4double LA, LB;
  G4double TkA, TkB;


  G4LogicalVolume *fScoringVolume_A;
  G4LogicalVolume *fScoringVolume_B;


};

#endif
  
