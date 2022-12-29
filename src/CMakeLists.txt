if( WIN32 )
    SET(UTILITY_INSTALL_DESTINATION_RUNTIME bin)
    SET(UTILITY_INSTALL_DESTINATION_LIBRARY lib)
    SET(UTILITY_INSTALL_DESTINATION_ARCHIVE lib)
    SET(UTILITY_INSTALL_DESTINATION_INCLUDE include)
else( WIN32 )
    SET(UTILITY_INSTALL_DESTINATION_RUNTIME bin/Utility)
    SET(UTILITY_INSTALL_DESTINATION_LIBRARY lib/Utility)
    SET(UTILITY_INSTALL_DESTINATION_ARCHIVE lib/Utility)
    SET(UTILITY_INSTALL_DESTINATION_INCLUDE include/Utility)
endif( WIN32 )

if( NOT WIN32 )
    # don't skip the full RPATH for the build tree
    SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

    # when building, don't use the install RPATH already
    # (but later on when installing)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

    SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/Utility")

    # not sure if there is any use from below command
    # add the automatically determined parts of the RPATH
    # which point to directories outside the build tree to the install RPATH
    #SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

add_subdirectory(Utility)

# following is used for find_package functionality
install(FILES utility-config.cmake DESTINATION ${UTILITY_INSTALL_DESTINATION_LIBRARY})
install(EXPORT Utility.package NAMESPACE tg:: DESTINATION ${UTILITY_INSTALL_DESTINATION_LIBRARY})


