##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Aqule-Core
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/rahul/Development/codelite-projects/Aqule
ProjectPath            :=/home/rahul/Development/codelite-projects/Aqule/Aqule-Core
IntermediateDirectory  :=../build-$(ConfigurationName)/Aqule-Core
OutDir                 :=../build-$(ConfigurationName)/Aqule-Core
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
OutputFile             :=../build-$(ConfigurationName)/lib/$(ProjectName)
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
Objects0=../build-$(ConfigurationName)/Aqule-Core/Aqule_core.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Aqule-Core/Aqule_Application.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Aqule-Core/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Aqule-Core"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@echo rebuilt > $(IntermediateDirectory)/Aqule-Core.relink

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Aqule-Core"
	@mkdir -p ""../build-$(ConfigurationName)/lib""

../build-$(ConfigurationName)/Aqule-Core/.d:
	@mkdir -p "../build-$(ConfigurationName)/Aqule-Core"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Aqule-Core/Aqule_core.cpp$(ObjectSuffix): Aqule/core.cpp ../build-$(ConfigurationName)/Aqule-Core/Aqule_core.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rahul/Development/codelite-projects/Aqule/Aqule-Core/Aqule/core.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Aqule_core.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Aqule-Core/Aqule_core.cpp$(DependSuffix): Aqule/core.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Aqule-Core/Aqule_core.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Aqule-Core/Aqule_core.cpp$(DependSuffix) -MM Aqule/core.cpp

../build-$(ConfigurationName)/Aqule-Core/Aqule_core.cpp$(PreprocessSuffix): Aqule/core.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Aqule-Core/Aqule_core.cpp$(PreprocessSuffix) Aqule/core.cpp

../build-$(ConfigurationName)/Aqule-Core/Aqule_Application.cpp$(ObjectSuffix): Aqule/Application.cpp ../build-$(ConfigurationName)/Aqule-Core/Aqule_Application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rahul/Development/codelite-projects/Aqule/Aqule-Core/Aqule/Application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Aqule_Application.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Aqule-Core/Aqule_Application.cpp$(DependSuffix): Aqule/Application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Aqule-Core/Aqule_Application.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Aqule-Core/Aqule_Application.cpp$(DependSuffix) -MM Aqule/Application.cpp

../build-$(ConfigurationName)/Aqule-Core/Aqule_Application.cpp$(PreprocessSuffix): Aqule/Application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Aqule-Core/Aqule_Application.cpp$(PreprocessSuffix) Aqule/Application.cpp


-include ../build-$(ConfigurationName)/Aqule-Core//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


