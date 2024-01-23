#include "Includinglibaries.hpp"

void ShowSearchDevices() {
    ImGui::Text("Bereich für die Suche nach Geräten");
}

void ShowSettingsMenu() {

    static bool showSubmenu1 = false;

    // Erster Menüpunkt als Button
    if (ImGui::Button("Einstellungen")) {
        // Aktion bei Klick auf Menüpunkt 1
        showSubmenu1 = !showSubmenu1;
    }

      // Zeigen Sie Untermenü 1 an, wenn showSubmenu1 wahr ist
    if (showSubmenu1) {
        if (ImGui::TreeNode("Sprache")) {
            ImGui::Button("Deutsch");
            ImGui::Button("Englisch");
            ImGui::TreePop(); // Schließt den TreeNode
        }
        if (ImGui::TreeNode("Layout")) {
            ImGui::TreePop(); // Schließt den TreeNode
        }
    }
}


void ShowDiagnosticsMenu() {

    static bool showSubmenu3 = false;

    // Erster Menüpunkt als Button
    if (ImGui::Button("Diagnose")) {
        // Aktion bei Klick auf Menüpunkt 1
        showSubmenu3 = !showSubmenu3;
    }

      // Zeigen Sie Untermenü 1 an, wenn showSubmenu1 wahr ist
    if (showSubmenu3) {
        if (ImGui::TreeNode("Batteriemessung")) {
            ImGui::Button("Analysiere Daten");
            ImGui::Button("Generiere Trainingsdaten");
            ImGui::TreePop(); // Schließt den TreeNode
        }
        if (ImGui::TreeNode("Kompressionsmessung")) {
            ImGui::Button("Analysiere Daten");
            ImGui::Button("Generiere Trainingsdaten");     
            ImGui::TreePop(); // Schließt den TreeNode
        }
    }
}

void ShowHelpMenu() {

    static bool showSubmenu5 = false;

    // Erster Menüpunkt als Button
    if (ImGui::Button("HelpMenu")) {
        // Aktion bei Klick auf Menüpunkt 1
        showSubmenu5 = !showSubmenu5;
    }

      // Zeigen Sie Untermenü 1 an, wenn showSubmenu1 wahr ist
    if (showSubmenu5) {
        ImGui::MenuItem("www.omnihelp.de");
        ImGui::MenuItem("www.omnihelp/FAQ.de");
    }
}


void SetSideBarMenu(){
    ImGui:: SetCursorPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.05f)); 

    ImGui::BeginChild("SideBarMenu", ImVec2(ImGui::GetIO().DisplaySize.x * 0.18f, ImGui::GetIO().DisplaySize.y * 0.95f), true); 

    if (ImGui::Button("Suche Geräte")) {
        ShowSearchDevices();
    }

    ShowSettingsMenu();

    ShowDiagnosticsMenu();

    ShowHelpMenu();

    ImGui::EndChild(); 
}