idf_component_register(SRCS "main.cpp"
                       INCLUDE_DIRS "." "../components/kalman_filter/include" 
                                        "../components/lte/include")
set(CMAKE_CXX_STANDARD 17)
