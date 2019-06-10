if (FLANN_FIND_VERSION)
    message(WARNING "Finding a specific version of FLANN is not supported.")
endif (FLANN_FIND_VERSION)

if( NOT $ENV{FLANN_ROOT} STREQUAL "" )
    set(FLANN_ROOT $ENV{FLANN_ROOT})
endif()

find_path(FLANN_INCLUDE_DIR
    flann/flann.h
    ${FLANN_ROOT}/include
    /usr/include
)

message(STATUS "FLANN_INCLUDE_DIR: " ${FLANN_INCLUDE_DIR})

#if (WIN32)
if (FLANN_USE_STATIC_LIBS)
    find_library(FLANN_LIBRARY_DEBUG
        NAMES libflann.lib libflann.a libflann.dylib
        PATHS ${FLANN_ROOT}/lib /usr/lib
    )

    find_library(FLANN_LIBRARY_RELEASE
        NAMES libflann.lib libflann.a libflann.dylib
        PATHS ${FLANN_ROOT}/lib usr/lib
    )
else (FLANN_USE_STATIC_LIBS)
    find_library(FLANN_LIBRARY_DEBUG
        NAMES libflann.lib libflann.a libflann.dylib
        PATHS ${FLANN_ROOT}/lib /usr/lib
    )

    find_library(FLANN_LIBRARY_RELEASE
        NAMES libflann.lib libflann.a libflann.dylib
        PATHS ${FLANN_ROOT}/lib /usr/lib
    )
endif(FLANN_USE_STATIC_LIBS)
#endif(WIN32)

set (FLANN_LIBRARY debug ${FLANN_LIBRARY_DEBUG} optimized ${FLANN_LIBRARY_RELEASE})

mark_as_advanced(
    FLANN_INCLUDE_DIR
    FLANN_LIBRARY_DEBUG
    FLANN_LIBRARY_RELEASE
    FLANN_LIBRARY
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    FLANN
    "Unable to find FLANN: \nPlease set the FLANN_ROOT variable to the FLANN directory.\n"
    FLANN_INCLUDE_DIR
    FLANN_LIBRARY_DEBUG
    FLANN_LIBRARY_RELEASE
    FLANN_LIBRARY
)
