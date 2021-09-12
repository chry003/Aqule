buildSystem=$1

function Clean()
{
	rm ./build/* -rf
}

function Build()
{
	rm ./build/${buildSystem}/Aqule
	cmake -B ./build/${buildSystem} -DCMAKE_BUILD_TYPE=${buildSystem} -G "Ninja"
	ninja -C ./build/${buildSystem}
}

function Run()
{
	if [[ -f "./build/${buildSystem}/Aqule" ]]; then
			xfce4-terminal -T "Aqule" -e "/usr/bin/cb_console_runner ./build/${buildSystem}/Aqule" --show-borders --hide-menubar --hide-toolbar  --geometry=50x15+5+10&
	fi
}

function GDBDebug()
{
	buildSystem="Debug"
	Build
	if [[ -f "./build/${buildSystem}/Aqule" ]]; then
		xfce4-terminal -T "Aqule" -e "/usr/bin/cb_console_runner gdb -q ./build/${buildSystem}/Aqule" --show-borders --hide-menubar --hide-toolbar  --geometry=75x15+200+100&
	fi
	Run
}


if [[ $buildSystem == "Clean" || $buildSystem == "CleanBuild" ]]; then
	Clean
elif [[ $buildSystem == "Debug" || $buildSystem == "Release" ]]; then
	Build
	Run
elif [[ $buildSystem == "GDBDebug" ]]; then
	GDBDebug
else
	exit
fi
