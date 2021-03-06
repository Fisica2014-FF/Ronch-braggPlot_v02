#ifndef EnergyDist_h
#define EnergyDist_h

//... include header files ...

#include <vector>

#include "AnalysisSteering.h"
#include "Event.h"

class TH1F;

class BraggStatistic;

class EnergyDist: public AnalysisSteering {

 public:

  EnergyDist();
  virtual ~EnergyDist();

  // function to be called at execution start
  virtual void beginJob();
  // function to be called at execution end
  virtual void   endJob();
  // function to be called for each event
  virtual void process( const Event& ev );

  EnergyDist           ( const EnergyDist& x ) = delete;
  EnergyDist& operator=( const EnergyDist& x ) = delete;

 private:

  // Bragg curve information
  struct BraggCurve {
	  BraggStatistic* bragg_statistic;  // mean and rms energies
      TH1F* braggStat_graph;  // energy loss graph
  };

  // set of Bragg curves for different total energies
  std::vector<BraggCurve*> vbraggCurv;

  // create objects for a Bragg curve
  void bCreate( int id, float min, float max );



};

#endif

