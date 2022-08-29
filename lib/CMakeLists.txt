
file(GLOB_RECURSE ARCADES_SOURCE_FILES
    "${ARCADES_LIBRARY_DIR}/src/*.cxx"
    "${ARCADES_LIBRARY_DIR}/src/*.hxx"
)

file(GLOB_RECURSE ARCADES_INCLUDE_FILES
    "${ARCADES_LIBRARY_DIR}/include/arcades/*.hxx"
)

configure_file(
    "${ARCADES_LIBRARY_DIR}/config/version.hxx.in"
    "${PROJECT_BINARY_DIR}/include/config/version.hxx"
)


set(ARCADES_LIBRARY_NAME "arcades-lib")

add_library(${ARCADES_LIBRARY_NAME} STATIC
    ${ARCADES_SOURCE_FILES}
    ${ARCADES_INCLUDE_FILES}
    "${PROJECT_BINARY_DIR}/include/config/version.hxx"
)

target_include_directories(${ARCADES_LIBRARY_NAME}
    PUBLIC
    "${ARCADES_LIBRARY_DIR}/include/"
    PRIVATE 
    "${ARCADES_LIBRARY_DIR}/src/"
    "${PROJECT_BINARY_DIR}/include/"
)

target_link_libraries(${ARCADES_LIBRARY_NAME} PUBLIC utils)
