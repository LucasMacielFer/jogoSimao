include(FetchContent)

# SFML
FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
)
add_subdirectory(sfml)

# Dear ImGui
FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG master
)

FetchContent_MakeAvailable(imgui)

# ImGui-SFML
FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml
  GIT_TAG 2.6.x
)
add_subdirectory(imgui-sfml)

# nlohmann-json
FetchContent_Declare(
  json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
add_subdirectory(json)

# # nlohmann-json
# FetchContent_Declare(
#   ldtk-loader
#   GIT_REPOSITORY https://github.com/Madour/LDtkLoader.git
#   GIT_TAG master
# )
# add_subdirectory(ldtk-loader)