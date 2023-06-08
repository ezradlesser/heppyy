#!/usr/bin/env python

import Sherpa
import sys
from mpi4py import MPI

Generator=Sherpa.Sherpa()
try:
    Generator.InitializeTheRun(len(sys.argv),sys.argv)
    Generator.InitializeTheEventHandler()
    for n in range(1,1+Generator.NumberOfEvents()):
        Generator.GenerateOneEvent()
        blobs=Generator.GetBlobList();
        print("Event",n,"{")
        ## print blobs
        print("  Weight ",blobs.GetFirst(1)["Weight"]);
        print("  Trials ",blobs.GetFirst(1)["Trials"]);
        for i in range(0,blobs.size()):
            print("  Blob",i,"{")
            ## print blobs[i];
            print("    Incoming particles")
            for j in range(0,blobs[i].NInP()):
                part=blobs[i].InPart(j)
                ## print part
                s=part.Stat()
                f=part.Flav()
                p=part.Momentum()
                print("     ",j,": ",s,f,p)
            print("    Outgoing particles")
            for j in range(0,blobs[i].NOutP()):
                part=blobs[i].OutPart(j)
                ## print part
                s=part.Stat()
                f=part.Flav()
                p=part.Momentum()
                print("     ",j,": ",s,f,p)
            print("  } Blob",i)
        print("} Event",n)
        if ((n%100)==0): print("  Event ",n)
    Generator.SummarizeRun()
        
except Sherpa.Exception as exc:
    exit(1)