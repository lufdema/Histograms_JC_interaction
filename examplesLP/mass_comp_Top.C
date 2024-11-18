/*
The next line shows how to run the program in the terminal. This program must be run inside the Delphes folder due to the 
exrootanalysis dependences

root -l examplesLP/mass_comp_Top.C'("TTBar_000.root", "TTBarLep_000.root", "ZJetsToNuNu_000.root")'



*/

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "external/ExRootAnalysis/ExRootResult.h"
#else
class ExRootTreeReader;
class ExRootResult;
#endif

//------------------------------------------------------------------------------

struct TestPlots
{
  
  TH1 *fJetMass;
  TH1 *fJetMass2;
  TH1 *fJetMass3;
  
};

//------------------------------------------------------------------------------

void BookHistograms(ExRootResult *result1, ExRootResult *result2 , ExRootResult *result3, TestPlots *plots)
{




 
  plots->fJetMass = result1->AddHist1D(
    "Jet T  Mass JC", "Jet T  Mass JC",
    "Mass", "number of jets",600, 0, 320, 0, 1); //Los ultimos numeros, el cero y 
                                                //el 1 significan que no hay escala log en x pero si en y
 
  plots->fJetMass->SetLineColor(kBlue);

  plots->fJetMass2 = result2->AddHist1D(
    "Jet T2  Mass JC", "Jet T2  Mass JC",
    "Mass", "number of jets",600, 0, 320, 0, 1);
   
  plots->fJetMass2->SetLineColor(kRed);  
  
  
  plots->fJetMass3 = result3->AddHist1D(
    "Jet T3  Mass JC", "Jet T3  Mass JC",
    "Mass", "number of jets",600, 0, 320, 0, 1);
   
  plots->fJetMass3->SetLineColor(kBlack);  
  
}

//------------------------------------------------------------------------------

void AnalyseEvents(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;

  TLeaf *mass=tree-> GetLeaf("jet_sdmass");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetMass->Fill(mass->GetValue());
       
   }

}



//------------------------------------------------------------------------------


void AnalyseEvents2(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;

  TLeaf *mass=tree-> GetLeaf("jet_sdmass");
  
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetMass2->Fill(mass->GetValue());
       
   }
      
}

//-------------------------------------------------------------------------------------

void AnalyseEvents3(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;

  TLeaf *mass=tree-> GetLeaf("jet_sdmass");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetMass3->Fill(mass->GetValue());
       
   }

}


//-------------------------------------------------------------------------------------
void PrintHistograms(ExRootResult *result1, ExRootResult *result2, TCanvas *cs, TestPlots *plots)
{ 

  TLegend *legend;
  TPaveText *comment;
  THStack *stack;


  cs = new TCanvas("Jet_Mass_Top","Jet_Mass_Top"); 
  
  
  auto hs = new THStack("Jet_Mass_Top","Jet Mass for Top Jets");
  hs->SetMinimum(1);
 
  plots->fJetMass->SetLineColor(kBlue);
  plots->fJetMass->SetLineWidth(1);
  hs->Add(plots->fJetMass);
       
       
  plots->fJetMass2->SetLineColor(kRed);  
  plots->fJetMass2->SetLineWidth(1);
  hs->Add(plots->fJetMass2);
  
  plots->fJetMass3->SetLineColor(kBlack);  
  plots->fJetMass3->SetLineWidth(1);
  plots->fJetMass3->SetLineStyle(2);
  hs->Add(plots->fJetMass3);
         
  
  //Union de plots
  //stack = result1->AddHistStack("jet_pt", "Constituents P_t for Top Jets");
  
  
  // book legend for stack of 2 histograms

  legend = result1->AddLegend(0.62, 0.86-0.2, 0.98, 0.98-0.1);
  legend->AddEntry(plots->fJetMass, "t -> bqq' ", "l");
  legend->AddEntry(plots->fJetMass2,"t -> blv ", "l");
  legend->AddEntry(plots->fJetMass3,"QCD jets (Background)", "l");

  // attach legend to stack (legend will be printed over stack in .eps file)
 
  //cs->SetLogy();
  //cs->SetLogx();
  cs->cd();
  cs->Update();
  hs->Draw("nostack");
  hs->GetXaxis()->SetTitle("Mass(GeV)");
  legend->Draw();
  cs->SetGrid();
  cs->Print("examplesLP/Histograms/mass_Top.png");



  //result1->Print("png");
  //result2->Print("png");
  
}

//------------------------------------------------------------------------------

void mass_comp_Top(const char *inputFile, const char *inputFile2, const char *inputFile3)
{
  gSystem->Load("libDelphes");



  ExRootResult *result1 = new ExRootResult();
  
  ExRootResult *result2 = new ExRootResult();
  
  ExRootResult *result3 = new ExRootResult();
  
  TCanvas *cs;

  TestPlots *plots = new TestPlots;

  BookHistograms(result1, result2, result3, plots);

  AnalyseEvents(inputFile, plots);
  AnalyseEvents2(inputFile2, plots);
  AnalyseEvents3(inputFile3, plots);

  PrintHistograms(result1,result2, cs, plots);
 

  cout << "** Exiting..." << endl;

  delete plots;
  delete result1;
  delete result2;
}

//------------------------------------------------------------------------------
