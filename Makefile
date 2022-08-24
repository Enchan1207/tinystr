#
#
#
.PHONY: clean test install

BUILD_DIR=build
LIB_INSTALL_PREFIX=~/

${BUILD_DIR}:
	@mkdir -p ${BUILD_DIR}
	@cmake \
		-S. \
		-B${BUILD_DIR} \
		-DCMAKE_INSTALL_PREFIX=${LIB_INSTALL_PREFIX} \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	@cmake --build build

test: build
	@cd ${BUILD_DIR}; ctest

clean:
	@rm -rf ./build
	@echo "clean finished"
