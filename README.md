# heppyy
HEP soft with python using cppyy 

# recommendation

## use yasp with virtualenv

```
git clone https://github.com/matplo/yasp
cd yasp
./yaspenv.sh
./yasp.py -i yasp -m
module load yasp
yasp --install jetty -m
./install_with_yasp.sh
```

then one can do

```
module load heppyy
python -m pip install tqdm
./heppyy/example/test_yaspcppyy_pythia_fastjet.py
```


## try conda
```
conda create -n heppyy
conda activate heppyy
conda install python
conda install -c conda-forge compilers
# install cppyy supporting c++11 - for fastjet
STDCXX=11 python -m pip install cppyy==2.4.0
# some more packages
conda install -c conda-forge hepmc2 hepmc3 lhapdf pyyaml numpy tqdm
# you can also grab root from conda
# conda install -c conda-forge root but this on some systems does not always work nice with the new cppyy
# you can install pythia8 also from conda but it will be pybind11 not cppyy we so use yasp (https://github.com/matplo/yasp) to install pythia - heppyy is yasp aware...
git clone https://github.com/matplo/yasp
# we will install those locally here ./external but we could also point to the conda dir or anywhere else in the system
./yasp/yasp.py --configure --prefix $PWD/external --workdir $PWD/build
./yasp/yasp.py --install fastjet fjcontrib pythia8
```

# test

- run `./example/test_pythia_fastjet.py`

