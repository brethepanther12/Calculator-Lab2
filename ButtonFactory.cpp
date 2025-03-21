#include "ButtonFactory.h"
wxButton* CreateButton(wxWindow* parent, int id, const wxString& label) {return new wxButton(parent, id, label);};


wxButton* CreateNumbersButton(wxWindow* parent, int id, const wxString& label) { return CreateButton(parent, id, label);};
wxButton* CreateAddButton(wxWindow* parent, int id) {return CreateButton(parent, id, "+");};
wxButton* CreateSubtractButton(wxWindow* parent, int id) {return CreateButton(parent, id, "-");};
wxButton* CreateMultiplyButton(wxWindow* parent, int id) { return CreateButton(parent, id, "*"); };
wxButton* CreateDivideButton(wxWindow* parent, int id) { return CreateButton(parent, id, "/"); };
wxButton* CreateModuloButton(wxWindow* parent, int id) { return CreateButton(parent, id, "%"); };

wxButton* CreateClearButton(wxWindow* parent, int id) { return CreateButton(parent, id, "Clear"); };
wxButton* CreateDeleteButton(wxWindow* parent, int id) { return CreateButton(parent, id, "Delete"); };
wxButton* CreateEqualsButton(wxWindow* parent, int id) { return CreateButton(parent, id, "="); };
wxButton* CreateSignageButton(wxWindow* parent, int id) { return CreateButton(parent, id, "+/-"); };

wxButton* CreateSinButton(wxWindow* parent, int id) { return CreateButton(parent, id, "sin"); };
wxButton* CreateCosButton(wxWindow* parent, int id) { return CreateButton(parent, id, "cos"); };
wxButton* CreateTanButton(wxWindow* parent, int id) { return CreateButton(parent, id, "tan"); };