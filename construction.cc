#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{

  fMessenger = new G4GenericMessenger(this, "/detector/","DetectorConstruction");

  xWorld = 1.*m;
  yWorld = 1.*m;
  zWorld = 1.*m;

  LA = 60*cm;
  LB = 60*cm;

  TkA = 10*cm;
  TkB = 10*cm;
  
  xA = 0.;
  yA = 0.;
  zA = 0.4*m;

  xB = 0.;
  yB = 0.;
  zB = -0.4*m;

  DefineMaterials();  
}

MyDetectorConstruction::~MyDetectorConstruction()
{}

void MyDetectorConstruction::DefineMaterials()
{
  G4NistManager *nist = G4NistManager::Instance();

  Na  = nist -> FindOrBuildElement("Na");
  I   = nist -> FindOrBuildElement("I");
  NaI = new G4Material("NaI", 3.67*g/cm3, 2);
  NaI -> AddElement(Na, 1);
  NaI -> AddElement(I, 1);

  worldMat = nist -> FindOrBuildMaterial("G4_AIR");


  G4double energy[2]        = {1.239841939*eV/0.9 , 1.239841939*eV/0.2};
  G4double rindexWorld[2]   = {1.0                , 1.0};

  G4MaterialPropertiesTable *mptWorld   = new G4MaterialPropertiesTable();

  mptWorld -> AddProperty("RINDEX", energy, rindexWorld, 2);
  worldMat -> SetMaterialPropertiesTable(mptWorld);
}



void MyDetectorConstruction::ConstructScintillator()
{
  solidScintillator_A = new G4Box("solidScintillator_A", LA, LA, TkA);
  logicScintillator_A = new G4LogicalVolume(solidScintillator_A, NaI, "logicScintillator_A");
  physScintillator_A  = new G4PVPlacement(0,G4ThreeVector(xA, yA, zA),logicScintillator_A, "physScintillator_A", logicWorld, false, 0, true );

  solidScintillator_B = new G4Box("solidScintillator_B", LB, LB, TkB);
  logicScintillator_B = new G4LogicalVolume(solidScintillator_B, NaI, "logicScintillator_B");
  physScintillator_B  = new G4PVPlacement(0,G4ThreeVector(xB, yB, zB),logicScintillator_B, "physScintillator_B", logicWorld, false, 0, true );

  fScoringVolume_A = logicScintillator_A;
  fScoringVolume_B = logicScintillator_B;
  
}



G4VPhysicalVolume *MyDetectorConstruction::Construct()
{

  solidWorld = new G4Box("solidWorld",xWorld, yWorld, zWorld);  
  logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  physWorld  = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true);
    
  ConstructScintillator();

  return physWorld;  
}


void MyDetectorConstruction::ConstructSDandField()
{
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
  
  //logicDetector -> SetSensitiveDetector(sensDet);
}

