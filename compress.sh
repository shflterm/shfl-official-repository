cmake -S . -B build/
cmake --build build

rm -rf temp
mkdir temp
cd build/$1

os_type=$(uname -s)

echo "Current OS: $os_type"

if [ "$os_type" == "Darwin" ]; then
  find . -name '*.dylib' -exec sh -c 'mkdir -p ../../temp-$1/"$(dirname "{}")" && cp "{}" ../../temp-$1/"$(dirname "{}")/command.dylib"' \;
  os=macos
elif [ "$os_type" == "Linux" ]; then
  find . -name '*.so' -exec sh -c "cp --parents "{}" ../../temp" \;
  find ../../temp -type f -name '*.so' -exec sh -c 'mv "{}" "$(dirname "{}")/command.so"' \;
  os=ubuntu
fi

cp $1/app.shfl ../../temp/

cd ../../temp
zip -r $1.zip *
mv $1.zip ../$1_$os.shflapp
cd ..
