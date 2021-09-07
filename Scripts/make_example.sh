path="/home/rahul/Development/Projects/Example"
folder=$(date +%a_%b_%d_%k_at_%I_%M)
mkdir ${path}/${folder}
mkdir ${path}/${folder}/source
mkdir ${path}/${folder}/binary

cp -r -v -i * ${path}/${folder}/source
cp -r -v -i "assets/" ${path}/${folder}/binary
cp -r -v -i "./build/Debug/Aqule" ${path}/${folder}/binary

rm -rf ${path}/${folder}/source/build/