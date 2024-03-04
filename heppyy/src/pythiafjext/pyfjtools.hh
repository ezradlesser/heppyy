#ifndef PYTHIA_FASTJET_TOOLS_HH
#define PYTHIA_FASTJET_TOOLS_HH

#include <fastjet/PseudoJet.hh>
#include <Pythia8/Pythia.h>

namespace pythiafjtools{
	std::vector<fastjet::PseudoJet> vectorize(const Pythia8::Pythia &p,
	                                          bool only_final,
	                                          double eta_min, double eta_max,
	                                          bool add_particle_info = false);

	enum Py8Part
	{
		kIgnore  = 0,
		kAny     	,
		kFinal   	,
		kCharged 	,
		kNeutral 	,
		kVisible 	,
		kParton  	,
		kGluon   	,
		kQuark   	,
		kDiquark 	,
		kLepton  	,
		kPhoton  	,
		kHadron  	,
		kResonance  ,
		kMaxSetting
	};

    int update_hadronization(Pythia8::Pythia & pythia, const int require_pid = 0, const int daughters_size = -1);

	std::vector<fastjet::PseudoJet> vectorize_select(	const Pythia8::Pythia &p,
														std::vector<int>& selection,
														int user_index_offset = 0,
														bool add_particle_info = false,
														float particle_mass = -1);

	std::vector<fastjet::PseudoJet> vectorize_select_replaceD0(	const Pythia8::Pythia &p,
																std::vector<int>& selection,
																int user_index_offset = 0,
																bool add_particle_info = false,
																bool remove_soft_pion = false);

	std::vector<fastjet::PseudoJet> add_vectors( std::vector<fastjet::PseudoJet> v1, 
												 std::vector<fastjet::PseudoJet> v2);
	bool checkD0mother( const Pythia8::Pythia &pythia, int D0particle_index );
	int getSoftPion( const Pythia8::Pythia &pythia, int D0particle_index );
	int removeIndexFromv( std::vector<fastjet::PseudoJet> v, std::vector<int> saved_indices, int index);
	std::vector<fastjet::PseudoJet> removeByIndex( std::vector<fastjet::PseudoJet> v, int indextoremove);
	std::vector<fastjet::PseudoJet> replaceKPwD0( const Pythia8::Pythia &pythia, std::vector<fastjet::PseudoJet> v, int D0index, int dau1index, int dau2index);

	// implemented in fjtools
	// double angularity(const fastjet::PseudoJet &j, double alpha, double scaleR0 = 1.);

	Pythia8::Particle *getPythia8Particle(const fastjet::PseudoJet *psj);

	class PythiaParticleInfo : public fastjet::PseudoJet::UserInfoBase
	{
	public:
		PythiaParticleInfo();
		PythiaParticleInfo(const Pythia8::Particle &p);
		~PythiaParticleInfo();
		Pythia8::Particle* getParticle() const ;
	private:
		Pythia8::Particle* fParticle;
	};
};

#endif
