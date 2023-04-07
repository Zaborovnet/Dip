# install_manifest.txt is created in the top build tree, not the project one
if (NOT EXISTS "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/install_manifest.txt")
    message(FATAL_ERROR "Cannot find install manifest: \"/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/install_manifest.txt\"")
endif()

set(uninstall_file_list "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/install_manifest.txt")
if(EXISTS "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/install_manifest_extra.txt")
   list(APPEND uninstall_file_list "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/install_manifest_extra.txt")
endif()

set(dir_list)
foreach (manifest_file IN ITEMS ${uninstall_file_list})
    file(READ "${manifest_file}" files)
    string(REGEX REPLACE "\n$" "" files "${files}")
    string(REGEX REPLACE "\n" ";" files "${files}")
    list(REVERSE files)
    foreach (file ${files})
        message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
        if (IS_DIRECTORY "$ENV{DESTDIR}${file}")
            list(APPEND dir_list "${file}")
        elseif (EXISTS "$ENV{DESTDIR}${file}")
            get_filename_component(dir "${file}" DIRECTORY)
            list(APPEND dir_list "${dir}")
            execute_process(
                COMMAND /usr/bin/cmake -E remove "$ENV{DESTDIR}${file}"
                OUTPUT_VARIABLE rm_out
                RESULT_VARIABLE rm_retval
            )
            if(NOT ${rm_retval} EQUAL 0)
                message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
            endif (NOT ${rm_retval} EQUAL 0)
        else ()
            message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
        endif ()
    endforeach(file)
endforeach()

while(NOT "${dir_list}" STREQUAL "")
    list(REMOVE_DUPLICATES dir_list)
    set(new_dir_list)
    foreach (file IN ITEMS ${dir_list})
        if (IS_DIRECTORY "$ENV{DESTDIR}${file}" AND "${file}" MATCHES "/usr/local[/\\].+")
            file(GLOB file_list "$ENV{DESTDIR}${file}/*")
            list(LENGTH file_list file_list_len)
            # Only remove empty directories
            if(file_list_len EQUAL 0)
                message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
                execute_process(
                    COMMAND /usr/bin/cmake -E remove_directory "$ENV{DESTDIR}${file}"
                    OUTPUT_VARIABLE rm_out
                    RESULT_VARIABLE rm_retval
                )
                if(${rm_retval} EQUAL 0)
                    get_filename_component(upper_dir "${file}" DIRECTORY)
                    list(APPEND new_dir_list "${upper_dir}")
                else()
                    message(STATUS "Problem when removing directory \"$ENV{DESTDIR}${file}\"")
                endif()
            endif()
        endif()
    endforeach()
    set(dir_list "${new_dir_list}")
endwhile()


