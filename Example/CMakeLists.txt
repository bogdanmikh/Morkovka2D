project("Example")

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE INCLUDE src/*.hpp)

add_executable(Example "${SOURCES}" "${INCLUDE}")
target_include_directories(Example PRIVATE src)

# MorkovkaCore
target_link_libraries(Example MorkovkaCore)
target_include_directories(Example PRIVATE ${MCORE_DIRECTORY}/include)

# Morkovka2D
target_link_libraries(Example Morkovka2D)
target_include_directories(Example PRIVATE ${M2D_DIRECTORY}/include)

# imgui
target_link_libraries(Example imgui)
target_include_directories(Example PRIVATE ${VENDOR_DIRECTORY}/imgui)

# set output directories for all builds (Debug, Release, etc.)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set_target_properties(Example
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BIN_DIRECTORY}
    )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

set_target_properties(Example
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIRECTORY}
)

file(GLOB RESOURCE_FOLDERS
        resources/*
        )
    
        foreach (RESOURCE_FOLDER IN ITEMS ${RESOURCE_FOLDERS})
        # Copy assets to target folder
        file(COPY ${RESOURCE_FOLDER} DESTINATION "${BIN_DIRECTORY}/")
    endforeach ()