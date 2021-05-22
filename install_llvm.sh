#!/usr/bin/env bash

set -e

WORK_DIRECTORY=$([ -z "$1" ] && 'pwd' || echo "$1")

LLVM_MAJOR_VERSION=12
LLVM_MINOR_VERSION=0
LLVM_PATCH_VERSION=0

LLVM_VERSION=${LLVM_MAJOR_VERSION}.${LLVM_MINOR_VERSION}.${LLVM_PATCH_VERSION}

LLVM_SOURCE_DIR=${WORK_DIRECTORY}/temp
LLVM_INSTALL_DIR=${WORK_DIRECTORY}/llvm

LLVM_URL="https://github.com/llvm/llvm-project/releases/download/llvmorg-${LLVM_VERSION}/llvm-${LLVM_VERSION}.src.tar.xz"

mkdir -v -p "${LLVM_SOURCE_DIR}" || exit 1
mkdir -v -p "${LLVM_INSTALL_DIR}" || exit 2

wget --no-check-certificate --quiet -O - ${LLVM_URL} | tar --strip-components=1 -xJ -C "${LLVM_SOURCE_DIR}"
if [ $? -ne 0 ]
  then exit 3
fi

cd "${LLVM_SOURCE_DIR}" || exit 4

cmake . \
      -DCMAKE_CXX_STANDARD=17              \
      -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
      -DBUILD_SHARED_LIBS=OFF              \
      -DCMAKE_BUILD_TYPE=RelWithDebInfo    \
      -DCMAKE_CXX_COMPILER="$CXX"          \
      -DCMAKE_CXX_FLAGS="-O2"              \
      -DLLVM_TARGETS_TO_BUILD="X86"        \
      -DLLVM_BUILD_DOCS=OFF                \
      -DLLVM_BUILD_TOOLS=OFF               \
      -DLLVM_INCLUDE_TOOLS=OFF             \
      -DLLVM_BUILD_BENCHMARKS=OFF          \
      -DLLVM_INCLUDE_BENCHMARKS=OFF        \
      -DLLVM_BUILD_EXAMPLES=OFF            \
      -DLLVM_INCLUDE_EXAMPLES=OFF          \
      -DLLVM_BUILD_TESTS=OFF               \
      -DLLVM_INCLUDE_TESTS=OFF             \
      -DLLVM_INSTALL_UTILS=OFF             \
      -DLLVM_ENABLE_BINDINGS=OFF           \
      -DLLVM_ENABLE_PIC=ON                 \
      -S"${LLVM_SOURCE_DIR}"               \
      -B"${LLVM_SOURCE_DIR}/build"         \
      -DCMAKE_INSTALL_PREFIX="${LLVM_INSTALL_DIR}"

cmake --build build -j "$(nproc)"
cmake --install build

cd "${WORK_DIRECTORY}" || exit 6
rm -rf "${LLVM_SOURCE_DIR}"

export LLVM_ROOT=${LLVM_INSTALL_DIR}
