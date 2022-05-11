#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}


G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROHist)
{
  G4Track *track = aStep -> GetTrack();
  //track -> SetTrackStatus(fStopAndKill);

  G4StepPoint *preStepPoint = aStep -> GetPreStepPoint();
  G4StepPoint *postStepPoint = aStep -> GetPostStepPoint();

  G4ThreeVector posPhoton = preStepPoint -> GetPosition();
  
  const G4VTouchable *touchable = aStep -> GetPreStepPoint() -> GetTouchable();
  G4int copyNo = touchable -> GetCopyNumber();

  G4VPhysicalVolume *physVol = touchable -> GetVolume();
  G4ThreeVector posDetector = physVol -> GetTranslation();


  G4int evt = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();

  return true;
}

