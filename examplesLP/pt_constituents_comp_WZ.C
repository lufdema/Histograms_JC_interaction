/*
The next line shows how to run the program in the terminal. This program must be run inside the Delphes folder due to the 
exrootanalysis dependences

root -l examplesLP/pt_constituents_comp_WZ.C'("WToQQ_000.root", "ZToQQ_000.root", "ZJetsToNuNu_000.root")'




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
  
};

//------------------------------------------------------------------------------

void BookHistograms(ExRootResult *result1, ExRootResult *result2 ,ExRootResult *result3 ,TestPlots *plots)
{




 
  plots->fJetPt = result1->AddHist1D(
    "Jet WZ Contituents Pt JC", "Jet WZ Contituents Pt JC",
    "p_{T}", "number of jets",600, 0, 1100, 0, 1); //Los ultimos numeros, el cero y 
                                                //el 1 significan que no hay escala log en x pero si en y
 
  plots->fJetPt->SetLineColor(kBlue);

  plots->fJetPt2 = result2->AddHist1D(
    "Jet WZ2 Contituents Pt JC", "Jet WZ2 Contituents Pt JC",
    "p_{T}", "number of jets",600, 0, 1100, 0, 1);
   
  plots->fJetPt2->SetLineColor(kRed);  
  
  plots->fJetPt3 = result3->AddHist1D(
    "Jet WZ3 Contituents Pt JC", "Jet WZ3 Contituents Pt JC",
    "p_{T}", "number of jets",600, 0, 1100, 0, 1);
   
  plots->fJetPt3->SetLineColor(kBlack);  
 
  
  
 
  
}

//------------------------------------------------------------------------------

void AnalyseEvents(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  auto px = new std::vector<double>();
  auto py = new std::vector<double>();
  auto pz = new std::vector<double>();
  auto E = new std::vector<double>();
  
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;

  TLorentzVector momentum;
  
  tree->SetBranchAddress("part_px", &px);
  tree->SetBranchAddress("part_py", &py);
  tree->SetBranchAddress("part_pz", &pz);
  tree->SetBranchAddress("part_energy", &E);
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);
    int size= px->size();

    // Loop over all jets in event
    for (i=0; (i<size); ++i)
    {	
     
  
     momentum.SetPxPyPzE(px[0][i], py[0][i], pz[0][i], E[0][i]);
     plots->fJetPt->Fill(momentum.Pt());
    }
               
   }

}


//------------------------------------------------------------------------------


void AnalyseEvents2(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  auto px = new std::vector<double>();
  auto py = new std::vector<double>();
  auto pz = new std::vector<double>();
  auto E = new std::vector<double>();
  
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;

  TLorentzVector momentum;
  
  tree->SetBranchAddress("part_px", &px);
  tree->SetBranchAddress("part_py", &py);
  tree->SetBranchAddress("part_pz", &pz);
  tree->SetBranchAddress("part_energy", &E);
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < allEntries; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);
    int size= px->size();

    // Loop over all jets in event
    for (i=0; (i<size); ++i)
    {	
     
  
     momentum.SetPxPyPzE(px[0][i], py[0][i], pz[0][i], E[0][i]);
     plots->fJetPt2->Fill(momentum.Pt());
    }
       
   }
      
}

//-------------------------------------------------------------------------------------

void AnalyseEvents3(const char *inputFile, TestPlots *plots)
{
  TFile *fopen=TFile::Open(inputFile); 
  TTree *tree=(TTree*)fopen->Get("tree"); 
  auto px = new std::vector<double>();
  auto py = new std::vector<double>();
  auto pz = new std::vector<double>();
  auto E = new std::vector<double>();
  
  int allEntries = tree->GetEntries();
  
  cout << "** Chain contains " << allEntries << " events" << endl;

  Long64_t entry;

  TLorentzVector momentum;
  
  tree->SetBranchAddress("part_px", &px);
  tree->SetBranchAddress("part_py", &py);
  tree->SetBranchAddress("part_pz", &pz);
  tree->SetBranchAddress("part_energy", &E);
  

  Int_t i, j, pdgCode;

  // Loop over all events
  for(entry = 0; entry < 100000; ++entry)
  {
    // Load selected branches with data from specified event
    tree->GetEntry(entry);
    int size= px->size();

    // Loop over all jets in event
    for (i=0; (i<size); ++i)
    {	
     
  
     momentum.SetPxPyPzE(px[0][i], py[0][i], pz[0][i], E[0][i]);
     plots->fJetPt3->Fill(momentum.Pt());
    }
               
   }

}
//-------------------------------------------------------------------------------------
void PrintHistograms(ExRootResult *result1, ExRootResult *result2, TCanvas *cs, TestPlots *plots)
{ 

  TLegend *legend;
  TPaveText *comment;
  THStack *stack;


  cs = new TCanvas("Pt_constituents_WZ","Pt_constituents_WZ"); 
  
  
  auto hs = new THStack("Jet_pt_constituents","Constituents P_t for W and Z Jets");
  hs->SetMinimum(1);
 
  plots->fJetPt->SetLineColor(kBlue);
  hs->Add(plots->fJetPt);
       
  plots->fJetPt2->SetLineColor(kRed);  
  hs->Add(plots->fJetPt2);
  
  plots->fJetPt3->SetLineColor(kBlack); 
  plots->fJetPt3->SetLineStyle(2); 
  hs->Add(plots->fJetPt3);
         
 
  //Union de plots
  //stack = result1->AddHistStack("jet_pt", "Constituents P_t for Top Jets");
  
  
  // book legend for stack of 2 histograms

  legend = result1->AddLegend(0.62, 0.86-0.2, 0.98, 0.98-0.1);
  legend->AddEntry(plots->fJetPt, "W -> qq' ", "l");
  legend->AddEntry(plots->fJetPt2,"Z -> qq_{anti} ", "l");
  legend->AddEntry(plots->fJetPt3,"QCD jets (Background)", "l");

  // attach legend to stack (legend will be printed over stack in .eps file)
 
  cs->SetLogy();
  cs->cd();
  cs->Update();
  hs->Draw("nostack");
  legend->Draw();
  cs->SetGrid();
  cs->Print("examplesLP/Histograms/Pt_constituents_WZ.png");



  //result1->Print("png");
  //result2->Print("png");
  
}

//------------------------------------------------------------------------------

void pt_constituents_comp_WZ(const char *inputFile, const char *inputFile2, const char *inputFile3)
{
  gSystem->Load("libDelphes");



  ExRootResult *result1 = new ExRootResult();
  
  ExRootResult *result2 = new ExRootResult();
  
  ExRootResult *result3 = new ExRootResult();
  
  TCanvas *cs;

  TestPlots *plots = new TestPlots;

  BookHistograms(result1, result2, result3 ,plots);

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
