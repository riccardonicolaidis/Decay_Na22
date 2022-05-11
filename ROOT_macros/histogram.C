void histogram()
{
    TString FileName = "output_0.root";
    TFile *file0 = TFile::Open(FileName);
    TTree *Edep = (TTree*) file0 -> Get("EnergyDeposition");
    Edep -> Print();
    
    TCanvas *c1 = new TCanvas();
    TH1D *h1 = new TH1D("h1", "", (int) TMath::Floor(TMath::Sqrt(Edep -> GetEntries())), 0.1, 2.4);
    Edep -> Draw("fEdep_A>>h1");
    h1 -> SetMarkerStyle(8);
    h1 -> SetMarkerColor(1);
    h1 -> SetLineColor(1);
    h1 -> SetMarkerSize(0.6);
    h1 -> SetStats(0);
    h1 -> GetXaxis() -> SetTitle("Energy [MeV]");
    h1 -> GetYaxis() -> SetTitle("Counts");
    h1 -> Draw();
    c1 -> Draw();
    gPad -> SetLogy();

    
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
        double sigma_A = TMath::Sqrt(energy_A) * 0.02;
        double sigma_B = TMath::Sqrt(energy_B) * 0.02;
        
        Edep_gaus_A = x_A *sigma_A + energy_A;
        Edep_gaus_B = x_B *sigma_B + energy_B;
        
        if((energy_A != 0.) && (energy_A != 0.))
            tree_gaus_conv -> Fill();
    }


    TCanvas *c3 = new TCanvas();
    TH2D *h2d = new TH2D("h2d", "", 400, 0.1,3,400,0.1, 3);
    tree_gaus_conv -> Draw("Edep_gaus_A:Edep_gaus_B>>h2d", "","colz");
    c3 -> Draw();


    TCanvas *c4 = new TCanvas();
    TH2D *h2d2 = new TH2D("h2d2", "", 700, 0.1,3,700,0.1, 3);
    Edep -> Draw("fEdep_A:fEdep_B>>h2d2", "","");
    c4 -> Draw();

}