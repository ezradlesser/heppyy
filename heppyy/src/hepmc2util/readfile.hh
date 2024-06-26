#ifndef HEPPYY_HEPMCWRAP_READFILE_HH
#define HEPPYY_HEPMCWRAP_READFILE_HH

#include <HepMC/IO_GenEvent.h>
#include <HepMC/GenEvent.h>

#include <vector>
#include <list>

namespace HeppyyHepMCUtil
{
	class ReadHepMCFile
	{
	public:
		ReadHepMCFile(const char *fname);
		virtual ~ReadHepMCFile();

		virtual bool 						NextEvent();

		HepMC::GenCrossSection* 			GetCrossSecion();
		double 								GetCrossSecionValue();
		double 								GetCrossSecionValueError();

		HepMC::PdfInfo* 					GetPDFinfo();
		HepMC::WeightContainer*  			GetWeightContainer();
		std::list<HepMC::GenVertex*> 		Vertices();
		std::vector<HepMC::GenParticle*> 	HepMCParticles(bool only_final = true);
		std::vector<HepMC::GenParticle*> 	HepMCParticlesWithStatus(int status = -1);

		long int 							CurrentEventNumber() { return fCurrentEvent;}

		HepMC::GenEvent* 					GetEvent() {return fEvent;}

		bool 								failed();

	protected:
		HepMC::IO_GenEvent fIn;
		HepMC::GenEvent* fEvent;
		std::list<HepMC::GenVertex*> fVertices;
		std::vector<HepMC::GenParticle*> fParticles;
		long int fCurrentEvent;
	};
}

#endif
