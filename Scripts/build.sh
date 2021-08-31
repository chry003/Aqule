buildSystem=""

if [[ $1 == "Clean" ]]; then
	rm ./build/* -rf
fi

if [[ $1 == "CleanBuild" ]]; then
	rm ./build/* -rf
fi

if [[ $1 == "Debug" ]]; then
	buildSystem="Debug"
elif [[ $1 == "Release" ]]; then
	buildSystem="Release"
elif [[ $1 == "CleanBuild" ]]; then
	buildSystem="Debug"
else
	exit
fi

rm ./build/${buildSystem}/Aqule

cmake -B ./build/${buildSystem} -DCMAKE_BUILD_TYPE=${buildSystem} -G "Ninja"

ninja -C ./build/${buildSystem}

if [[ -f "./build/${buildSystem}/Aqule" ]]; then
	xfce4-terminal -T "Aqule" -e "/usr/bin/cb_console_runner ./build/${buildSystem}/Aqule" --show-borders --hide-menubar --hide-toolbar  --geometry=50x15+5+10&
fi