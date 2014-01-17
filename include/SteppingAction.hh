// Martin Goettlich @ DESY
//

#ifndef SteppingAction_H
#define SteppingACtion_H 1

#include "globals.hh"
#include "G4UserSteppingAction.hh"
#include "DetectorConstruction.hh"
#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include <vector>


//class SteppingMessenger;

class SteppingAction : public G4UserSteppingAction
{
public:

  SteppingAction();
  ~SteppingAction();
  virtual void UserSteppingAction(const G4Step*);

  //void SetOneStepPrimaries(G4bool b){oneStepPrimaries=b;}
  //G4bool GetOneStepPrimaries(){return oneStepPrimaries;}
  
// private:

//   G4bool oneStepPrimaries;
//   SteppingMessenger* steppingMessenger;
};

#endif
