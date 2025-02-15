//==================================================================//
/*
    AtomicParsley - AtomDefs.h

    AtomicParsley is GPL software; you can freely distribute, 
    redistribute, modify & use under the terms of the GNU General
    Public License; either version 2 or its successor.

    AtomicParsley is distributed under the GPL "AS IS", without
    any warranty; without the implied warranty of merchantability
    or fitness for either an expressed or implied particular purpose.

    Please see the included GNU General Public License (GPL) for 
    your rights and further details; see the file COPYING. If you
    cannot, write to the Free Software Foundation, 59 Temple Place
    Suite 330, Boston, MA 02111-1307, USA.  Or www.fsf.org

    Copyright �2006-2007 puck_lock
    with contributions from others; see the CREDITS file
																																		*/
//==================================================================//

#include "AtomicParsley.h"

atomDefinition KnownAtoms[] = {
	//name		parent atom(s)			container					number								box_type
	{"<()>",	{"_ANY_LEVEL"},	    UNKNOWN_ATOM_TYPE, UKNOWN_REQUIREMENTS,	UNKNOWN_ATOM },      //our unknown atom (self-defined)
	
	{"ftyp",	{"FILE_LEVEL"},			CHILD_ATOM,				REQUIRED_ONCE,				SIMPLE_ATOM },

	{"moov",	{"FILE_LEVEL"},			PARENT_ATOM,			REQUIRED_ONCE,				SIMPLE_ATOM },

	{"mdat",	{"FILE_LEVEL"},			CHILD_ATOM,				OPTIONAL_MANY,				SIMPLE_ATOM },

	{"pdin",	{"FILE_LEVEL"},			CHILD_ATOM,				OPTIONAL_ONCE,				VERSIONED_ATOM },			

	{"moof",	{"FILE_LEVEL"},			PARENT_ATOM,			OPTIONAL_MANY,				SIMPLE_ATOM },
	{"mfhd",	{"moof"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },
	{"traf",	{"moof"},						PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },
	{"tfhd",	{"traf"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },
	{"trun",	{"traf"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },

	{"mfra",	{"FILE_LEVEL"},			PARENT_ATOM,			OPTIONAL_ONCE,				SIMPLE_ATOM },
	{"tfra",	{"mfra"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"mfro",	{"mfra"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },

	{"free",	{"_ANY_LEVEL"},			CHILD_ATOM,				OPTIONAL_MANY,				SIMPLE_ATOM },
	{"skip",	{"_ANY_LEVEL"},			CHILD_ATOM,				OPTIONAL_MANY,				SIMPLE_ATOM },

	{"uuid",	{"_ANY_LEVEL"},			CHILD_ATOM,				REQUIRED_ONCE,				EXTENDED_ATOM },			

	{"mvhd",	{"moov"},						CHILD_ATOM,				REQUIRED_ONCE,				VERSIONED_ATOM },			
	{"iods",	{"moov"},						CHILD_ATOM,				OPTIONAL_ONCE,				VERSIONED_ATOM },
	{"drm ",	{"moov"},						CHILD_ATOM,				OPTIONAL_ONCE,				VERSIONED_ATOM },     // 3gp/MobileMP4
	{"trak",	{"moov"},						PARENT_ATOM,			OPTIONAL_MANY,				SIMPLE_ATOM },
	
	{"tkhd",	{"trak"},						CHILD_ATOM,				OPTIONAL_MANY,				VERSIONED_ATOM },
	{"tref",	{"trak"},						PARENT_ATOM,			OPTIONAL_MANY,				SIMPLE_ATOM },
	{"mdia",	{"trak"},						PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },
	
	{"tapt",	{"trak"},						PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },
	{"clef",	{"tapt"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"prof",	{"tapt"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"enof",	{"tapt"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },

	{"mdhd",	{"mdia"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"minf",	{"mdia"},						PARENT_ATOM,			REQUIRED_ONE,					SIMPLE_ATOM },

	{"hdlr",	{"mdia", "meta", "minf"},	CHILD_ATOM, REQUIRED_ONE,					VERSIONED_ATOM },     //minf parent present in chapterized

	{"vmhd",	{"minf"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"smhd",	{"minf"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"hmhd",	{"minf"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"nmhd",	{"minf"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"gmhd",	{"minf"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },     //present in chapterized

	{"dinf",	{"minf", "meta"},		PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },        //required in minf

	{"dref",	{"dinf"},						DUAL_STATE_ATOM,	REQUIRED_ONE,					VERSIONED_ATOM },

	{"url ",	{"dref"},						CHILD_ATOM,				OPTIONAL_MANY,			  VERSIONED_ATOM },
	{"urn ",	{"dref"},						CHILD_ATOM,				OPTIONAL_MANY,		  	VERSIONED_ATOM },
	{"alis",	{"dref"},						CHILD_ATOM,				OPTIONAL_MANY,		  	VERSIONED_ATOM },
	{"cios",	{"dref"},						CHILD_ATOM,				OPTIONAL_MANY,		  	VERSIONED_ATOM },

	{"stbl",	{"minf"},						PARENT_ATOM,			REQUIRED_ONE,					SIMPLE_ATOM },
	{"stts",	{"stbl"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },
	{"ctts",	{"stbl"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"stsd",	{"stbl"},						DUAL_STATE_ATOM,	REQUIRED_ONE,					VERSIONED_ATOM },

	{"stsz",	{"stbl"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"stz2",	{"stbl"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },

	{"stsc",	{"stbl"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },

	{"stco",	{"stbl"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"co64",	{"stbl"},						CHILD_ATOM,				REQ_FAMILIAL_ONE,			VERSIONED_ATOM },

	{"stss",	{"stbl"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"stsh",	{"stbl"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"stdp",	{"stbl"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"padb",	{"stbl"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"sdtp",	{"stbl", "traf"},		CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"sbgp",	{"stbl", "traf"},		CHILD_ATOM,				OPTIONAL_MANY,				VERSIONED_ATOM },
	{"sbgp",	{"stbl"},						CHILD_ATOM,				OPTIONAL_MANY,				VERSIONED_ATOM },
	{"stps",	{"stbl"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },

	{"edts",	{"trak"},						PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },
	{"elst",	{"edts"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },

	{"udta",	{"moov", "trak"},		PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },

	{"meta",	{"FILE_LEVEL", "moov", "trak", "udta"},	DUAL_STATE_ATOM, OPTIONAL_ONE, VERSIONED_ATOM },			//optionally contains info

	{"mvex",	{"moov"},						PARENT_ATOM,			OPTIONAL_ONCE,				SIMPLE_ATOM },
	{"mehd",	{"mvex"},						CHILD_ATOM,				OPTIONAL_ONCE,				VERSIONED_ATOM },
	{"trex",	{"mvex"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },

	//{"stsl",	{"????"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },				//contained by a sample entry box
	{"subs",	{"stbl", "traf"},		CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },

	{"xml ",	{"meta"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"bxml",	{"meta"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"iloc",	{"meta"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"pitm",	{"meta"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"ipro",	{"meta"},						PARENT_ATOM,			OPTIONAL_ONE,					VERSIONED_ATOM },
	{"iinf",	{"meta"},						DUAL_STATE_ATOM,	OPTIONAL_ONE,					VERSIONED_ATOM },
	{"infe",	{"iinf"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },

	{"sinf",	{"ipro", "drms", "drmi"}, PARENT_ATOM,			REQUIRED_ONE,					SIMPLE_ATOM },    //parent atom is also "Protected Sample Entry"
	{"frma",	{"sinf"},						CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"imif",	{"sinf"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"schm",	{"sinf", "srpp"},		CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"schi",	{"sinf", "srpp"},		DUAL_STATE_ATOM,	OPTIONAL_ONE,					SIMPLE_ATOM },
	{"skcr",	{"sinf"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	
	{"user",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"key ",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },    //could be required in 'drms'/'drmi'
	{"iviv",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"righ",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"name",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"priv",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	
	{"iKMS",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },     // 'iAEC', '264b', 'iOMA', 'ICSD'
	{"iSFM",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },
	{"iSLT",	{"schi"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //boxes with 'k***' are also here; reserved
	{"IKEY",	{"tref"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"hint",	{"tref"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"dpnd",	{"tref"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"ipir",	{"tref"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"mpod",	{"tref"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"sync",	{"tref"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"chap",	{"tref"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //?possible versioned?

	{"ipmc",	{"moov", "meta"},		CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },

	{"tims",	{"rtp "},						CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"tsro",	{"rtp "},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"snro",	{"rtp "},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },

	{"srpp",	{"srtp"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },

	{"hnti",	{"udta"},						PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },
	{"rtp ",	{"hnti"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //'rtp ' is defined twice in different containers
	{"sdp ",	{"hnti"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },

	{"hinf",	{"udta"},						PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },
	{"name",	{"udta"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"trpy",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"nump",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"tpyl",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"totl",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"npck",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"maxr",	{"hinf"},						CHILD_ATOM,				OPTIONAL_MANY,				SIMPLE_ATOM },
	{"dmed",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"dimm",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"drep",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"tmin",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"tmax",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"pmax",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"dmax",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"payt",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"tpay",	{"hinf"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },

	{"drms",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"drmi",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"alac",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"mp4a",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"mp4s",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"mp4v",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"avc1",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"avcp",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"text",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"jpeg",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"tx3g",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"rtp ",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },     //"rtp " occurs twice; disparate meanings
	{"srtp",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			SIMPLE_ATOM },
	{"enca",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"encv",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"enct",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"encs",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"samr",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"sawb",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"sawp",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"s263",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"sevc",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"sqcp",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"ssmv",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"tmcd",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },
	{"mjp2",	{"stsd"},						DUAL_STATE_ATOM,	REQ_FAMILIAL_ONE,			VERSIONED_ATOM },     //mjpeg2000

	{"alac",	{"alac"},						CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"avcC",	{"avc1", "drmi"},		CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"damr",	{"samr", "sawb"},		CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"d263",	{"s263"},						CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"dawp",	{"sawp"},		        CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"devc",	{"sevc"},		        CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"dqcp",	{"sqcp"},		        CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"dsmv",	{"ssmv"},		        CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"bitr",	{"d263"},						CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },
	{"btrt",	{"avc1"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //found in NeroAVC
	{"m4ds",	{"avc1"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //?possible versioned?
	{"ftab",	{"tx3g"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },
	{"jp2h",	{"mjp2"},						PARENT_ATOM,			OPTIONAL_ONE,					SIMPLE_ATOM },        //mjpeg2000
	
	{"ihdr",	{"jp2h"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //mjpeg2000
	{"colr",	{"jp2h"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },     //mjpeg2000
	{"fiel",	{"mjp2"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //mjpeg2000
	{"jp2p",	{"mjp2"},						CHILD_ATOM,				OPTIONAL_ONE,					VERSIONED_ATOM },     //mjpeg2000
	{"jsub",	{"mjp2"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //mjpeg2000
	{"orfo",	{"mjp2"},						CHILD_ATOM,				OPTIONAL_ONE,					SIMPLE_ATOM },        //mjpeg2000

	{"cprt",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },     //the only ISO defined metadata tag; also a 3gp asset
	{"titl",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },     //3gp assets
	{"auth",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	{"perf",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	{"gnre",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	{"dscp",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	{"albm",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	{"yrrc",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				VERSIONED_ATOM },
	{"rtng",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	{"clsf",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	{"kywd",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	{"loci",	{"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },
	
	{"ID32",	{"meta"},						CHILD_ATOM,				OPTIONAL_MANY,				PACKED_LANG_ATOM },     //id3v2 tag
	{"tsel",  {"udta"},						CHILD_ATOM,				OPTIONAL_MANY,				SIMPLE_ATOM },        //but only at track level in a 3gp file

	//{"chpl",	{"udta"},						CHILD_ATOM,				OPTIONAL_ONCE,				VERSIONED_ATOM },		//Nero - seems to be versioned
	//{"ndrm",	{"udta"},						CHILD_ATOM,				OPTIONAL_ONCE,				VERSIONED_ATOM },		//Nero - seems to be versioned
	//{"tags",	{"udta"},						CHILD_ATOM,				OPTIONAL_ONCE,				SIMPLE_ATOM },			//Another Nero-Creation�
																																															// ...so if they claim that "tags doesn't have any children",
																																															// why does nerotags.exe say "tshd atom"? If 'tags' doesn't
																																															// have any children, then tshd can't be an atom....
																																															// Clearly, they are EternallyRight� and everyone else is
																																															// always wrong.
																																															
																																															//Pish! Seems that Nero is simply unable to register any atoms.

	{"ilst",	{"meta"},						PARENT_ATOM,			OPTIONAL_ONCE,				SIMPLE_ATOM },        //iTunes metadata container
	{"----",	{"ilst"},						PARENT_ATOM,			OPTIONAL_MANY,				SIMPLE_ATOM },        //reverse dns metadata
	{"mean",	{"----"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },
	{"name",	{"----"},						CHILD_ATOM,				REQUIRED_ONE,					VERSIONED_ATOM },
	
	{".><.",	{"dref"},						CHILD_ATOM,				OPTIONAL_MANY,		  	VERSIONED_ATOM },      //support any future named child to dref; keep 4th from end; manual return

	{"esds",	{"SAMPLE_DESC"},		CHILD_ATOM,				REQUIRED_ONE,					SIMPLE_ATOM },         //multiple parents; keep 3rd from end; manual return

	{"(..)",	{"ilst"},						PARENT_ATOM,		  OPTIONAL_ONE,			    SIMPLE_ATOM },         //multiple parents; keep 2nd from end; manual return
	{"data",	{"ITUNES_METADATA"},	CHILD_ATOM,			PARENT_SPECIFIC,			VERSIONED_ATOM }       //multiple parents
	
};

