cmake_minimum_required(VERSION 3.15)
project(TECPROG
  LANGUAGES CXX
  VERSION 1.0
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(DCMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/**/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/**/*.hpp")

add_executable(TECPROG ${SOURCES})
target_link_libraries(TECPROG PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(TECPROG PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(TECPROG PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_subdirectory(dependencies)

file(COPY
${CMAKE_CURRENT_SOURCE_DIR}/assets/
DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets/)

# Copy DLLs needed for runtime on Windows
if(WIN32)
  if (BUILD_SHARED_LIBS)
    add_custom_command(TARGET TECPROG POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
          $<TARGET_FILE:sfml-graphics>
          $<TARGET_FILE:sfml-window>
          $<TARGET_FILE:sfml-system>
          $<TARGET_FILE_DIR:TECPROG>)
  endif()
endif()