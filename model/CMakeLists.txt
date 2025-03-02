qt_add_library(model STATIC
        model.cpp
    )

find_package(Qt6 REQUIRED COMPONENTS Sql)

target_link_libraries(model PRIVATE Qt6::Core Qt6::Sql)
target_include_directories(model INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
