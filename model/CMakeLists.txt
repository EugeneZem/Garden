qt_add_library(model STATIC
        model.cpp
    )

find_package(Qt6 REQUIRED COMPONENTS Sql)

target_link_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/PG_Libs)

target_link_libraries(model PRIVATE Qt6::Core
        Qt6::Sql
        libcrypto-3-x64
        libiconv-2
        libintl-9
        libpq
        libssl-3-x64
    )

target_include_directories(model INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/PG_Libs
    )
