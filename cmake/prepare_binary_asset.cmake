# Helper to prepare in binary assets
function(prepare_binary_asset asset_path)
    cmake_path(GET asset_path FILENAME filename)
    string(REPLACE ${PROJECT_SOURCE_DIR}/ "" local_asset_path ${asset_path})
    string(REGEX REPLACE
        "([A-Za-z0-9_\/]+)\\.([A-Za-z0-9_]+)" "\\1_\\2.h"
        header_file_path ${CMAKE_CURRENT_BINARY_DIR}/${local_asset_path}
    )
    string(TOUPPER ${filename} variable_name)
    bin2h(
        SOURCE_FILE ${PROJECT_SOURCE_DIR}/${local_asset_path}
        HEADER_FILE ${header_file_path}
        VARIABLE_NAME ${variable_name}
        NULL_TERMINATE
    )
    file(APPEND ${header_file_path} "\n")
endfunction()
