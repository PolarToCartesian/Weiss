# Setup
CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

include(GNUInstallDirs)

# Create Main Project
PROJECT(Weiss VERSION 0.0.1)

# Set Standard Version
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

# Create The Weiss Engine Library
ADD_LIBRARY(WeissEngine STATIC "${PROJECT_SOURCE_DIR}/Weiss.h" "${PROJECT_SOURCE_DIR}/Weiss.cpp")

# Set Target Propreties
SET_TARGET_PROPERTIES(WeissEngine PROPERTIES LINKER_LANGUAGE CXX)
SET_TARGET_PROPERTIES(WeissEngine PROPERTIES VERSION ${PROJECT_VERSION})
SET_TARGET_PROPERTIES(WeissEngine PROPERTIES PUBLIC_HEADER Include.h)

# Include Dependencies
FIND_PACKAGE(Vulkan REQUIRED FATAL_ERROR)
LINK_LIBRARIES(WeissEngine "${Vulkan_LIBRARIES}")

TARGET_INCLUDE_DIRECTORIES(WeissEngine PUBLIC
                          "${PROJECT_BINARY_DIR}/d3dx12/"
                          "${Vulkan_INCLUDE_DIRS}")

# Create A Sandbox Project That Includes WeissEngine
ADD_EXECUTABLE(Sandbox "${PROJECT_SOURCE_DIR}/samples/hello\ triangle/Source.cpp"
                       "${PROJECT_SOURCE_DIR}/samples/hello\ triangle/vert.src.ws"
                       "${PROJECT_SOURCE_DIR}/samples/hello\ triangle/frag.src.ws")

# Set Target Propreties
SET_TARGET_PROPERTIES(Sandbox PROPERTIES LINKER_LANGUAGE CXX)
SET_TARGET_PROPERTIES(Sandbox PROPERTIES VERSION ${PROJECT_VERSION})

# Include Dependencies
LINK_LIBRARIES(Sandbox "${Vulkan_LIBRARIES}")

TARGET_INCLUDE_DIRECTORIES(Sandbox PUBLIC
                          "${PROJECT_BINARY_DIR}/d3dx12/"
                          "${Vulkan_INCLUDE_DIRS}"
                          "${PROJECT_BINARY_DIR}/")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)