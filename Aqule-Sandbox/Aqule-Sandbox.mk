##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Aqule-Sandbox
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/rahul/Development/codelite-projects/Aqule
ProjectPath            :=/home/rahul/Development/codelite-projects/Aqule/Aqule-Sandbox
IntermediateDirectory  :=../build-$(ConfigurationName)/Aqule-Sandbox
OutDir                 :=../build-$(ConfigurationName)/Aqule-Sandbox
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rahul
Date                   :=08/20/21
CodeLitePath           :=/home/rahul/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Aqule-Sandbox/src_SandboxApp.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Aqule-Sandbox/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Aqule-Sandbox"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Aqule-Sandbox"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Aqule-Sandbox/.d:
	@mkdir -p "../build-$(ConfigurationName)/Aqule-Sandbox"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Aqule-Sandbox/src_SandboxApp.cpp$(ObjectSuffix): src/SandboxApp.cpp ../build-$(ConfigurationName)/Aqule-Sandbox/src_SandboxApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rahul/Development/codelite-projects/Aqule/Aqule-Sandbox/src/SandboxApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SandboxApp.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Aqule-Sandbox/src_SandboxApp.cpp$(DependSuffix): src/SandboxApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Aqule-Sandbox/src_SandboxApp.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Aqule-Sandbox/src_SandboxApp.cpp$(DependSuffix) -MM src/SandboxApp.cpp

../build-$(ConfigurationName)/Aqule-Sandbox/src_SandboxApp.cpp$(PreprocessSuffix): src/SandboxApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Aqule-Sandbox/src_SandboxApp.cpp$(PreprocessSuffix) src/SandboxApp.cpp


-include ../build-$(ConfigurationName)/Aqule-Sandbox//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


