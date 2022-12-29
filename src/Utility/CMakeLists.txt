# interface library for headers only module
add_library(Utility INTERFACE)

# modules linking to this library will include following
# directories. two options are provided for installed package
# and for in-tree source build
target_include_directories(Utility INTERFACE
    $<INSTALL_INTERFACE:include/Utility>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>)

# what to do on make install
install(TARGETS Utility
        EXPORT Utility.package
        DESTINATION ${UTILITY_INSTALL_DESTINATION_LIBRARY})

export(TARGETS Utility NAMESPACE tg:: FILE ${PROJECT_BINARY_DIR}/Utility.package.cmake)

set(SRC_FILES
    Scope.hpp
    Global.hpp)

install(FILES
    ${SRC_FILES}
    DESTINATION ${UTILITY_INSTALL_DESTINATION_INCLUDE}/Utility)

#
# add custom target simply for IDE to show the files
#
add_custom_target(Utility.include SOURCES
    ${SRC_FILES})
