# src/core/CMakeLists.txt

# Core 라이브러리 생성
add_library(stockflow_core STATIC
    # 나중에 core 소스 추가
)

# 라이브러리 연결
target_link_libraries(stockflow_core
    PUBLIC
        Qt6::Core
)

# 포함 경로 설정
target_include_directories(stockflow_core
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
)