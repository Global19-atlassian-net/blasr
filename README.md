##Installation##

###1. Requirements###

  To build BLASR, you must have hdf 1.8.0 or above installed and
  configured with c++ support (you should have the library
  libhdf5_cpp.a).  If you are intalling the entire PacBio secondary
  analysis software suite, appropriate hdf libraries are already
  distributed and no configuration is necessary.  Otherwise, it is
  necessary to point two environment variables, HDF5INCLUDEDIR and
  HDF5LIBDIR to the locations of the HDF5 libraries.

  For example:

+    > export HDF5INCLUDEDIR=/usr/include/hdf
+    > export HDF5LIBDIR=/usr/lib/hdf

###2. Build the source tree###

+    > make


###3. The executable will be in alignment/bin/blasr###

+    > cd alignment/bin/blasr


##Running BLASR##

Typing blasr -h or blasr -help on the command line will give you a
list of options.  At the least, provide a fasta, fastq, or bas.h5 file,
and a genome.

*Some typical use cases:*

+    Align reads from reads.bas.h5 to ecoli_K12 genome, and output in SAM format.

    * > blasr reads.bas.h5  ecoli_K12.fasta -sam

+    Same as above, but with soft clipping

    * > blasr reads.bas.h5  ecoli_K12.fasta -sam -clipping soft

+    Use multiple threads

    * > blasr reads.bas.h5  ecoli_K12.fasta -sam -clipping soft -out alignments.sam -nproc 16

+    Include a larger minimal match, for faster but less sensitive alignments

    * > blasr reads.bas.h5  ecoli_K12.fasta -sam -clipping soft -minMatch 15

+    Produce alignments in a pairwise human readable format

    * > blasr reads.bas.h5  ecoli_K12.fasta -m 0


+    Use a precomputed suffix array for faster startup

    * > sawriter hg19.fasta.sa hg19.fasta #First precompute the suffix array
    * > blasr reads.bas.h5 hg19.fasta -sa hg19.fasta.sa


+    Use a precomputed BWT-FM index for smaller runtime memory footprint, but slower alignments.
    * > sa2bwt hg19.fasta hg19.fasta.sa hg19.fasta.bwt
    * > blasr reads.bas.h5 hg19.fasta -bwt hg19.fasta.bwt

<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-13166584-21', 'github.com');
  ga('send', 'pageview');

</script>

