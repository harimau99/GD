#include <wx/log.h>

#include "DndTextObjectsEditor.h"
#include "EditorObjectList.h"

/**
 * Handle text dropped to the editor : Do nothing for now
 */
bool DndTextObjectsEditor::OnDropText(wxCoord x, wxCoord y, const wxString& text)
{
    return true;
}

