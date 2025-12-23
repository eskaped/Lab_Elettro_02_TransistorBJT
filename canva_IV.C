#ifdef __CLING__
#pragma cling optimize(0)
#endif
void canva_IV()
{
//=========Macro generated from canvas: canva_IV/Canva_IV
//=========  (Tue Dec 23 12:24:23 2025) by ROOT version 6.32.10

   gStyle->SetCanvasPreferGL(kTRUE);

   TCanvas *canva_IV = new TCanvas("canva_IV", "Canva_IV",0,69,1366,699);
   canva_IV->Range(-0.5708758,-2.741679,5.137882,29.17511);
   canva_IV->SetFillColor(0);
   canva_IV->SetBorderMode(0);
   canva_IV->SetBorderSize(2);
   canva_IV->SetGridx();
   canva_IV->SetGridy();
   canva_IV->SetTopMargin(0.215);
   canva_IV->SetFrameBorderMode(0);
   canva_IV->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1003[32] = { 4, 3.6, 3.2, 2.8, 2.4, 2, 1.8, 1.6, 1.4, 1.2, 1, 0.92, 0.84, 0.76, 0.68, 0.6, 0.56,
   0.52, 0.48, 0.44, 0.4, 0.36, 0.32, 0.3, 0.25, 0.2, 0.15, 0.12, 0.1, 0.08, 0.06, 0.05 };
   Double_t Graph0_fy1003[32] = { 20.1, 19.8, 19.54, 19.17, 19.05, 18.81, 18.58, 18.4, 18.19, 18.06, 17.81, 17.65, 17.53, 17.38, 17.25, 17.14, 17,
   16.86, 16.77, 16.45, 16.19, 15.83, 15.2, 15.13, 14, 11.56, 7, 4.88, 2.94, 1.6, 0.85, 0.54 };
   Double_t Graph0_fex1003[32] = { 0.156205, 0.147187, 0.1386218, 0.09775485, 0.08765849, 0.07810256, 0.07359355, 0.06931097, 0.06529939, 0.04118264, 0.03605565, 0.03408475, 0.03217219, 0.03032903, 0.02856869, 0.0205915, 0.01955121,
   0.01853025, 0.01753197, 0.0165605, 0.01562082, 0.01471904, 0.01386254, 0.01029612, 0.009014433, 0.00781089, 0.006727555, 0.004119466, 0.003606938, 0.0031257, 0.002061553, 0.001805547 };
   Double_t Graph0_fey1003[32] = { 0.23, 0.23, 0.23, 0.22, 0.22, 0.22, 0.22, 0.21, 0.21, 0.21, 0.21, 0.21, 0.21, 0.2, 0.2, 0.2, 0.2,
   0.2, 0.2, 0.19, 0.19, 0.19, 0.18, 0.18, 0.17, 0.15, 0.1, 0.08, 0.06, 0.05, 0.04, 0.04 };
   TGraphErrors *gre = new TGraphErrors(32,Graph0_fx1003,Graph0_fy1003,Graph0_fex1003,Graph0_fey1003);
   gre->SetName("Graph0");
   gre->SetTitle("Caratteristica Transistor BJT");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   
   TH1F *Graph_Graph01003 = new TH1F("Graph_Graph01003","Caratteristica Transistor BJT",100,0,4.567006);
   Graph_Graph01003->SetMinimum(0.45);
   Graph_Graph01003->SetMaximum(22.313);
   Graph_Graph01003->SetDirectory(nullptr);
   Graph_Graph01003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph01003->SetLineColor(ci);
   Graph_Graph01003->GetXaxis()->SetTitle("-V_{CE}");
   Graph_Graph01003->GetXaxis()->SetLabelFont(42);
   Graph_Graph01003->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph01003->GetXaxis()->SetTitleOffset(0.7);
   Graph_Graph01003->GetXaxis()->SetTitleFont(42);
   Graph_Graph01003->GetYaxis()->SetTitle("-I_{C}");
   Graph_Graph01003->GetYaxis()->SetLabelFont(42);
   Graph_Graph01003->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph01003->GetYaxis()->SetTitleOffset(0.6);
   Graph_Graph01003->GetYaxis()->SetTitleFont(42);
   Graph_Graph01003->GetZaxis()->SetLabelFont(42);
   Graph_Graph01003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01003);
   
   gre->Draw("ape");
   
   Double_t Graph1_fx1004[32] = { 4, 3.6, 3.2, 2.8, 2.4, 2, 1.8, 1.6, 1.4, 1.2, 1, 0.92, 0.84, 0.76, 0.68, 0.6, 0.56,
   0.52, 0.48, 0.44, 0.4, 0.36, 0.32, 0.3, 0.25, 0.2, 0.15, 0.12, 0.1, 0.08, 0.06, 0.05 };
   Double_t Graph1_fy1004[32] = { 9.78, 9.7, 9.58, 9.48, 9.31, 9.15, 9.05, 8.98, 8.91, 8.86, 8.77, 8.72, 8.68, 8.62, 8.58, 8.55, 8.51,
   8.49, 8.46, 8.42, 8.38, 8.33, 8.24, 8.22, 7.86, 6.66, 3.95, 2.62, 1.52, 0.8, 0.41, 0.25 };
   Double_t Graph1_fex1004[32] = { 0.156205, 0.147187, 0.1386218, 0.09775485, 0.08765849, 0.07810256, 0.07359355, 0.06931097, 0.06529939, 0.04118264, 0.03605565, 0.03408475, 0.03217219, 0.03032903, 0.02856869, 0.0205915, 0.01955121,
   0.01853025, 0.01753197, 0.0165605, 0.01562082, 0.01471904, 0.01386254, 0.01029612, 0.009014433, 0.00781089, 0.006727555, 0.004119466, 0.003606938, 0.0031257, 0.002061553, 0.001805547 };
   Double_t Graph1_fey1004[32] = { 0.13, 0.13, 0.13, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12,
   0.11, 0.11, 0.11, 0.11, 0.11, 0.11, 0.11, 0.11, 0.1, 0.07, 0.06, 0.05, 0.04, 0.03, 0.03 };
   gre = new TGraphErrors(32,Graph1_fx1004,Graph1_fy1004,Graph1_fex1004,Graph1_fey1004);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   
   TH1F *Graph_Graph11004 = new TH1F("Graph_Graph11004","Graph",100,0,4.567006);
   Graph_Graph11004->SetMinimum(0.198);
   Graph_Graph11004->SetMaximum(10.879);
   Graph_Graph11004->SetDirectory(nullptr);
   Graph_Graph11004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph11004->SetLineColor(ci);
   Graph_Graph11004->GetXaxis()->SetLabelFont(42);
   Graph_Graph11004->GetXaxis()->SetTitleOffset(1);
   Graph_Graph11004->GetXaxis()->SetTitleFont(42);
   Graph_Graph11004->GetYaxis()->SetLabelFont(42);
   Graph_Graph11004->GetYaxis()->SetTitleFont(42);
   Graph_Graph11004->GetZaxis()->SetLabelFont(42);
   Graph_Graph11004->GetZaxis()->SetTitleOffset(1);
   Graph_Graph11004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph11004);
   
   gre->Draw("pe, ");
   
   TF1 *fit_VI_100uA3 = new TF1("fit_VI_100uA","[0] + [1]*x",1.1,4.1, TF1::EAddToList::kDefault);
   fit_VI_100uA3->SetFillColor(19);
   fit_VI_100uA3->SetFillStyle(0);

   ci = TColor::GetColor("#00ff00");
   fit_VI_100uA3->SetLineColor(ci);
   fit_VI_100uA3->SetLineWidth(2);
   fit_VI_100uA3->GetXaxis()->SetLabelFont(42);
   fit_VI_100uA3->GetXaxis()->SetTitleOffset(1);
   fit_VI_100uA3->GetXaxis()->SetTitleFont(42);
   fit_VI_100uA3->GetYaxis()->SetLabelFont(42);
   fit_VI_100uA3->GetYaxis()->SetTitleFont(42);
   fit_VI_100uA3->SetParameter(0,17.25589);
   fit_VI_100uA3->SetParError(0,0.200097);
   fit_VI_100uA3->SetParLimits(0,0,0);
   fit_VI_100uA3->SetParameter(1,0.7139892);
   fit_VI_100uA3->SetParError(1,0.08159583);
   fit_VI_100uA3->SetParLimits(1,0,0);
   fit_VI_100uA3->Draw("SAME");
   
   TF1 *fit_VI_50uA4 = new TF1("fit_VI_50uA","[0] + [1]*x",0.7,4.1, TF1::EAddToList::kDefault);
   fit_VI_50uA4->SetFillColor(19);
   fit_VI_50uA4->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   fit_VI_50uA4->SetLineColor(ci);
   fit_VI_50uA4->SetLineWidth(2);
   fit_VI_50uA4->GetXaxis()->SetLabelFont(42);
   fit_VI_50uA4->GetXaxis()->SetTitleOffset(1);
   fit_VI_50uA4->GetXaxis()->SetTitleFont(42);
   fit_VI_50uA4->GetYaxis()->SetLabelFont(42);
   fit_VI_50uA4->GetYaxis()->SetTitleFont(42);
   fit_VI_50uA4->SetParameter(0,8.37866);
   fit_VI_50uA4->SetParError(0,0.06576209);
   fit_VI_50uA4->SetParLimits(0,0,0);
   fit_VI_50uA4->SetParameter(1,0.3726946);
   fit_VI_50uA4->SetParError(1,0.03238708);
   fit_VI_50uA4->SetParLimits(1,0,0);
   fit_VI_50uA4->Draw("SAME");
   
   TLegend *leg = new TLegend(0.1,0.785,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","Punti \\; IV \\; (I_{B}=-0.10\\,mA)","ep");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("fit_VI_100uA","Fit \\; IV \\; attiva \\; (I_{B}=-0.10\\,mA)","l");

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","\\frac{V_{Early}}{R_{att}} = (17.255892 \\pm 0.200097) mA","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","\\frac{1}{R_{att}} = (0.713989 \\pm 0.081596) (k \\Omega)^{-1}","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Punti \\; IV \\; (I_{B}=-0.05\\,mA)","ep");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("fit_VI_50uA","Fit \\; IV \\; attiva \\; (I_{B}=-0.05\\,mA)","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","\\frac{V_{Early}}{R_{att}} = (8.378660 \\pm 0.065762) mA","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","\\frac{1}{R_{att}} = (0.372695 \\pm 0.032387) (k \\Omega)^{-1}","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2580645,0.9244444,0.7419355,0.9925926,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Caratteristica Transistor BJT");
   pt->Draw();
   canva_IV->Modified();
   canva_IV->SetSelected(canva_IV);
}
