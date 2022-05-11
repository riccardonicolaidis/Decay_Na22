#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{ 
  fParticleGun = new G4ParticleGun(1);

  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName = "geantino";
  G4ParticleDefinition *particle = particleTable -> FindParticle(particleName);

  G4ThreeVector pos(0.,0.,0.);
  G4ThreeVector mom(0.,0.,0.);

  fParticleGun -> SetParticlePosition(pos);
  fParticleGun -> SetParticleMomentumDirection(mom);
  fParticleGun -> SetParticleMomentum(0.);
  fParticleGun -> SetParticleDefinition(particle);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
  delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
  G4ParticleDefinition *particle = fParticleGun -> GetParticleDefinition();

  if(particle == G4Geantino::Geantino())
  {
    G4int Z = 11;
    G4int A = 22;
    G4double charge = 0.*eplus;
    G4double energy = 0.*keV;

    G4ParticleDefinition *ion = G4IonTable::GetIonTable() -> GetIon(Z,A, energy);

    fParticleGun -> SetParticleDefinition(ion);
    fParticleGun -> SetParticleCharge(charge);
  }
  fParticleGun -> GeneratePrimaryVertex(anEvent);
}
