#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TMath.h"

void fit_maneskin()
{
    gStyle->SetCanvasPreferGL();
    gStyle->SetGridColor(14);
    gStyle->SetGridStyle(3);
    
    TCanvas *canva = new TCanvas("canva", "Fit canva", 0., 0., 800, 600);

    TGraphErrors *graph_IV_100uA = new TGraphErrors("dati_100uA.txt", "%lg%lg%lg%lg");
    TGraphErrors *graph_IV_50uA = new TGraphErrors("dati_50uA.txt", "%lg%lg%lg%lg");
    
    Int_t N_POINTS_100uA = graph_IV_100uA->GetN();
    Double_t * V_100uA = graph_IV_100uA->GetX();
    Double_t * V_Err_100uA = graph_IV_100uA->GetEX();
    Double_t * I_100uA = graph_IV_100uA->GetY();
    Double_t * I_Err_100uA = graph_IV_100uA->GetEY();
    
    Int_t N_POINTS_50uA = graph_IV_50uA->GetN();
    Double_t * V_50uA = graph_IV_50uA->GetX();
    Double_t * V_Err_50uA = graph_IV_50uA->GetEX();
    Double_t * I_50uA = graph_IV_50uA->GetY();
    Double_t * I_Err_50uA = graph_IV_50uA->GetEY();

    TGraphErrors *graph_VI_100uA = new TGraphErrors(N_POINTS_100uA, I_100uA, V_100uA, I_Err_100uA, V_Err_100uA);
    TGraphErrors *graph_VI_50uA  = new TGraphErrors(N_POINTS_50uA, I_50uA, V_50uA, I_Err_50uA, V_Err_50uA);

    // TF1 *fit_100uA = new TF1("fit_100uA", "[0] + [1]*x", 1.1, 5);
    // TF1 *fit_50uA = new TF1("fit_50uA", "[0] + [1]*x", 0.6, 5);
    TF1 *fit_VI_100uA = new TF1("fit_VI_100uA", "[0] + [1]*x", 18, 22);
    TF1 *fit_VI_50uA = new TF1("fit_VI_50uA", "[0] + [1]*x", 8.56, 11);

    // fit_Si->SetParameter(0, 1.484e-6);
    // fit_Si->SetParameter(1, 46.05);
    // fit_Ge->SetParameter(0, 1.39e-4);
    // fit_Ge->SetParameter(1, 22.49);

    // fit_Si->SetParName(0, "I_{0}");
    // fit_Si->SetParName(1, "#eta V_{T}");
    // fit_Ge->SetParName(0, "I_{0}");
    // fit_Ge->SetParName(1, "#eta V_{T}");

    // graph_100uA->Fit(fit_100uA, "R");
    // graph_50uA->Fit(fit_50uA, "R");
    graph_VI_100uA->Fit(fit_VI_100uA, "R");
    graph_VI_50uA->Fit(fit_VI_50uA, "R");



    // graph_100uA->SetTitle("I-V Trasistor");
    // graph_100uA->GetXaxis()->SetTitle("-V_{CE} (V)");
    // graph_100uA->GetYaxis()->SetTitle("-I_{C} (mA)");
    // graph_100uA->GetXaxis()->SetTitleOffset(1.1);
    // graph_100uA->GetYaxis()->SetTitleOffset(1.3);
    // graph_100uA->SetMarkerColor(kBlue);
    // graph_100uA->SetLineColor(kBlue);
    
    // graph_100uA->SetTitle("I-V Trasistor");
    // graph_100uA->GetXaxis()->SetTitle("-V_{CE} (V)");
    // graph_100uA->GetYaxis()->SetTitle("-I_{C} (mA)");
    // graph_100uA->GetXaxis()->SetTitleOffset(1.1);
    // graph_100uA->GetYaxis()->SetTitleOffset(1.3);
    // graph_100uA->SetMarkerColor(kBlue);
    // graph_100uA->SetLineColor(kBlue);
    

    // graph_Ge->SetTitle("I-V Germanio");
    // graph_Ge->GetXaxis()->SetTitle("Tensione (mV)");
    // graph_Ge->GetYaxis()->SetTitle("Corrente (mA)");
    // graph_Ge->GetXaxis()->SetTitleOffset(1.1);
    // graph_Ge->GetYaxis()->SetTitleOffset(1.3);

    // gPad->SetLogy();
    canva->SetGrid();
    graph_VI_100uA->Draw("APE");
    graph_VI_50uA->Draw("PE, SAME");
    
    TLegend *legend{new TLegend(0., 1., 0.2, 0.9)};
    legend->SetNColumns(2);
    // RIGA 1
    legend->AddEntry(graph_VI_100uA, "Punti I-V (I_{B}=100uA)", "ep");
    legend->AddEntry(graph_VI_50uA, "Punti I-V (I_{B}=50uA)", "ep");
    // legend->AddEntry(fit_Si, "Fit caratteristica I-V (Si)", "l");
    // legend->AddEntry(fit_Si, "Fit caratteristica I-V (Si)", "l");
    // legend->AddEntry((TObject *)0, (std::string(fit_Si->GetParName(0)) + " = (" + std::to_string(fit_Si->GetParameter(0)* 1e6) + " ± " +  std::to_string(fit_Si->GetParError(0) * 1e6)+ ") nA").c_str(), "");
    // legend->AddEntry((TObject *)0, (std::string(fit_Si->GetParName(1)) + " = (" + std::to_string(fit_Si->GetParameter(1)) + " ± " +  std::to_string(fit_Si->GetParError(1)) + ") mV").c_str(), "");
    // legend->AddEntry((TObject *)0,"", "");
    legend->Draw();
    

}