#include "MyMaterials.hh"
#include "G4NistManager.hh"



MyMaterials::MyMaterials()
{}



MyMaterials::~MyMaterials()
{}



G4Material* MyMaterials::Air()
{
  G4double a, z, density;
  G4int nelements;
  
  G4Element* N = new G4Element("Nitrogen", "N", z=7 , a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);
  
  G4Material* mat = new G4Material("Air", density=1.29*mg/cm3, nelements=2);
  mat->AddElement(N, 70.*perCent);
  mat->AddElement(O, 30.*perCent);
  
  const G4int nEntries = 34;
  G4double PhotonEnergy[nEntries] =
    { 0.0001*eV, 1.0000*eV, 2.0340*eV, 2.0680*eV,
      2.1030*eV, 2.1390*eV, 2.1770*eV, 2.2160*eV,
      2.2560*eV, 2.2980*eV, 2.3410*eV, 2.3860*eV,
      2.4330*eV, 2.4810*eV, 2.5320*eV, 2.5850*eV,
      2.6400*eV, 2.6970*eV, 2.7570*eV, 2.8200*eV,
      2.8850*eV, 2.9540*eV, 3.0260*eV, 3.1020*eV,
      3.1810*eV, 3.2650*eV, 3.3530*eV, 3.4460*eV,
      3.5450*eV, 3.6490*eV, 3.7600*eV, 3.8770*eV,
      4.0020*eV, 4.1360*eV };
  G4double RefractiveIndex[nEntries] =
    { 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00 };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX",PhotonEnergy,RefractiveIndex,nEntries);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::Water()
{
  G4double a, z, density;
  G4int nelements;
  
  G4Element* H = new G4Element("Hydrogen", "H", z=1 , a=1.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);
  
  G4Material* mat = new G4Material("Water", density= 1.0*g/cm3, nelements=2);
  mat->AddElement(H, 2);
  mat->AddElement(O, 1);
  
  const G4int nEntries = 33;
  G4double PhotonEnergy[nEntries] =
    { 0.100*eV, 2.034*eV, 2.068*eV, 2.103*eV,
      2.139*eV, 2.177*eV, 2.216*eV, 2.256*eV,
      2.298*eV, 2.341*eV, 2.386*eV, 2.433*eV,
      2.481*eV, 2.532*eV, 2.585*eV, 2.640*eV,
      2.697*eV, 2.757*eV, 2.820*eV, 2.885*eV,
      2.954*eV, 3.026*eV, 3.102*eV, 3.181*eV,
      3.265*eV, 3.353*eV, 3.446*eV, 3.545*eV,
      3.649*eV, 3.760*eV, 3.877*eV, 4.002*eV,
      4.136*eV };
  G4double RefractiveIndex[nEntries] =
    { 1.3435, 1.3435, 1.3440, 1.3445,
      1.3450, 1.3455, 1.3460, 1.3465,
      1.3470, 1.3475, 1.3480, 1.3485,
      1.3492, 1.3500, 1.3505, 1.3510,
      1.3518, 1.3522, 1.3530, 1.3535,
      1.3540, 1.3545, 1.3550, 1.3555,
      1.3560, 1.3568, 1.3572, 1.3580,
      1.3585, 1.3590, 1.3595, 1.3600,
      1.3608};
  G4double Absorption[nEntries] =
    {  3.448*m,  3.448*m,  4.082*m,  6.329*m,
       9.174*m, 12.346*m, 13.889*m, 15.152*m,
      17.241*m, 18.868*m, 20.000*m, 26.316*m,
      35.714*m, 45.455*m, 47.619*m, 52.632*m,
      52.632*m, 55.556*m, 52.632*m, 52.632*m,
      47.619*m, 45.455*m, 41.667*m, 37.037*m,
      33.333*m, 30.000*m, 28.500*m, 27.000*m,
      24.500*m, 22.000*m, 19.500*m, 17.500*m,
      14.500*m };
  G4double FastComponent[nEntries] =
    { 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00 };
  G4double SlowComponent[nEntries] =
    { 0.01, 0.01, 1.00, 2.00,
      3.00, 4.00, 5.00, 6.00,
      7.00, 8.00, 9.00, 8.00,
      7.00, 6.00, 4.00, 3.00,
      2.00, 1.00, 0.01, 1.00,
      2.00, 3.00, 4.00, 5.00,
      6.00, 7.00, 8.00, 9.00,
      8.00, 7.00, 6.00, 5.00,
      4.00 };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX",        PhotonEnergy, RefractiveIndex, nEntries);
  myMPT->AddProperty("ABSLENGTH",     PhotonEnergy, Absorption,      nEntries);
  myMPT->AddProperty("FASTCOMPONENT", PhotonEnergy, FastComponent,   nEntries);
  myMPT->AddProperty("SLOWCOMPONENT", PhotonEnergy, SlowComponent,   nEntries);
  
  myMPT->AddConstProperty("SCINTILLATIONYIELD",50./MeV);
  //myMPT->AddConstProperty("ELECTRONSCINTILLATIONYIELD",50./MeV);
  myMPT->AddConstProperty("RESOLUTIONSCALE",1.0);
  myMPT->AddConstProperty("FASTTIMECONSTANT", 1.*ns);
  myMPT->AddConstProperty("SLOWTIMECONSTANT",10.*ns);
  myMPT->AddConstProperty("YIELDRATIO",0.8);
  
  mat->SetMaterialPropertiesTable(myMPT);

  return mat;
}



G4Material* MyMaterials::Vacuum()
{
  G4double a, z, density;
  G4int nelements;

  G4Element* N = new G4Element("Nitrogen", "N", z=7 , a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);
  
  G4Material* mat = new G4Material("Vacuum", density=0.001*mg/cm3, nelements=2);
  mat->AddElement(N, 70.*perCent);
  mat->AddElement(O, 30.*perCent);
  
  const G4int nEntries = 3;
  G4double PhotonEnergy[nEntries] =
    { 0.0001*eV, 1.00*eV,100.00*eV };
  G4double RefractiveIndex[nEntries] =
    { 1.00, 1.00, 1.00 };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX", PhotonEnergy, RefractiveIndex, nEntries);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::Silicon()
{
  G4double a, z, density;
  
  G4Element* Si = new G4Element("Silicon", "Si", z=14., a=28.09*g/mole);
  
  G4Material* mat = new G4Material("Silicon", density=2.33*g/cm3,1);
  mat->AddElement(Si,1);
  
  const G4int nEntries = 4;
  G4double PhotonEnergy[nEntries] =
    { 0.0001*eV, 1.0*eV, 1.84*eV, 4.08*eV };
  G4double RefractiveIndex[nEntries] =
    { 4.0, 4.0, 4.0, 4.0 };
  G4double Absorption[nEntries] =
    { 0.1*mm, 0.1*mm, 0.1*mm, 0.1*mm};
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX",    PhotonEnergy,  RefractiveIndex, nEntries);
  myMPT->AddProperty("ABSLENGTH", PhotonEnergy,  Absorption,      nEntries);
  
  mat->SetMaterialPropertiesTable(myMPT);

  return mat;
}


G4Material* MyMaterials::Brass()
{
  G4double a, z, density;

  G4Element* Cu = new G4Element("Copper", "Cu", z=29., a=63.546*g/mole);
  G4Element* Zn = new G4Element("Zinc",   "Zn", z=30., a=65.409*g/mole);
  
  G4Material* mat = new G4Material("Brass", density=8.73*g/cm3,2);
  mat->AddElement(Cu,0.75);
  mat->AddElement(Zn,0.25);
  
  return mat;
}


G4Material* MyMaterials::Tungsten()
{
  //   G4Element* Cu = new G4Element("Copper", "Cu", z=29., a=63.546*g/mole);
  G4NistManager* man = G4NistManager::Instance();
  G4Element* W = man->FindOrBuildElement("W");
  G4Element* Ni = man->FindOrBuildElement("Ni");
  G4Element* Cu = man->FindOrBuildElement("Cu");

  G4Material* mat = new G4Material("Tungsten", 17.*g/cm3,3);
  mat->AddElement(W,90.*perCent);
  mat->AddElement(Ni,5.*perCent);
  mat->AddElement(Cu,5.*perCent);
  return mat;
}

  


G4Material* MyMaterials::OpticalGrease()
{
  G4double a, z, density;
  G4Element* H = new G4Element("Hydrogen", "H", z=1., a= 1.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8., a=16.00*g/mole);
  G4Element* C = new G4Element("Carbon"  , "C", z=6., a=12.01*g/mole);

  G4Material* mat = new G4Material("Grease", density=1.0*g/cm3,3);
  mat->AddElement(C,1);
  mat->AddElement(H,1);
  mat->AddElement(O,1);

  const G4int nEntries = 34;
  G4double PhotonEnergy[nEntries] =
    { 0.0001*eV, 1.000*eV, 2.034*eV, 2.068*eV,
       2.103*eV, 2.139*eV, 2.177*eV, 2.216*eV,
       2.256*eV, 2.298*eV, 2.341*eV, 2.386*eV,
       2.433*eV, 2.481*eV, 2.532*eV, 2.585*eV,
       2.640*eV, 2.697*eV, 2.757*eV, 2.820*eV,
       2.885*eV, 2.954*eV, 3.026*eV, 3.102*eV,
       3.181*eV, 3.265*eV, 3.353*eV, 3.446*eV,
       3.545*eV, 3.649*eV, 3.760*eV, 3.877*eV,
       4.002*eV, 4.136*eV };
  G4double RefractiveIndex[nEntries] =
    { 1.45, 1.45, 1.45, 1.45,
      1.45, 1.45, 1.45, 1.45,
      1.45, 1.45, 1.45, 1.45,
      1.45, 1.45, 1.45, 1.45,
      1.45, 1.45, 1.45, 1.45,
      1.45, 1.45, 1.45, 1.45,
      1.45, 1.45, 1.45, 1.45,
      1.45, 1.45, 1.45, 1.45,
      1.45, 1.45 };

  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX",    PhotonEnergy, RefractiveIndex, nEntries);
  //myMPT->AddProperty("ABSLENGTH", PhotonEnergy, Absorption,      nEntries);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}

G4Material* MyMaterials::PWO()
{
  G4double a, z, density;
  G4Element* Pb = new G4Element("Lead",     "Pb", z = 82., a = 207.21*g/mole);
  G4Element* W  = new G4Element("Tungsten", "W",  z = 74., a = 183.85*g/mole);
  G4Element* O  = new G4Element("Oxygen",   "O",  z =  8., a =  16.00*g/mole);
  
  G4Material* mat = new G4Material ("PWO", density = 8.28*g/cm3,3);
  mat->AddElement (Pb, 1);
  mat->AddElement (W, 1);
  mat->AddElement (O, 4);
  
  const G4int nEntries_FAST = 501;
  G4double PhotonEnergy_FAST[nEntries_FAST] =
    { 1.7712*eV, 1.77374*eV, 1.77628*eV, 1.77883*eV, 1.78138*eV, 1.78395*eV, 1.78652*eV, 1.78909*eV, 1.79168*eV, 1.79427*eV,
      1.79687*eV, 1.79948*eV, 1.8021*eV, 1.80472*eV, 1.80735*eV, 1.80999*eV, 1.81263*eV, 1.81529*eV, 1.81795*eV, 1.82062*eV,
      1.8233*eV, 1.82598*eV, 1.82868*eV, 1.83138*eV, 1.83409*eV, 1.8368*eV, 1.83953*eV, 1.84226*eV, 1.845*eV, 1.84775*eV,
      1.85051*eV, 1.85328*eV, 1.85605*eV, 1.85883*eV, 1.86162*eV, 1.86442*eV, 1.86723*eV, 1.87005*eV, 1.87287*eV, 1.87571*eV,
      1.87855*eV, 1.8814*eV, 1.88426*eV, 1.88713*eV, 1.89*eV, 1.89289*eV, 1.89578*eV, 1.89869*eV, 1.9016*eV, 1.90452*eV,
      1.90745*eV, 1.91039*eV, 1.91334*eV, 1.91629*eV, 1.91926*eV, 1.92224*eV, 1.92522*eV, 1.92821*eV, 1.93122*eV, 1.93423*eV,
      1.93725*eV, 1.94028*eV, 1.94333*eV, 1.94638*eV, 1.94944*eV, 1.95251*eV, 1.95559*eV, 1.95868*eV, 1.96178*eV, 1.96488*eV,
      1.968*eV, 1.97113*eV, 1.97427*eV, 1.97742*eV, 1.98058*eV, 1.98375*eV, 1.98693*eV, 1.99012*eV, 1.99331*eV, 1.99652*eV,
      1.99974*eV, 2.00298*eV, 2.00622*eV, 2.00947*eV, 2.01273*eV, 2.016*eV, 2.01929*eV, 2.02258*eV, 2.02589*eV, 2.0292*eV,
      2.03253*eV, 2.03587*eV, 2.03921*eV, 2.04257*eV, 2.04594*eV, 2.04933*eV, 2.05272*eV, 2.05612*eV, 2.05954*eV, 2.06296*eV,
      2.0664*eV, 2.06985*eV, 2.07331*eV, 2.07679*eV, 2.08027*eV, 2.08377*eV, 2.08728*eV, 2.0908*eV, 2.09433*eV, 2.09787*eV,
      2.10143*eV, 2.10499*eV, 2.10857*eV, 2.11217*eV, 2.11577*eV, 2.11939*eV, 2.12302*eV, 2.12666*eV, 2.13031*eV, 2.13398*eV,
      2.13766*eV, 2.14135*eV, 2.14506*eV, 2.14877*eV, 2.1525*eV, 2.15625*eV, 2.16*eV, 2.16377*eV, 2.16756*eV, 2.17135*eV,
      2.17516*eV, 2.17898*eV, 2.18282*eV, 2.18667*eV, 2.19053*eV, 2.19441*eV, 2.1983*eV, 2.20221*eV, 2.20612*eV, 2.21006*eV,
      2.214*eV, 2.21796*eV, 2.22194*eV, 2.22593*eV, 2.22993*eV, 2.23395*eV, 2.23798*eV, 2.24203*eV, 2.24609*eV, 2.25017*eV,
      2.25426*eV, 2.25836*eV, 2.26249*eV, 2.26662*eV, 2.27077*eV, 2.27494*eV, 2.27912*eV, 2.28332*eV, 2.28753*eV, 2.29176*eV,
      2.296*eV, 2.30026*eV, 2.30454*eV, 2.30883*eV, 2.31314*eV, 2.31746*eV, 2.3218*eV, 2.32616*eV, 2.33053*eV, 2.33492*eV,
      2.33932*eV, 2.34375*eV, 2.34819*eV, 2.35264*eV, 2.35711*eV, 2.3616*eV, 2.36611*eV, 2.37063*eV, 2.37518*eV, 2.37973*eV,
      2.38431*eV, 2.38891*eV, 2.39352*eV, 2.39815*eV, 2.40279*eV, 2.40746*eV, 2.41214*eV, 2.41685*eV, 2.42157*eV, 2.42631*eV,
      2.43106*eV, 2.43584*eV, 2.44063*eV, 2.44545*eV, 2.45028*eV, 2.45513*eV, 2.46*eV, 2.46489*eV, 2.4698*eV, 2.47473*eV,
      2.47968*eV, 2.48465*eV, 2.48964*eV, 2.49465*eV, 2.49968*eV, 2.50473*eV, 2.5098*eV, 2.51489*eV, 2.52*eV, 2.52514*eV,
      2.53029*eV, 2.53546*eV, 2.54066*eV, 2.54588*eV, 2.55111*eV, 2.55637*eV, 2.56166*eV, 2.56696*eV, 2.57229*eV, 2.57763*eV,
      2.583*eV, 2.5884*eV, 2.59381*eV, 2.59925*eV, 2.60471*eV, 2.61019*eV, 2.6157*eV, 2.62123*eV, 2.62678*eV, 2.63236*eV,
      2.63796*eV, 2.64359*eV, 2.64923*eV, 2.65491*eV, 2.6606*eV, 2.66633*eV, 2.67207*eV, 2.67784*eV, 2.68364*eV, 2.68946*eV,
      2.69531*eV, 2.70118*eV, 2.70708*eV, 2.713*eV, 2.71895*eV, 2.72493*eV, 2.73093*eV, 2.73696*eV, 2.74301*eV, 2.7491*eV,
      2.7552*eV, 2.76134*eV, 2.7675*eV, 2.7737*eV, 2.77991*eV, 2.78616*eV, 2.79244*eV, 2.79874*eV, 2.80507*eV, 2.81143*eV,
      2.81782*eV, 2.82424*eV, 2.83069*eV, 2.83717*eV, 2.84367*eV, 2.85021*eV, 2.85678*eV, 2.86338*eV, 2.87*eV, 2.87666*eV,
      2.88335*eV, 2.89007*eV, 2.89683*eV, 2.90361*eV, 2.91043*eV, 2.91727*eV, 2.92416*eV, 2.93107*eV, 2.93801*eV, 2.94499*eV,
      2.952*eV, 2.95905*eV, 2.96613*eV, 2.97324*eV, 2.98039*eV, 2.98757*eV, 2.99479*eV, 3.00204*eV, 3.00932*eV, 3.01665*eV,
      3.024*eV, 3.0314*eV, 3.03883*eV, 3.04629*eV, 3.0538*eV, 3.06134*eV, 3.06892*eV, 3.07653*eV, 3.08418*eV, 3.09187*eV,
      3.0996*eV, 3.10737*eV, 3.11518*eV, 3.12303*eV, 3.13091*eV, 3.13884*eV, 3.14681*eV, 3.15481*eV, 3.16286*eV, 3.17095*eV,
      3.17908*eV, 3.18725*eV, 3.19547*eV, 3.20373*eV, 3.21203*eV, 3.22037*eV, 3.22875*eV, 3.23719*eV, 3.24566*eV, 3.25418*eV,
      3.26274*eV, 3.27135*eV, 3.28*eV, 3.28871*eV, 3.29745*eV, 3.30624*eV, 3.31509*eV, 3.32397*eV, 3.33291*eV, 3.34189*eV,
      3.35092*eV, 3.36001*eV, 3.36914*eV, 3.37832*eV, 3.38755*eV, 3.39683*eV, 3.40616*eV, 3.41554*eV, 3.42498*eV, 3.43447*eV,
      3.44401*eV, 3.4536*eV, 3.46325*eV, 3.47295*eV, 3.4827*eV, 3.49251*eV, 3.50238*eV, 3.5123*eV, 3.52228*eV, 3.53231*eV,
      3.54241*eV, 3.55256*eV, 3.56276*eV, 3.57303*eV, 3.58336*eV, 3.59374*eV, 3.60419*eV, 3.6147*eV, 3.62527*eV, 3.6359*eV,
      3.64659*eV, 3.65735*eV, 3.66817*eV, 3.67906*eV, 3.69001*eV, 3.70102*eV, 3.7121*eV, 3.72325*eV, 3.73446*eV, 3.74575*eV,
      3.7571*eV, 3.76852*eV, 3.78001*eV, 3.79157*eV, 3.8032*eV, 3.8149*eV, 3.82667*eV, 3.83852*eV, 3.85044*eV, 3.86244*eV,
      3.87451*eV, 3.88665*eV, 3.89887*eV, 3.91117*eV, 3.92355*eV, 3.93601*eV, 3.94854*eV, 3.96116*eV, 3.97385*eV, 3.98663*eV,
      3.99949*eV, 4.01243*eV, 4.02546*eV, 4.03857*eV, 4.05177*eV, 4.06506*eV, 4.07843*eV, 4.09189*eV, 4.10544*eV, 4.11908*eV,
      4.13281*eV, 4.14663*eV, 4.16054*eV, 4.17455*eV, 4.18865*eV, 4.20285*eV, 4.21715*eV, 4.23154*eV, 4.24603*eV, 4.26062*eV,
      4.27532*eV, 4.29011*eV, 4.30501*eV, 4.32001*eV, 4.33511*eV, 4.35032*eV, 4.36564*eV, 4.38107*eV, 4.3966*eV, 4.41225*eV,
      4.42801*eV, 4.44388*eV, 4.45986*eV, 4.47596*eV, 4.49218*eV, 4.50852*eV, 4.52497*eV, 4.54155*eV, 4.55824*eV, 4.57506*eV,
      4.59201*eV, 4.60908*eV, 4.62628*eV, 4.6436*eV, 4.66106*eV, 4.67865*eV, 4.69637*eV, 4.71423*eV, 4.73222*eV, 4.75035*eV,
      4.76862*eV, 4.78703*eV, 4.80559*eV, 4.82429*eV, 4.84313*eV, 4.86212*eV, 4.88127*eV, 4.90056*eV, 4.92001*eV, 4.93961*eV,
      4.95937*eV, 4.97928*eV, 4.99936*eV, 5.0196*eV, 5.04001*eV, 5.06058*eV, 5.08132*eV, 5.10223*eV, 5.12331*eV, 5.14457*eV,
      5.16601*eV, 5.18762*eV, 5.20942*eV, 5.2314*eV, 5.25357*eV, 5.27592*eV, 5.29847*eV, 5.32121*eV, 5.34415*eV, 5.36728*eV,
      5.39062*eV, 5.41416*eV, 5.4379*eV, 5.46186*eV, 5.48603*eV, 5.51041*eV, 5.53501*eV, 5.55983*eV, 5.58487*eV, 5.61014*eV,
      5.63564*eV, 5.66138*eV, 5.68735*eV, 5.71356*eV, 5.74001*eV, 5.76671*eV, 5.79365*eV, 5.82085*eV, 5.84831*eV, 5.87603*eV,
      5.90401*eV, 5.93226*eV, 5.96078*eV, 5.98957*eV, 6.01865*eV, 6.04801*eV, 6.07766*eV, 6.1076*eV, 6.13783*eV, 6.16837*eV,
      6.19921*eV };
      
  G4double FastComponent[nEntries_FAST] =
    { 5.48303e-45, 1.10277e-44, 2.21239e-44, 4.42745e-44, 8.83811e-44, 1.75987e-43, 3.49554e-43, 6.92569e-43, 1.36876e-42, 2.69838e-42,
      5.30634e-42, 1.04088e-41, 2.03667e-41, 3.97517e-41, 7.73935e-41, 1.50303e-40, 2.91169e-40, 5.62647e-40, 1.08453e-39, 2.08527e-39,
      3.99941e-39, 7.65147e-39, 1.46018e-38, 2.77962e-38, 5.27808e-38, 9.99728e-38, 1.88887e-37, 3.55988e-37, 6.69243e-37, 1.25501e-36,
      2.3476e-36, 4.38041e-36, 8.15305e-36, 1.5137e-35, 2.80333e-35, 5.17872e-35, 9.543e-35, 1.75413e-34, 3.21627e-34, 5.88244e-34,
      1.07319e-33, 1.95304e-33, 3.54535e-33, 6.4198e-33, 1.15957e-32, 2.08924e-32, 3.75486e-32, 6.73153e-32, 1.20378e-31, 2.14731e-31,
      3.82083e-31, 6.78163e-31, 1.20067e-30, 2.12046e-30, 3.7355e-30, 6.56421e-30, 1.15062e-29, 2.01183e-29, 3.50888e-29, 6.10463e-29,
      1.05941e-28, 1.83393e-28, 3.16677e-28, 5.45461e-28, 9.37186e-28, 1.60621e-27, 2.74595e-27, 4.68271e-27, 7.96556e-27, 1.3516e-26,
      2.28769e-26, 3.86241e-26, 6.50481e-26, 1.09276e-25, 1.83117e-25, 3.06089e-25, 5.10365e-25, 8.48845e-25, 1.40828e-24, 2.33059e-24,
      3.8473e-24, 6.3352e-24, 1.04059e-23, 1.70495e-23, 2.7865e-23, 4.54277e-23, 7.38748e-23, 1.19836e-22, 1.93906e-22, 3.12974e-22,
      5.03897e-22, 8.09261e-22, 1.29643e-21, 2.07169e-21, 3.30229e-21, 5.25072e-21, 8.32794e-21, 1.31756e-20, 2.0793e-20, 3.27324e-20,
      5.13989e-20, 8.05088e-20, 1.2579e-19, 1.96049e-19, 3.04788e-19, 4.72655e-19, 7.31148e-19, 1.12819e-18, 1.73648e-18, 2.66608e-18,
      4.08312e-18, 6.2377e-18, 9.50541e-18, 1.44488e-17, 2.19082e-17, 3.31357e-17, 4.99919e-17, 7.52346e-17, 1.1294e-16, 1.6912e-16,
      2.52614e-16, 3.76384e-16, 5.59398e-16, 8.29324e-16, 1.22643e-15, 1.80915e-15, 2.66207e-15, 3.90734e-15, 5.72078e-15, 8.35496e-15,
      1.21716e-14, 1.76875e-14, 2.56388e-14, 3.70718e-14, 5.34692e-14, 7.69269e-14, 1.10399e-13, 1.58041e-13, 2.25677e-13, 3.21454e-13,
      4.56736e-13, 6.4733e-13, 9.15166e-13, 1.29059e-12, 1.81548e-12, 2.54747e-12, 3.56566e-12, 4.97836e-12, 6.9334e-12, 9.63209e-12,
      1.33478e-11, 1.84507e-11, 2.54407e-11, 3.49913e-11, 4.80072e-11, 6.57001e-11, 8.96892e-11, 1.22132e-10, 1.65894e-10, 2.24775e-10,
      3.03794e-10, 4.09567e-10, 5.50788e-10, 7.38854e-10, 9.8866e-10, 1.31962e-09, 1.75698e-09, 2.33344e-09, 3.09131e-09, 4.0851e-09,
      5.38488e-09, 7.0805e-09, 9.28681e-09, 1.21502e-08, 1.58567e-08, 2.06424e-08, 2.68052e-08, 3.4721e-08, 4.48622e-08, 5.78206e-08,
      7.4336e-08, 9.533e-08, 1.21948e-07, 1.55609e-07, 1.98065e-07, 2.51475e-07, 3.18491e-07, 4.02359e-07, 5.07043e-07, 6.37367e-07,
      7.99187e-07, 9.9959e-07, 1.24712e-06, 1.55207e-06, 1.92676e-06, 2.38593e-06, 2.94715e-06, 3.6313e-06, 4.46308e-06, 5.4717e-06,
      6.69151e-06, 8.16282e-06, 9.93277e-06, 1.20563e-05, 1.45973e-05, 1.76298e-05, 2.1239e-05, 2.55232e-05, 3.05951e-05, 3.65832e-05,
      4.36341e-05, 5.19141e-05, 6.1611e-05, 7.29365e-05, 8.61284e-05, 0.0001015, 0.0001192, 0.0001397, 0.0001633, 0.0001905,
      0.0002216, 0.0002571, 0.0002976, 0.0003436, 0.0003958, 0.0004547, 0.000521, 0.0005956, 0.0006791, 0.0007725,
      0.0008764, 0.0009919, 0.0011197, 0.0012609, 0.0014164, 0.001587, 0.0017737, 0.0019775, 0.0021992, 0.0024396,
      0.0026995, 0.0029797, 0.0032808, 0.0036032, 0.0039475, 0.0043139, 0.0047025, 0.0051132, 0.005546, 0.0060005,
      0.0064759, 0.0069715, 0.0074864, 0.0080192, 0.0085684, 0.0091325, 0.0097093, 0.0102968, 0.0108926, 0.0114941,
      0.0120985, 0.012703, 0.0133043, 0.0138992, 0.0144846, 0.0150569, 0.0156127, 0.0161486, 0.0166612, 0.0171472,
      0.0176033, 0.0180263, 0.0184135, 0.018762, 0.0190694, 0.0193334, 0.0195521, 0.019724, 0.0198476, 0.0199222,
      0.0199471, 0.0199222, 0.0198476, 0.019724, 0.0195521, 0.0193334, 0.0190694, 0.018762, 0.0184135, 0.0180263,
      0.0176033, 0.0171472, 0.0166612, 0.0161486, 0.0156127, 0.0150569, 0.0144846, 0.0138992, 0.0133043, 0.012703,
      0.0120985, 0.0114941, 0.0108926, 0.0102968, 0.0097093, 0.0091325, 0.0085684, 0.0080192, 0.0074864, 0.0069715,
      0.0064759, 0.0060005, 0.005546, 0.0051132, 0.0047025, 0.0043139, 0.0039475, 0.0036032, 0.0032808, 0.0029797,
      0.0026995, 0.0024396, 0.0021992, 0.0019775, 0.0017737, 0.001587, 0.0014164, 0.0012609, 0.0011197, 0.0009919,
      0.0008764, 0.0007725, 0.0006791, 0.0005956, 0.000521, 0.0004547, 0.0003958, 0.0003436, 0.0002976, 0.0002571,
      0.0002216, 0.0001905, 0.0001633, 0.0001397, 0.0001192, 0.0001015, 8.61284e-05, 7.29365e-05, 6.1611e-05, 5.19141e-05,
      4.36341e-05, 3.65832e-05, 3.05951e-05, 2.55232e-05, 2.1239e-05, 1.76298e-05, 1.45973e-05, 1.20563e-05, 9.93277e-06, 8.16282e-06,
      6.69151e-06, 5.4717e-06, 4.46308e-06, 3.6313e-06, 2.94715e-06, 2.38593e-06, 1.92676e-06, 1.55207e-06, 1.24712e-06, 9.9959e-07,
      7.99187e-07, 6.37367e-07, 5.07043e-07, 4.02359e-07, 3.18491e-07, 2.51475e-07, 1.98065e-07, 1.55609e-07, 1.21948e-07, 9.533e-08,
      7.4336e-08, 5.78206e-08, 4.48622e-08, 3.4721e-08, 2.68052e-08, 2.06424e-08, 1.58567e-08, 1.21502e-08, 9.28681e-09, 7.0805e-09,
      5.38488e-09, 4.0851e-09, 3.09131e-09, 2.33344e-09, 1.75698e-09, 1.31962e-09, 9.8866e-10, 7.38854e-10, 5.50788e-10, 4.09567e-10,
      3.03794e-10, 2.24775e-10, 1.65894e-10, 1.22132e-10, 8.96892e-11, 6.57001e-11, 4.80072e-11, 3.49913e-11, 2.54407e-11, 1.84507e-11,
      1.33478e-11, 9.63209e-12, 6.9334e-12, 4.97836e-12, 3.56566e-12, 2.54747e-12, 1.81548e-12, 1.29059e-12, 9.15166e-13, 6.4733e-13,
      4.56736e-13, 3.21454e-13, 2.25677e-13, 1.58041e-13, 1.10399e-13, 7.69269e-14, 5.34692e-14, 3.70718e-14, 2.56388e-14, 1.76875e-14,
      1.21716e-14, 8.35496e-15, 5.72078e-15, 3.90734e-15, 2.66207e-15, 1.80915e-15, 1.22643e-15, 8.29324e-16, 5.59398e-16, 3.76384e-16,
      2.52614e-16, 1.6912e-16, 1.1294e-16, 7.52346e-17, 4.99919e-17, 3.31357e-17, 2.19082e-17, 1.44488e-17, 9.50541e-18, 6.2377e-18,
      4.08312e-18, 2.66608e-18, 1.73648e-18, 1.12819e-18, 7.31148e-19, 4.72655e-19, 3.04788e-19, 1.96049e-19, 1.2579e-19, 8.05088e-20,
      5.13989e-20, 3.27324e-20, 2.0793e-20, 1.31756e-20, 8.32794e-21, 5.25072e-21, 3.30229e-21, 2.07169e-21, 1.29643e-21, 8.09261e-22,
      5.03897e-22, 3.12974e-22, 1.93906e-22, 1.19836e-22, 7.38748e-23, 4.54277e-23, 2.7865e-23, 1.70495e-23, 1.04059e-23, 6.3352e-24,
      3.8473e-24, 2.33059e-24, 1.40828e-24, 8.48845e-25, 5.10365e-25, 3.06089e-25, 1.83117e-25, 1.09276e-25, 6.50481e-26, 3.86241e-26,
      2.28769e-26, 1.3516e-26, 7.96556e-27, 4.68271e-27, 2.74595e-27, 1.60621e-27, 9.37186e-28, 5.45461e-28, 3.16677e-28, 1.83393e-28,
      1.05941e-28 };
  
  G4double PbWO_indexZero = 1.5861;
  G4double PbWO_nVec[1]   = { 1.1062 };
  G4double PbWO_lVec[1]   = { 270.63 };
  int sizeVect = sizeof(PbWO_nVec)/sizeof(*PbWO_nVec);
  
  const G4int nEntries_RI = 5;
  G4double PhotonEnergy_RI[nEntries_RI] =
    { 0.0001 * eV, 1.0 * eV, 1.84 * eV, 2.952 * eV, 4.08 * eV };
  G4double RefractiveIndex[nEntries_RI] =
    { CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[0])),
      CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[1])),
      CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[2])),
      CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[3])),
      CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[4])) };
  
  const G4int nEntries_ABS = 70;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.25237 * eV, 1.26514 * eV, 1.27819 * eV, 1.2915 * eV, 1.3051 * eV, 1.31898 * eV, 1.33316 * eV, 1.34765 * eV, 1.36246 * eV, 1.3776 * eV,
      1.39308 * eV, 1.40891 * eV, 1.42511 * eV, 1.44168 * eV, 1.45864 * eV, 1.476 * eV, 1.49379 * eV, 1.512 * eV, 1.53067 * eV, 1.5498 * eV,
      1.56942 * eV, 1.58954 * eV, 1.61018 * eV, 1.63137 * eV, 1.65312 * eV, 1.67546 * eV, 1.69841 * eV, 1.722 * eV, 1.74626 * eV, 1.7712 * eV,
      1.79687 * eV, 1.8233 * eV, 1.85051 * eV, 1.87855 * eV, 1.90745 * eV, 1.93725 * eV, 1.968 * eV, 1.99974 * eV, 2.03253 * eV, 2.0664 * eV,
      2.10143 * eV, 2.13766 * eV, 2.17516 * eV, 2.214 * eV, 2.25426 * eV, 2.296 * eV, 2.33932 * eV, 2.38431 * eV, 2.43106 * eV, 2.47968 * eV,
      2.53029 * eV, 2.583 * eV, 2.63796 * eV, 2.69531 * eV, 2.7552 * eV, 2.81782 * eV, 2.88335 * eV, 2.952 * eV, 3.024 * eV, 3.0996 * eV,
      3.17908 * eV, 3.26274 * eV, 3.35092 * eV, 3.44401 * eV, 3.54241 * eV, 3.64659 * eV, 3.7571 * eV, 3.87451 * eV, 3.99949 * eV, 4.13281 * eV };

      G4double Absorption[nEntries_ABS] =
    { 3110 * mm, 3110 * mm, 3110 * mm, 3110 * mm, 3110 * mm, 3105 * mm, 3105 * mm, 3105 * mm, 3105 * mm, 3105 * mm,
      3105 * mm, 2745 * mm, 2460 * mm, 2230 * mm, 2039 * mm, 1877 * mm, 1859 * mm, 1826 * mm, 1764 * mm, 1760 * mm,
      1664 * mm, 1585 * mm, 1471 * mm, 1376 * mm, 1272 * mm, 1187 * mm, 1114 * mm, 1046 * mm, 993.2 * mm, 942.9 * mm,
      898.8 * mm, 856.9 * mm, 821.7 * mm, 794.2 * mm, 767.7 * mm, 746.5 * mm, 725.6 * mm, 710.7 * mm, 695.3 * mm, 686.2 * mm,
      674.8 * mm, 663.5 * mm, 648.3 * mm, 633.4 * mm, 622.3 * mm, 607.8 * mm, 590.9 * mm, 568.9 * mm, 541.4 * mm, 502.9 * mm,
      467 * mm, 430.2 * mm, 390.1 * mm, 345.3 * mm, 298.9 * mm, 256.7 * mm, 219.8 * mm, 185.4 * mm, 150.9 * mm, 116.4 * mm,
      84.8 * mm, 59.4 * mm, 41.1 * mm, 27.5 * mm, 24.2 * mm, 24.2 * mm, 24.3 * mm, 24.3 * mm, 24.4 * mm, 24.6 * mm };
  
  const G4int nEntries_SCY = 12;
  G4double ElectronEnergy_SCY[nEntries_SCY] =
    { 0.000 * MeV, 0.015 * MeV, 0.020 * MeV, 0.030 * MeV,
      0.040 * MeV, 0.060 * MeV, 0.080 * MeV, 0.090 * MeV,
      0.105 * MeV, 0.300 * MeV, 0.500 * MeV, 1.000 * MeV };
      
  G4double ScintilYield[nEntries_SCY] =
    { 0.10, 0.46, 0.60, 0.68,
      0.74, 0.80, 0.82, 0.84,
      0.87,  0.96,  0.98,  1.00 };
      
  for(int i = 0; i < nEntries_SCY; i++)
    ScintilYield[i] = 0.3 * MeV * ScintilYield[i] * ElectronEnergy_SCY[i];
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty ("FASTCOMPONENT", PhotonEnergy_FAST, FastComponent,   nEntries_FAST);
  myMPT->AddProperty ("RINDEX",        PhotonEnergy_RI,   RefractiveIndex, nEntries_RI);
  myMPT->AddProperty ("ABSLENGTH",     PhotonEnergy_ABS,  Absorption,      nEntries_ABS);
  myMPT->AddProperty ("ELECTRONSCINTILLATIONYIELD", ElectronEnergy_SCY, ScintilYield, nEntries_SCY);
  myMPT->AddConstProperty ("SCINTILLATIONYIELD", 100/MeV);
  myMPT->AddConstProperty ("RESOLUTIONSCALE", 1.0); //3.2 default value
  myMPT->AddConstProperty ("FASTTIMECONSTANT", 20.*ns);
  myMPT->AddConstProperty ("YIELDRATIO", 1.0);
  myMPT->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * ns);
  
  mat->SetMaterialPropertiesTable (myMPT);
  
  return mat;
}



G4double MyMaterials::CalculateSellmeier (int size, G4double indexZero, G4double *nVec, G4double *lVec, G4double wavelength)
{
  /*------http://gentitfx.fr/SLitrani/code/SLitraniCode/TLitSellmeier.html----*/
  
  float partial = indexZero * indexZero;
  float sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += nVec[i] * nVec[i] / (1 - lVec[i] * lVec[i] / (wavelength*wavelength));
  }
  
  partial += sum;
  partial += 1;
  
  //G4cout << "Wavelength: " << wavelength << " -> rifr. index: " << sqrt(partial) << G4endl;
  
  return sqrt(partial);
}



G4double MyMaterials::fromEvToNm (G4double energy)
{
  return 1239.84187 / energy;
}

G4double MyMaterials::fromNmToEv (G4double wavelength)
{
  return 1239.84187 / wavelength;
}
