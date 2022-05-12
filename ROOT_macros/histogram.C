void histogram()
{
    TString FileName = "output_0.root";
    TFile *file0 = TFile::Open(FileName);
    TTree *Edep = (TTree*) file0 -> Get("EnergyDeposition");
    Edep -> Print();
    
    TCanvas *c1A = new TCanvas();
    TH1D *h1 = new TH1D("h1", "", (int) TMath::Floor(TMath::Sqrt(Edep -> GetEntries())), 0.1, 2.4);
    Edep -> Draw("fEdep_A>>h1");
    h1 -> SetMarkerStyle(8);
    h1 -> SetMarkerColor(1);
    h1 -> SetLineColor(1);
    h1 -> SetMarkerSize(0.6);
    h1 -> SetStats(0);
    h1 -> GetXaxis() -> SetTitle("Energy Scintillator B[MeV]");
    h1 -> GetYaxis() -> SetTitle("Counts");
    h1 -> Draw();
    c1A -> Draw();
    gPad -> SetLogy();
    c1A -> SaveAs("../docs/assets/images/Edep_A.png");


    TCanvas *c1B = new TCanvas();
    TH1D *h3 = new TH1D("h3", "", (int) TMath::Floor(TMath::Sqrt(Edep -> GetEntries())), 0.1, 2.4);
    Edep -> Draw("fEdep_B>>h3");
    h3 -> SetMarkerStyle(8);
    h3 -> SetMarkerColor(1);
    h3 -> SetLineColor(1);
    h3 -> SetMarkerSize(0.6);
    h3 -> SetStats(0);
    h3 -> GetXaxis() -> SetTitle("Energy Scintillator A[MeV]");
    h3 -> GetYaxis() -> SetTitle("Counts");
    h3 -> Draw();
    c1B -> Draw();
    gPad -> SetLogy();
    c1B -> SaveAs("../docs/assets/images/Edep_B.png");


    TTree *tree_gaus_conv = new TTree("tree_gaus_conv", "tree_gaus_conv");
    
    double Edep_gaus_A;
    double Edep_gaus_B;

    tree_gaus_conv -> Branch("Edep_gaus_A", &Edep_gaus_A, "Edep_gaus_A/D");
    tree_gaus_conv -> Branch("Edep_gaus_B", &Edep_gaus_B, "Edep_gaus_B/D");

    double energy_A;
    double energy_B;

    Edep -> SetBranchAddress("fEdep_A", &energy_A);
    Edep -> SetBranchAddress("fEdep_B", &energy_B);
    
    for(int i = 0; i < (Edep->GetEntries());++i)
    {
        double x_A = gRandom->Gaus(0., 1.0);
        double x_B = gRandom->Gaus(0., 1.0);
        Edep -> GetEntry(i);
        double sigma_A = TMath::Sqrt(energy_A) * 0.05;
        double sigma_B = TMath::Sqrt(energy_B) * 0.05;
        
        Edep_gaus_A = x_A *sigma_A + energy_A;
        Edep_gaus_B = x_B *sigma_B + energy_B;
        
        if((energy_A != 0.) && (energy_A != 0.))
            tree_gaus_conv -> Fill();
    }

    TCanvas *c3A = new TCanvas();
    TH1D *h3A = new TH1D("h3A", "", (int) TMath::Floor(TMath::Sqrt(Edep -> GetEntries())), 0.1, 2.4);
    tree_gaus_conv -> Draw("Edep_gaus_A>>h3A");
    h3A -> SetMarkerStyle(8);
    h3A -> SetMarkerColor(1);
    h3A -> SetLineColor(1);
    h3A -> SetMarkerSize(0.6);
    h3A -> SetStats(0);
    h3A -> GetXaxis() -> SetTitle("Energy Scintillator A[MeV]");
    h3A -> GetYaxis() -> SetTitle("Counts");
    h3A -> Draw();
    c3A -> Draw();
    gPad -> SetLogy();
    c3A -> SaveAs("../docs/assets/images/Edep_gaus_A.png");

    TCanvas *c3B = new TCanvas();
    TH1D *h3B = new TH1D("h3B", "", (int) TMath::Floor(TMath::Sqrt(Edep -> GetEntries())), 0.1, 2.4);
    tree_gaus_conv -> Draw("Edep_gaus_B>>h3B");
    h3B -> SetMarkerStyle(8);
    h3B -> SetMarkerColor(1);
    h3B -> SetLineColor(1);
    h3B -> SetMarkerSize(0.6);
    h3B -> SetStats(0);
    h3B -> GetXaxis() -> SetTitle("Energy Scintillator B[MeV]");
    h3B -> GetYaxis() -> SetTitle("Counts");
    h3B -> Draw();
    c3B -> Draw();
    gPad -> SetLogy();
    c3B -> SaveAs("../docs/assets/images/Edep_gaus_B.png");




    TCanvas *c3 = new TCanvas();
    TH2D *h2d = new TH2D("h2d", "", 400, 0.1,3,400,0.1, 3);
    tree_gaus_conv -> Draw("Edep_gaus_A:Edep_gaus_B>>h2d", "","colz");
    c3 -> Draw();
    c3 -> SaveAs("../docs/assets/images/AB_gaus.png");


    TCanvas *c4 = new TCanvas();
    TH2D *h2d2 = new TH2D("h2d2", "", 1000, 0.1,3,1000,0.1, 3);
    Edep -> Draw("fEdep_A:fEdep_B>>h2d2", "","colz");
    c4 -> Draw();
    c4 -> SaveAs("../docs/assets/images/AB.png");

}