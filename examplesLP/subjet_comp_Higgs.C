/*
The next line shows how to run the program in the terminal. This program must be run inside the Delphes folder due to the 
exrootanalysis dependences

root -l examplesLP/subjet_comp_Higgs.C'("HToBB_000.root", "HToCC_000.root", "HToGG_000.root","HToWW2Q1L_000.root","HToWW4Q_000.root", "ZJetsToNuNu_000.root")'



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
  TH1 *fJetSub4;
  TH1 *fJetSub5;
  TH1 *fJetSub6;
  
};

//------------------------------------------------------------------------------

void BookHistograms(ExRootResult *result1, ExRootResult *result2 , ExRootResult *result3, ExRootResult *result4, ExRootResult *result5, ExRootResult *result6, TestPlots *plots)
{




 
  plots->fJetSub = result1->AddHist1D(
    "Jet T  Subjetiness JC", "Jet T  Subjetiness JC",
    "Subjetiness", "number of jets",600, 1.0e-1, 1); //Los ultimos numeros, el cero y 
                                                //el 1 significan que no hay escala log en x pero si en y
 
  plots->fJetSub->SetLineColor(kBlue+1);

  plots->fJetSub2 = result2->AddHist1D(
    "Jet H2  Subjetiness JC", "Jet H2  Subjetiness JC",
    "Subjetiness", "number of jets",600, 1.0e-1, 1);
   
  plots->fJetSub2->SetLineColor(kRed+1);  
  
  plots->fJetSub3 = result3->AddHist1D(
    "Jet H3  Subjetiness JC", "Jet H3  Subjetiness JC",
    "Subjetiness", "number of jets",600, 1.0e-1, 1);
   
  plots->fJetSub3->SetLineColor(kGreen-2);
  
  
  plots->fJetSub4 = result4->AddHist1D(
    "Jet H4  Subjetiness JC", "Jet H4  Subjetiness JC",
    "Subjetiness", "number of jets",600, 1.0e-1, 1);
   
  plots->fJetSub4->SetLineColor(kMagenta-7);
  
  
  plots->fJetSub5 = result5->AddHist1D(
    "Jet H5  Subjetiness JC", "Jet H5  Subjetiness JC",
    "Subjetiness", "number of jets",600, 1.0e-1, 1);
   
  plots->fJetSub5->SetLineColor(kCyan);
 
 
  plots->fJetSub6 = result6->AddHist1D(
    "Jet H6  Subjetiness JC", "Jet H6  Subjetiness JC",
    "Subjetiness", "number of jets",600, 1.0e-1, 1);
   
  plots->fJetSub6->SetLineColor(kBlack);
  
  
 
  
}

//------------------------------------------------------------------------------

void AnalyseEvents(const char *inputFile, TestPlots *plots)
{

  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;


  TLeaf *tau3=tree-> GetLeaf("jet_tau3");
  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < allEntries; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
  plots->fJetSub->Fill((tau3->GetValue())/ (tau2->GetValue()));
    
     
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


  TLeaf *tau3=tree-> GetLeaf("jet_tau3");
  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < allEntries; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
  plots->fJetSub2->Fill((tau3->GetValue())/ (tau2->GetValue()));
    
     
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


  TLeaf *tau3=tree-> GetLeaf("jet_tau3");
  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < allEntries; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
  plots->fJetSub3->Fill((tau3->GetValue())/ (tau2->GetValue()));
    
     
    }

      
    }


//----------------------------------------------------------------------------------------

void AnalyseEvents4(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;


  TLeaf *tau3=tree-> GetLeaf("jet_tau3");
  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < allEntries; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
  plots->fJetSub4->Fill((tau3->GetValue())/ (tau2->GetValue()));
    
     
    }

      
    }


//-----------------------------------------------------------------------------------------


void AnalyseEvents5(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;


  TLeaf *tau3=tree-> GetLeaf("jet_tau3");
  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < allEntries; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
  plots->fJetSub5->Fill((tau3->GetValue())/ (tau2->GetValue()));
    
     
    }
      
    }
    
//-----------------------------------------------------------------------------------------

void AnalyseEvents6(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;


  TLeaf *tau3=tree-> GetLeaf("jet_tau3");
  TLeaf *tau2=tree-> GetLeaf("jet_tau2");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < allEntries; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
  plots->fJetSub6->Fill((tau3->GetValue())/ (tau2->GetValue()));
    
     
    }
      
    }

//-----------------------------------------------------------------------------------------

void PrintHistograms(ExRootResult *result1, ExRootResult *result2, TCanvas *cs, TestPlots *plots)
{ 

  TLegend *legend;
  TPaveText *comment;
  THStack *stack;


  cs = new TCanvas("Jet_Subjetiness_Higgs","Jet_Subjetiness_Higgs"); 
  
  
  auto hs = new THStack("Jet_Subjetiness_Higgs","Jet #tau_{3}/#tau_{2} for Jets coming from Higgs Decays");
  hs->SetMinimum(1);
 
  plots->fJetSub->SetLineColor(kBlue+1);
  plots->fJetSub->SetLineWidth(2);
  hs->Add(plots->fJetSub);
       
       
  plots->fJetSub2->SetLineColor(kRed+1);  
  plots->fJetSub2->SetLineWidth(2);
  hs->Add(plots->fJetSub2);
  
  plots->fJetSub3->SetLineColor(kGreen-2);  
  plots->fJetSub3->SetLineWidth(2);
  hs->Add(plots->fJetSub3);
  
  plots->fJetSub4->SetLineColor(kMagenta-7);  
  plots->fJetSub4->SetLineWidth(2);
  hs->Add(plots->fJetSub4);
  
  plots->fJetSub5->SetLineColor(kCyan);  
  plots->fJetSub5->SetLineWidth(2);
  hs->Add(plots->fJetSub5);
         
  plots->fJetSub6->SetLineColor(kBlack);  
  plots->fJetSub6->SetLineWidth(2);
  plots->fJetSub6->SetLineStyle(2);
  hs->Add(plots->fJetSub6);
         
  
  //Union de plots
  //stack = result1->AddHistStack("jet_pt", "Constituents P_t for Top Jets");
  
  
  // book legend for stack of 2 histograms

  legend = result1->AddLegend(0.15, 0.86-0.2, 0.51, 0.98-0.1);
  legend->AddEntry(plots->fJetSub,"H -> b b_{anti}' ", "l");
  legend->AddEntry(plots->fJetSub2,"H -> c c_{anti} ", "l");
  legend->AddEntry(plots->fJetSub3,"H -> gg ", "l");
  legend->AddEntry(plots->fJetSub4,"H -> lvqq' ", "l");
  legend->AddEntry(plots->fJetSub5,"H -> 4q ", "l");
  legend->AddEntry(plots->fJetSub6,"QCD jets (Background)", "lp");

  // attach legend to stack (legend will be printed over stack in .eps file)
 
  //cs->SetLogy();
  //cs->SetLogx();
  cs->cd();
  cs->Update();
  hs->Draw("nostack");
  hs->GetXaxis()->SetTitle("#tau_{3}/#tau_{2}");
  legend->Draw();
  cs->SetGrid();
  cs->Print("examplesLP/Histograms/sub_Higgs32.png");



  //result1->Print("png");
  //result2->Print("png");
  
}

//------------------------------------------------------------------------------

void subjet_comp_Higgs(const char *inputFile, const char *inputFile2, const char *inputFile3,const char *inputFile4,const char *inputFile5, const char *inputFile6)
{
  gSystem->Load("libDelphes");



  ExRootResult *result1 = new ExRootResult();
  
  ExRootResult *result2 = new ExRootResult();
  
  ExRootResult *result3 = new ExRootResult();
  
  ExRootResult *result4 = new ExRootResult();
  
  ExRootResult *result5 = new ExRootResult();
  
  ExRootResult *result6 = new ExRootResult();
  
  
  TCanvas *cs;

  TestPlots *plots = new TestPlots;

  BookHistograms(result1, result2,result3,result4,result5,result6, plots);

  AnalyseEvents(inputFile, plots);
  AnalyseEvents2(inputFile2, plots);
  AnalyseEvents3(inputFile3, plots);
  AnalyseEvents4(inputFile4, plots);
  AnalyseEvents5(inputFile5, plots);
  AnalyseEvents6(inputFile6, plots);
  

  PrintHistograms(result1,result2, cs, plots);
 

  cout << "** Exiting..." << endl;

  delete plots;
  delete result1;
  delete result2;
  
}

//------------------------------------------------------------------------------
