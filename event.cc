#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*){
    fEdep_A = 0.;
    fEdep_B = 0.;
}

MyEventAction::~MyEventAction()
{}


void MyEventAction::BeginOfEventAction(const G4Event*)
{
        fEdep_A = 0.;
        fEdep_B = 0.;
}


void MyEventAction::EndOfEventAction(const G4Event*)
{
        G4cout << "Energy deposition A : " << fEdep_A << "  " << "Energy deposition B : " << fEdep_B << G4endl;
        G4AnalysisManager *man = G4AnalysisManager::Instance();
        man -> FillNtupleDColumn(0,fEdep_A);
        man -> FillNtupleDColumn(1,fEdep_B);
        man ->AddNtupleRow(0);
}
