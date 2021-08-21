rm ./build/Aqule

cmake -B ./build -DCMAKE_BUILD_TYPE=Release

cmake --build ./build --config Release

if [[ -f "./build/Aqule" ]]; then
	./build/Aqule
fi