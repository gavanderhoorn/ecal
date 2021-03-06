function(PROTOBUF_GENERATE_CPP_EXT SRCS_RET HDRS_RET PROTO_OUT_DIR_RET PROTO_ROOT)
  if(NOT ARGN)
    message(SEND_ERROR "Error: PROTOBUF_GENERATE_CPP_EXT() called without any proto files")
    return()
  endif()
  
  #Backwards compatability
  if (DEFINED PROTOBUF_PROTOC_EXECUTABLE AND NOT DEFINED Protobuf_PROTOC_EXECUTABLE)
    set(Protobuf_PROTOC_EXECUTABLE ${PROTOBUF_PROTOC_EXECUTABLE})
  endif (DEFINED PROTOBUF_PROTOC_EXECUTABLE AND NOT DEFINED Protobuf_PROTOC_EXECUTABLE)

  set(PROTO_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/protobuf")
  file(MAKE_DIRECTORY ${PROTO_OUT_DIR})  
  get_filename_component(PROTO_ROOT ${PROTO_ROOT} ABSOLUTE)

  foreach(FIL ${ARGN})
    # Make the file path absolute, so that it is also normalized (no a\..\a\b)
    get_filename_component(ABS_FIL ${FIL} ABSOLUTE)
    # Compute the relative path of the .proto file compared to the proto root
    FILE(RELATIVE_PATH REL_FIL ${PROTO_ROOT} ${FIL})
    # Remove the file extension
    string(REGEX REPLACE "\\.[^.]*$" "" REL_FIL_WE ${REL_FIL})

    list(APPEND SRCS "${PROTO_OUT_DIR}/${REL_FIL_WE}.pb.cc")
    list(APPEND HDRS "${PROTO_OUT_DIR}/${REL_FIL_WE}.pb.h")

    add_custom_command(
      OUTPUT "${PROTO_OUT_DIR}/${REL_FIL_WE}.pb.cc"
             "${PROTO_OUT_DIR}/${REL_FIL_WE}.pb.h"
      COMMAND ${Protobuf_PROTOC_EXECUTABLE}
      ARGS "--proto_path=${PROTO_ROOT}" "--cpp_out=${PROTO_OUT_DIR}" ${ABS_FIL}
      DEPENDS ${ABS_FIL} ${Protobuf_PROTOC_EXECUTABLE}
      COMMENT "Running C++ protocol buffer compiler on ${ABS_FIL} ${Protobuf_PROTOC_EXECUTABLE}"
      VERBATIM )

  endforeach()

  set_source_files_properties(${SRCS} ${HDRS} PROPERTIES GENERATED TRUE)
  
  
  set(${SRCS_RET}          ${SRCS}          PARENT_SCOPE)
  set(${HDRS_RET}          ${HDRS}          PARENT_SCOPE)
  set(${PROTO_OUT_DIR_RET} ${PROTO_OUT_DIR} PARENT_SCOPE)
endfunction()

# CPP_FILES
# H_FILES
# PROTO_FILES
# INCLUDE_DIR
# INSTALL_DIR
function(PROTOBUF_TARGET_SOURCES TARGET_NAME)
set(oneValueArgs   INSTALL_DIR INCLUDE_DIR)
set(multiValueArgs PROTO_FILES H_FILES CPP_FILES)

cmake_parse_arguments(INPUT "" 
  "${oneValueArgs}"
  "${multiValueArgs}" ${ARGN} )

  if (MSVC)
    set_source_files_properties(${INPUT_CPP_FILES} PROPERTIES COMPILE_FLAGS "/wd4100 /wd4146 /wd4512 /wd4127 /wd4125 /wd4244 /wd4267 /wd4300 /wd4309 /wd4800")
  endif(MSVC)


  # This adds the pb.h and pb.cc files to the project
  target_include_directories(${TARGET_NAME} PUBLIC 
    $<BUILD_INTERFACE:${INPUT_INCLUDE_DIR}> 
    $<INSTALL_INTERFACE:${INPUT_INSTALL_DIR}>
  )
  target_sources(${TARGET_NAME} PRIVATE ${INPUT_CPP_FILES} ${INPUT_H_FILES})  
  
  source_group(protobuf\\cpp FILES
    ${INPUT_CPP_FILES} 
    ${INPUT_H_FILES} 
  )
  
  # Also add the original protobuf files to the project
  target_sources(${TARGET_NAME} PRIVATE ${INPUT_PROTO_FILES})    
  set_source_files_properties(${INPUT_PROTO_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
  source_group(protobuf\\proto FILES
    ${INPUT_PROTO_FILES} 
  )

  if (INPUT_INSTALL_DIR)
    install(
      DIRECTORY ${INPUT_INCLUDE_DIR}/
      DESTINATION ${INPUT_INSTALL_DIR}
      FILES_MATCHING PATTERN "*.h"
    )
  endif ()  
endfunction()


function(PROTOBUF_TARGET_CPP TARGET_NAME PROTO_ROOT)
  
  set(oneValueArgs   INSTALL_FOLDER)
  cmake_parse_arguments(PROTOBUF_TARGET_CPP "" 
    "${oneValueArgs}"
    "" ${ARGN} )
   
  # PROTOBUF_TARGET_CPP_UNPARSED_ARGUMENTS: These are all .proto files
  # INPUT_INSTALL_DIR: If this option is given, we want also to install files and and add them to the interface include path.

  #message(STATUS "ProtoFiles: ${PROTOBUF_TARGET_CPP_UNPARSED_ARGUMENTS}")
  #message(STATUS "install folder: ${PROTOBUF_TARGET_CPP_INSTALL_FOLDER}")
  
  PROTOBUF_GENERATE_CPP_EXT(proto_sources proto_headers proto_include_dirs ${PROTO_ROOT} ${PROTOBUF_TARGET_CPP_UNPARSED_ARGUMENTS})
  PROTOBUF_TARGET_SOURCES(${TARGET_NAME}
    PROTO_FILES ${PROTOBUF_TARGET_CPP_UNPARSED_ARGUMENTS}
    H_FILES     ${proto_headers}
    CPP_FILES   ${proto_sources}
    INCLUDE_DIR ${proto_include_dirs}
    INSTALL_DIR ${PROTOBUF_TARGET_CPP_INSTALL_FOLDER}
  )
  
endfunction()