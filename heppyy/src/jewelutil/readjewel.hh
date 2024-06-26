#ifndef HEPPYY_READJEWEL_HH
#define HEPPYY_READJEWEL_HH

#include <hepmc2util/readfile.hh>

#include <HepMC/IO_GenEvent.h>
#include <HepMC/GenEvent.h>

#include <vector>
#include <list>

#include<fastjet/PseudoJet.hh>

#include <TDatabasePDG.h>

#include "jewelrivetstrip.hh"

namespace HeppyyJewelUtil
{
	class ReadJewelHepMC2File : public HeppyyHepMCUtil::ReadHepMCFile
	{
	public:
		ReadJewelHepMC2File(const char *fname);
		virtual ~ReadJewelHepMC2File();

        std::vector<fastjet::PseudoJet> fjParticles(bool only_final = true);
        std::vector<fastjet::PseudoJet> fjParticlesWithStatus(int status = -1);
        std::vector<fastjet::PseudoJet> fjFinalParticlesSubtractedThermalTest();

		void runSubstractionThermalRivet(double dmax);
		std::vector<fastjet::PseudoJet> getPseudoJets(bool charged_only = false);

		TDatabasePDG *getPDG() {return _PDG;}
		HeppyyRivet::SubtractedJewelEvent *getSE() {return _se;}

	private: 
		TDatabasePDG *_PDG;
		HeppyyRivet::SubtractedJewelEvent *_se;
	};
};
#endif
