##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Montella
ConfigurationName      :=Debug
WorkspacePath          := "/home/scoyle/Dropbox/CS/Data_Structures/Final/Coyle_CSCI2270_FinalProject/FinalProject"
ProjectPath            := "/home/scoyle/Dropbox/CS/Data_Structures/Final/Coyle_CSCI2270_FinalProject/FinalProject"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Samuel Coyle
Date                   :=30/04/16
CodeLitePath           :="/home/scoyle/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Montella.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(ObjectSuffix) $(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(ObjectSuffix): ../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/statTree.cpp $(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/scoyle/Dropbox/CS/Data_Structures/Final/Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/statTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(DependSuffix): ../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/statTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(DependSuffix) -MM "../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/statTree.cpp"

$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(PreprocessSuffix): ../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/statTree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Montella_CSCI2270_FinalProject_statTree.cpp$(PreprocessSuffix) "../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/statTree.cpp"

$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(ObjectSuffix): ../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/main.cpp $(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/scoyle/Dropbox/CS/Data_Structures/Final/Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(DependSuffix): ../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(DependSuffix) -MM "../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/main.cpp"

$(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(PreprocessSuffix): ../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Montella_CSCI2270_FinalProject_main.cpp$(PreprocessSuffix) "../../Montella_CSCI2270_FinalProject/Montella_CSCI2270_FinalProject/main.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


