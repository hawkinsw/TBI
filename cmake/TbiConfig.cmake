project(TbiConfigPackage)

include(FindPackageHandleStandardArgs)

#set(TBI_CONFIG_DEBUG TRUE)
set(TBI_CONFIG_DEBUG FALSE)

try_run(TBI_RUN_RESULT
    TBI_COMPILE_RESULT
    SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp 
    NO_CACHE 
    CXX_STANDARD 20 
    COMPILE_OUTPUT_VARIABLE TBI_COMPILE_OUTPUT)

if(TBI_CONFIG_DEBUG)
    message("TBI_COMPILE_RESULT: ${TBI_COMPILE_RESULT}")
    message("TBI_COMPILE_OUTPUT: ${TBI_COMPILE_OUTPUT}")
    message("TBI_RUN_RESULT: ${TBI_RUN_RESULT}")
endif()

if(TBI_COMPILE_RESULT AND TBI_RUN_RESULT EQUAL 95)
set(FOUND TRUE)
else()
set(FOUND FALSE)
endif()

find_package_handle_standard_args(Tbi DEFAULT_MSG FOUND)