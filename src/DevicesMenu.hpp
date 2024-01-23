#include "Includinglibaries.hpp"

void SetDevicesMenu(){
    ImGui:: SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.18f, ImGui::GetIO().DisplaySize.y * 0.7f)); 

    ImGui::BeginChild("DevicesMenu", ImVec2(ImGui::GetIO().DisplaySize.x * 0.82f, ImGui::GetIO().DisplaySize.y * 0.3f), true); 

     ImGui::Text("Verbundene Geräte");

    ImGui::EndChild(); 
}