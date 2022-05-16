cmake_minimum_required(VERSION 3.21.2)

project(BezierCurves)

set( DEPS_DIR ${CMAKE_SOURCE_DIR}/build/external)

file(GLOB BezierCurves_SOURCE_FILES src/*.cpp)
file(GLOB BezierCurves_HEADER_FILES include/*.h)

add_subdirectory(external/SDL)

add_subdirectory(external/SDL_image)

add_executable(BezierCurves ${BezierCurves_SOURCE_FILES} ${BezierCurves_HEADER_FILES})

target_include_directories(BezierCurves PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
                                            ${CMAKE_CURRENT_SOURCE_DIR}/external/SDL/include/
                                            ${CMAKE_CURRENT_SOURCE_DIR}/external/SDL_image/)

target_link_libraries(BezierCurves PRIVATE SDL2 SDL2main SDL2_image)

add_custom_command(TARGET BezierCurves POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${DEPS_DIR}/SDL/Debug/SDL2d.dll"
                    "${DEPS_DIR}/SDL_image/Debug/SDL2_imaged.dll"
                    $<TARGET_FILE_DIR:BezierCurves>)

add_custom_command(TARGET BezierCurves POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:BezierCurves>/res)