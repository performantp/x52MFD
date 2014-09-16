# - Try to find x52pro
# Once done this will define
#  X52PRO_FOUND - System has the x52pro Library
#  X52PRO_INCLUDE_DIRS - The x52pro include directories
#  X52PRO_LIBRARIES - The libraries needed to use x52pro

find_package(PkgConfig)

find_library(X52PRO_LIBRARY NAMES x52pro
             HINTS /usr/lib )

set(X52PRO_LIBRARIES ${X52PRO_LIBRARY} )
set(X52PRO_INCLUDE_DIRS ${X52PRO_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set X52PRO_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(LibXml2  DEFAULT_MSG
                                  X52PRO_LIBRARY X52PRO_INCLUDE_DIR)

mark_as_advanced(X52PRO_INCLUDE_DIR X52PRO_LIBRARY )