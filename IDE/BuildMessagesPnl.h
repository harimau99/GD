/** \file
 *  Game Develop
 *  2008-2013 Florian Rival (Florian.Rival@gmail.com)
 */

#ifndef BUILDMESSAGESPNL_H
#define BUILDMESSAGESPNL_H

//(*Headers(BuildMessagesPnl)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
//*)
namespace gd { class Project; }
class ProjectManager;
#include <vector>
#include "GDL/IDE/CompilerMessagesParser.h"

class BuildMessagesPnl: public wxPanel
{
	public:

		BuildMessagesPnl(wxWindow* parent, ProjectManager * projectManager);
		virtual ~BuildMessagesPnl();

		void OpenFileContainingFirstError();

        ProjectManager * projectManager; ///< Used to open files.
		gd::Project * gameAssociatedWithErrors; ///< Game for which errors have been emitted.

		//(*Declarations(BuildMessagesPnl)
		wxListCtrl* messagesList;
		//*)

	protected:

		//(*Identifiers(BuildMessagesPnl)
		static const long ID_LISTCTRL1;
		//*)

	private:

		//(*Handlers(BuildMessagesPnl)
		void OnmessagesListItemActivated(wxListEvent& event);
		void OnResize(wxSizeEvent& event);
		//*)

        /**
         * Clear and add messages.
         * \param game Game from which the messages have been emitted
         * \param messages Messages to be displayed
         */
		void RefreshWith(gd::Project * game, std::vector < GDpriv::CompilerMessage > messages);

		/**
		 * Called thanks to an event of type CodeCompiler::refreshEventType sent ( typically ) by CodeCompiler.
		 */
		void OnMustRefresh(wxCommandEvent&);

		DECLARE_EVENT_TABLE()
};

#endif

