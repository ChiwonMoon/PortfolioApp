# src/ui/CMakeLists.txt

# 라이브러리 생성
add_library(portfolio_ui
    STATIC
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
)

# Qt 연결
target_link_libraries(portfolio_ui
    PUBLIC
        Qt6::Widgets
        portfolio_core
)

# 포함 경로 설정 변경
target_include_directories(portfolio_ui
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
)