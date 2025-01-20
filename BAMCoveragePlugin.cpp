#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BAMCoveragePlugin.h"

void BAMCoveragePlugin::input(std::string file) {
   inputfile = file;
}

void BAMCoveragePlugin::run() {}

void BAMCoveragePlugin::output(std::string file) {
       	std::string outputfile = file;
//Avg_depth_ont=$(samtools depth ./ont_alignments/contig_${i}_reads.bam | awk '{sum+=$3; count++} END {if (count > 0) print sum/count; else print "0"}')
//#echo -e "contig_${i}\t${Avg_depth_ont}" >> ./stats/Avg_depth_ont.txt

	std::string myCommand = "echo -e \"contig\tont_average_coverage\tont_coverage_percent\" > "+file+"/coverageStats.txt; ";
myCommand += "samtools depth "+inputfile+" > "+file+"/coverage.txt; ";
myCommand += "awk '{if ($3 > 0) {covered_bases[$1]++; sum_coverage[$1] += $3; } total_bases[$1]++; } END { for (contig in sum_coverage) { average_coverage = sum_coverage[contig] / total_bases[contig]; coverage_percent = ((covered_bases[contig] / total_bases[contig]) *100); print contig, average_coverage, coverage_percent; } }' "+file+"/coverage.txt >> "+file+"/coverageStats.txt;";
myCommand += "sed -i 's/ /\t/g' "+file+"/coverageStats.txt";
		
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<BAMCoveragePlugin> BAMCoveragePluginProxy = PluginProxy<BAMCoveragePlugin>("BAMCoverage", PluginManager::getInstance());
