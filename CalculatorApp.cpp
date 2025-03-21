#include "CalculatorApp.h"

wxBEGIN_EVENT_TABLE(CalculatorWindow, wxFrame)

EVT_BUTTON(BUTTON_BASE_ID + 0, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 1, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 2, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 3, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 4, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 5, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 6, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 7, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 8, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 9, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 10, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 11, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 12, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 13, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 14, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 15, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 16, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 17, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 18, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 19, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 20, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 21, CalculatorWindow::OnButtonClicked)
EVT_BUTTON(BUTTON_BASE_ID + 22, CalculatorWindow::OnButtonClicked)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(CalculatorApp);
bool CalculatorApp::OnInit() {
    CalculatorWindow* calc_window = new CalculatorWindow("Calculator");
    calc_window->Show(true);
    return true;
}

CalculatorWindow::CalculatorWindow(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
  
    calc_Panel = new wxPanel(this);

   
    calc_TextCtrl = new wxTextCtrl(calc_Panel, wxID_ANY, "", wxDefaultPosition, wxSize(250, 50), wxTE_RIGHT | wxTE_MULTILINE);


    calc_ButtonGrid = new wxGridSizer(5, 5, 5, 5);
    
    for (int i = 0; i < 9; i++) {
        calc_ButtonGrid->Add(ButtonFactory::CreateNumbersButton(calc_Panel, BUTTON_BASE_ID + i, wxString::Format("%d", i)), 0, wxEXPAND | wxALL, 5);
    }
   
    calc_ButtonGrid->Add(ButtonFactory::CreateAddButton(calc_Panel, BUTTON_BASE_ID + 10), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateSubtractButton(calc_Panel, BUTTON_BASE_ID + 11), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateMultiplyButton(calc_Panel, BUTTON_BASE_ID + 12), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateDivideButton(calc_Panel, BUTTON_BASE_ID + 13), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateDecimalButton(calc_Panel, BUTTON_BASE_ID + 14), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateModuloButton(calc_Panel, BUTTON_BASE_ID + 15), 0, wxEXPAND | wxALL, 5);

    calc_ButtonGrid->Add(ButtonFactory::CreateSinButton(calc_Panel, BUTTON_BASE_ID + 16), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateCosButton(calc_Panel, BUTTON_BASE_ID + 17), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateTanButton(calc_Panel, BUTTON_BASE_ID + 18), 0, wxEXPAND | wxALL, 5);

    calc_ButtonGrid->Add(ButtonFactory::CreateClearButton(calc_Panel, BUTTON_BASE_ID + 19), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateDeleteButton(calc_Panel, BUTTON_BASE_ID + 20), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateSignageButton(calc_Panel, BUTTON_BASE_ID + 21), 0, wxEXPAND | wxALL, 5);
    calc_ButtonGrid->Add(ButtonFactory::CreateEqualsButton(calc_Panel, BUTTON_BASE_ID + 22), 0, wxEXPAND | wxALL, 5);

    /*
wxString buttonLabels[] = {
     "7", "8", "9", "/", "Clear",
     "4", "5", "6", "*", "Delete",
     "1", "2", "3", "-", "+/-",
     "0", ".", "=", "+", "sin",
     "cos", "tan", "%"
 };

  for (int i = 0; i < 25; ++i) {
     wxButton* button = new wxButton(calc_Panel, BUTTON_BASE_ID + i, buttonLabels[i]);
     calc_ButtonGrid->Add(button, 0, wxEXPAND | wxALL, 5);
 }
*/


    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(calc_TextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(calc_ButtonGrid, 1, wxEXPAND, 5);

    calc_Panel->SetSizerAndFit(sizer);

   
    SetSize(300, 400);
}


CalculatorWindow::~CalculatorWindow() {}


void CalculatorWindow::OnButtonClicked(wxCommandEvent & event) {
    int id = event.GetId();
    wxString value = calc_TextCtrl->GetValue();
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    wxString label = button->GetLabel();

    wxLogDebug("Button clicked: ID = %d, Label = %s", id, label); 

    try {
        if (label == "Clear") {
            calc_TextCtrl->Clear();
        }
        else if (label == "Delete") {
            if (!value.IsEmpty()) {
                value.RemoveLast();
                calc_TextCtrl->SetValue(value);
            }
        }
        else if (label == "=") {
            if (value.IsEmpty()) {
                wxMessageBox("Textbox is empty.");
                return;
            }
            std::vector<wxString> tokens = Tokenize(value);
            double result = EvaluateExpression(tokens);
            calc_TextCtrl->SetValue(wxString::Format("%.2f", result));
        }
        else if (label == "sin" || label == "cos" || label == "tan") {
            calc_TextCtrl->AppendText(label + "(");
        }
        else if (label == "+/-") {
            if (!value.IsEmpty()) {
                if (value.StartsWith("-")) {
                    value = value.Mid(1);
                }
                else {
                    value = "-" + value;
                }
                calc_TextCtrl->SetValue(value);
            }
        }
        else {
            calc_TextCtrl->AppendText(label);
        }
    }
    catch (const std::exception& error) {
        wxMessageBox("Error: " + wxString(error.what()));
    }
}


std::vector<wxString> CalculatorWindow::Tokenize(const wxString& input) {
    std::vector<wxString> tokens;
    wxString number;
    wxString _operators = "+-*/";

    for (size_t i = 0; i < input.Length(); ++i) {
        wxChar ch = input[i];

        if (wxIsspace(ch)) continue; // skip spaces

        if (_operators.Find(ch) != wxNOT_FOUND) {
            if (!number.IsEmpty()) {
                tokens.push_back(number);
                number.clear();
            }
            tokens.push_back(wxString(ch));
        }
        else {
            number += ch;
        }
    }

    if (!number.IsEmpty()) {
        tokens.push_back(number);
    }

    return tokens;
}


double CalculatorWindow::EvaluateExpression(const std::vector<wxString>& tokens) {
    if (tokens.size() != 3) {
        throw std::runtime_error("Invalid expression. Expected format: <num> <op> <num>");
    }

    double lhs = wxAtof(tokens[0]);
    wxString _operator = tokens[1];
    double rhs = wxAtof(tokens[2]);

    if (_operator == "+") return lhs + rhs;
    if (_operator == "-") return lhs - rhs;
    if (_operator == "*") return lhs * rhs;
    if (_operator == "/") {
        if (rhs == 0) throw std::runtime_error("Division by zero");
        return lhs / rhs;
    }

    throw std::runtime_error("Unknown operator");
}