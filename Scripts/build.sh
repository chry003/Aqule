rm ./build/Aqule

cmake -B ./build -DCMAKE_BUILD_TYPE=Debug

cmake --build ./build --config Release

if [[ -f "./build/Aqule" ]]; then
	xterm -bg black -fg white -T "Aqule Engine" -e /usr/bin/cb_console_runner ./build/Aqule
fi