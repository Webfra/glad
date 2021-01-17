#======================================================================
# CMake configuration file for glad library.
#======================================================================
cmake_minimum_required(VERSION 3.17)
#-----------------------------------------------------------------
project( glad LANGUAGES C )
#-----------------------------------------------------------------
add_library ( glad STATIC )
#-----------------------------------------------------------------
target_include_directories( glad PUBLIC  "${CMAKE_CURRENT_LIST_DIR}/include" )
#-----------------------------------------------------------------
# Required for Linux?
target_link_libraries(      glad PRIVATE "${CMAKE_DL_LIBS}" GL )
#-----------------------------------------------------------------
target_sources (            glad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/glad.c" )
target_sources (            glad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/glad/glad.h" )
target_sources (            glad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/KHR/khrplatform.h" )
#-----------------------------------------------------------------
#set_source_files_properties( "${CMAKE_CURRENT_LIST_DIR}/src/glad.c" PROPERTIES COMPILE_FLAGS -Wno-pedantic )
#-----------------------------------------------------------------
#======================================================================
# End of file.
#======================================================================
