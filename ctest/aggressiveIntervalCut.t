Set up
  $ mkdir -p $OUTDIR

Test --aggressiveIntervalCut.
  $ rm -f $TMP1
  $ BASFILE=/pbi/dept/secondary/siv/testdata/BlasrTestData/ctest/data/aggressiveIntervalCut/m130812_185809_42141_c100533960310000001823079711101380_s1_p0.bas.h5
  $ REFFA=/pbi/dept/secondary/siv/testdata/BlasrTestData/ctest/data/references/Ecoli_BL21_O26/sequence/Ecoli_BL21_O26.fasta
  $ $BLASR_EXE $BASFILE $REFFA --holeNumbers 1--100 --out $TMP1 --aggressiveIntervalCut
  [INFO] * [blasr] started. (glob)
  [INFO] * [blasr] ended. (glob)
  $ echo $?
  0
