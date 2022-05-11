#include "stepping.hh"


MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
    fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}


void MySteppingAction::UserSteppingAction(const G4Step *step)
{
    G4LogicalVolume *volume = step -> GetPreStepPoint() -> GetTouchableHandle() -> GetVolume() -> GetLogicalVolume();

    const MyDetectorConstruction *detectorConstruction = static_cast <const MyDetectorConstruction*> (G4RunManager::GetRunManager() -> GetUserDetectorConstruction());

    G4LogicalVolume *fScoringVolume_A = detectorConstruction -> GetScoringVolume_A();
    G4LogicalVolume *fScoringVolume_B = detectorConstruction -> GetScoringVolume_B();

    G4double edep = 0.;

    if( volume == fScoringVolume_A )
    {
        edep = step -> GetTotalEnergyDeposit();
        fEventAction -> AddEdep_A(edep);
    } else if( volume == fScoringVolume_B )
    {
        edep = step -> GetTotalEnergyDeposit();
        fEventAction -> AddEdep_B(edep);
    } else
    {
        return;
    }
//    return;
}