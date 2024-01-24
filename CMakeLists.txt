cmake_minimum_required (VERSION 3.20)

# Searching for VCPKG-installation and download if needed
include(FetchContent)
FetchContent_Populate(
  vcpkg
  GIT_REPOSITORY https://github.com/microsoft/vcpkg.git
  GIT_TAG        2023.11.20
  SOURCE_DIR     "${CMAKE_SOURCE_DIR}/vcpkg"
)

# saves vcpkg build artifacts in vcpkg directory
list(APPEND CMAKE_PROJECT_TOP_LEVEL_INCLUDES "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake")
list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES CMAKE_PROJECT_TOP_LEVEL_INCLUDES)

set(CMAKE_TOOLCHAIN_FILE "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake")

project ("ImGuiExample")

add_subdirectory(ImGuiInstance)

add_executable(imgui_example src/main.cpp)

target_link_libraries(imgui_example PUBLIC imgui_instance::imgui_instance)

target_compile_features(imgui_example PUBLIC cxx_std_20)
