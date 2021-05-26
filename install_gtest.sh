#!/usr/bin/env bash

set -e

WORK_DIRECTORY=$([ -z "$1" ] && 'pwd' || echo "$1")

GTEST_MAJOR_VERSION=1
GTEST_MINOR_VERSION=10
GTEST_PATCH_VERSION=0

GTEST_VERSION=${GTEST_MAJOR_VERSION}.${GTEST_MINOR_VERSION}.${GTEST_PATCH_VERSION}

GTEST_SOURCE_DIR=${WORK_DIRECTORY}/temp
GTEST_INSTALL_DIR=${WORK_DIRECTORY}/gtest

GTEST_URL="https://github.com/google/googletest/archive/release-${GTEST_VERSION}.tar.gz"

mkdir -v -p "${GTEST_SOURCE_DIR}" || exit 1
mkdir -v -p "${GTEST_INSTALL_DIR}" || exit 2

wget --no-check-certificate --quiet -O - ${GTEST_URL} | tar --strip-components=1 -xz -C "${GTEST_SOURCE_DIR}"
if [ $? -ne 0 ]
  then exit 3
fi

cd "${GTEST_SOURCE_DIR}" || exit 4

cmake . \
      -DCMAKE_CXX_STANDARD=17              \
      -DBUILD_SHARED_LIBS=ON               \
      -DCMAKE_BUILD_TYPE=RelWithDebInfo    \
      -DCMAKE_CXX_FLAGS="-O2"              \
      -DGTEST_HAS_PTHREAD=1                \
      -S"${GTEST_SOURCE_DIR}"              \
      -B"${GTEST_SOURCE_DIR}/build"        \
      -DCMAKE_INSTALL_PREFIX="${GTEST_INSTALL_DIR}"

cmake --build build -j "$(nproc)"
cmake --install build

cd "${WORK_DIRECTORY}" || exit 6
rm -rf "${GTEST_SOURCE_DIR}"

export GTest_ROOT=${GTEST_INSTALL_DIR}
