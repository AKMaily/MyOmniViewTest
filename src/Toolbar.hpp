#include "Includinglibaries.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image/stb_image.h" // externe Libary aus Git 

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb_image/stb_image_write.h"


void CreateToolbar(){

        ImVec4 color = ImVec4(0.8f, 1.0f, 1.0f, 0.5f);

        ImGui::SetCursorPos(ImVec2(0,0)); 

        ImGui::BeginChild("Toolbar", ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.05f), true); 

                

                ImGui::Text("Hier kommen noch Bilder hin"); 

               
        ImGui::EndChild(); 
}