#include "Includinglibaries.hpp"

#include "../ImGuiInstance/src/ImGuiInstance/ImGuiInstance.hpp"


// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

void CreateToolbar(){

        ImVec4 color = ImVec4(0.8f, 1.0f, 1.0f, 0.5f);

        ImGui::SetCursorPos(ImVec2(0,0)); 

        ImGui::BeginChild("Toolbar", ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.05f), true); 

        int my_image_width = 0;
        int my_image_height = 0;
        GLuint my_image_texture = 0;
        bool ret = LoadTextureFromFile("../images/AutoInternLogo.png", &my_image_texture, &my_image_width, &my_image_height);
        IM_ASSERT(ret);


        //ImGui::Text("pointer = %p", my_image_texture);
        //ImGui::Text("size = %d x %d", my_image_width, my_image_height);
        ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width*0.15, my_image_height*0.15));


               
        ImGui::EndChild(); 
}


