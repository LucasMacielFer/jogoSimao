# Install script for directory: /home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-sfml-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML_d.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML_d.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML_d.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-sfml-build/libImGui-SFML_d.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML_d.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML_d.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML_d.so"
         OLD_RPATH "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/sfml-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML_d.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-sfml-src/imgui-SFML.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-sfml-src/imgui-SFML_export.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-src/imconfig.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-src/imgui.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-src/imgui_internal.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-src/imstb_rectpack.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-src/imstb_textedit.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-src/imstb_truetype.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-src/misc/cpp/imgui_stdlib.h"
    "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-sfml-src/imconfig-SFML.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake"
         "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-sfml-build/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML" TYPE FILE FILES "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-sfml-build/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML" TYPE FILE FILES "/home/lucas/Documents/jogoSimao/CaveEscape++/build/_deps/imgui-sfml-build/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig-debug.cmake")
  endif()
endif()

