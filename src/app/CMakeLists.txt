# src/app/CMakeLists.txt

# 실행 파일 생성
add_executable(PortfolioApp
    main.cpp
)

# 윈도우 앱 설정 (콘솔창 숨기기)
set_target_properties(PortfolioApp PROPERTIES
    WIN32_EXECUTABLE TRUE
)

# 라이브러리 연결
target_link_libraries(PortfolioApp
    PRIVATE
        portfolio_ui
        portfolio_core
        Qt6::Widgets
)