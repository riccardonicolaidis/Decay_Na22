#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"

#include "run.hh"

class MyEventAction : public G4UserEventAction
{
public:
        MyEventAction(MyRunAction*);
        ~MyEventAction();

        virtual void BeginOfEventAction(const G4Event*);
        virtual void EndOfEventAction(const G4Event*);

        void AddEdep_A(G4double edep) {fEdep_A += edep; }
        void AddEdep_B(G4double edep) {fEdep_B += edep; }


private:
        G4double fEdep_A;
        G4double fEdep_B;
};


#endif