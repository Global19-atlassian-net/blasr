#pragma once

#define REQUIRE_PBBAM_ERROR() \
    assert("blasr must be compiled with lib pbbam to perform IO on bam." == 0);

#include <vector>

#include <alignment/algorithms/alignment/AlignmentFormats.hpp>
#include <alignment/datastructures/alignment/FilterCriteria.hpp>
#include <alignment/datastructures/anchoring/AnchorParameters.hpp>
#include <alignment/files/BaseSequenceIO.hpp>
#include <alignment/format/SAMPrinter.hpp>
#include <alignment/tuples/TupleMetrics.hpp>
#include <alignment/utils/FileOfFileNames.hpp>
#include <alignment/utils/RangeUtils.hpp>
#include <pbdata/qvs/QualityValue.hpp>
#include <pbdata/reads/ReadType.hpp>

class MappingParameters
{
public:
    //
    // Parameters for global substitution, insertion, and deletion priors.
    //
    float minFractionToBeConsideredOverlapping;
    float indelRate;
    float minRatio;
    int indel;
    int idsIndel;
    int sdpIndel;
    int sdpIns, sdpDel;
    int insertion;
    int deletion;
    int mismatch;
    int sdpTupleSize;
    int match;
    int showAlign;
    bool useScoreCutoff;
    int maxScore;
    int argi;
    int nProc;
    int globalChainType;
    SAMOutput::Clipping clipping;
    std::string clippingString;
    QVScale qvScaleType;
    std::vector<std::string> readsFileNames;  // = queryFileNames, genomeFileName
    std::vector<std::string> queryFileNames;
    std::vector<std::string>
        scrapsFileNames;  // needed for noSplitSubread flag in PBBAM, deriived from queryFileNames
    std::string genomeFileName;
    // Query file type: FASTA/FASTQ/HDF*/PBBAM,
    // Note that mixed query file types is not allowed.
    FileType queryFileType;
    // Query read type, SUBREAD, CCS or UNKNOWN
    // Note that mixed read types is not allowed.
    ReadType::ReadTypeEnum queryReadType;
    std::vector<std::string> regionTableFileNames;
    std::vector<std::string> ccsFofnFileNames;
    std::string tupleListName;
    std::string posTableName;
    std::string outFileName;
    std::string suffixArrayFileName;
    std::string bwtFileName;
    std::string indexFileName;
    std::string anchorFileName;
    std::string clusterFileName;
    int nBest;
    int printWindow;
    int doCondense;
    int do4BitComp;
    int cutoff;
    int useSuffixArray;
    int useBwt;
    int useReverseCompressIndex;
    int useTupleList;
    int useSeqDB;
    std::string seqDBName;
    int useCountTable;
    std::string countTableName;
    int minMatchLength;
    int listTupleSize;
    int printFormat;
    int maxExpand, minExpand;
    int startRead;
    int stride;
    int pValueType;
    float subsample;
    int sortRefinedAlignments;
    int verbosity;
    bool printSAM;
    bool cigarUseSeqMatch;
    bool printBAM;
    bool sam_via_bam;  // for SAM output via pbbam using IRecordWriter
    bool storeMapQV;
    bool useRandomSeed;
    int randomSeed;
    bool placeRandomly;
    bool placeGapConsistently;
    bool printHeader;
    bool samplePaths;
    bool warp, nowarp;
    //bool usePrefixLookupTable;
    bool doSensitiveSearch;
    bool emulateNucmer;
    bool refineBetweenAnchorsOnly;
    bool byAdapter;
    bool extendDenovoCCSSubreads;
    TupleMetrics saTupleMetrics;
    TupleMetrics sdpTupleMetrics;
    int lookupTableLength;
    //int branchQualityThreshold;
    int qualityLowerCaseThreshold;
    AnchorParameters anchorParameters;
    int readsFileIndex;
    //int numBranches;
    bool storeMetrics;
    bool ignoreQualities;
    bool extendFrontAlignment;
    bool extendAlignments;
    int maxExtendDropoff;
    int minReadLength;
    int maxReadLength;
    int minSubreadLength;
    int minRawSubreadScore;
    int minAvgQual;
    bool overlap;
    bool advanceHalf;
    int advanceExactMatches;
    float approximateMaxInsertionRate;
    float minPctSimilarity;  // [0, 100]
    float minPctAccuracy;    // [0, 100]
    bool refineAlignments;
    int nCandidates;
    bool doGlobalAlignment;
    std::string tempDirectory;
    bool useTitleTable;
    std::string titleTableName;
    bool readSeparateRegionTable;
    bool readSeparateCcsFofn;
    std::string regionTableFileName;
    std::string ccsFofnFileName;
    //float averageMismatchScore;
    bool mapSubreadsSeparately;
    bool concordant;
    bool refineConcordantAlignments;
    int flankSize;
    bool useRegionTable;
    bool setIgnoreRegions;
    bool useHQRegionTable;
    bool setIgnoreHQRegions;
    bool printUnaligned;
    bool noPrintUnalignedSeqs;  // print unaligned reads names only.
    std::string unalignedFileName;
    std::string metricsFileName;
    std::string lcpBoundsFileName;
    std::string fullMetricsFileName;
    bool printSubreadTitle;
    bool useCcs;
    bool useAllSubreadsInCcs;
    bool useCcsOnly;
    bool detailedSDPAlignment, nouseDetailedSDPAlignment;
    int chunkSize;
    int sdpFilterType;
    bool useGuidedAlign;
    int guidedAlignBandSize;
    int bandSize;
    int extendBandSize;
    bool useQVScore;
    int scoreType;
    bool printVerboseHelp;
    float sdpBypassThreshold;
    bool computeAlignProbability;
    float qvMatchWeight;
    float qvMismatchWeight;
    float qvInsWeight;
    float qvDelWeight;
    float readAccuracyPrior;
    bool printVersion;
    int substitutionPrior;
    int globalDeletionPrior;
    bool outputByThread;
    int recurseOver;
    bool allowAdjacentIndels;
    bool separateGaps;
    std::string scoreMatrixString;
    bool printDotPlots;
    bool preserveReadTitle;
    bool forwardOnly;
    bool printOnlyBest;
    bool affineAlign;
    int affineExtend;
    int affineOpen;
    bool scaleMapQVByNumSignificantClusters;
    int limsAlign;
    std::string holeNumberRangesStr;
    Ranges holeNumberRanges;
    int minAlnLength;
    bool printSAMQV;
    std::vector<std::string> samQV;
    SupplementalQVList samQVList;
    bool fastMaxInterval;
    bool aggressiveIntervalCut;
    bool fastSDP;
    std::string concordantTemplate;
    bool concordantAlignBothDirections;
    FilterCriteria filterCriteria;
    std::string hitPolicyStr;
    HitPolicy hitPolicy;
    bool enableHiddenPaths;
    bool polymeraseMode;

    void Init()
    {
        qvMatchWeight = 1.0;
        qvMismatchWeight = 1.0;
        qvInsWeight = 1.0;
        qvDelWeight = 1.0;
        minFractionToBeConsideredOverlapping = 0.75;
        minRatio = 0.25;
        indelRate = 0.3;
        indel = 5;
        insertion = 4;  // asymmetric indel parameters
        deletion = 5;
        idsIndel = 15;
        sdpIndel = 5;
        sdpIns = 5;
        sdpDel = 10;
        sdpTupleSize = 11;
        match = 0;
        mismatch = 0;
        showAlign = 1;
        useScoreCutoff = false;
        maxScore = -200;
        argi = 1;
        nProc = 1;
        readsFileNames.clear();
        queryFileNames.clear();
        genomeFileName = "";
        queryReadType = ReadType::UNKNOWN;
        queryFileType = FileType::None;
        tupleListName = "";
        posTableName = "";
        suffixArrayFileName = "";
        bwtFileName = "";
        indexFileName = "";
        anchorFileName = "";
        outFileName = "";
        nBest = 10;
        nCandidates = 10;
        printWindow = 0;
        doCondense = 0;
        do4BitComp = 0;
        pValueType = 0;
        cutoff = 0;
        useSuffixArray = 0;
        useBwt = 0;
        useReverseCompressIndex = 0;
        useTupleList = 0;
        useSeqDB = 0;
        seqDBName = "";
        useCountTable = 0;
        countTableName = "";
        lookupTableLength = 8;
        anchorParameters.minMatchLength = minMatchLength = 12;
        printFormat = SummaryPrint;
        maxExpand = 0;
        minExpand = 0;
        startRead = 0;
        stride = 1;
        subsample = 1.1;
        listTupleSize = 6;
        sortRefinedAlignments = 1;
        anchorParameters.verbosity = verbosity = 0;
        saTupleMetrics.Initialize(listTupleSize);
        sdpTupleMetrics.Initialize(sdpTupleSize);
        qualityLowerCaseThreshold = 0;
        anchorParameters.branchQualityThreshold = 0;
        readsFileIndex = 0;
        printSAM = false;
        printBAM = false;
        sam_via_bam = false;
        useRandomSeed = false;
        randomSeed = 0;
        placeRandomly = false;
        placeGapConsistently = false;
        samplePaths = false;
        nowarp = false;
        storeMapQV = true;
        warp = true;
        extendDenovoCCSSubreads = false;
        storeMetrics = false;
        ignoreQualities = true;
        extendFrontAlignment = false;
        extendAlignments = false;
        maxExtendDropoff = 10;
        minReadLength = 50;
        maxReadLength = 0;  // means no max read length
        minSubreadLength = 0;
        minRawSubreadScore = -1;  // raw subread score in region table should be in range [0, 1000].
        minAvgQual = 0;
        overlap = false;
        advanceHalf = false;
        refineAlignments = true;
        anchorParameters.advanceExactMatches = advanceExactMatches = 0;
        approximateMaxInsertionRate = 1.30;
        minPctSimilarity = 0;
        minPctAccuracy = 0;
        doGlobalAlignment = false;
        tempDirectory = "";
        useTitleTable = false;
        titleTableName = "";
        readSeparateRegionTable = false;
        readSeparateCcsFofn = false;
        regionTableFileName = "";
        ccsFofnFileName = "";
        mapSubreadsSeparately = true;
        concordant = false;
        refineConcordantAlignments = false;
        flankSize = 40;
        useRegionTable = true;
        setIgnoreRegions = false;
        useHQRegionTable = true;
        setIgnoreHQRegions = false;
        printUnaligned = false;
        unalignedFileName = "";
        noPrintUnalignedSeqs = false;
        globalChainType = 0;
        metricsFileName = "";
        fullMetricsFileName = "";
        doSensitiveSearch = false;
        emulateNucmer = false;
        refineBetweenAnchorsOnly = false;
        printSubreadTitle = true;
        detailedSDPAlignment = true;
        nouseDetailedSDPAlignment = false;
        useCcs = false;
        useCcsOnly = false;
        useAllSubreadsInCcs = false;
        chunkSize = 10000000;
        sdpFilterType = 0;
        anchorParameters.stopMappingOnceUnique = true;
        useGuidedAlign = true;
        bandSize = 0;
        extendBandSize = 10;
        guidedAlignBandSize = 10;
        useQVScore = false;
        printVerboseHelp = false;
        sdpBypassThreshold = 1000000.0;
        scoreType = 0;
        byAdapter = false;
        qvScaleType = PHRED;
        printHeader = false;
        computeAlignProbability = false;
        readAccuracyPrior = 0.85;
        printVersion = false;
        clipping = SAMOutput::none;
        clippingString = "";
        substitutionPrior = 20;
        globalDeletionPrior = 13;
        outputByThread = false;
        recurseOver = 10000;
        allowAdjacentIndels = false;
        separateGaps = false;
        scoreMatrixString = "";
        printDotPlots = false;
        preserveReadTitle = false;
        forwardOnly = false;
        printOnlyBest = false;
        affineAlign = false;
        affineExtend = 0;
        affineOpen = 10;
        scaleMapQVByNumSignificantClusters = false;
        limsAlign = 0;
        holeNumberRangesStr = "";
        minAlnLength = 0;
        printSAMQV = false;
        cigarUseSeqMatch = false;
        samQV.clear();
        samQVList.clear();
        fastMaxInterval = false;
        aggressiveIntervalCut = false;
        fastSDP = false;
        concordantTemplate = "mediansubread";  // typicalsubread or longestsubread
        concordantAlignBothDirections = false;

        hitPolicyStr = "all";
        ResetFilterAndHit();
        enableHiddenPaths = false;  //turn off hidden paths.

        polymeraseMode = false;
    }

    MappingParameters()
        : filterCriteria(0, 0, 0, false, Score(0, ScoreSign::NEGATIVE))
        , hitPolicy("all", ScoreSign::NEGATIVE)
    {
        Init();
    }

    void MakeSane()
    {
        if (polymeraseMode && mapSubreadsSeparately) {
            std::cout << "ERROR, --polymerase can only be used with --noSplitSubreads."
                      << std::endl;
            std::exit(EXIT_FAILURE);
        }
        // Expand FOFN
        FileOfFileNames::ExpandFileNameList(readsFileNames);

        // Must have at least a query and a genome
        if (readsFileNames.size() <= 1) {
            std::cout << "Error, you must provide at least one reads file and a genome file."
                      << std::endl;
            std::exit(EXIT_FAILURE);
        }

        // Separate query reads files and a genome read file
        // The last reads file is the genome
        queryFileNames = readsFileNames;
        queryFileNames.pop_back();
        genomeFileName = readsFileNames.back();

        // Check query file type.
        BaseSequenceIO::DetermineFileTypeByExtension(queryFileNames[0], queryFileType);
        for (size_t i = 1; i < queryFileNames.size(); i++) {
            FileType fileType;
            BaseSequenceIO::DetermineFileTypeByExtension(queryFileNames[i], fileType);
            if (fileType != queryFileType) {
                std::cout << "ERROR, mixed query file types is not allowed." << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }

        // if unrolled(Polymerase) read mode, and extension is .bam, need to derive scraps file name
        // rules
        // 1. string.subreads.bam -> string.scraps.bam substitute subreads to scraps
        // 2. string.bam ->  string.scraps.bam   insert .scraps before .bam
        // TODO loop over query check for each
        // not needed for xml since scraps specified explicetely
        //
        if (not mapSubreadsSeparately && (queryFileType == FileType::PBBAM)) {
            const std::string dsubdb = ".subreads.bam";
            const std::string dbam = ".bam";
            // loop over all subread files and fill the vector or scraps files
            for (size_t i = 0; i < queryFileNames.size(); i++) {
                scrapsFileNames.push_back(queryFileNames[i]);
                size_t dsubdb_pos = scrapsFileNames[i].find(dsubdb);  // find .subreads.bam
                if (dsubdb_pos != std::string::npos) {
                    // TODO check that .subreads.bam is LAST occurence
                    // replace subreads.bam with scraps.bam
                    scrapsFileNames[i].replace(dsubdb_pos, dsubdb.length(), ".scraps.bam");
                } else {
                    // insert scraps before .bam"
                    // actually we can just replace last 4 characters
                    // fix later
                    size_t dbam_pos = scrapsFileNames[0].find(dbam);  // find .bam
                    scrapsFileNames[i].replace(dbam_pos, dbam.length(), ".scraps.bam");
                }
            }
        }

        // -useQuality can not be used in combination with a fasta input
        if (!ignoreQualities) {
            if (queryFileType == FileType::Fasta) {
                std::cout
                    << "ERROR, you can not use -useQuality option when any of the input reads "
                       "files are in multi-fasta format."
                    << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }

        //
        // Fix all logical incompatibilities with parameters.
        //
        if (setIgnoreRegions) {
            useRegionTable = false;
        }
        if (setIgnoreHQRegions) {
            useHQRegionTable = false;
        }

        if (nowarp) {
            warp = false;
        }

        if (nCandidates < nBest) {
            std::cerr << "Warning: resetting nCandidates to nBest " << nBest << std::endl;
            nCandidates = nBest;
        }

        if (placeRandomly and hitPolicyStr != "randombest") {
            std::cerr << "Warning: placeRepeatsRandomly is deprecated, resetting hit policy to "
                         "randombest."
                      << std::endl;
            hitPolicyStr = "randombest";
        }

        if (placeGapConsistently) {
            if (refineBetweenAnchorsOnly) {
                std::cout << "ERROR, rbao and placeGapConsistently cannot be set at the same time."
                          << std::endl;
                std::exit(EXIT_FAILURE);
            }
            if (extendAlignments) {
                std::cout
                    << "ERROR, extend and placeGapConsistently cannot be set at the same time."
                    << std::endl;
                std::exit(EXIT_FAILURE);
            }
            if (not useGuidedAlign) {
                std::cout
                    << "ERROR, noUseGuidedAlign and placeGapConsistently cannot be set the same "
                       "time."
                    << std::endl;
                std::exit(EXIT_FAILURE);
            }
            if (affineAlign) {
                std::cout
                    << "ERROR, affineAlign and placeGapConsistently cannot be set the same time."
                    << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }

        if ((hitPolicyStr == "random" or hitPolicyStr == "randombest") and nBest == 1) {
            std::cerr << "Warning: When attempting to select equivalently scoring reads at random "
                      << std::endl
                      << "the bestn parameter should be greater than one." << std::endl;
        }

        if (concordant) {
            if (useCcs) {
                concordant = false;
            } else {
                useRegionTable = true;
                useHQRegionTable = true;
            }
            if (concordantTemplate != "longestsubread" and
                concordantTemplate != "typicalsubread" and concordantTemplate != "mediansubread") {
                std::cout << "ERROR, unsupported concordantTemplate: " << concordantTemplate
                          << std::endl;
                std::exit(EXIT_FAILURE);
            }
            if (refineConcordantAlignments) {
                refineAlignments = true;
            }
        }

        if (sdpFilterType > 1) {
            std::cerr << "Warning: using new filter method for SDP alignments.  The parameter is "
                      << std::endl
                      << "either 0 or 1, but " << sdpFilterType << " was specified." << std::endl;
            sdpFilterType = 1;
        }
        if (sdpFilterType == 0) {
            detailedSDPAlignment = true;
            nouseDetailedSDPAlignment = false;
        }
        if (detailedSDPAlignment == false) {
            sdpFilterType = 1;
        }
        if (useGuidedAlign == true and bandSize == 0) {
            bandSize = 16;
        }
        anchorParameters.minMatchLength = minMatchLength;
        if (suffixArrayFileName != "") {
            useSuffixArray = true;
        }
        if (bwtFileName != "") {
            useBwt = true;
        }
        if (useBwt and useSuffixArray) {
            std::cout << "ERROR, sa and bwt must be used independently." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (countTableName != "") {
            useCountTable = true;
        }
        if (metricsFileName != "" or fullMetricsFileName != "") {
            storeMetrics = true;
        }
        if (useCcsOnly) {
            useCcs = true;
        }
        if (useAllSubreadsInCcs == true) {
            useCcs = true;
        }
        if (titleTableName != "") {
            useTitleTable = true;
        }
        if (unalignedFileName != "") {
            printUnaligned = true;
        }
        if (regionTableFileName != "") {
            useRegionTable = true;
            readSeparateRegionTable = true;
        }

        bool isHDFFile =
            (queryFileType == FileType::HDFPulse or queryFileType == FileType::HDFBase or
             queryFileType == FileType::HDFCCSONLY);
        if ((setIgnoreRegions or setIgnoreHQRegions) and not isHDFFile) {
            std::cout << "ERROR: query must be HDF files in order to set ignoreRegions or "
                         "ignoreHQRegions."
                      << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (ccsFofnFileName != "") {
            readSeparateCcsFofn = true;
        }
        if (nouseDetailedSDPAlignment == true) {
            detailedSDPAlignment = false;
        }
        if (nouseDetailedSDPAlignment == false) {
            detailedSDPAlignment = true;
        }
        if (anchorParameters.maxLCPLength != 0 and
            int(anchorParameters.maxLCPLength) < int(anchorParameters.minMatchLength)) {
            std::cerr
                << "ERROR: maxLCPLength is less than minLCPLength, which will result in no hits."
                << std::endl;
        }
        if (subsample < 1 and stride > 1) {
            std::cout << "ERROR, subsample and stride must be used independently." << std::endl;
            std::exit(EXIT_FAILURE);
        }

        if (emulateNucmer) {
            SetEmulateNucmer();
        }

        if (randomSeed != 0) {
            useRandomSeed = true;
        }
        //
        // Parse the clipping.
        //
        if (clippingString == "soft") {
            clipping = SAMOutput::soft;
        } else if (clippingString == "hard") {
            clipping = SAMOutput::hard;
        } else if (clippingString == "none") {
            clipping = SAMOutput::none;
        } else if (clippingString == "subread") {
            clipping = SAMOutput::subread;
        } else if (clippingString != "") {
            std::cout << "ERROR, clipping should either be soft, hard, or none." << std::endl;
            std::exit(EXIT_FAILURE);
        }

        if (printSAM) {  // since sam is printed via bam we need to use ifndef USE_PBBAM here
#ifndef USE_PBBAM
            REQUIRE_PBBAM_ERROR();
#else
            printSAM = false;
            printBAM = true;
            sam_via_bam = true;  // set to true for constructors and to avoid entering if (printBAM
            cigarUseSeqMatch = true;  // ALWAYS true for BAM
            printFormat = BAM;        // Not sure for sam_via_bam
            samQVList.SetDefaultQV();
            printSAMQV = true;
            if (clipping != SAMOutput::soft) {
                // Only support two clipping methods: soft or subread.
                clipping = SAMOutput::subread;
            }
            // Turn on fa fa -> sam pipe
            /*
            if (queryFileType != FileType::PBBAM and queryFileType != FileType::PBDATASET and not enableHiddenPaths) {
                // bax|fasta|fastq -> bam paths are turned off by default
                std::cout << "ERROR, could not output alignments in BAM unless input reads are in PacBio BAM or DATASET files." << std::endl;
                std::exit(EXIT_FAILURE);
            }
            */

            if (outFileName == "") {
                std::cout << "ERROR, SAM output file must be specified." << std::endl;
                std::exit(EXIT_FAILURE);
            }
            // VR Need to see what happens if printing SAM
            // VR Check with Derek regarding sam_via_bam
            if (outputByThread) {
                std::cout << "ERROR, could not output alignments by threads in BAM format."
                          << std::endl;
                std::exit(EXIT_FAILURE);
            }
#endif
        }

        if (printBAM && !sam_via_bam) {  // Need to check settings for SAM,
#ifndef USE_PBBAM
            REQUIRE_PBBAM_ERROR();
#else
            cigarUseSeqMatch = true;  // ALWAYS true for BAM
            printFormat = BAM;
            printSAM = false;
            samQVList.SetDefaultQV();
            printSAMQV = true;
            if (clipping != SAMOutput::soft) {
                // Only support two clipping methods: soft or subread.
                clipping = SAMOutput::subread;
            }
            if (queryFileType != FileType::PBBAM and queryFileType != FileType::PBDATASET and
                queryFileType != FileType::HDFCCS and queryFileType != FileType::HDFBase and
                queryFileType != FileType::HDFPulse) {
                // fasta|fastq -> bam paths are turned off by default
                std::cout << "WARNING, BAM output without PacBio BAM or DATASET input is not "
                             "supported by PacBio."
                          << std::endl;
            }
            if (outFileName == "") {
                std::cout << "ERROR, BAM output file must be specified." << std::endl;
                std::exit(EXIT_FAILURE);
            }
            // VR Need to see what happens if printing SAM
            // VR Check with Derek regarding sam_via_bam
            if (outputByThread) {
                std::cout << "ERROR, could not output alignments by threads in BAM format."
                          << std::endl;
                std::exit(EXIT_FAILURE);
            }
#endif
        }

        if (limsAlign != 0) {
            mapSubreadsSeparately = false;
            forwardOnly = true;
        }

        if (holeNumberRangesStr.size() > 0) {
            if (not holeNumberRanges.setRanges(holeNumberRangesStr)) {
                std::cout << "ERROR, could not parse hole number ranges: " << holeNumberRangesStr
                          << "." << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }

        if (printSAMQV) {
            if (samQV.size() == 0) {
                samQVList.SetDefaultQV();
            } else {
                samQVList.UseQV(samQV);
            }
        }

        if (minRawSubreadScore > 1000) {
            std::cout << "ERROR, minimum raw subread score should be less than 1000." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (minRawSubreadScore != -1 and byAdapter) {
            std::cout << "ERROR, minRawSubreadScore and byAdapter should not be used together."
                      << std::endl;
            std::exit(EXIT_FAILURE);
        }
        // Determine query read type
        queryReadType = DetermineQueryReadType();
        // Pass verbosity
        anchorParameters.verbosity = verbosity;

        // Set filter criteria and hit policy
        ResetFilterAndHit();
    }
    void ResetFilterAndHit(void)
    {
        filterCriteria = FilterCriteria(minAlnLength, minPctSimilarity, minPctAccuracy, true,
                                        Score(static_cast<float>(maxScore), ScoreSign::NEGATIVE));
        hitPolicy = HitPolicy(hitPolicyStr, ScoreSign::NEGATIVE);
    }

    ReadType::ReadTypeEnum DetermineQueryReadType()
    {
        if (useCcsOnly or queryFileType == FileType::HDFCCSONLY) {
            return ReadType::CCS;
        }
        if (queryFileType == FileType::PBBAM) {
            if (not mapSubreadsSeparately) {
                // specifal case: blasr subread.bam ref.fa --noSplitSubreads
                // input type seems like subread while infact is polymerase
                return ReadType::POLYMERASE;
            }
            // Read type in BAM may be CCS, SUBREAD, HQREGION or POLYMERASE.
            // Determine it later.
            return ReadType::UNKNOWN;
        }
        if (mapSubreadsSeparately) {
            return ReadType::SUBREAD;
        } else {
            if (useHQRegionTable and
                (queryFileType == FileType::HDFCCSONLY or queryFileType == FileType::HDFBase or
                 queryFileType == FileType::HDFPulse)) {
                // Only HDF files can contain region table.
                return ReadType::HQREGION;
            } else {
                return ReadType::POLYMERASE;
            }
        }
    }

    void SetEmulateNucmer()
    {
        anchorParameters.stopMappingOnceUnique = true;
        anchorParameters.advanceExactMatches = 30;
        anchorParameters.maxAnchorsPerPosition = 1;
        sdpBypassThreshold = 0.75;
        sdpTupleSize = 15;
        anchorParameters.minMatchLength = 30;
        useGuidedAlign = true;
        refineAlignments = false;
    }

    void SetForSensitivity()
    {
        advanceExactMatches = 0;
        anchorParameters.numBranches = 1;
        anchorParameters.maxAnchorsPerPosition = 10000;
    }
};
