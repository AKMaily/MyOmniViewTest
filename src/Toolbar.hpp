#include "Includinglibaries.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image/stb_image.h" // externe Libary aus Git 

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb_image/stb_image_write.h"


void CreateToolbar(){

        // laden des Bildes 
        // Laden Sie ein Bild aus einem Ordner in Ihrem Projekt
                const char* imagePath = "../images/download.jpg";
                int width, height, channels;
                unsigned char* imageData = stbi_load(imagePath, &width, &height, &channels, 0);

                if(imageData == NULL) {
                printf("Error in loading the image\n");
                exit(1);
                }


        ImVec4 color = ImVec4(0.8f, 1.0f, 1.0f, 0.5f);

        ImGui::SetCursorPos(ImVec2(0,0)); 

        ImGui::BeginChild("Toolbar", ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.05f), true);

                ImGui::Text("Hier kommen noch Bilder hin"); 

                 if(false){

                         // Hier fügen Sie ein Bild ein
                        ImTextureID textureID = ImGui::GetIO().Fonts->TexID; // Benutzen Sie die TexID des ImGui-Fensters als Dummy
                        ImVec2 imageSize = ImVec2(static_cast<float>(width), static_cast<float>(height));

                        ImGui::Image(textureID, imageSize); // Dummy Image
                }

               

        ImGui::EndChild(); 
}