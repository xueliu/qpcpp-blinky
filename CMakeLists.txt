cmake_minimum_required(VERSION 3.5)

project(blinky)

# -- set cxx 14 standard default
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -- Required to build
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

find_package(qpcpp-posix CONFIG REQUIRED)
find_package(qpcpp-posix-qutest CONFIG REQUIRED)

set(BUILD_TEST_UNIT "Build Unit-Tests" ON)
set(BUILD_TEST_COMP "Build Component Tests" ON)
set(BUILD_TEST_QUTEST "Build QUTests" ON)

if(BUILD_TEST_UNIT)
	add_subdirectory(extern/google-test)
	# enable CTest testing
	enable_testing()
	include(test-unit/CMakeLists.txt)
endif()
	include(test-qutest/CMakeLists.txt)
if(BUILD_TEST_QUTEST)

endif()

set(APP blinky)
add_executable(${APP} "")

target_include_directories(
	${APP}
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		${CMAKE_CURRENT_LIST_DIR}/generate
		${CMAKE_CURRENT_LIST_DIR}
		${CMAKE_CURRENT_BINARY_DIR}
)

target_sources(
	${APP}
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/generate/blinky.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/blinky_impl.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/bsp.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/server.cpp
		${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
)

target_link_libraries(
	${APP}
	PRIVATE
		qp::qpcpp-posix
)

install (TARGETS ${APP}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT bin
)