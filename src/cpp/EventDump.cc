#include <iostream>

#include "../EventDump.h"
#include "../Event.h"

using namespace std;

EventDump::EventDump() {
}


EventDump::~EventDump() {
}


// function to be called at execution start
void EventDump::beginJob() {
  return;
}


// function to be called at execution end
void EventDump::endJob() {
  return;
}


// function to be called for each event
void EventDump::process( const Event& ev ) {

	using namespace std;

	cout << "Event " << ev.eventNumber() << ": " << ev.dataSize() << " points"
			<< endl;
	for (unsigned i = 0; i < ev.dataSize(); ++i) {
		cout << "    " << ev.energy(i);

		// Digression: It should be noted that on modern processor complicated conditions
		// inside repeated blocks (like a for loop) are not cpu-intensive if
		// they are almost always true or false, thanks to branch prediction.
		// Anyway, since logic operators like && (=and) uses short-circuit evalutation,
		// it's better to put them in order of probability to have different values during
		// the cycle.
		if (i % 12 == 0 and i != 0 and i != ev.dataSize()-1) {
			cout << endl;
		}
	}
	cout << endl << endl;
	return;

}

