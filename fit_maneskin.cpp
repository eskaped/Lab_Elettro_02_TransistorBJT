#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TMatrixD.h"
#include "TMath.h"
#include "TText.h"
#include "TPaveText.h"
void fit_maneskin()
{
    gStyle->SetCanvasPreferGL();
    gStyle->SetGridColor(14);
    gStyle->SetGridStyle(3);

    TCanvas *canva_VI = new TCanvas("canva_VI", "Canva_VI", 0., 0., 800, 600);

    TGraphErrors *graph_IV_100uA = new TGraphErrors("dati_100uA.txt", "%lg%lg%lg%lg");
    TGraphErrors *graph_IV_50uA = new TGraphErrors("dati_50uA.txt", "%lg%lg%lg%lg");

    Int_t N_POINTS_100uA = graph_IV_100uA->GetN();
    Double_t *V_100uA = graph_IV_100uA->GetX();
    Double_t *V_Err_100uA = graph_IV_100uA->GetEX();
    Double_t *I_100uA = graph_IV_100uA->GetY();
    Double_t *I_Err_100uA = graph_IV_100uA->GetEY();

    Int_t N_POINTS_50uA = graph_IV_50uA->GetN();
    Double_t *V_50uA = graph_IV_50uA->GetX();
    Double_t *V_Err_50uA = graph_IV_50uA->GetEX();
    Double_t *I_50uA = graph_IV_50uA->GetY();
    Double_t *I_Err_50uA = graph_IV_50uA->GetEY();

    TGraphErrors *graph_VI_100uA = new TGraphErrors(N_POINTS_100uA, I_100uA, V_100uA, I_Err_100uA, V_Err_100uA);
    TGraphErrors *graph_VI_50uA = new TGraphErrors(N_POINTS_50uA, I_50uA, V_50uA, I_Err_50uA, V_Err_50uA);

    // invert to have all negative and make it easier
    for (int i = 0; i != N_POINTS_100uA; ++i)
    {
        graph_VI_100uA->GetX()[i] *= -1;
        graph_VI_100uA->GetY()[i] *= -1;
        graph_VI_50uA->GetX()[i] *= -1;
        graph_VI_50uA->GetY()[i] *= -1;
    }

    // TF1 *fit_100uA = new TF1("fit_100uA", "[0] + [1]*x", 1.1, 5);
    // TF1 *fit_50uA = new TF1("fit_50uA", "[0] + [1]*x", 0.6, 5);
    TF1 *fit_VI_100uA = new TF1("fit_VI_100uA", "[0] + [1]*x", -22, -18);
    TF1 *fit_VI_50uA = new TF1("fit_VI_50uA", "[0] + [1]*x", -11, -8.56);

    fit_VI_100uA->SetParameter(0, 24);
    fit_VI_100uA->SetParameter(1, 1.4);
    fit_VI_50uA->SetParameter(0, 22);
    fit_VI_50uA->SetParameter(1, 2.7);

    fit_VI_100uA->SetParName(0, "V_{early_100}");
    fit_VI_100uA->SetParName(1, "R_{attiva_100}"); // NB!!!:: è in V/mA!! => per averla in ohm devi fare *10^3
    fit_VI_50uA->SetParName(0, "V_{early_50}");
    fit_VI_50uA->SetParName(1, "R_{attiva_50}"); // NB!!!:: è in V/mA!! => per averla in ohm devi fare *10^3

    // graph_100uA->Fit(fit_100uA, "R");
    // graph_50uA->Fit(fit_50uA, "R");
    TFitResultPtr res_100uA = graph_VI_100uA->Fit(fit_VI_100uA, "R S");
    TFitResultPtr res_50uA = graph_VI_50uA->Fit(fit_VI_50uA, "R S");

    TMatrixD covariance_matrix_100uA = res_100uA->GetCovarianceMatrix();
    // TMatrixD correlation_matrix_100uA = res_100uA->GetCorrelationMatrix();
    TMatrixD covariance_matrix_50uA = res_50uA->GetCovarianceMatrix();
    // TMatrixD correlation_matrix_50uA = res_50uA->GetCorrelationMatrix();

    std::cout << "COVARIANCE MATRIX 100uA:";
    covariance_matrix_100uA.Print();
    // std::cout<<"CORRELATION MATRIX 100uA:";
    // correlation_matrix_100uA.Print();

    std::cout << "COVARIANCE MATRIX 50uA:";
    covariance_matrix_50uA.Print();
    // std::cout<<"CORRELATION MATRIX 50uA:";
    // correlation_matrix_50uA.Print();

    // correlazione
    Double_t covariance_100uA = covariance_matrix_100uA[0][1];
    Double_t covariance_50uA = covariance_matrix_50uA[0][1];
    std::cout << "Covariance 100uA:\t" << covariance_100uA << " VmA\n";
    std::cout << "Covariance 50uA:\t" << covariance_50uA << " VmA\n";

    graph_VI_100uA->SetTitle("V-I Trasistor");
    // graph_100uA->GetXaxis()->SetTitle("-V_{CE} (V)");
    // graph_100uA->GetYaxis()->SetTitle("-I_{C} (mA)");
    // graph_100uA->GetXaxis()->SetTitleOffset(1.1);
    // graph_100uA->GetYaxis()->SetTitleOffset(1.3);
    // graph_100uA->SetMarkerColor(kBlue);
    // graph_100uA->SetLineColor(kBlue);

    graph_VI_50uA->SetTitle("V-I Trasistor");
    // graph_100uA->GetXaxis()->SetTitle("-V_{CE} (V)");
    // graph_100uA->GetYaxis()->SetTitle("-I_{C} (mA)");
    // graph_100uA->GetXaxis()->SetTitleOffset(1.1);
    // graph_100uA->GetYaxis()->SetTitleOffset(1.3);
    // graph_100uA->SetMarkerColor(kBlue);
    // graph_100uA->SetLineColor(kBlue);

    canva_VI->SetGrid();
    graph_VI_100uA->Draw("APE");
    graph_VI_50uA->Draw("PE, SAME");

    TLegend *legend{new TLegend(0., 1., 0.2, 0.9)};
    legend->SetNColumns(2);
    // RIGA 1
    legend->AddEntry(graph_VI_100uA, "Punti V-I (I_{B}=-100uA)", "ep");
    legend->AddEntry(graph_VI_50uA, "Punti V-I (I_{B}=-50uA)", "ep");
    // legend->AddEntry(fit_Si, "Fit caratteristica I-V (Si)", "l");
    // legend->AddEntry(fit_Si, "Fit caratteristica I-V (Si)", "l");
    // legend->AddEntry((TObject *)0, (std::string(fit_Si->GetParName(0)) + " = (" + std::to_string(fit_Si->GetParameter(0)* 1e6) + " ± " +  std::to_string(fit_Si->GetParError(0) * 1e6)+ ") nA").c_str(), "");
    // legend->AddEntry((TObject *)0, (std::string(fit_Si->GetParName(1)) + " = (" + std::to_string(fit_Si->GetParameter(1)) + " ± " +  std::to_string(fit_Si->GetParError(1)) + ") mV").c_str(), "");
    // legend->AddEntry((TObject *)0,"", "");
    legend->Draw();

    TCanvas *canva_IV = new TCanvas("canva_IV", "Canva_IV", 0, 0, 1600, 1080);
    canva_IV->SetGrid();
    canva_IV->SetTopMargin(1 - 0.785); // leave space for legend

    graph_IV_100uA->SetTitle("Caratteristica IV Transistor BJT");


    graph_IV_100uA->GetXaxis()->SetTitle("-V_{CE}");
    graph_IV_100uA->GetYaxis()->SetTitle("-I_{C}");
    graph_IV_100uA->GetXaxis()->SetTitleSize(0.055);
    graph_IV_100uA->GetYaxis()->SetTitleSize(0.055);
    graph_IV_100uA->GetXaxis()->SetTitleOffset(0.75);
    graph_IV_100uA->GetYaxis()->SetTitleOffset(0.55);

    graph_IV_100uA->SetMarkerColor(kBlue);
    graph_IV_100uA->SetLineColor(kBlue);

    graph_IV_50uA->SetMarkerColor(kBlack);
    graph_IV_50uA->SetLineColor(kBlack);

    TF1 *fit_IV_100uA = new TF1("fit_VI_100uA", "[0] + [1]*x", 1.1, 4.1);
    TF1 *fit_IV_50uA = new TF1("fit_VI_50uA", "[0] + [1]*x", 0.7, 4.1);

    fit_IV_100uA->SetParName(0, "\\frac{V_{Early}}{R_{att}}");
    fit_IV_100uA->SetParName(1, "\\frac{1}{R_{att}}");
    fit_IV_50uA->SetParName(0, "\\frac{V_{Early}}{R_{att}}");
    fit_IV_50uA->SetParName(1, "\\frac{1}{R_{att}}");

    fit_IV_100uA->SetLineColor(kGreen);
    fit_IV_50uA->SetLineColor(kRed);

    Double_t V_early_100uA = fit_VI_100uA->GetParameter(0);
    Double_t R_att_100uA = fit_VI_100uA->GetParameter(1);
    Double_t V_early_50uA = fit_VI_50uA->GetParameter(0);
    Double_t R_att_50uA = fit_VI_50uA->GetParameter(1);

    Double_t err_V_early_100uA = fit_VI_100uA->GetParError(0);
    Double_t err_R_att_100uA = fit_VI_100uA->GetParError(1);
    Double_t err_V_early_50uA = fit_VI_50uA->GetParError(0);
    Double_t err_R_att_50uA = fit_VI_50uA->GetParError(1);

    Double_t a_100uA = V_early_100uA / R_att_100uA;
    Double_t b_100uA = 1 / R_att_100uA;
    Double_t a_50uA = V_early_50uA / R_att_50uA;
    Double_t b_50uA = 1 / R_att_50uA;

    Double_t err_a_100uA = std::sqrt((a_100uA * err_V_early_100uA / V_early_100uA) * (a_100uA * err_V_early_100uA / V_early_100uA) +
                                     (a_100uA * err_R_att_100uA / R_att_100uA) * (a_100uA * err_R_att_100uA / R_att_100uA) -
                                     2 * (a_100uA * a_100uA / (V_early_100uA * R_att_100uA) * covariance_100uA));
    Double_t err_b_100uA = b_100uA * err_R_att_100uA / R_att_100uA;
    Double_t err_a_50uA = std::sqrt((a_50uA * err_V_early_50uA / V_early_50uA) * (a_50uA * err_V_early_50uA / V_early_50uA) +
                                    (a_50uA * err_R_att_50uA / R_att_50uA) * (a_50uA * err_R_att_50uA / R_att_50uA) -
                                    2 * (a_50uA * a_50uA / (V_early_50uA * R_att_50uA) * covariance_50uA));
    Double_t err_b_50uA = b_50uA * err_R_att_50uA / R_att_50uA;

    fit_IV_100uA->SetParameter(0, a_100uA);
    fit_IV_100uA->SetParameter(1, b_100uA);
    fit_IV_50uA->SetParameter(0, a_50uA);
    fit_IV_50uA->SetParameter(1, b_50uA);

    fit_IV_100uA->SetParError(0, err_a_100uA);
    fit_IV_100uA->SetParError(1, err_b_100uA);
    fit_IV_50uA->SetParError(0, err_a_50uA);
    fit_IV_50uA->SetParError(1, err_b_50uA);

    graph_IV_100uA->Draw("APE");
    graph_IV_50uA->Draw("PE, SAME");
    fit_IV_100uA->Draw("SAME");
    fit_IV_50uA->Draw("SAME");

    TLegend *legend_IV{new TLegend(0.1, 0.9, 0.9, 0.785)};
    legend_IV->SetNColumns(4);
    legend_IV->AddEntry(graph_IV_100uA, "Punti \\; IV \\; (I_{B}=-0.10\\,mA)", "ep");
    legend_IV->AddEntry(fit_IV_100uA, "Fit \\; IV \\; attiva \\; (I_{B}=-0.10\\,mA)", "l");
    legend_IV->AddEntry((TObject *)0, (std::string(fit_IV_100uA->GetParName(0)) + " = (" + std::to_string(fit_IV_100uA->GetParameter(0)) + " \\pm " + std::to_string(fit_IV_100uA->GetParError(0)) + ") mA").c_str(), "");
    legend_IV->AddEntry((TObject *)0, (std::string(fit_IV_100uA->GetParName(1)) + " = (" + std::to_string(fit_IV_100uA->GetParameter(1)) + " \\pm " + std::to_string(fit_IV_100uA->GetParError(1)) + ") (k \\Omega)^{-1}").c_str(), "");

    legend_IV->AddEntry(graph_IV_50uA, "Punti \\; IV \\; (I_{B}=-0.05\\,mA)", "ep");
    legend_IV->AddEntry(fit_IV_50uA, "Fit \\; IV \\; attiva \\; (I_{B}=-0.05\\,mA)", "l");
    legend_IV->AddEntry((TObject *)0, (std::string(fit_IV_50uA->GetParName(0)) + " = (" + std::to_string(fit_IV_50uA->GetParameter(0)) + " \\pm " + std::to_string(fit_IV_50uA->GetParError(0)) + ") mA").c_str(), "");
    legend_IV->AddEntry((TObject *)0, (std::string(fit_IV_50uA->GetParName(1)) + " = (" + std::to_string(fit_IV_50uA->GetParameter(1)) + " \\pm " + std::to_string(fit_IV_50uA->GetParError(1)) + ") (k \\Omega)^{-1}").c_str(), "");

    legend_IV->Draw();


//     //per fare il titolo grande
//     TPaveText *pt = new TPaveText(0.2580645, 0.9244444, 0.7419355, 0.9925926, "blNDC");
//     pt->SetName("title");
//     pt->SetBorderSize(0);
//     pt->SetFillColor(0);
//     pt->SetFillStyle(0);
//     pt->SetTextFont(42);
//     TText *pt_LaTex = pt->AddText("Caratteristica Transistor BJT");
//     pt->Draw();
//    canva_IV->Modified();
//    canva_IV->SetSelected(canva_IV);
}