#include "run.hh"

MyRunAction::MyRunAction()
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
 
    man -> CreateNtuple("EnergyDeposition","EnergyDeposition");
    man -> CreateNtupleDColumn("fEdep_A");
    man -> CreateNtupleDColumn("fEdep_B");
    man -> FinishNtuple(0);
}

MyRunAction::~MyRunAction()
{}



void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    G4int runNumber = run -> GetRunID();
    std::stringstream strRunID;
    strRunID << runNumber;
    man -> OpenFile("output" + strRunID.str() + ".root");
}

void MyRunAction::EndOfRunAction(const G4Run* )
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man -> Write();
    man -> CloseFile("output.root");
}