#include "ButtonFactory.h"
wxButton* ButtonFactory::CreateButton(wxWindow* parent, int id, const wxString& label) {return new wxButton(parent, id, label,wxDefaultPosition, wxSize(50,50));};


wxButton* ButtonFactory::CreateNumbersButton(wxWindow* parent, int id, const wxString& label) { return CreateButton(parent, id, label);};
wxButton* ButtonFactory::CreateAddButton(wxWindow* parent, int id) {return CreateButton(parent, id, "+");};
wxButton* ButtonFactory::CreateSubtractButton(wxWindow* parent, int id) {return CreateButton(parent, id, "-");};
wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent, int id) { return CreateButton(parent, id, "*"); };
wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent, int id) { return CreateButton(parent, id, "/"); };
wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent, int id) { return CreateButton(parent, id, "%"); };

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent, int id) { return CreateButton(parent, id, "Clear"); };
wxButton* ButtonFactory::CreateDeleteButton(wxWindow* parent, int id) { return CreateButton(parent, id, "Delete"); };
wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent, int id) { return CreateButton(parent, id, "="); };
wxButton* ButtonFactory::CreateSignageButton(wxWindow* parent, int id) { return CreateButton(parent, id, "+/-"); };
wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent, int id) { return CreateButton(parent, id, "."); };
wxButton* ButtonFactory::CreateSinButton(wxWindow* parent, int id) { return CreateButton(parent, id, "sin"); };
wxButton* ButtonFactory::CreateCosButton(wxWindow* parent, int id) { return CreateButton(parent, id, "cos"); };
wxButton* ButtonFactory::CreateTanButton(wxWindow* parent, int id) { return CreateButton(parent, id, "tan"); };

