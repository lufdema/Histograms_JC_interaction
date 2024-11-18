/*
The next line shows how to run the program in the terminal. This program must be run inside the Delphes folder due to the 
exrootanalysis dependences

root -l examplesLP/pt_comp_Higgs.C'("HToBB_000.root", "HToCC_000.root", "HToGG_000.root","HToWW2Q1L_000.root","HToWW4Q_000.root", "ZJetsToNuNu_000.root")'



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
  
  TH1 *fJetPt;
  TH1 *fJetPt2;
  TH1 *fJetPt3;
  TH1 *fJetPt4;
  TH1 *fJetPt5;
  TH1 *fJetPt6;
  
};

//------------------------------------------------------------------------------

void BookHistograms(ExRootResult *result1, ExRootResult *result2 , ExRootResult *result3, ExRootResult *result4, ExRootResult *result5, ExRootResult *result6, TestPlots *plots)
{




 
  plots->fJetPt = result1->AddHist1D(
    "Jet T  Pt JC", "Jet T  Pt JC",
    "Pt", "number of jets",600, 450, 1100, 0, 1); //Los ultimos numeros, el cero y 
                                                //el 1 significan que no hay escala log en x pero si en y
 
  plots->fJetPt->SetLineColor(kBlue+1);

  plots->fJetPt2 = result2->AddHist1D(
    "Jet H2  Pt JC", "Jet H2  Pt JC",
    "Pt", "number of jets",600, 450, 1100, 0, 1);
   
  plots->fJetPt2->SetLineColor(kRed+1);  
  
  plots->fJetPt3 = result3->AddHist1D(
    "Jet H3  Pt JC", "Jet H3  Pt JC",
    "Pt", "number of jets",600, 450, 1100, 0, 1);
   
  plots->fJetPt3->SetLineColor(kGreen-2);
  
  
  plots->fJetPt4 = result4->AddHist1D(
    "Jet H4  Pt JC", "Jet H4  Pt JC",
    "Pt", "number of jets",600, 450, 1100, 0, 1);
   
  plots->fJetPt4->SetLineColor(kMagenta-7);
  
  
  plots->fJetPt5 = result5->AddHist1D(
    "Jet H5  Pt JC", "Jet H5  Pt JC",
    "Pt", "number of jets",600, 450, 1100, 0, 1);
   
  plots->fJetPt5->SetLineColor(kCyan);
  
  
  plots->fJetPt6 = result6->AddHist1D(
    "Jet H6  Pt JC", "Jet H6  Pt JC",
    "Pt", "number of jets",600, 450, 1100, 0, 1);
   
  plots->fJetPt6->SetLineColor(kBlack);
 
  
  
 
  
}

//------------------------------------------------------------------------------

void AnalyseEvents(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;

  TLeaf *pt=tree-> GetLeaf("jet_pt");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetPt->Fill(pt->GetValue());
    
     
      
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

  TLeaf *pt=tree-> GetLeaf("jet_pt");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetPt2->Fill(pt->GetValue());
    
     
      
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

  TLeaf *pt=tree-> GetLeaf("jet_pt");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetPt3->Fill(pt->GetValue());
    
     
      
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

  TLeaf *pt=tree-> GetLeaf("jet_pt");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetPt4->Fill(pt->GetValue());
    
     
      
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

  TLeaf *pt=tree-> GetLeaf("jet_pt");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetPt5->Fill(pt->GetValue());
    
     
      
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

  TLeaf *pt=tree-> GetLeaf("jet_pt");
  
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);

    // Loop over all jets in event	
    plots->fJetPt6->Fill(pt->GetValue());
    
     
      
      }

      
    }



//------------------------------------------------------------------------------------------
void PrintHistograms(ExRootResult *result1, ExRootResult *result2, TCanvas *cs, TestPlots *plots)
{ 

  TLegend *legend;
  TPaveText *comment;
  THStack *stack;


  cs = new TCanvas("Jet_Pt_Higgs","Jet_Pt_Higgs"); 
  
  
  auto hs = new THStack("Jet_Pt_Higgs","Jet P_{t} for Jets coming from Higgs Decays");
  hs->SetMinimum(1);
 
  plots->fJetPt->SetLineColor(kBlue+1);
  plots->fJetPt->SetLineWidth(2);
  hs->Add(plots->fJetPt);
       
       
  plots->fJetPt2->SetLineColor(kRed+1);  
  plots->fJetPt2->SetLineWidth(2);
  hs->Add(plots->fJetPt2);
  
  plots->fJetPt3->SetLineColor(kGreen-2);  
  plots->fJetPt3->SetLineWidth(2);
  hs->Add(plots->fJetPt3);
  
  plots->fJetPt4->SetLineColor(kMagenta-7);  
  plots->fJetPt4->SetLineWidth(2);
  hs->Add(plots->fJetPt4);
  
  plots->fJetPt5->SetLineColor(kCyan);  
  plots->fJetPt5->SetLineWidth(2);
  hs->Add(plots->fJetPt5);
  
  plots->fJetPt6->SetLineColor(kBlack);  
  plots->fJetPt6->SetLineWidth(2);
  plots->fJetPt6->SetLineStyle(2);
  hs->Add(plots->fJetPt6);
         
  
  //Union de plots
  //stack = result1->AddHistStack("jet_pt", "Constituents P_t for Top Jets");
  
  
  // book legend for stack of 2 histograms

  legend = result1->AddLegend(0.62, 0.86-0.2, 0.98, 0.98-0.1);
  legend->AddEntry(plots->fJetPt, "H -> b b_{anti}' ", "l");
  legend->AddEntry(plots->fJetPt2,"H -> c c_{anti} ", "l");
  legend->AddEntry(plots->fJetPt3,"H -> gg ", "l");
  legend->AddEntry(plots->fJetPt4,"H -> lvqq' ", "l");
  legend->AddEntry(plots->fJetPt5,"H -> 4q ", "l");
  legend->AddEntry(plots->fJetPt6,"QCD jets (Background)", "lp");

  // attach legend to stack (legend will be printed over stack in .eps file)
 
  //cs->SetLogy();
  //cs->SetLogx();
  cs->cd();
  cs->Update();
  hs->Draw("nostack");
  hs->GetXaxis()->SetTitle("Pt(GeV)");
  legend->Draw();
  cs->SetGrid();
  cs->Print("examplesLP/Histograms/Pt_Higgs.png");



  //result1->Print("png");
  //result2->Print("png");
  
}

//------------------------------------------------------------------------------

void pt_comp_Higgs(const char *inputFile, const char *inputFile2, const char *inputFile3,const char *inputFile4,const char *inputFile5, const char *inputFile6)
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
