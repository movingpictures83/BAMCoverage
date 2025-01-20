#ifndef BAMCoveragePLUGIN_H
#define BAMCoveragePLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class BAMCoveragePlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "BAMCoverage";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
