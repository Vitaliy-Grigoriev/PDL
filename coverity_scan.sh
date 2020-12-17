#!/usr/bin/env bash

if [ "$#" -lt 1 ]
then
 echo "Error in input parameters!  Not find the version of the build."
 exit "0"
fi

export CXX="/usr/bin/g++"
export BUILD_TYPE="Debug"

mkdir check && cd check && cmake -DPDL_WITH_TESTS=1 -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DCMAKE_CXX_COMPILER=${CXX} -j4 ..

/home/vitaly/Coverity/bin/cov-configure --comptype gcc --compiler gcc-9 --template
/home/vitaly/Coverity/bin/cov-build --dir cov-int make -j4 && tar czvf project.tgz cov-int && curl \
  --form token=2d9uWgkZDh2Nms5m4tp3sg \
  --form email=Vit.link420@gmail.com \
  --form file=@project.tgz \
  --form version="$1" \
  --form description="$2" \
  https://scan.coverity.com/builds?project=Vitaliy-Grigoriev%2FPDL && echo "Send packet success."

cp cov-int/build-log.txt ../coverity-build-log.txt
cd .. && rm -rf check
