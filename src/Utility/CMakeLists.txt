# interface library for headers only module
add_library(Utility INTERFACE)
add_library(tg::Utility ALIAS Utility)
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

set(SRC_FILES
    Global.hpp
    Meta.hpp
    Scope.hpp)

install(FILES
    ${SRC_FILES}
    DESTINATION ${UTILITY_INSTALL_DESTINATION_INCLUDE}/Utility)

#
# add custom target simply for IDE to show the files
#
add_custom_target(Utility.include SOURCES
    ${SRC_FILES})
