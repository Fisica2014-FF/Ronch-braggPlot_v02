//============================================================================
// Name        : ECLIPSE_MARS_PROJECT_CPP11.cpp
// Author      : Francesco Forcher
// Version     : 0.1
// Copyright   : All rights reserved © 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>

#include "AnalysisInfo.h"
#include "dbg_macro.h"
#include "EnergyDist.h"
#include "Event.h"
#include "EventDump.h"
#include "EventSource.h"
#include "SourceFactory.h"

int main(int argc, char* argv[]) {
	using namespace std;

	// store command line parameters
    AnalysisInfo* info = new AnalysisInfo(argc, argv);

	// create data source
	EventSource* es = SourceFactory::create(info);

	// create a list of analyzers
	vector<AnalysisSteering*> aList;

	// create object to dump event
	// and store into list of analyzers
	aList.push_back(new EventDump());

	// create object to compute mean and rms energies
	// and store into list of analyzers
	aList.push_back(new EnergyDist());

	// initialize all analyzers
	for (auto& as : aList) {
		as->beginJob();
	}

	// loop over events
	const Event* ev;
	while ((ev = es->get())) {
		for (auto& as : aList) {
			as->process(*ev);
		}
		delete ev;
	}

	// finalize all analyzers
	for (auto& as : aList) {
		as->endJob();
	}

	//Clear memory
	for (auto& as : aList) {
		delete as;
	}
	delete es;

	return 0;
}

