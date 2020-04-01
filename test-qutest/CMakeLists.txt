set(APP_QUTEST blinky_qutest)
add_executable(${APP_QUTEST} "")

target_include_directories(
		${APP_QUTEST}
		PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		${CMAKE_CURRENT_LIST_DIR}/../generate
		${CMAKE_CURRENT_LIST_DIR}
		${CMAKE_CURRENT_BINARY_DIR}
)

target_sources(
		${APP_QUTEST}
		PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/../generate/blinky.cpp
		${CMAKE_CURRENT_LIST_DIR}/../src/blinky_impl.cpp
		${CMAKE_CURRENT_LIST_DIR}/../src/server.cpp
		${CMAKE_CURRENT_LIST_DIR}/blinky_qutest.cpp
)

#target_compile_options(
#		${APP_QUTEST}
#		PRIVATE
#		-DQ_UTEST
#		-DQ_HOST
#)

target_link_libraries(
		${APP_QUTEST}
		PRIVATE
		qp::qpcpp-posix-qutest
)

install (TARGETS ${APP}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT bin
		)