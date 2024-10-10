#include "MyForm.h"
#include "Kasier.h"
#include "TicketList.h"
#include "StartSales.h"
#include "Financial.h"
#include "Account.h"
#include "Tournament.h"
#include "Match.h"
#include "DataBaseHandler.h"
#include <sqlite3.h>
#include <msclr\marshal_cppstd.h> 
#include "CreateTournament.h"
#include "CreateTournament2.h"
#include "Organization.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array <String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	KursovaInterface::MyForm form;
	Application::Run(% form);


}