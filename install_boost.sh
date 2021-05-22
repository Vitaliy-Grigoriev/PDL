#!/usr/bin/env bash

set -e

WORK_DIRECTORY=$([ -z "$1" ] && 'pwd' || echo "$1")

BOOST_MAJOR_VERSION=1
BOOST_MINOR_VERSION=76
BOOST_PATCH_VERSION=0

BOOST_VERSION_1=${BOOST_MAJOR_VERSION}.${BOOST_MINOR_VERSION}.${BOOST_PATCH_VERSION}
BOOST_VERSION_2=${BOOST_MAJOR_VERSION}_${BOOST_MINOR_VERSION}_${BOOST_PATCH_VERSION}

BOOST_SOURCE_DIR=${WORK_DIRECTORY}/temp
BOOST_INSTALL_DIR=${WORK_DIRECTORY}/boost

BOOST_URL="https://boostorg.jfrog.io/artifactory/main/release/${BOOST_VERSION_1}/source/boost_${BOOST_VERSION_2}.tar.gz"

mkdir -p "${BOOST_SOURCE_DIR}" || exit 1
mkdir -p "${BOOST_INSTALL_DIR}" || exit 2

wget --no-check-certificate --quiet -O - ${BOOST_URL} | tar --strip-components=1 -xz -C "${BOOST_SOURCE_DIR}"
if [ $? -ne 0 ]
  then exit 3
fi

cd "${BOOST_SOURCE_DIR}" || exit 4

./bootstrap.sh --prefix="${BOOST_INSTALL_DIR}" --with-icu
./b2 install --prefix="${BOOST_INSTALL_DIR}" cxxflags="-std=c++17 -g -fPIC" variant=release link=static runtime-link=shared threading=multi --layout=tagged --build-type=complete --with-atomic --with-chrono --with-context --with-date_time --with-filesystem --with-iostreams --with-locale --with-program_options --with-random --with-regex --with-serialization --with-system --with-thread

cd "${WORK_DIRECTORY}" || exit 5
rm -rf "${BOOST_SOURCE_DIR}"

export Boost_ROOT=${BOOST_INSTALL_DIR}