/*****************************************************************************

    Module      tvGetStr.C
                The function that looks up the ToolVox error strings.

    Copyright 1996 Voxware, Inc.

*****************************************************************************/



#if _DEBUG_MESSAGES || _DEBUG

#ifndef __TVGETSTR_C_
#define __TVGETSTR_C_

#if defined( WIN32 )
	#define VOXWARE_WIN32
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "toolvox.h"


#if defined (VOXWARE_WIN16) || defined(VOXWARE_WIN32)
    #include "Windows.h"
#endif

#include <stdio.h>
#include "tvgetstr.h"



/*

The following code shows a sample of calling the routine to get the error string.
A sample call would be:

DebugErrorMessage(wVoxwareError, dwReturnCode, __FILE__, __LINE__);


void DebugErrorMessage(VOXWARE_RETCODE wVoxwareError, signed long dwReturnCode,
                       unsigned char VOX_FAR *lpFilename, unsigned short wLineNumber)
{
    char    szMessage[256];
    char    szContext[80];

    STRING_FORMAT(szContext, "Error #%d in \"%s\" at line number: %d.", wVoxwareError, lpFilename, wLineNumber);

    tvGetStringFromError(wVoxwareError, dwReturnCode, szMessage)

#if defined (VOXWARE_WIN16) || (VOXWARE_WIN32)
    MessageBox(GetActiveWindow(), szMessage, szContext, MB_OK);
#endif

}
*/



/* The following function will be packaged for users: */
void tvGetStringFromError(VOXWARE_RETCODE wVoxwareError, signed long dwReturnCode,
                          char VOX_FAR *lpMessage)
{
    switch (wVoxwareError)
    {
        /* Parameter validation error codes. */
        case obsERR_BITS_PER_SAMPLE:
            STRING_FORMAT(lpMessage,	"obsERR_BITS_PER_SAMPLE (101)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_SAMPLE_RATE:
            STRING_FORMAT(lpMessage,	"obsERR_SAMPLE_RATE (102)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case VOXERR_FORMAT_PCM:
            STRING_FORMAT(lpMessage,	"VOXERR_FORMAT_PCM (103)\n" \
										"The input file should contain Vox data.  The file specified contains waveform data.\n" \
										"Verify that the input file is a Vox file and try again.\n");
            break;

        case VOXERR_NOT_MONO:
            STRING_FORMAT(lpMessage,	"VOXERR_NOT_MONO (104)\n" \
										"The input file must be a mono file.  This file has %ld wChannels.\n" \
										"Specify a file that has the proper format and try again.\n", dwReturnCode);
            break;

        case VOXERR_VOXWARE_DATA_POINTER_NULL:
            STRING_FORMAT(lpMessage,	"VOXERR_VOXWARE_DATA_POINTER_NULL (105)\n" \
										"The lpVoxwareData structure parameter that was passed in is NULL.\n" \
										"Check the calling parameters to verify that an appropriate value is passed in.\n");
            break;

        case VOXERR_VOXWARE_DATA_SIZE:
            STRING_FORMAT(lpMessage,	"VOXERR_VOXWARE_DATA_SIZE (106)\n" \
										"The lpVoxwareData->wSizeOfVoxwareData field is filled with an improper size - sizeof(VOXWARE_DATA) should be %ld bytes.\n" \
										"Verify that a beta version of the ToolVox DLLs aren't being used and recompile your application with the new ToolVox.H file.\n", dwReturnCode);
            break;

        case VOXERR_VOX_FILE_INFO_POINTER_NULL:
            STRING_FORMAT(lpMessage,	"VOXERR_VOX_FILE_INFO_POINTER_NULL (107)\n" \
										"The lpVoxwareData->lpOutputLocation parameter is NULL.  It should point to a valid lpVoxFileInfo structure.\n" \
										"Check the calling parameters to verify that an appropriate value is passed in.\n");
            break;

        case VOXERR_VOX_FILE_INFO_SIZE:
            STRING_FORMAT(lpMessage,	"VOXERR_VOX_FILE_INFO_SIZE (108)\n" \
										"The lpVoxwareData->dwOutputSize field is filled with an improper size - sizeof(VOX_FILE_INFO) should be %ld bytes.\n" \
										"Verify that a beta version of the ToolVox DLLs aren't being used and recompile your application with the new ToolVox.H file.\n", dwReturnCode);
            break;

        case VOXERR_VOX_VERSION_POINTER_NULL:
            STRING_FORMAT(lpMessage,	"VOXERR_VOX_VERSION_POINTER_NULL (109)\n" \
										"The lpVoxwareData->lpOutputLocation parameter is NULL.  It should point to a valid lpVoxVersion structure.\n" \
										"Check the calling parameters to verify that an appropriate value is passed in.\n");
            break;

        case VOXERR_VOX_VERSION_SIZE:
            STRING_FORMAT(lpMessage,	"VOXERR_VOX_VERSION_SIZE (110)\n" \
										"The lpVoxwareData->dwOutputSize field is filled with an improper size - sizeof(VOX_VERSION) should be %ld bytes.\n" \
										"Verify that a beta version of the ToolVox DLLs aren't being used.\n", dwReturnCode);
            break;

        case VOXERR_VOX_VOICE_POINTER_NULL:
            STRING_FORMAT(lpMessage,	"VOXERR_VOX_VOICE_POINTER_NULL (111)\n" \
										"The lpVoxwareData->lpVoiceFont field is NULL.\n" \
										"Make sure that the call to vfontCreateData() was made successfully.  This call is obsolete with ToolVox version 1.1.0 - use vfontLoadVoiceFont().\n");
            break;

        case VOXERR_VOX_VOICE_NAME_NULL:
            STRING_FORMAT(lpMessage,	"VOXERR_VOX_VOICE_NAME_NULL (112)\n" \
										"The lpVoxwareData->lpInputLocation field is NULL or the string length is zero.\n" \
										"This field must contain a VoiceFont name or VoiceFont filename (they must be a NULL terminated C string).\n");
            break;

        case VOXERR_MORPHIO_POINTER_BAD:
            STRING_FORMAT(lpMessage,	"VOXERR_MORPHIO_POINTER_BAD (113)\n" \
										"An internal pointer was invalid.  The pointer has the value %ld.\n" \
										"This is a programmatic error - call Voxware technical support.\n", dwReturnCode);
            break;

        case VOXERR_INVALID_INPUT_TYPE:
            STRING_FORMAT(lpMessage,	"VOXERR_INVALID_INPUT_TYPE (114)\n" \
										"An invalid or unsupported lpVoxwareData->dwInputType was specified (0x%08lX).\n" \
										"Check the ToolVox user manual for proper bit values for this field.\n", dwReturnCode);
            break;

        case VOXERR_INVALID_OUTPUT_TYPE:
            STRING_FORMAT(lpMessage,	"VOXERR_INVALID_OUTPUT_TYPE (115)\n" \
										"An invalid or unsupported lpVoxwareData->dwOutputType was specified (0x%08lX).\n" \
										"Check the ToolVox user manual for proper bit values for this field.\n", dwReturnCode);
            break;

        case VOXERR_INPUT_HANDLER:
            STRING_FORMAT(lpMessage,	"VOXERR_INPUT_HANDLER (116)\n" \
										"An internal programming error was made.  We called an output for reading or an input for writing. (0x%08lX).\n" \
										"This is a programmatic error - call Voxware technical support.\n", dwReturnCode);
            break;

        case VOXERR_OUTPUT_HANDLER:
            STRING_FORMAT(lpMessage,	"VOXERR_OUTPUT_HANDLER (117)\n" \
										"An internal programming error was made.  We called an output for reading or an input for writing. (0x%08lX).\n" \
										"This is a programmatic error - call Voxware technical support.\n", dwReturnCode);
            break;

        case VOXERR_PRIME_TIME:
            STRING_FORMAT(lpMessage,	"VOXERR_PRIME_TIME (118)\n" \
										"Indicates that the output buffer is too small - should be at least %ld bytes.\n" \
										"Try calling the function again with a larger buffer.\n", dwReturnCode);
            break;

        case VOXERR_WARP_2_BIG:
            STRING_FORMAT(lpMessage,	"VOXERR_WARP_2_BIG (119)\n" \
										"The lpVoxwareData->fWarpedLengthFactor value is too large - it should be less than %f.\n" \
										"Correct this field and try again.  The MAX_WARPED_LENGTH_FACTOR constant can be used to validate this data.\n", MAX_WARPED_LENGTH_FACTOR);
            break;

        case VOXERR_WARP_2_SMALL:
            STRING_FORMAT(lpMessage,	"VOXERR_WARP_2_SMALL (120)\n" \
										"The lpVoxwareData->fWarpedLengthFactor value is too small - it should be larger than %f.\n" \
										"Correct this field and try again.  The MIN_WARPED_LENGTH_FACTOR constant can be used to validate this data.\n", MIN_WARPED_LENGTH_FACTOR);
            break;

        case VOXERR_ABS_PITCH_2_BIG:
            STRING_FORMAT(lpMessage,	"VOXERR_ABS_PITCH_2_BIG (121)\n" \
										"The lpVoxwareData->fAbsolutePitch value is too large - it should be smaller than %f.\n" \
										"Correct this field and try again.  The MAX_ABSOLUTE_PITCH constant can be used to validate this data.\n", MAX_ABSOLUTE_PITCH);
            break;

        case VOXERR_ABS_PITCH_2_SMALL:
            STRING_FORMAT(lpMessage,	"VOXERR_ABS_PITCH_2_BIG (122)\n" \
										"The lpVoxwareData->fAbsolutePitch value is too small - it should be larger than %f.\n" \
										"Correct this field and try again.  The MIN_ABSOLUTE_PITCH constant can be used to validate this data.\n", MIN_ABSOLUTE_PITCH);
            break;

        case VOXERR_REL_PITCH_2_BIG:
            STRING_FORMAT(lpMessage,	"VOXERR_REL_PITCH_2_BIG (123)\n" \
										"The lpVoxwareData->fRelativePitch value is too large - it should be larger than %f.\n" \
										"Correct this field and try again.  The MAX_RELATIVE_PITCH constant can be used to validate this data.\n", MAX_RELATIVE_PITCH);
            break;

        case VOXERR_REL_PITCH_2_SMALL:
            STRING_FORMAT(lpMessage,	"VOXERR_REL_PITCH_2_SMALL (124)\n" \
										"The lpVoxwareData->fRelativePitch value is too small - it should be larger than %f.\n" \
										"Correct this field and try again.  The MIN_RELATIVE_PITCH constant can be used to validate this data.\n", MIN_RELATIVE_PITCH);
            break;

        case VOXERR_CODEC_UNKNOWN:
            STRING_FORMAT(lpMessage,	"VOXERR_CODEC_UNKNOWN (125)\n" \
										"A bad value was specified for the lpVoxwareData->dwCompression settings field - found a value of (0x%08lX).\n" \
										"Check the ToolVox user manual for proper bit values for this field.\n", dwReturnCode);
            break;

        case VOXERR_INPUT_BYTES_PER_SAMPLE:
            STRING_FORMAT(lpMessage,	"VOXERR_INPUT_BYTES_PER_SAMPLE (126)\n" \
										"The lpVoxwareData->dwInputBytesPerSample field has an invalid value (%ld).\n" \
										"Specify a proper value and try again.  You can use VOXWARE_SAMPLE_SIZE_8BIT or VOXWARE_SAMPLE_SIZE_16BIT.\n", dwReturnCode);
            break;

        case VOXERR_OUTPUT_BYTES_PER_SAMPLE:
            STRING_FORMAT(lpMessage,	"VOXERR_OUTPUT_BYTES_PER_SAMPLE (127)\n" \
										"The lpVoxwareData->dwOutputBytesPerSample field has an invalid value (%ld).\n" \
										"Specify a proper value and try again.  You can use VOXWARE_SAMPLE_SIZE_8BIT or VOXWARE_SAMPLE_SIZE_16BIT.\n", dwReturnCode);
            break;

        case VOXERR_FORMAT_VOX:
            STRING_FORMAT(lpMessage,	"VOXERR_FORMAT_VOX (128)\n" \
										"A Wave file containing Vox data was passed in.  ToolVox was expecting a file that contains PCM data.\n" \
										"Specify a file that has the proper format and try again.\n", dwReturnCode);
            break;

        case VOXERR_UNKNOWN_ATTRIBUTE:
            STRING_FORMAT(lpMessage,	"VOXERR_UNKNOWN_ATTRIBUTE (129)\n" \
										"An attribute was specified (0x%08lX) that ToolVox didn't recognize.\n" \
										"Check the ToolVox user manual for proper values for this field.\n", dwReturnCode);
            break;

        case VOXERR_VWD_OR_VCB_IS_NULL:
            STRING_FORMAT(lpMessage,	"VOXERR_VWD_OR_VCB_IS_NULL (130)\n" \
										"The lpVoxwareData pointer is NULL or the internal VoxControlBlock is NULL.  (lpVoxwareData = 0x%08lX).\n" \
										"Pass in a proper lpVoxwareData parameter and try again.  If the problem persists, call Voxware technical support.\n", dwReturnCode);
            break;

        case VOXERR_NO_MARKERS_IN_INPUT_FILE:
            STRING_FORMAT(lpMessage,	"VOXERR_NO_MARKERS_IN_INPUT_FILE (131)\n" \
										"When writing the output file, no markers were found in the input file.\n" \
										"This is a programmatic error - call Voxware technical support.\n", dwReturnCode);
            break;

        case VOXERR_BAD_SRC_4_MARKER_INPUT:
            STRING_FORMAT(lpMessage,	"VOXERR_BAD_SRC_4_MARKER_INPUT (132)\n" \
										"The lpVoxwareData->dwInputType is not a file (0x%08lX).  We only support markers with files.\n" \
										"Set the input location to file and try again.\n", dwReturnCode);
            break;

        case VOXERR_UNSUPPORTED_MARKER_CHUNK:
            STRING_FORMAT(lpMessage,	"VOXERR_UNSUPPORTED_MARKER_CHUNK (133)\n" \
										"An older version of the marker chunk was encountered in the Vox file. It has an ID of (0x%08lX).\n" \
										"Recreate the file with a non-beta version of ToolVox.\n", dwReturnCode);
            break;

        case VOXERR_INVALID_MARKER_SELECTOR:
            STRING_FORMAT(lpMessage,	"VOXERR_INVALID_MARKER_SELECTOR (134)\n" \
										"The marker record that was specified is incorrect (0x%08lX).\n" \
										"Will should check the code and call Voxware if this problem persists.\n", dwReturnCode);
            break;

        case VOXERR_NO_INPUT_SAMPLE_SIZE:
            STRING_FORMAT(lpMessage,	"VOXERR_NO_INPUT_SAMPLE_SIZE (135)\n" \
										"The lpVoxwareData->wInputBytesPerSample field must be filled in when processing raw data.\n" \
										"Specify the proper sample size (VOXWARE_SAMPLE_SIZE_8BIT or VOXWARE_SAMPLE_SIZE_16BIT) and try again.\n", dwReturnCode);
            break;

        case VOXERR_NO_INPUT_SAMPLING_RATE:
            STRING_FORMAT(lpMessage,	"VOXERR_NO_INPUT_SAMPLING_RATE (136)\n" \
										"The lpVoxwareData->wInputSamplingRate field must be filled in when processing raw data.\n" \
										"Specify the proper sampling rate and try again.\n", dwReturnCode);
            break;

        case VOXERR_BAD_INPUT_SAMPLING_RATE:
            STRING_FORMAT(lpMessage,	"VOXERR_BAD_INPUT_SAMPLING_RATE (137)\n" \
										"The lpVoxwareData->wInputSamplingRate was filled in with an unsupported sampling rate.\n" \
										"Specify the proper sampling rate and try again.\n", dwReturnCode);
            break;

        case VOXERR_BAD_OUTPUT_SAMPLING_RATE:
            STRING_FORMAT(lpMessage,	"VOXERR_BAD_OUTPUT_SAMPLING_RATE (138)\n" \
										"The lpVoxwareData->wOutputSamplingRate was filled in with an unsupported sampling rate.\n" \
										"Specify the proper sampling rate and try again.\n", dwReturnCode);
            break;

        case VOXERR_VALIDATE_NO_GESTALT:
            STRING_FORMAT(lpMessage,	"VOXERR_VALIDATE_NO_GESTALT (139)\n" \
										"MacOS specific error: No gestalt check available.\n" \
										"Update your system software - ToolVox requires System 7 or better.\n");
            break;

        case VOXERR_VALIDATE_CPU_OLD_AS_DIRT:
            STRING_FORMAT(lpMessage,	"VOXERR_VALIDATE_CPU_OLD_AS_DIRT (140)\n" \
										"MacOS specific error: Current CPU can not run ToolVox.\n" \
										"Update your system - ToolVox requires a 68020 or better.\n");
            break;

        case VOXERR_VALIDATE_NO_FPU:
            STRING_FORMAT(lpMessage,	"VOXERR_VALIDATE_NO_FPU (141)\n" \
										"MacOS specific error: Wrong math library for this machine - ToolVox was compiled to run with a math co-processor.\n" \
										"On a PowerPC, the PowerPC native version of ToolVox should be linked to your application.  On 68K machines link with the NoFPU version.\n");
            break;

        case VOXERR_VALIDATE_FILE_MGR_TOO_OLD:
            STRING_FORMAT(lpMessage,	"VOXERR_VALIDATE_FILE_MGR_TOO_OLD (142)\n" \
										"MacOS specific error: This version of the file manager doesn't support FSSpec routines.\n" \
										"Update your system software - ToolVox requires System 7 or better.\n");
            break;

        case VOXERR_VALIDATE_NO_NOTIFICATION_MGR:
            STRING_FORMAT(lpMessage,	"VOXERR_VALIDATE_NO_NOTIFICATION_MGR (143)\n" \
										"MacOS specific error: Can't use notification manager.\n" \
										"Update your system software - ToolVox requires System 7 or better.\n");
            break;

        case VOXERR_VALIDATE_YIKES_NO_SOUND_MGR:
            STRING_FORMAT(lpMessage,	"VOXERR_VALIDATE_YIKES_NO_SOUND_MGR (144)\n" \
										"MacOS specific error: The Sound Manager wasn't found.\n" \
										"Update your system software - ToolVox requires Sound Manager 3.0 or better.\n");
            break;

        case VOXERR_VALIDATE_U_LACK_16BIT_SND:
            STRING_FORMAT(lpMessage,	"VOXERR_VALIDATE_U_LACK_16BIT_SND (145)\n" \
										"MacOS specific error: The system doesn't have a 16-bit sound card.\n" \
										"Either update the Sound Manager to version 3.0 or better or set lpVoxwareData->wOutputBytesPerSample to VOXWARE_SAMPLE_SIZE_8BIT.\n");
            break;

        case VOXERR_VALIDATE_SND_MGR_NOT_CURRENT:
            STRING_FORMAT(lpMessage,	"VOXERR_VALIDATE_SND_MGR_NOT_CURRENT (146)\n" \
										"MacOS specific error: The Sound Manager is too old.\n" \
										"Update your system software - ToolVox requires Sound Manager 3.0 or better.\n");
            break;

        case VOXERR_DONT_GIVE_INPUT_SAMPLE_RATE:
            STRING_FORMAT(lpMessage,	"VOXERR_DONT_GIVE_INPUT_SAMPLE_RATE (147)\n" \
										"An lpVoxwareData->dwInputSamplingRate was specified (%ld) for an input type that has a header.\n" \
										"Set all unused lpVoxwareData fields to zero and try again.\n", dwReturnCode);
            break;

        case VOXERR_DONT_GIVE_INPUT_SAMPLE_SIZE:
            STRING_FORMAT(lpMessage,	"VOXERR_DONT_GIVE_INPUT_SAMPLE_SIZE (148)\n" \
										"An lpVoxwareData->wInputBytesPerSample was specified (%ld) for an input type that has a header.\n" \
										"Set all unused lpVoxwareData fields to zero and try again.\n", dwReturnCode);
            break;

        case VOXERR_NO_SAMPLE_RATE_FOR_VOX:
            STRING_FORMAT(lpMessage,	"VOXERR_NO_SAMPLE_RATE_FOR_VOX (149)\n" \
										"An lpVoxwareData->dwInputSamplingRate was specified (%ld) for a vox data type.\n" \
										"Set all unused lpVoxwareData fields to zero and try again.\n", dwReturnCode);
            break;

        case VOXERR_NO_SAMPLE_SIZE_FOR_VOX:
            STRING_FORMAT(lpMessage,	"VOXERR_NO_SAMPLE_SIZE_FOR_VOX (150)\n" \
										"An lpVoxwareData->wInputBytesPerSample was specified (%ld) for a vox data type.\n" \
										"Set all unused lpVoxwareData fields to zero and try again.\n", dwReturnCode);
            break;

        case VOXERR_EFFECTS_ARE_NOT_SUPPORTED:
            STRING_FORMAT(lpMessage,	"VOXERR_EFFECTS_ARE_NOT_SUPPORTED (151)\n" \
										"The file was compressed with a codec (0x%08lX) that doesn't support VoiceFonts or pitch shifting.\n" \
										"Don't specify VoiceFonts or pitch shifting for this codec.\n", dwReturnCode);
            break;

        case VOXERR_FX_R_4_DECOMPRESSION_ONLY:
            STRING_FORMAT(lpMessage,	"VOXERR_FX_R_4_DECOMPRESSION_ONLY (152)\n" \
										"VoiceFonts, pitch shifting and warping are not available for compression.\n" \
										"Set all unused lpVoxwareData fields to zero and try again.\n");
            break;

        case VOXERR_ONLY_RT_8K_CODEC_AVAILABLE:
            STRING_FORMAT(lpMessage,	"VOXERR_ONLY_RT_8K_CODEC_AVAILABLE (153)\n" \
										"The multimedia codecs are not available in the current library. (0x%08lX).\n" \
										"Set lpVoxwareData->dwCompressionSettings to VOXWARE_CODEC_RT_8K or obtain the multimedia codecs from Voxware.\n", dwReturnCode);
            break;

        case VOXERR_INVALID_MARKER_SIZEOF:
            STRING_FORMAT(lpMessage,	"VOXERR_INVALID_MARKER_SIZEOF (154)\n" \
										"The size of the lpMarker field is wrong for the type of structure it's supposed to be (%ld).\n" \
										"Will should check that the code has been compiled with the latest header files (and the dwSizeOf field filled in) and call Voxware if this problem persists.\n", dwReturnCode);
            break;

        case VOXERR_INVALID_VCB:
            STRING_FORMAT(lpMessage,	"VOXERR_INVALID_VCB (155)\n" \
            							"check secondary error for details.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveOutWrite() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_INVALID_OUTPUT_VARS:
            STRING_FORMAT(lpMessage,	"VOXERR_INVALID_OUTPUT_VARS (156)\n" \
            							"check secondary error for details.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveOutWrite() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_INVALID_INPUT_VARS:
            STRING_FORMAT(lpMessage,	"VOXERR_INVALID_INPUT_VARS (157)\n" \
            							"check secondary error for details.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveOutWrite() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_ABS_GAIN_2_BIG:
            STRING_FORMAT(lpMessage,	"VOXERR_ABS_GAIN_2_BIG (158)\n" \
										"The lpVoxwareData->fAbsoluteGain value is too large - it should be smaller than %f.\n" \
										"Correct this field and try again.  The MAX_ABSOLUTE_GAIN constant can be used to validate this data.\n", MAX_ABSOLUTE_GAIN);
            break;

        case VOXERR_ABS_GAIN_2_SMALL:
            STRING_FORMAT(lpMessage,	"VOXERR_ABS_GAIN_2_SMALL (159)\n" \
										"The lpVoxwareData->fAbsoluteGain value is too small - it should be larger than %f.\n" \
										"Correct this field and try again.  The MIN_ABSOLUTE_GAIN constant can be used to validate this data.\n", MIN_ABSOLUTE_GAIN);
            break;

        case VOXERR_REL_GAIN_2_BIG:
            STRING_FORMAT(lpMessage,	"VOXERR_REL_GAIN_2_BIG (160)\n" \
										"The lpVoxwareData->fRelativeGain value is too large - it should be larger than %f.\n" \
										"Correct this field and try again.  The MAX_RELATIVE_GAIN constant can be used to validate this data.\n", MAX_RELATIVE_GAIN);
            break;

        case VOXERR_REL_GAIN_2_SMALL:
            STRING_FORMAT(lpMessage,	"VOXERR_REL_GAIN_2_SMALL (161)\n" \
										"The lpVoxwareData->fRelativeGain value is too small - it should be larger than %f.\n" \
										"Correct this field and try again.  The MIN_RELATIVE_GAIN constant can be used to validate this data.\n", MIN_RELATIVE_GAIN);
            break;

        case VOXERR_VOXWARE_ALREADY_INITIALIZED:
            STRING_FORMAT(lpMessage,	"VOXERR_VOXWARE_ALREADY_INITIALIZED (162)\n" \
            							"The lpVoxwareData structure was passed in while in use by a previous call to ToolVox.\n" \
                                     	"Wait for a previous function to end and verify that the Vox free function is called.\n");
            break;

        case VOXERR_MUST_PLAY_TO_LOCATION_SOUND:
            STRING_FORMAT(lpMessage,	"VOXERR_MUST_PLAY_TO_LOCATION_SOUND (163)\n" \
            							"The lpVoxwareData->dwOutputType field's location must be set to VOXTYPE_LOCATION_SOUND.\n" \
                                     	"Set dwOutputType = VOXTYPE_LOCATION_SOUND|VOXTYPE_QUALIFIER_VOX (or [mac only] VOXTYPE_LOCATION_SOUND|VOXTYPE_QUALIFIER_PCM.)\n");
            break;

        case VOXERR_MUST_CALL_DCMP_TOOLVOX_PLAY:
            STRING_FORMAT(lpMessage,	"VOXERR_MUST_CALL_DCMP_TOOLVOX_PLAY (164)\n" \
            							"The lpVoxwareData->dwOutputType field's location is set to VOXTYPE_LOCATION_SOUND so you should call dcmpToolVoxPlay.\n" \
                                     	"Call the dcmpToolVoxPlay() function or change the output location.\n");
            break;

        case VOXERR_FPU_DETECT:
            STRING_FORMAT(lpMessage,	"VOXERR_FPU_DETECT (165)\n" \
            							"MacOS only: gestalt returned an error (%ld) calling:\n" \
                                     	"You should never encounter this error.\n", dwReturnCode);
            break;

        case VOXERR_IDENTIFYING_THE_CPU:
            STRING_FORMAT(lpMessage,	"VOXERR_IDENTIFYING_THE_CPU (166)\n" \
            							"We don't know what kind of CPU is in your machine. (%ld)\n" \
                                     	"Use an older machine that we know about... (just kidding.)\n", dwReturnCode);
            break;

        case VOXERR_IDENTIFYING_THE_OS:
            STRING_FORMAT(lpMessage,	"VOXERR_IDENTIFYING_THE_OS (167)\n" \
            							"Can't figure out which OS you are running: Windows 95, 3.1, NT, etc.\n" \
                                     	"Use an older software that we know about... (just kidding.)\n");
            break;



        /* File I/O error codes. */
        case obsERR_DATA_CHUNK_SEEK:
            STRING_FORMAT(lpMessage,	"obsERR_DATA_CHUNK_SEEK (201)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_FMT_CHUNK_READ:
            STRING_FORMAT(lpMessage,	"obsERR_FMT_CHUNK_READ (202)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case VOXERR_FMT_CHUNK_SIZE:
            STRING_FORMAT(lpMessage,	"VOXERR_FMT_CHUNK_SIZE (203)\n" \
										"The size of the 'fmt ' chunk is too small (%ld bytes) to contain a pcmWaveFormat structure (16 bytes)." \
										"Make sure the file adheres to the Windows Wave specification and try again.\n", dwReturnCode);
            break;

        case VOXERR_RIFF_CHUNK_READ:
            STRING_FORMAT(lpMessage,	"VOXERR_RIFF_CHUNK_READ (204)\n" \
										"The first field in the 'RIFF' data is not 'WAVE' - a chunk ID of 0x%08lX was found [%.4s].\n" \
										"Make sure the file adheres to the Windows Wave specification.\n", dwReturnCode, (unsigned char VOX_FAR *)&dwReturnCode);
            break;

        case VOXERR_VOX_HEADER_FLAG:
            STRING_FORMAT(lpMessage,	"VOXERR_VOX_HEADER_FLAG (205)\n" \
										"An invalid Vox header flag was found: 0x%08lX [%.4s].\n" \
										"Make sure that this file wasn't built with a pre-release version of ToolVox.\n", dwReturnCode, (unsigned char VOX_FAR *)&dwReturnCode);
            break;

        case VOXERR_VOX_HEADER_SIZE:
            STRING_FORMAT(lpMessage,	"VOXERR_VOX_HEADER_SIZE (206)\n" \
										"An invalid size for the Vox file header was found: 0x%04X.\n" \
										"Make sure that this file wasn't built with a pre-release version of ToolVox.\n", dwReturnCode);
            break;

        case obsERR_VOX_INIT_READ:
            STRING_FORMAT(lpMessage,	"obsERR_VOX_INIT_READ (207)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_VOX_INIT_WRITE:
            STRING_FORMAT(lpMessage,	"obsERR_VOX_INIT_WRITE (208)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_VOX_OPEN:
            STRING_FORMAT(lpMessage,	"obsERR_VOX_OPEN (209)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_VOX_READ:
            STRING_FORMAT(lpMessage,	"obsERR_VOX_READ (210)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_VOX_WRITE:
            STRING_FORMAT(lpMessage,	"obsERR_VOX_WRITE (211)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_WAVE_CKID:
            STRING_FORMAT(lpMessage,	"obsERR_WAVE_CKID (212)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_WAVE_INIT_READ:
            STRING_FORMAT(lpMessage,	"obsERR_WAVE_INIT_READ (213)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_WAVE_INIT_WRITE:
            STRING_FORMAT(lpMessage,	"obsERR_WAVE_INIT_WRITE (214)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_WAVE_OPEN:
            STRING_FORMAT(lpMessage,	"obsERR_WAVE_OPEN (215)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_WAVE_READ:
            STRING_FORMAT(lpMessage,	"obsERR_WAVE_READ (216)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_WAVE_WRITE:
            STRING_FORMAT(lpMessage,	"obsERR_WAVE_WRITE (217)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case VOXERR_VFONT_OPEN:
            STRING_FORMAT(lpMessage,	"VOXERR_VFONT_OPEN (218)\n" \
										"Cannot open the VoiceFont file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file open call.\n", dwReturnCode);
            break;

        case VOXERR_VFONT_READ:
            STRING_FORMAT(lpMessage,	"VOXERR_VFONT_READ (219)\n" \
										"Cannot read from the VoiceFont file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file read call.\n", dwReturnCode);
            break;

        case VOXERR_VFONT_WRITE:
            STRING_FORMAT(lpMessage,	"VOXERR_VFONT_WRITE (220)\n" \
										"Cannot write to the VoiceFont file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file write call.\n", dwReturnCode);
            break;

        case VOXERR_ENDOFFILE_REACHED:
            STRING_FORMAT(lpMessage,	"VOXERR_ENDOFFILE_REACHED (221)\n" \
										"!!! The end of a file was reached.  This is not an error and should only be returned internally. !!!\n" \
										"Call Voxware technical support.\n");
            break;

        case VOXERR_READING_FROM_FILE:
            STRING_FORMAT(lpMessage,	"VOXERR_READING_FROM_FILE (222)\n" \
										"Cannot read from the file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file read call.\n", dwReturnCode);
            break;

        case VOXERR_WRITING_TO_FILE:
            STRING_FORMAT(lpMessage,	"VOXERR_WRITING_TO_FILE (223)\n" \
										"Cannot write to the file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file write call.\n", dwReturnCode);
            break;

        case VOXERR_BAD_PATH_TO_FILE:
            STRING_FORMAT(lpMessage,	"VOXERR_BAD_PATH_TO_FILE (224)\n" \
										"MacOS specific error: Could not get a full-pathname.\n" \
										"Verify that the location field of the lpVoxwareData structure contains a full path name.\n");
            break;

        case VOXERR_SET_FPOS:
            STRING_FORMAT(lpMessage,	"VOXERR_SET_FPOS (225)\n" \
										"MacOS specific error: Could not seek into a file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the SetFPos() call.\n", dwReturnCode);
            break;

        case VOXERR_OPENING_INPUT_FILE:
            STRING_FORMAT(lpMessage,	"VOXERR_OPENING_INPUT_FILE (226)\n" \
										"Cannot open the input file.  A system error of %ld occurred.  lpVoxwareData->lpInputLocation must contain a NULL terminated C string for the filename.\n" \
										"Look up the system error, which indicates the return value from the file open call.\n", dwReturnCode);
            break;

        case VOXERR_OPENING_OUTPUT_FILE:
            STRING_FORMAT(lpMessage,	"VOXERR_OPENING_OUTPUT_FILE (227)\n" \
										"Cannot open the output file.  A system error of %ld occurred.  lpVoxwareData->lpOutputLocation must contain a NULL terminated C string for the filename.\n" \
										"Look up the system error, which indicates the return value from the file open call.\n", dwReturnCode);
            break;

        case VOXERR_CLOSING_INPUT_FILE:
            STRING_FORMAT(lpMessage,	"VOXERR_CLOSING_INPUT_FILE (228)\n" \
										"Cannot close the input file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file close call.\n", dwReturnCode);
            break;

        case VOXERR_CLOSING_OUTPUT_FILE:
            STRING_FORMAT(lpMessage,	"VOXERR_CLOSING_OUTPUT_FILE (229)\n" \
										"Cannot close the output file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file close call.\n", dwReturnCode);
            break;

        case VOXERR_READING_MARKER:
            STRING_FORMAT(lpMessage,	"VOXERR_READING_MARKER (230)\n" \
										"Could not read the amount of data that is specified in the marker 'cue ' or 'LIST' chunk.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file read call.\n", dwReturnCode);
            break;

        case VOXERR_SEEKING_TO_MARKER_CHUNK:
            STRING_FORMAT(lpMessage,	"VOXERR_SEEKING_TO_MARKER_CHUNK (231)\n" \
										"Could not seek to a marker 'VOXm' chunk.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file seek call.\n", dwReturnCode);
            break;

        case VOXERR_MARKER_SEEK_RESET:
            STRING_FORMAT(lpMessage,	"VOXERR_MARKER_SEEK_RESET (232)\n" \
										"Could not reset seek positon after parsing markers.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file seek call.\n", dwReturnCode);
            break;

        case VOXERR_FAILED_SEEK_TO_MARKER:
            STRING_FORMAT(lpMessage,	"VOXERR_FAILED_SEEK_TO_MARKER (233)\n" \
										"Could not seek to a marker (%ld).  The lpMarkerReserved->dwStartByte value is invalid.\n" \
										"Will should check that the Vox file and the database of markers are matching.  Call Voxware if this problem persists.\n", dwReturnCode);
            break;

        case VOXERR_REOPENING_MARKER_LOG:
            STRING_FORMAT(lpMessage,	"VOXERR_REOPENING_MARKER_LOG (234)\n" \
										"Could not reopen the output marker log.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file open call.\n", dwReturnCode);
            break;

        case VOXERR_OPENING_MARKER_LOG:
            STRING_FORMAT(lpMessage,	"VOXERR_REOPENING_MARKER_LOG (235)\n" \
										"Could not open the output marker log.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file open call.\n", dwReturnCode);
            break;

        case VOXERR_FAILED_TO_GET_EOF:
            STRING_FORMAT(lpMessage,	"VOXERR_FAILED_TO_GET_EOF (236)\n" \
										"Could not find the end of the file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the GetEOF call.\n", dwReturnCode);
            break;

        case VOXERR_SEEKING_PAST_HEADER:
            STRING_FORMAT(lpMessage,	"VOXERR_SEEKING_PAST_HEADER (237)\n" \
										"Could not seek past the header of a file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file seek call.\n", dwReturnCode);
            break;

        case VOXERR_ENDOFBUFFER_REACHED:
            STRING_FORMAT(lpMessage,	"VOXERR_ENDOFBUFFER_REACHED (238)\n" \
										"Could not process all of the data because the output buffer is not large enough.\n" \
										"Allocate a larger buffer and try again.\n");
            break;


		/* Format/Header error codes                                                */
        case VOXERR_UNKNOWN_HEADER_FORMAT:
            STRING_FORMAT(lpMessage,	"VOXERR_UNKNOWN_HEADER_FORMAT (301)\n" \
										"The lpVoxwareData->dwInputType that was specified (0x%08lX) has an invalid format flag.\n" \
										"Check the ToolVox user manual for proper values for this field.\n", dwReturnCode);
            break;

        case VOXERR_WE_DONT_SUPPORT_RIFX:
            STRING_FORMAT(lpMessage,	"VOXERR_WE_DONT_SUPPORT_RIFX (302)\n" \
										"ToolVox can not read Motorola format Wave files.\n" \
										"Call Voxware technical support.\n");
            break;

        case VOXERR_WAVE_DOESNT_START_RIFF:
            STRING_FORMAT(lpMessage,	"VOXERR_WAVE_DOESNT_START_RIFF (303)\n" \
										"The Wave file doesn't have the 'RIFF' chunk id as the first four bytes  - a chunk ID of 0x%08lX was found [%.4s].\n" \
										"Verify that the file is a Windows Wave or specify a file that has the proper format and try again.\n", dwReturnCode, (unsigned char VOX_FAR *)&dwReturnCode);
            break;

        case VOXERR_CANT_SURF_THIS_WAVE:
            STRING_FORMAT(lpMessage,	"VOXERR_CANT_SURF_THIS_WAVE (304)\n" \
										"The Windows wave file has no format or data information.\n" \
										"Specify a file that has the proper format and try again.\n");
            break;

        case VOXERR_AIFF_COULDNT_FIND_ALL_CHUNKS:
            STRING_FORMAT(lpMessage,	"VOXERR_AIFF_COULDNT_FIND_ALL_CHUNKS (305)\n" \
										"The AIFF or AIFF-C file has no form, common, or data information.\n" \
										"Specify a file that has the proper format and try again.\n");
            break;

        case VOXERR_HDR_MISSING_BITS_OF_DATA:
            STRING_FORMAT(lpMessage,	"VOXERR_HDR_MISSING_BITS_OF_DATA (307)\n" \
										"When reading a compressed header, invalid information was encountered - (%ld).\n" \
										"Recreate the file with a non-beta version of ToolVox.\n", dwReturnCode);
            break;

        case VOXERR_NOT_A_COMPRESSED_HEADER:
            STRING_FORMAT(lpMessage,	"VOXERR_NOT_A_COMPRESSED_HEADER (308)\n" \
										"When reading a compressed header, an invalid ID was encountered - 0x%08lX [%.4s].\n" \
										"Recreate the file with a non-beta version of ToolVox.\n", dwReturnCode, (unsigned char VOX_FAR *)&dwReturnCode);
            break;


        /* Memory alloction error codes. */
        case VOXERR_PLAYBACK_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_PLAYBACK_MEMORY (401)\n" \
            							"Unable to calloc() %ld bytes for the playback buffer.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_VOXSTRUCT_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_VOXSTRUCT_MEMORY (402)\n" \
            							"Unable to calloc() %ld bytes for the VoxControlBlock.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case obsERR_VOX_DATA_MEMORY:
            STRING_FORMAT(lpMessage,	"obsERR_VOX_DATA_MEMORY (403)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case obsERR_WAVE_DATA_MEMORY:
            STRING_FORMAT(lpMessage,	"obsERR_WAVE_DATA_MEMORY (404)\n" \
										"This error number became obsolete with ToolVox version 1.1.0.\n" \
										"Verify that a current version of the ToolVox DLLs are being used.\n");
            break;

        case VOXERR_WAVEHDR_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_WAVEHDR_MEMORY (405)\n" \
            							"Unable to calloc() %ld bytes for a sound header for recording or playback.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_VER_INFO_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_VER_INFO_MEMORY (406)\n" \
            							"Unable to calloc() %ld bytes for the VersionInfo structure.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_MORPHIO_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_MORPHIO_MEMORY (407)\n" \
            							"Unable to calloc() an internal Morphio structure.\n" \
            							"Free some memory up and try again.\n");
            break;

        case VOXERR_INPUT_VARS_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_INPUT_VARS_MEMORY (408)\n" \
            							"Unable to calloc() %ld bytes for the InputVars structure.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_OUTPUT_VARS_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_OUTPUT_VARS_MEMORY (409)\n" \
            							"Unable to calloc() %ld bytes for the OutputVars structure.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;
 
        case VOXERR_RECORD_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_RECORD_MEMORY (410)\n" \
            							"Unable to calloc() %ld bytes for the internal buffer used for recording.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;
 
        case VOXERR_MARKERS_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_MARKERS_MEMORY (411)\n" \
            							"Unable to calloc() %ld bytes for the internal marker buffers.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_FILELINK_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_FILELINK_MEMORY (412)\n" \
            							"Unable to calloc() %ld bytes for the internal file structure.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_READ_COMPLETION_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_READ_COMPLETION_MEMORY (413)\n" \
            							"Unable to allocate UPP for read completeion routine becuse of an error %ld.\n" \
										"Look up the system error, which indicates the return value from the MemError() call.\n", dwReturnCode);
            break;

        case VOXERR_INPUT_DISKIO_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_INPUT_DISKIO_MEMORY (414)\n" \
            							"Unable to calloc() %ld bytes for the input disk buffer.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_OUTPUT_DISKIO_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_OUTPUT_DISKIO_MEMORY (415)\n" \
            							"Unable to calloc() %ld bytes for the output disk buffer.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_FLUSH_BUFFER_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_FLUSH_BUFFER_MEMORY (416)\n" \
            							"Unable to calloc() %ld bytes for a temporary flush buffer.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);

        case VOXERR_FUNCIN_BUFFER_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_FUNCIN_BUFFER_MEMORY (417)\n" \
            							"Unable to calloc() %ld bytes for the internal buffer used for function streaming.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);

        case VOXERR_FUNCOUT_BUFFER_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_FUNCOUT_BUFFER_MEMORY (418)\n" \
            							"Unable to calloc() %ld bytes for the internal buffer used for function streaming.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);

        case VOXERR_DEFERRED_TASK_PROC_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_DEFERRED_TASK_PROC_MEMORY (419)\n" \
            							"Unable to start a deferred task using NewDeferredTaskProc() because of a memory error (%ld).\n" \
										"Look up the system error, which indicates the return value from the MemError() call.\n", dwReturnCode);

        case VOXERR_DEFERRED_TASK_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_DEFERRED_TASK_MEMORY (420)\n" \
            							"Unable to calloc() %ld bytes for the internal buffer used for a deferred task.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);

        case VOXERR_SOUND_CALLBACK_PROC_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_SOUND_CALLBACK_PROC_MEMORY (421)\n" \
            							"Unable to allocate UPP for the sound callback procedure becuse of an error %ld.\n" \
										"Look up the system error, which indicates the return value from the MemError() call.\n", dwReturnCode);

        case VOXERR_NOTIFICATION_REC_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_NOTIFICATION_REC_MEMORY (422)\n" \
            							"Unable to calloc() %ld bytes for a notification record.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);

        case VOXERR_PLAYBACK_VARS_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_PLAYBACK_VARS_MEMORY (423)\n" \
            							"Unable to calloc() %ld bytes for playback buffer variables.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);

        case VOXERR_PLAYBACK_BUFFER_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_PLAYBACK_BUFFER_MEMORY (424)\n" \
            							"Unable to calloc() %ld bytes for a playback buffer.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
 
        case VOXERR_ORD_MARKERS_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_ORD_MARKERS_MEMORY (425)\n" \
            							"Unable to calloc() %ld bytes for the internal marker buffers.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;
 
        case VOXERR_MARKERS_TEMP_CHUNK_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_MARKERS_TEMP_CHUNK_MEMORY (426)\n" \
            							"Unable to calloc() %ld bytes for the internal marker buffers.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;
 
        case VOXERR_WAVE_MARKER_CHUNK_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_WAVE_MARKER_CHUNK_MEMORY (427)\n" \
            							"Unable to calloc() %ld bytes for the internal marker buffers.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;
 
        case VOXERR_GENERIC_MARKERS_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_GENERIC_MARKERS_MEMORY (428)\n" \
            							"Unable to calloc() %ld bytes for the internal marker buffers.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;

        case VOXERR_TEMP_INPUT_BUFFER_MEMORY:
            STRING_FORMAT(lpMessage,	"VOXERR_TEMP_INPUT_BUFFER_MEMORY (429)\n" \
            							"Unable to calloc() %ld bytes for a temporary input buffer.\n" \
            							"Free some memory up and try again.\n", dwReturnCode);
            break;



        /* General system error codes. */
        case VOXERR_BREW_BLACK_ART:
            STRING_FORMAT(lpMessage,	"VOXERR_BREW_BLACK_ART (501)\n" \
										"An error was encountered while brewing the black art (an internal initialization process).  The actual codec error ID is %ld.\n" \
										"Call Voxware technical support with this information for further diagnosis.\n", dwReturnCode);
            break;

        case VOXERR_COMPRESSION:
            STRING_FORMAT(lpMessage,	"VOXERR_COMPRESSION (502)\n" \
            							"An error was encountered while encoding speech.  The actual codec error ID is %ld.\n" \
										"Call Voxware technical support with this information for further diagnosis.\n", dwReturnCode);
            break;

        case VOXERR_CREATE_WINDOW:
            STRING_FORMAT(lpMessage,	"VOXERR_CREATE_WINDOW (503)\n" \
            							"Unable to create internal Window that would control the playback and record messages.\n" \
                                     	"See the Microsoft SDK documentation for more information on the CreateWindow() function.\n");
            break;

        case VOXERR_DECOMPRESSION:
            STRING_FORMAT(lpMessage,	"VOXERR_DECOMPRESSION (504)\n" \
            							"An error was encountered while decoding speech.  The actual codec error ID is %ld.\n" \
										"Call Voxware technical support with this information for further diagnosis.\n", dwReturnCode);
            break;

        case VOXERR_WAVEOUT_OPEN:
            STRING_FORMAT(lpMessage,	"VOXERR_WAVEOUT_OPEN (505)\n" \
            							"Cannot open the Wave device to play data that is being decompressed.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveOutOpen() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_PREPARE_HDR:
            STRING_FORMAT(lpMessage,	"VOXERR_PREPARE_HDR (506)\n" \
            							"Unable to prepare a header for playing or recording with this Windows wave device.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveOutPrepareHeader() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_WAVEOUT_WRITE:
            STRING_FORMAT(lpMessage,	"VOXERR_WAVEOUT_WRITE (507)\n" \
            							"Unable to play a buffer of speech on this Wave device.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveOutWrite() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_WAVEIN_ADD_BUFFER:
            STRING_FORMAT(lpMessage,	"VOXERR_WAVEIN_ADD_BUFFER (508)\n" \
            							"Unable to record a buffer of speech on this Wave device.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveInAddBuffer() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_WAVEIN_OPEN:
            STRING_FORMAT(lpMessage,	"VOXERR_WAVEIN_OPEN (509)\n" \
            							"Cannot open the Wave device to record data for compression.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveInOpen() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_WAVEIN_START:
            STRING_FORMAT(lpMessage,	"VOXERR_WAVEIN_START (510)\n" \
            							"Cannot start the Wave device to record data for compression.\n" \
                                     	"See the Microsoft SDK documentation for more information on the waveInStart() function, return value = 0x%04X.\n", dwReturnCode);
            break;

        case VOXERR_FUNCTION_EXPIRED:
            STRING_FORMAT(lpMessage,	"VOXERR_FUNCTION_EXPIRED (511)\n" \
            							"This is a demo or beta version of ToolVox and it has expired.\n" \
                                     	"Purchase a copy of ToolVox or get an upgrade - call Voxware sales for further help.\n");
            break;

        case VOXERR_NOT_ENOUGH_DATA_TO_COMPRESS:
            STRING_FORMAT(lpMessage,	"VOXERR_NOT_ENOUGH_DATA_TO_COMPRESS (512)\n" \
            							"The lpInputBuffer is too small.  It must be at least %ld bytes.\n" \
                                     	"Increase the buffer size and try this operation again.\n", dwReturnCode);
            break;

        case VOXERR_COMPRESS_BUFFER:
            STRING_FORMAT(lpMessage,	"VOXERR_COMPRESS_BUFFER (513)\n" \
            							"An error was encountered while compressing a buffer - %ld.\n" \
										"Call Voxware technical support with this information for further diagnosis.\n", dwReturnCode);
            break;

        case VOXERR_PROCESSING_ABORTED:
            STRING_FORMAT(lpMessage,	"VOXERR_PROCESSING_ABORTED (514)\n" \
            							"A non-zero value was returned from the callback - %ld.\n" \
										"The user aborted processing.  This is not an \"error\", but the output is not valid.\n", dwReturnCode);
            break;


        /* Errors that occur using the VoiceFonts API. */
        case VOXERR_VFONT_FILE_NOT_FOUND:
            STRING_FORMAT(lpMessage,	"VOXERR_VFONT_FILE_NOT_FOUND (601)\n" \
										"Cannot open the VoiceFont file.\n" \
										"Check the calling parameters to verify that an appropriate value is passed in.\n");
            break;

        case VOXERR_VFONT_WRONGNAME:
            STRING_FORMAT(lpMessage,	"VOXERR_VFONT_WRONGNAME (602)\n" \
            							"The name stored in the VoiceFont file does not match the name that was passed in.\n" \
										"Check the calling parameters to verify that an appropriate value is passed in.\n");
            break;

        case VOXERR_VFONT_DELETE:
            STRING_FORMAT(lpMessage,	"VOXERR_VFONT_DELETE (603)\n" \
										"Cannot delete the VoiceFont file.  A system error of %ld occurred.\n" \
										"Look up the system error, which indicates the return value from the file remove call.\n", dwReturnCode);
            break;

        case VOXERR_VFONT_FILE_FORMAT:
            STRING_FORMAT(lpMessage,	"VOXERR_VFONT_FILE_FORMAT (604)\n" \
            							"Wrong format or invalid entry in the VoiceFont file.  The secondary error field has the value %ld.\n" \
										"Call Voxware technical support with this information for further diagnosis.\n", dwReturnCode);
            break;

        case VOXERR_MORPHIO_HANDLE_INVALID:
            STRING_FORMAT(lpMessage,	"VOXERR_MORPHIO_HANDLE_INVALID (605)\n" \
										"An incorrect internal Morphio structure was encountered.  The signature is %ld\n" \
										"Call Voxware technical support with this information for further diagnosis.\n", dwReturnCode);
            break;


        case VOXWARE_PLAYBACKERROR:
            STRING_FORMAT(lpMessage,	"VOXWARE_PLAYBACKERROR (10)\n" \
            							"A playback error occurred.  The actual VoxWare error number is %ld.\n" \
										"Call Voxware technical support with this information for further diagnosis.\n", dwReturnCode);
            break;

        default:
            STRING_FORMAT(lpMessage,	"[UNKNOWN] (%d)\n" \
                                     	"The Secondary return code is 0x%08lX.\n" \
                                     	"[BLANK]\n", wVoxwareError, dwReturnCode);
            break;
    }

	return;

}   /* end of tvGetStringFromError() */


#ifdef __cplusplus
}
#endif

#endif /*__TVGETSTR_H_*/


#endif /* _DEBUG_MESSAGES */
