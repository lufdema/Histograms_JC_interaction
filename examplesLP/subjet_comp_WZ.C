/*
The next line shows how to run the program in the terminal. This program must be run inside the Delphes folder due to the 
exrootanalysis dependences

root -l examplesLP/subjet_comp_WZ.C'("WToQQ_000.root", "ZToQQ_000.root", "ZJetsToNuNu_000.root")'



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
  
  TH1 *fJetSub;
  TH1 *fJetSub2;
  TH1 *fJetSub3;
  
};

//------------------------------------------------------------------------------

void BookHistograms(ExRootResult *result1, ExRootResult *result2 , ExRootResult *result3, TestPlots *plots)
{




 
  plots->fJetSub = result1->AddHist1D(
    "Jet WZ  Sub JC", "Jet WZ  Sub JC",
    "Subjetiness", "number of jets",600,1.0e-1, 1); //Los ultimos numeros, el cero y 
                                                //el 1 significan que no hay escala log en x pero si en y
 
  plots->fJetSub->SetLineColor(kBlue);

  plots->fJetSub2 = result2->AddHist1D(
    "Jet WZ2  Sub JC", "Jet WZ2  Sub JC",
    "Subjetiness", "number of jets",600, 1.0e-1, 1);
   
  plots->fJetSub2->SetLineColor(kRed);
  
  plots->fJetSub3 = result3->AddHist1D(
    "Jet WZ3  Sub JC", "Jet WZ3  Sub JC",
    "Subjetiness", "number of jets",600, 1.0e-1, 1);
   
  plots->fJetSub3->SetLineColor(kBlack);   
  
}

//------------------------------------------------------------------------------

void AnalyseEvents(const char *inputFile, TestPlots *plots)
{
 TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;


  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  TLeaf *tau1=tree-> GetLeaf("jet_tau1");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
  plots->fJetSub->Fill((tau2->GetValue())/ (tau1->GetValue()));
          
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

  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  TLeaf *tau1=tree-> GetLeaf("jet_tau1");
  
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetSub2->Fill((tau2->GetValue())/ (tau1->GetValue()));
    
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


  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  TLeaf *tau1=tree-> GetLeaf("jet_tau1");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
  plots->fJetSub3->Fill((tau2->GetValue())/ (tau1->GetValue()));
          
   }

}

//-------------------------------------------------------------------------------------
void PrintHistograms(ExRootResult *result1, ExRootResult *result2, TCanvas *cs, TestPlots *plots)
{ 

  TLegend *legend;
  TPaveText *comment;
  THStack *stack;


  cs = new TCanvas("Jet_Sub_WZ","Jet_Sub_WZ"); 
  
  
  auto hs = new THStack("Jet_Sub_WZ","Jet #tau_{2}/#tau_{1} for W and Z Jets");
  hs->SetMinimum(1);
 
  plots->fJetSub->SetLineColor(kBlue);
  plots->fJetSub->SetLineWidth(1);
  hs->Add(plots->fJetSub);
       
       
  plots->fJetSub2->SetLineColor(kRed);  
  plots->fJetSub2->SetLineWidth(1);
  hs->Add(plots->fJetSub2);
  
  
  plots->fJetSub3->SetLineColor(kBlack);  
  plots->fJetSub3->SetLineWidth(1);
  plots->fJetSub3->SetLineStyle(2);
  hs->Add(plots->fJetSub3);
         
 
  //Union de plots
  //stack = result1->AddHistStack("jet_pt", "Constituents P_t for Top Jets");
  
  
  // book legend for stack of 2 histograms

  legend = result1->AddLegend(0.63, 0.96-0.2, 0.99, 1-0.1);
  legend->AddEntry(plots->fJetSub, "W -> qq' ", "l");
  legend->AddEntry(plots->fJetSub2,"Z -> qq_{anti} ", "l");
  legend->AddEntry(plots->fJetSub3,"QCD jets (Background)", "l");

  // attach legend to stack (legend will be printed over stack in .eps file)
 
  //cs->SetLogy();
  //cs->SetLogx();
  cs->cd();
  cs->Update();
  hs->Draw("nostack");
  hs->GetXaxis()->SetTitle("#tau_{2}/#tau_{1}");
  legend->Draw();
  cs->SetGrid();
  cs->Print("examplesLP/Histograms/sub_WZ.png");



  //result1->Print("png");
  //result2->Print("png");
  
}

//------------------------------------------------------------------------------

void subjet_comp_WZ(const char *inputFile, const char *inputFile2, const char *inputFile3)
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
