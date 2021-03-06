MACRO(GET_PYTHON_ENV)
	LIST(APPEND PYTHON_ENV_VARS PYTHON=${PYTHON_EXECUTABLE})
	LIST(APPEND PYTHON_ENV_VARS PYTHONPATH=${CMAKE_BINARY_DIR}/src/interfaces/python:${CMAKE_INSTALL_PREFIX}/${PYTHON_PACKAGES_PATH}:$ENV{PYTHONPATH})
	if(WIN32)
		LIST(APPEND PYTHON_ENV_VARS PATH=${CMAKE_BINARY_DIR}/src/shogun;${CMAKE_INSTALL_PREFIX}/lib;$ENV{PATH})
	elseif(APPLE)
		LIST(APPEND PYTHON_ENV_VARS DYLD_LIBRARY_PATH=${CMAKE_BINARY_DIR}/src/shogun:${CMAKE_INSTALL_PREFIX}/lib:$ENV{DYLD_LIBRARY_PATH})
	else()
		LIST(APPEND PYTHON_ENV_VARS LD_LIBRARY_PATH=${CMAKE_BINARY_DIR}/src/shogun:${CMAKE_INSTALL_PREFIX}/lib:$ENV{LD_LIBRARY_PATH})
	endif()
ENDMACRO()
