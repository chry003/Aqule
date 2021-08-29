buildSystem="Debug"

if [[ -f "./build/Aqule" ]]; then
	rm ./build/Aqule
fi

cmake -B ./build/${buildSystem} -DCMAKE_BUILD_TYPE=${buildSystem} -G "Ninja"

ninja -C ./build/${buildSystem}

if [[ -f "./build/${buildSystem}/Aqule" ]]; then
	xfce4-terminal -T "Aqule" -e "/usr/bin/cb_console_runner ./build/${buildSystem}/Aqule" --show-borders --hide-menubar --hide-toolbar  --geometry=50x15+5+10&
fi