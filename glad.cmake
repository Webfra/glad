#======================================================================
# CMake configuration file for glad library.
#======================================================================
cmake_minimum_required(VERSION 3.17)
#-----------------------------------------------------------------
if( NOT TARGET glad )
    #-----------------------------------------------------------------
    add_library ( glad STATIC )
    enable_language( C CXX )
    #-----------------------------------------------------------------
    target_include_directories( glad PUBLIC  "${CMAKE_CURRENT_LIST_DIR}/include" )
    target_include_directories( glad PUBLIC  "${CMAKE_CURRENT_LIST_DIR}/src_cpp" )
    #-----------------------------------------------------------------
    # Required for Linux?
    target_link_libraries( glad PRIVATE "${CMAKE_DL_LIBS}" )
    #-----------------------------------------------------------------
    target_sources ( glad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/glad.c" )
    target_sources ( glad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/glad/glad.h" )
    target_sources ( glad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/KHR/khrplatform.h" )
    #-----------------------------------------------------------------
    target_sources ( glad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src_cpp/glad.cpp" )
    target_sources ( glad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src_cpp/glad.hpp" )
    #-----------------------------------------------------------------
    #set_source_files_properties( "${CMAKE_CURRENT_LIST_DIR}/src/glad.c" PROPERTIES COMPILE_FLAGS -Wno-pedantic )
    #-----------------------------------------------------------------
endif()
#======================================================================
# End of file.
#======================================================================
