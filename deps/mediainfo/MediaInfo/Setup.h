/*  Copyright (c) MediaArea.net SARL. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license that can
 *  be found in the License.html file in the root of the source tree.
 */

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// All compilation definitions
// Helpers for compilers (precompilation)
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//---------------------------------------------------------------------------
#ifndef MediaInfo_SetupH
#define MediaInfo_SetupH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Needed in the whole library
#include "ZenLib/Conf.h"

//***************************************************************************
// General configuration
//***************************************************************************



//---------------------------------------------------------------------------
// Optional features
#define MEDIAINFO_TRACE 1
#define MEDIAINFO_FILTER 0
#define MEDIAINFO_DUPLICATE 0
#define MEDIAINFO_MACROBLOCKS 1
#define MEDIAINFO_NEXTPACKET 1
#define MEDIAINFO_SEEK 1
#define MEDIAINFO_EVENTS 1
#define MEDIAINFO_ADVANCED 1
#define MEDIAINFO_MD5 1
#define MEDIAINFO_DEMUX 1
#define MEDIAINFO_IBI 1

//***************************************************************************
// Precise configuration
//***************************************************************************

//---------------------------------------------------------------------------
// Readers
#define MEDIAINFO_FILE_YES

//---------------------------------------------------------------------------
// Multiple
#define MEDIAINFO_REFERENCES_YES
#define MEDIAINFO_ANCILLARY_YES
#define MEDIAINFO_BDAV_YES
#define MEDIAINFO_BDMV_YES
#define MEDIAINFO_CDXA_YES
#define MEDIAINFO_DASHMPD_YES
#define MEDIAINFO_DCP_YES
#define MEDIAINFO_DVDIF_YES
#define MEDIAINFO_DVDIF_ANALYZE_YES
#define MEDIAINFO_DVDV_YES
#define MEDIAINFO_DXW_YES
#define MEDIAINFO_FLV_YES
#define MEDIAINFO_GXF_YES
#define MEDIAINFO_HDSF4M_YES
#define MEDIAINFO_HLS_YES
#define MEDIAINFO_ISM_YES
#define MEDIAINFO_IVF_YES
#define MEDIAINFO_IBI_YES
#define MEDIAINFO_LXF_YES
#define MEDIAINFO_MK_YES
#define MEDIAINFO_MPEG4_YES
#define MEDIAINFO_MPEGPS_YES
#define MEDIAINFO_MPEGTS_YES
#define MEDIAINFO_MPEGTS_PCR_YES
#define MEDIAINFO_MPEGTS_PESTIMESTAMP_YES
#define MEDIAINFO_MPEGTS_DUPLICATE_YES
#define MEDIAINFO_MXF_YES
#define MEDIAINFO_NUT_YES
#define MEDIAINFO_OGG_YES
#define MEDIAINFO_P2_YES
#define MEDIAINFO_PMP_YES
#define MEDIAINFO_RIFF_YES
#define MEDIAINFO_RM_YES
#define MEDIAINFO_SEQUENCEINFO_YES
#define MEDIAINFO_SKM_YES
#define MEDIAINFO_SWF_YES
#define MEDIAINFO_TSP_YES
#define MEDIAINFO_UMF_YES
#define MEDIAINFO_WM_YES
#define MEDIAINFO_XDCAM_YES
#define MEDIAINFO_DPG_YES

//---------------------------------------------------------------------------
// Video
#define MEDIAINFO_AIC_YES
#define MEDIAINFO_AFDBARDATA_YES
#define MEDIAINFO_AVC_YES
#define MEDIAINFO_AVSV_YES
#define MEDIAINFO_CANOPUS_YES
#define MEDIAINFO_DIRAC_YES
#define MEDIAINFO_FLIC_YES
#define MEDIAINFO_FRAPS_YES
#define MEDIAINFO_H263_YES
#define MEDIAINFO_HEVC_YES
#define MEDIAINFO_LAGARITH_YES
#define MEDIAINFO_MPEG4V_YES
#define MEDIAINFO_MPEGV_YES
#define MEDIAINFO_PRORES_YES
#define MEDIAINFO_VC1_YES
#define MEDIAINFO_VC3_YES
#define MEDIAINFO_TIMECODE_YES
#define MEDIAINFO_THEORA_YES
#define MEDIAINFO_VP8_YES
#define MEDIAINFO_Y4M_YES

//---------------------------------------------------------------------------
// Audio
#define MEDIAINFO_AAC_YES
#define MEDIAINFO_AC3_YES
#define MEDIAINFO_ADPCM_YES
#define MEDIAINFO_ALS_YES
#define MEDIAINFO_LATM_YES
#define MEDIAINFO_AMR_YES
#define MEDIAINFO_AMV_YES
#define MEDIAINFO_APE_YES
#define MEDIAINFO_AU_YES
#define MEDIAINFO_CELT_YES
#define MEDIAINFO_DOLBYE_YES
#define MEDIAINFO_DTS_YES
#define MEDIAINFO_FLAC_YES
#define MEDIAINFO_IT_YES
#define MEDIAINFO_LA_YES
#define MEDIAINFO_MIDI_YES
#define MEDIAINFO_MOD_YES
#define MEDIAINFO_MPC_YES
#define MEDIAINFO_MPCSV8_YES
#define MEDIAINFO_MPEGA_YES
#define MEDIAINFO_OPUS_YES
#define MEDIAINFO_PCM_YES
#define MEDIAINFO_PCMM2TS_YES
#define MEDIAINFO_PCMVOB_YES
#define MEDIAINFO_PS2A_YES
#define MEDIAINFO_RKAU_YES
#define MEDIAINFO_S3M_YES
#define MEDIAINFO_SPEEX_YES
#define MEDIAINFO_SMPTEST0302_YES
#define MEDIAINFO_SMPTEST0331_YES
#define MEDIAINFO_SMPTEST0337_YES
#define MEDIAINFO_TAK_YES
#define MEDIAINFO_TTA_YES
#define MEDIAINFO_TWINVQ_YES
#define MEDIAINFO_VORBIS_YES
#define MEDIAINFO_WVPK_YES
#define MEDIAINFO_XM_YES

//---------------------------------------------------------------------------
// Text
#define MEDIAINFO_ARIBSTDB24B37_YES
#define MEDIAINFO_CDP_YES
#define MEDIAINFO_CMML_YES
#define MEDIAINFO_DVBSUBTITLE_YES
#define MEDIAINFO_DTVCCTRANSPORT_YES
#define MEDIAINFO_EIA608_YES
#define MEDIAINFO_EIA708_YES
#define MEDIAINFO_N19_YES
#define MEDIAINFO_KATE_YES
#define MEDIAINFO_PGS_YES
#define MEDIAINFO_SCC_YES
#define MEDIAINFO_SCTE20_YES
#define MEDIAINFO_SUBRIP_YES
#define MEDIAINFO_TELETEXT_YES
#define MEDIAINFO_TIMEDTEXT_YES
#define MEDIAINFO_TTML_YES
#define MEDIAINFO_OTHERTEXT_YES

//---------------------------------------------------------------------------
// Image
#define MEDIAINFO_BMP_YES
#define MEDIAINFO_DPX_YES
#define MEDIAINFO_EXR_YES
#define MEDIAINFO_GIF_YES
#define MEDIAINFO_ICO_YES
#define MEDIAINFO_JPEG_YES
#define MEDIAINFO_PCX_YES
#define MEDIAINFO_PNG_YES
#define MEDIAINFO_PSD_YES
#define MEDIAINFO_RLE_YES
#define MEDIAINFO_TIFF_YES
#define MEDIAINFO_TGA_YES

//---------------------------------------------------------------------------
// Archive
#define MEDIAINFO_7Z_YES
#define MEDIAINFO_ACE_YES
#define MEDIAINFO_BZIP2_YES
#define MEDIAINFO_ELF_YES
#define MEDIAINFO_GZIP_YES
#define MEDIAINFO_ISO9660_YES
#define MEDIAINFO_MZ_YES
#define MEDIAINFO_RAR_YES
#define MEDIAINFO_TAR_YES
#define MEDIAINFO_ZIP_YES

//---------------------------------------------------------------------------
// Tag
#define MEDIAINFO_TAG_YES
#define MEDIAINFO_APETAG_YES
#define MEDIAINFO_ID3_YES
#define MEDIAINFO_ID3V2_YES
#define MEDIAINFO_LYRICS3_YES
#define MEDIAINFO_LYRICS3V2_YES
#define MEDIAINFO_VORBISCOM_YES

//---------------------------------------------------------------------------
// Other
#define MEDIAINFO_OTHER_YES
#define MEDIAINFO_UNKNOWN_YES





#endif
