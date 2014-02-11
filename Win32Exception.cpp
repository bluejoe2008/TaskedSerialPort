// Win32Exception.cpp: implementation of the CWin32Exception class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Logger.h"
#include "Win32Exception.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWin32Exception::CWin32Exception(DWORD nErrorCode)
{
	ASSERT(nErrorCode);
	m_nErrorCode = nErrorCode;
	ParseError();

	::Logger.Log("发生系统错误：%s", m_sErrorLabel);
}

CWin32Exception::~CWin32Exception()
{
	
}

void CWin32Exception::ParseError()
{
	switch(m_nErrorCode)
	{
	case 0:
		{
			m_sErrorName = "ERROR_SUCCESS";
			m_sErrorDescription = "The operation completed successfully. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1:
		{
			m_sErrorName = "ERROR_INVALID_FUNCTION";
			m_sErrorDescription = "Incorrect function. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2:
		{
			m_sErrorName = "ERROR_FILE_NOT_FOUND";
			m_sErrorDescription = "The system cannot find the file specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3:
		{
			m_sErrorName = "ERROR_PATH_NOT_FOUND";
			m_sErrorDescription = "The system cannot find the path specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4:
		{
			m_sErrorName = "ERROR_TOO_MANY_OPEN_FILES";
			m_sErrorDescription = "The system cannot open the file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5:
		{
			m_sErrorName = "ERROR_ACCESS_DENIED";
			m_sErrorDescription = "Access is denied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6:
		{
			m_sErrorName = "ERROR_INVALID_HANDLE";
			m_sErrorDescription = "The handle is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7:
		{
			m_sErrorName = "ERROR_ARENA_TRASHED";
			m_sErrorDescription = "The storage control blocks were destroyed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8:
		{
			m_sErrorName = "ERROR_NOT_ENOUGH_MEMORY";
			m_sErrorDescription = "Not enough storage is available to process this command. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9:
		{
			m_sErrorName = "ERROR_INVALID_BLOCK";
			m_sErrorDescription = "The storage control block address is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10:
		{
			m_sErrorName = "ERROR_BAD_ENVIRONMENT";
			m_sErrorDescription = "The environment is incorrect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11:
		{
			m_sErrorName = "ERROR_BAD_FORMAT";
			m_sErrorDescription = "An attempt was made to load a program with an incorrect format. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 12:
		{
			m_sErrorName = "ERROR_INVALID_ACCESS";
			m_sErrorDescription = "The access code is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 13:
		{
			m_sErrorName = "ERROR_INVALID_DATA";
			m_sErrorDescription = "The data is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 14:
		{
			m_sErrorName = "ERROR_OUTOFMEMORY";
			m_sErrorDescription = "Not enough storage is available to complete this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 15:
		{
			m_sErrorName = "ERROR_INVALID_DRIVE";
			m_sErrorDescription = "The system cannot find the drive specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 16:
		{
			m_sErrorName = "ERROR_CURRENT_DIRECTORY";
			m_sErrorDescription = "The directory cannot be removed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 17:
		{
			m_sErrorName = "ERROR_NOT_SAME_DEVICE";
			m_sErrorDescription = "The system cannot move the file to a different disk drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 18:
		{
			m_sErrorName = "ERROR_NO_MORE_FILES";
			m_sErrorDescription = "There are no more files. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 19:
		{
			m_sErrorName = "ERROR_WRITE_PROTECT";
			m_sErrorDescription = "The media is write protected. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 20:
		{
			m_sErrorName = "ERROR_BAD_UNIT";
			m_sErrorDescription = "The system cannot find the device specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 21:
		{
			m_sErrorName = "ERROR_NOT_READY";
			m_sErrorDescription = "The device is not ready. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 22:
		{
			m_sErrorName = "ERROR_BAD_COMMAND";
			m_sErrorDescription = "The device does not recognize the command. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 23:
		{
			m_sErrorName = "ERROR_CRC";
			m_sErrorDescription = "Data error (cyclic redundancy check). ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 24:
		{
			m_sErrorName = "ERROR_BAD_LENGTH";
			m_sErrorDescription = "The program issued a command but the command length is incorrect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 25:
		{
			m_sErrorName = "ERROR_SEEK";
			m_sErrorDescription = "The drive cannot locate a specific area or track on the disk. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 26:
		{
			m_sErrorName = "ERROR_NOT_DOS_DISK";
			m_sErrorDescription = "The specified disk or diskette cannot be accessed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 27:
		{
			m_sErrorName = "ERROR_SECTOR_NOT_FOUND";
			m_sErrorDescription = "The drive cannot find the sector requested. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 28:
		{
			m_sErrorName = "ERROR_OUT_OF_PAPER";
			m_sErrorDescription = "The printer is out of paper. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 29:
		{
			m_sErrorName = "ERROR_WRITE_FAULT";
			m_sErrorDescription = "The system cannot write to the specified device. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 30:
		{
			m_sErrorName = "ERROR_READ_FAULT";
			m_sErrorDescription = "The system cannot read from the specified device. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 31:
		{
			m_sErrorName = "ERROR_GEN_FAILURE";
			m_sErrorDescription = "A device attached to the system is not functioning. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 32:
		{
			m_sErrorName = "ERROR_SHARING_VIOLATION";
			m_sErrorDescription = "The process cannot access the file because it is being used by another process. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 33:
		{
			m_sErrorName = "ERROR_LOCK_VIOLATION";
			m_sErrorDescription = "The process cannot access the file because another process has locked a portion of the file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 34:
		{
			m_sErrorName = "ERROR_WRONG_DISK";
			m_sErrorDescription = "The wrong diskette is in the drive. Insert %2 (Volume Serial Number: %3) into drive %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 36:
		{
			m_sErrorName = "ERROR_SHARING_BUFFER_EXCEEDED";
			m_sErrorDescription = "Too many files opened for sharing. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 38:
		{
			m_sErrorName = "ERROR_HANDLE_EOF";
			m_sErrorDescription = "Reached the end of the file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 39:
		{
			m_sErrorName = "ERROR_HANDLE_DISK_FULL";
			m_sErrorDescription = "The disk is full. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 50:
		{
			m_sErrorName = "ERROR_NOT_SUPPORTED";
			m_sErrorDescription = "The network request is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 51:
		{
			m_sErrorName = "ERROR_REM_NOT_LIST";
			m_sErrorDescription = "The remote computer is not available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 52:
		{
			m_sErrorName = "ERROR_DUP_NAME";
			m_sErrorDescription = "A duplicate name exists on the network. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 53:
		{
			m_sErrorName = "ERROR_BAD_NETPATH";
			m_sErrorDescription = "The network path was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 54:
		{
			m_sErrorName = "ERROR_NETWORK_BUSY";
			m_sErrorDescription = "The network is busy. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 55:
		{
			m_sErrorName = "ERROR_DEV_NOT_EXIST";
			m_sErrorDescription = "The specified network resource or device is no longer available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 56:
		{
			m_sErrorName = "ERROR_TOO_MANY_CMDS";
			m_sErrorDescription = "The network BIOS command limit has been reached. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 57:
		{
			m_sErrorName = "ERROR_ADAP_HDW_ERR";
			m_sErrorDescription = "A network adapter hardware error occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 58:
		{
			m_sErrorName = "ERROR_BAD_NET_RESP";
			m_sErrorDescription = "The specified server cannot perform the requested operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 59:
		{
			m_sErrorName = "ERROR_UNEXP_NET_ERR";
			m_sErrorDescription = "An unexpected network error occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 60:
		{
			m_sErrorName = "ERROR_BAD_REM_ADAP";
			m_sErrorDescription = "The remote adapter is not compatible. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 61:
		{
			m_sErrorName = "ERROR_PRINTQ_FULL";
			m_sErrorDescription = "The printer queue is full. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 62:
		{
			m_sErrorName = "ERROR_NO_SPOOL_SPACE";
			m_sErrorDescription = "Space to store the file waiting to be printed is not available on the server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 63:
		{
			m_sErrorName = "ERROR_PRINT_CANCELLED";
			m_sErrorDescription = "Your file waiting to be printed was deleted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 64:
		{
			m_sErrorName = "ERROR_NETNAME_DELETED";
			m_sErrorDescription = "The specified network name is no longer available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 65:
		{
			m_sErrorName = "ERROR_NETWORK_ACCESS_DENIED";
			m_sErrorDescription = "Network access is denied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 66:
		{
			m_sErrorName = "ERROR_BAD_DEV_TYPE";
			m_sErrorDescription = "The network resource type is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 67:
		{
			m_sErrorName = "ERROR_BAD_NET_NAME";
			m_sErrorDescription = "The network name cannot be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 68:
		{
			m_sErrorName = "ERROR_TOO_MANY_NAMES";
			m_sErrorDescription = "The name limit for the local computer network adapter card was exceeded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 69:
		{
			m_sErrorName = "ERROR_TOO_MANY_SESS";
			m_sErrorDescription = "The network BIOS session limit was exceeded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 70:
		{
			m_sErrorName = "ERROR_SHARING_PAUSED";
			m_sErrorDescription = "The remote server has been paused or is in the process of being started. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 71:
		{
			m_sErrorName = "ERROR_REQ_NOT_ACCEP";
			m_sErrorDescription = "No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 72:
		{
			m_sErrorName = "ERROR_REDIR_PAUSED";
			m_sErrorDescription = "The specified printer or disk device has been paused. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 80:
		{
			m_sErrorName = "ERROR_FILE_EXISTS";
			m_sErrorDescription = "The file exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 82:
		{
			m_sErrorName = "ERROR_CANNOT_MAKE";
			m_sErrorDescription = "The directory or file cannot be created. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 83:
		{
			m_sErrorName = "ERROR_FAIL_I24";
			m_sErrorDescription = "Fail on INT 24. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 84:
		{
			m_sErrorName = "ERROR_OUT_OF_STRUCTURES";
			m_sErrorDescription = "Storage to process this request is not available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 85:
		{
			m_sErrorName = "ERROR_ALREADY_ASSIGNED";
			m_sErrorDescription = "The local device name is already in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 86:
		{
			m_sErrorName = "ERROR_INVALID_PASSWORD";
			m_sErrorDescription = "The specified network password is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 87:
		{
			m_sErrorName = "ERROR_INVALID_PARAMETER";
			m_sErrorDescription = "The parameter is incorrect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 88:
		{
			m_sErrorName = "ERROR_NET_WRITE_FAULT";
			m_sErrorDescription = "A write fault occurred on the network. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 89:
		{
			m_sErrorName = "ERROR_NO_PROC_SLOTS";
			m_sErrorDescription = "The system cannot start another process at this time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 100:
		{
			m_sErrorName = "ERROR_TOO_MANY_SEMAPHORES";
			m_sErrorDescription = "Cannot create another system semaphore. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 101:
		{
			m_sErrorName = "ERROR_EXCL_SEM_ALREADY_OWNED";
			m_sErrorDescription = "The exclusive semaphore is owned by another process. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 102:
		{
			m_sErrorName = "ERROR_SEM_IS_SET";
			m_sErrorDescription = "The semaphore is set and cannot be closed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 103:
		{
			m_sErrorName = "ERROR_TOO_MANY_SEM_REQUESTS";
			m_sErrorDescription = "The semaphore cannot be set again. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 104:
		{
			m_sErrorName = "ERROR_INVALID_AT_INTERRUPT_TIME";
			m_sErrorDescription = "Cannot request exclusive semaphores at interrupt time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 105:
		{
			m_sErrorName = "ERROR_SEM_OWNER_DIED";
			m_sErrorDescription = "The previous ownership of this semaphore has ended. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 106:
		{
			m_sErrorName = "ERROR_SEM_USER_LIMIT";
			m_sErrorDescription = "Insert the diskette for drive %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 107:
		{
			m_sErrorName = "ERROR_DISK_CHANGE";
			m_sErrorDescription = "The program stopped because an alternate diskette was not inserted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 108:
		{
			m_sErrorName = "ERROR_DRIVE_LOCKED";
			m_sErrorDescription = "The disk is in use or locked by another process. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 109:
		{
			m_sErrorName = "ERROR_BROKEN_PIPE";
			m_sErrorDescription = "The pipe has been ended. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 110:
		{
			m_sErrorName = "ERROR_OPEN_FAILED";
			m_sErrorDescription = "The system cannot open the device or file specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 111:
		{
			m_sErrorName = "ERROR_BUFFER_OVERFLOW";
			m_sErrorDescription = "The file name is too long. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 112:
		{
			m_sErrorName = "ERROR_DISK_FULL";
			m_sErrorDescription = "There is not enough space on the disk. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 113:
		{
			m_sErrorName = "ERROR_NO_MORE_SEARCH_HANDLES";
			m_sErrorDescription = "No more internal file identifiers available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 114:
		{
			m_sErrorName = "ERROR_INVALID_TARGET_HANDLE";
			m_sErrorDescription = "The target internal file identifier is incorrect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 117:
		{
			m_sErrorName = "ERROR_INVALID_CATEGORY";
			m_sErrorDescription = "The IOCTL call made by the application program is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 118:
		{
			m_sErrorName = "ERROR_INVALID_VERIFY_SWITCH";
			m_sErrorDescription = "The verify-on-write switch parameter value is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 119:
		{
			m_sErrorName = "ERROR_BAD_DRIVER_LEVEL";
			m_sErrorDescription = "The system does not support the command requested. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 120:
		{
			m_sErrorName = "ERROR_CALL_NOT_IMPLEMENTED";
			m_sErrorDescription = "This function is not supported on this system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 121:
		{
			m_sErrorName = "ERROR_SEM_TIMEOUT";
			m_sErrorDescription = "The semaphore timeout period has expired. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 122:
		{
			m_sErrorName = "ERROR_INSUFFICIENT_BUFFER";
			m_sErrorDescription = "The data area passed to a system call is too small. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 123:
		{
			m_sErrorName = "ERROR_INVALID_NAME";
			m_sErrorDescription = "The filename, directory name, or volume label syntax is incorrect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 124:
		{
			m_sErrorName = "ERROR_INVALID_LEVEL";
			m_sErrorDescription = "The system call level is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 125:
		{
			m_sErrorName = "ERROR_NO_VOLUME_LABEL";
			m_sErrorDescription = "The disk has no volume label. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 126:
		{
			m_sErrorName = "ERROR_MOD_NOT_FOUND";
			m_sErrorDescription = "The specified module could not be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 127:
		{
			m_sErrorName = "ERROR_PROC_NOT_FOUND";
			m_sErrorDescription = "The specified procedure could not be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 128:
		{
			m_sErrorName = "ERROR_WAIT_NO_CHILDREN";
			m_sErrorDescription = "There are no child processes to wait for. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 129:
		{
			m_sErrorName = "ERROR_CHILD_NOT_COMPLETE";
			m_sErrorDescription = "The %1 application cannot be run in Win32 mode. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 130:
		{
			m_sErrorName = "ERROR_DIRECT_ACCESS_HANDLE";
			m_sErrorDescription = "Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 131:
		{
			m_sErrorName = "ERROR_NEGATIVE_SEEK";
			m_sErrorDescription = "An attempt was made to move the file pointer before the beginning of the file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 132:
		{
			m_sErrorName = "ERROR_SEEK_ON_DEVICE";
			m_sErrorDescription = "The file pointer cannot be set on the specified device or file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 133:
		{
			m_sErrorName = "ERROR_IS_JOIN_TARGET";
			m_sErrorDescription = "A JOIN or SUBST command cannot be used for a drive that contains previously joined drives. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 134:
		{
			m_sErrorName = "ERROR_IS_JOINED";
			m_sErrorDescription = "An attempt was made to use a JOIN or SUBST command on a drive that has already been joined. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 135:
		{
			m_sErrorName = "ERROR_IS_SUBSTED";
			m_sErrorDescription = "An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 136:
		{
			m_sErrorName = "ERROR_NOT_JOINED";
			m_sErrorDescription = "The system tried to delete the JOIN of a drive that is not joined. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 137:
		{
			m_sErrorName = "ERROR_NOT_SUBSTED";
			m_sErrorDescription = "The system tried to delete the substitution of a drive that is not substituted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 138:
		{
			m_sErrorName = "ERROR_JOIN_TO_JOIN";
			m_sErrorDescription = "The system tried to join a drive to a directory on a joined drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 139:
		{
			m_sErrorName = "ERROR_SUBST_TO_SUBST";
			m_sErrorDescription = "The system tried to substitute a drive to a directory on a substituted drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 140:
		{
			m_sErrorName = "ERROR_JOIN_TO_SUBST";
			m_sErrorDescription = "The system tried to join a drive to a directory on a substituted drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 141:
		{
			m_sErrorName = "ERROR_SUBST_TO_JOIN";
			m_sErrorDescription = "The system tried to SUBST a drive to a directory on a joined drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 142:
		{
			m_sErrorName = "ERROR_BUSY_DRIVE";
			m_sErrorDescription = "The system cannot perform a JOIN or SUBST at this time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 143:
		{
			m_sErrorName = "ERROR_SAME_DRIVE";
			m_sErrorDescription = "The system cannot join or substitute a drive to or for a directory on the same drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 144:
		{
			m_sErrorName = "ERROR_DIR_NOT_ROOT";
			m_sErrorDescription = "The directory is not a subdirectory of the root directory. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 145:
		{
			m_sErrorName = "ERROR_DIR_NOT_EMPTY";
			m_sErrorDescription = "The directory is not empty. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 146:
		{
			m_sErrorName = "ERROR_IS_SUBST_PATH";
			m_sErrorDescription = "The path specified is being used in a substitute. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 147:
		{
			m_sErrorName = "ERROR_IS_JOIN_PATH";
			m_sErrorDescription = "Not enough resources are available to process this command. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 148:
		{
			m_sErrorName = "ERROR_PATH_BUSY";
			m_sErrorDescription = "The path specified cannot be used at this time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 149:
		{
			m_sErrorName = "ERROR_IS_SUBST_TARGET";
			m_sErrorDescription = "An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 150:
		{
			m_sErrorName = "ERROR_SYSTEM_TRACE";
			m_sErrorDescription = "System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 151:
		{
			m_sErrorName = "ERROR_INVALID_EVENT_COUNT";
			m_sErrorDescription = "The number of specified semaphore events for DosMuxSemWait is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 152:
		{
			m_sErrorName = "ERROR_TOO_MANY_MUXWAITERS";
			m_sErrorDescription = "DosMuxSemWait did not execute; too many semaphores are already set. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 153:
		{
			m_sErrorName = "ERROR_INVALID_LIST_FORMAT";
			m_sErrorDescription = "The DosMuxSemWait list is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 154:
		{
			m_sErrorName = "ERROR_LABEL_TOO_LONG";
			m_sErrorDescription = "The volume label you entered exceeds the label character limit of the target file system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 155:
		{
			m_sErrorName = "ERROR_TOO_MANY_TCBS";
			m_sErrorDescription = "Cannot create another thread. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 156:
		{
			m_sErrorName = "ERROR_SIGNAL_REFUSED";
			m_sErrorDescription = "The recipient process has refused the signal. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 157:
		{
			m_sErrorName = "ERROR_DISCARDED";
			m_sErrorDescription = "The segment is already discarded and cannot be locked. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 158:
		{
			m_sErrorName = "ERROR_NOT_LOCKED";
			m_sErrorDescription = "The segment is already unlocked. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 159:
		{
			m_sErrorName = "ERROR_BAD_THREADID_ADDR";
			m_sErrorDescription = "The address for the thread ID is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 160:
		{
			m_sErrorName = "ERROR_BAD_ARGUMENTS";
			m_sErrorDescription = "The argument string passed to DosExecPgm is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 161:
		{
			m_sErrorName = "ERROR_BAD_PATHNAME";
			m_sErrorDescription = "The specified path is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 162:
		{
			m_sErrorName = "ERROR_SIGNAL_PENDING";
			m_sErrorDescription = "A signal is already pending. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 164:
		{
			m_sErrorName = "ERROR_MAX_THRDS_REACHED";
			m_sErrorDescription = "No more threads can be created in the system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 167:
		{
			m_sErrorName = "ERROR_LOCK_FAILED";
			m_sErrorDescription = "Unable to lock a region of a file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 170:
		{
			m_sErrorName = "ERROR_BUSY";
			m_sErrorDescription = "The requested resource is in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 173:
		{
			m_sErrorName = "ERROR_CANCEL_VIOLATION";
			m_sErrorDescription = "A lock request was not outstanding for the supplied cancel region. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 174:
		{
			m_sErrorName = "ERROR_ATOMIC_LOCKS_NOT_SUPPORTED";
			m_sErrorDescription = "The file system does not support atomic changes to the lock type. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 180:
		{
			m_sErrorName = "ERROR_INVALID_SEGMENT_NUMBER";
			m_sErrorDescription = "The system detected a segment number that was not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 182:
		{
			m_sErrorName = "ERROR_INVALID_ORDINAL";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 183:
		{
			m_sErrorName = "ERROR_ALREADY_EXISTS";
			m_sErrorDescription = "Cannot create a file when that file already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 186:
		{
			m_sErrorName = "ERROR_INVALID_FLAG_NUMBER";
			m_sErrorDescription = "The flag passed is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 187:
		{
			m_sErrorName = "ERROR_SEM_NOT_FOUND";
			m_sErrorDescription = "The specified system semaphore name was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 188:
		{
			m_sErrorName = "ERROR_INVALID_STARTING_CODESEG";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 189:
		{
			m_sErrorName = "ERROR_INVALID_STACKSEG";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 190:
		{
			m_sErrorName = "ERROR_INVALID_MODULETYPE";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 191:
		{
			m_sErrorName = "ERROR_INVALID_EXE_SIGNATURE";
			m_sErrorDescription = "Cannot run %1 in Win32 mode. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 192:
		{
			m_sErrorName = "ERROR_EXE_MARKED_INVALID";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 193:
		{
			m_sErrorName = "ERROR_BAD_EXE_FORMAT";
			m_sErrorDescription = "%1 is not a valid Win32 application. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 194:
		{
			m_sErrorName = "ERROR_ITERATED_DATA_EXCEEDS_64k";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 195:
		{
			m_sErrorName = "ERROR_INVALID_MINALLOCSIZE";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 196:
		{
			m_sErrorName = "ERROR_DYNLINK_FROM_INVALID_RING";
			m_sErrorDescription = "The operating system cannot run this application program. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 197:
		{
			m_sErrorName = "ERROR_IOPL_NOT_ENABLED";
			m_sErrorDescription = "The operating system is not presently configured to run this application. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 198:
		{
			m_sErrorName = "ERROR_INVALID_SEGDPL";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 199:
		{
			m_sErrorName = "ERROR_AUTODATASEG_EXCEEDS_64k";
			m_sErrorDescription = "The operating system cannot run this application program. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 200:
		{
			m_sErrorName = "ERROR_RING2SEG_MUST_BE_MOVABLE";
			m_sErrorDescription = "The code segment cannot be greater than or equal to 64K. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 201:
		{
			m_sErrorName = "ERROR_RELOC_CHAIN_XEEDS_SEGLIM";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 202:
		{
			m_sErrorName = "ERROR_INFLOOP_IN_RELOC_CHAIN";
			m_sErrorDescription = "The operating system cannot run %1. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 203:
		{
			m_sErrorName = "ERROR_ENVVAR_NOT_FOUND";
			m_sErrorDescription = "The system could not find the environment option that was entered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 205:
		{
			m_sErrorName = "ERROR_NO_SIGNAL_SENT";
			m_sErrorDescription = "No process in the command subtree has a signal handler. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 206:
		{
			m_sErrorName = "ERROR_FILENAME_EXCED_RANGE";
			m_sErrorDescription = "The filename or extension is too long. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 207:
		{
			m_sErrorName = "ERROR_RING2_STACK_IN_USE";
			m_sErrorDescription = "The ring 2 stack is in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 208:
		{
			m_sErrorName = "ERROR_META_EXPANSION_TOO_LONG";
			m_sErrorDescription = "The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 209:
		{
			m_sErrorName = "ERROR_INVALID_SIGNAL_NUMBER";
			m_sErrorDescription = "The signal being posted is not correct. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 210:
		{
			m_sErrorName = "ERROR_THREAD_1_INACTIVE";
			m_sErrorDescription = "The signal handler cannot be set. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 212:
		{
			m_sErrorName = "ERROR_LOCKED";
			m_sErrorDescription = "The segment is locked and cannot be reallocated. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 214:
		{
			m_sErrorName = "ERROR_TOO_MANY_MODULES";
			m_sErrorDescription = "Too many dynamic-link modules are attached to this program or dynamic-link module. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 215:
		{
			m_sErrorName = "ERROR_NESTING_NOT_ALLOWED";
			m_sErrorDescription = "Cannot nest calls to LoadModule. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 216:
		{
			m_sErrorName = "ERROR_EXE_MACHINE_TYPE_MISMATCH";
			m_sErrorDescription = "The image file %1 is valid, but is for a machine type other than the current machine. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 230:
		{
			m_sErrorName = "ERROR_BAD_PIPE";
			m_sErrorDescription = "The pipe state is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 231:
		{
			m_sErrorName = "ERROR_PIPE_BUSY";
			m_sErrorDescription = "All pipe instances are busy. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 232:
		{
			m_sErrorName = "ERROR_NO_DATA";
			m_sErrorDescription = "The pipe is being closed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 233:
		{
			m_sErrorName = "ERROR_PIPE_NOT_CONNECTED";
			m_sErrorDescription = "No process is on the other end of the pipe. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 234:
		{
			m_sErrorName = "ERROR_MORE_DATA";
			m_sErrorDescription = "More data is available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 240:
		{
			m_sErrorName = "ERROR_VC_DISCONNECTED";
			m_sErrorDescription = "The session was canceled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 254:
		{
			m_sErrorName = "ERROR_INVALID_EA_NAME";
			m_sErrorDescription = "The specified extended attribute name was invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 255:
		{
			m_sErrorName = "ERROR_EA_LIST_INCONSISTENT";
			m_sErrorDescription = "The extended attributes are inconsistent. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 258:
		{
			m_sErrorName = "WAIT_TIMEOUT";
			m_sErrorDescription = "The wait operation timed out. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 259:
		{
			m_sErrorName = "ERROR_NO_MORE_ITEMS";
			m_sErrorDescription = "No more data is available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 266:
		{
			m_sErrorName = "ERROR_CANNOT_COPY";
			m_sErrorDescription = "The copy functions cannot be used. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 267:
		{
			m_sErrorName = "ERROR_DIRECTORY";
			m_sErrorDescription = "The directory name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 275:
		{
			m_sErrorName = "ERROR_EAS_DIDNT_FIT";
			m_sErrorDescription = "The extended attributes did not fit in the buffer. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 276:
		{
			m_sErrorName = "ERROR_EA_FILE_CORRUPT";
			m_sErrorDescription = "The extended attribute file on the mounted file system is corrupt. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 277:
		{
			m_sErrorName = "ERROR_EA_TABLE_FULL";
			m_sErrorDescription = "The extended attribute table file is full. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 278:
		{
			m_sErrorName = "ERROR_INVALID_EA_HANDLE";
			m_sErrorDescription = "The specified extended attribute handle is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 282:
		{
			m_sErrorName = "ERROR_EAS_NOT_SUPPORTED";
			m_sErrorDescription = "The mounted file system does not support extended attributes. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 288:
		{
			m_sErrorName = "ERROR_NOT_OWNER";
			m_sErrorDescription = "Attempt to release mutex not owned by caller. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 298:
		{
			m_sErrorName = "ERROR_TOO_MANY_POSTS";
			m_sErrorDescription = "Too many posts were made to a semaphore. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 299:
		{
			m_sErrorName = "ERROR_PARTIAL_COPY";
			m_sErrorDescription = "Only part of a ReadProcessMemory or WriteProcessMemory request was completed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 300:
		{
			m_sErrorName = "ERROR_OPLOCK_NOT_GRANTED";
			m_sErrorDescription = "The oplock request is denied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 301:
		{
			m_sErrorName = "ERROR_INVALID_OPLOCK_PROTOCOL";
			m_sErrorDescription = "An invalid oplock acknowledgment was received by the system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 317:
		{
			m_sErrorName = "ERROR_MR_MID_NOT_FOUND";
			m_sErrorDescription = "The system cannot find message text for message number 0x%1 in the message file for %2. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 487:
		{
			m_sErrorName = "ERROR_INVALID_ADDRESS";
			m_sErrorDescription = "Attempt to access invalid address. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 534:
		{
			m_sErrorName = "ERROR_ARITHMETIC_OVERFLOW";
			m_sErrorDescription = "Arithmetic result exceeded 32 bits. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 535:
		{
			m_sErrorName = "ERROR_PIPE_CONNECTED";
			m_sErrorDescription = "There is a process on other end of the pipe. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 536:
		{
			m_sErrorName = "ERROR_PIPE_LISTENING";
			m_sErrorDescription = "Waiting for a process to open the other end of the pipe. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 994:
		{
			m_sErrorName = "ERROR_EA_ACCESS_DENIED";
			m_sErrorDescription = "Access to the extended attribute was denied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 995:
		{
			m_sErrorName = "ERROR_OPERATION_ABORTED";
			m_sErrorDescription = "The I/O operation has been aborted because of either a thread exit or an application request. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 996:
		{
			m_sErrorName = "ERROR_IO_INCOMPLETE";
			m_sErrorDescription = "Overlapped I/O event is not in a signaled state. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 997:
		{
			m_sErrorName = "ERROR_IO_PENDING";
			m_sErrorDescription = "Overlapped I/O operation is in progress. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 998:
		{
			m_sErrorName = "ERROR_NOACCESS";
			m_sErrorDescription = "Invalid access to memory location. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 999:
		{
			m_sErrorName = "ERROR_SWAPERROR";
			m_sErrorDescription = "Error performing inpage operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1001:
		{
			m_sErrorName = "ERROR_STACK_OVERFLOW";
			m_sErrorDescription = "Recursion too deep; the stack overflowed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1002:
		{
			m_sErrorName = "ERROR_INVALID_MESSAGE";
			m_sErrorDescription = "The window cannot act on the sent message. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1003:
		{
			m_sErrorName = "ERROR_CAN_NOT_COMPLETE";
			m_sErrorDescription = "Cannot complete this function. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1004:
		{
			m_sErrorName = "ERROR_INVALID_FLAGS";
			m_sErrorDescription = "Invalid flags. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1005:
		{
			m_sErrorName = "ERROR_UNRECOGNIZED_VOLUME";
			m_sErrorDescription = "The volume does not contain a recognized file system. Please make sure that all required file system drivers are loaded and that the volume is not corrupted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1006:
		{
			m_sErrorName = "ERROR_FILE_INVALID";
			m_sErrorDescription = "The volume for a file has been externally altered so that the opened file is no longer valid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1007:
		{
			m_sErrorName = "ERROR_FULLSCREEN_MODE";
			m_sErrorDescription = "The requested operation cannot be performed in full-screen mode. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1008:
		{
			m_sErrorName = "ERROR_NO_TOKEN";
			m_sErrorDescription = "An attempt was made to reference a token that does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1009:
		{
			m_sErrorName = "ERROR_BADDB";
			m_sErrorDescription = "The configuration registry database is corrupt. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1010:
		{
			m_sErrorName = "ERROR_BADKEY";
			m_sErrorDescription = "The configuration registry key is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1011:
		{
			m_sErrorName = "ERROR_CANTOPEN";
			m_sErrorDescription = "The configuration registry key could not be opened. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1012:
		{
			m_sErrorName = "ERROR_CANTREAD";
			m_sErrorDescription = "The configuration registry key could not be read. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1013:
		{
			m_sErrorName = "ERROR_CANTWRITE";
			m_sErrorDescription = "The configuration registry key could not be written. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1014:
		{
			m_sErrorName = "ERROR_REGISTRY_RECOVERED";
			m_sErrorDescription = "One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1015:
		{
			m_sErrorName = "ERROR_REGISTRY_CORRUPT";
			m_sErrorDescription = "The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1016:
		{
			m_sErrorName = "ERROR_REGISTRY_IO_FAILED";
			m_sErrorDescription = "An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1017:
		{
			m_sErrorName = "ERROR_NOT_REGISTRY_FILE";
			m_sErrorDescription = "The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1018:
		{
			m_sErrorName = "ERROR_KEY_DELETED";
			m_sErrorDescription = "Illegal operation attempted on a registry key that has been marked for deletion. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1019:
		{
			m_sErrorName = "ERROR_NO_LOG_SPACE";
			m_sErrorDescription = "System could not allocate the required space in a registry log. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1020:
		{
			m_sErrorName = "ERROR_KEY_HAS_CHILDREN";
			m_sErrorDescription = "Cannot create a symbolic link in a registry key that already has subkeys or values. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1021:
		{
			m_sErrorName = "ERROR_CHILD_MUST_BE_VOLATILE";
			m_sErrorDescription = "Cannot create a stable subkey under a volatile parent key. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1022:
		{
			m_sErrorName = "ERROR_NOTIFY_ENUM_DIR";
			m_sErrorDescription = "A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1051:
		{
			m_sErrorName = "ERROR_DEPENDENT_SERVICES_RUNNING";
			m_sErrorDescription = "A stop control has been sent to a service that other running services are dependent on. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1052:
		{
			m_sErrorName = "ERROR_INVALID_SERVICE_CONTROL";
			m_sErrorDescription = "The requested control is not valid for this service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1053:
		{
			m_sErrorName = "ERROR_SERVICE_REQUEST_TIMEOUT";
			m_sErrorDescription = "The service did not respond to the start or control request in a timely fashion. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1054:
		{
			m_sErrorName = "ERROR_SERVICE_NO_THREAD";
			m_sErrorDescription = "A thread could not be created for the service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1055:
		{
			m_sErrorName = "ERROR_SERVICE_DATABASE_LOCKED";
			m_sErrorDescription = "The service database is locked. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1056:
		{
			m_sErrorName = "ERROR_SERVICE_ALREADY_RUNNING";
			m_sErrorDescription = "An instance of the service is already running. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1057:
		{
			m_sErrorName = "ERROR_INVALID_SERVICE_ACCOUNT";
			m_sErrorDescription = "The account name is invalid or does not exist, or the password is invalid for the account name specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1058:
		{
			m_sErrorName = "ERROR_SERVICE_DISABLED";
			m_sErrorDescription = "The service cannot be started, either because it is disabled or because it has no enabled devices associated with it. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1059:
		{
			m_sErrorName = "ERROR_CIRCULAR_DEPENDENCY";
			m_sErrorDescription = "Circular service dependency was specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1060:
		{
			m_sErrorName = "ERROR_SERVICE_DOES_NOT_EXIST";
			m_sErrorDescription = "The specified service does not exist as an installed service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1061:
		{
			m_sErrorName = "ERROR_SERVICE_CANNOT_ACCEPT_CTRL";
			m_sErrorDescription = "The service cannot accept control messages at this time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1062:
		{
			m_sErrorName = "ERROR_SERVICE_NOT_ACTIVE";
			m_sErrorDescription = "The service has not been started. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1063:
		{
			m_sErrorName = "ERROR_FAILED_SERVICE_CONTROLLER_CONNECT";
			m_sErrorDescription = "The service process could not connect to the service controller. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1064:
		{
			m_sErrorName = "ERROR_EXCEPTION_IN_SERVICE";
			m_sErrorDescription = "An exception occurred in the service when handling the control request. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1065:
		{
			m_sErrorName = "ERROR_DATABASE_DOES_NOT_EXIST";
			m_sErrorDescription = "The database specified does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1066:
		{
			m_sErrorName = "ERROR_SERVICE_SPECIFIC_ERROR";
			m_sErrorDescription = "The service has returned a service-specific error code. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1067:
		{
			m_sErrorName = "ERROR_PROCESS_ABORTED";
			m_sErrorDescription = "The process terminated unexpectedly. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1068:
		{
			m_sErrorName = "ERROR_SERVICE_DEPENDENCY_FAIL";
			m_sErrorDescription = "The dependency service or group failed to start. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1069:
		{
			m_sErrorName = "ERROR_SERVICE_LOGON_FAILED";
			m_sErrorDescription = "The service did not start due to a logon failure. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1070:
		{
			m_sErrorName = "ERROR_SERVICE_START_HANG";
			m_sErrorDescription = "After starting, the service hung in a start-pending state. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1071:
		{
			m_sErrorName = "ERROR_INVALID_SERVICE_LOCK";
			m_sErrorDescription = "The specified service database lock is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1072:
		{
			m_sErrorName = "ERROR_SERVICE_MARKED_FOR_DELETE";
			m_sErrorDescription = "The specified service has been marked for deletion. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1073:
		{
			m_sErrorName = "ERROR_SERVICE_EXISTS";
			m_sErrorDescription = "The specified service already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1074:
		{
			m_sErrorName = "ERROR_ALREADY_RUNNING_LKG";
			m_sErrorDescription = "The system is currently running with the last-known-good configuration. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1075:
		{
			m_sErrorName = "ERROR_SERVICE_DEPENDENCY_DELETED";
			m_sErrorDescription = "The dependency service does not exist or has been marked for deletion. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1076:
		{
			m_sErrorName = "ERROR_BOOT_ALREADY_ACCEPTED";
			m_sErrorDescription = "The current boot has already been accepted for use as the last-known-good control set. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1077:
		{
			m_sErrorName = "ERROR_SERVICE_NEVER_STARTED";
			m_sErrorDescription = "No attempts to start the service have been made since the last boot. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1078:
		{
			m_sErrorName = "ERROR_DUPLICATE_SERVICE_NAME";
			m_sErrorDescription = "The name is already in use as either a service name or a service display name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1079:
		{
			m_sErrorName = "ERROR_DIFFERENT_SERVICE_ACCOUNT";
			m_sErrorDescription = "The account specified for this service is different from the account specified for other services running in the same process. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1080:
		{
			m_sErrorName = "ERROR_CANNOT_DETECT_DRIVER_FAILURE";
			m_sErrorDescription = "Failure actions can only be set for Win32 services, not for drivers. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1081:
		{
			m_sErrorName = "ERROR_CANNOT_DETECT_PROCESS_ABORT";
			m_sErrorDescription = "This service runs in the same process as the service control manager. Therefore, the service control manager cannot take action if this service's process terminates unexpectedly. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1082:
		{
			m_sErrorName = "ERROR_NO_RECOVERY_PROGRAM";
			m_sErrorDescription = "No recovery program has been configured for this service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1083:
		{
			m_sErrorName = "ERROR_SERVICE_NOT_IN_EXE";
			m_sErrorDescription = "The executable program that this service is configured to run in does not implement the service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1100:
		{
			m_sErrorName = "ERROR_END_OF_MEDIA";
			m_sErrorDescription = "The physical end of the tape has been reached. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1101:
		{
			m_sErrorName = "ERROR_FILEMARK_DETECTED";
			m_sErrorDescription = "A tape access reached a filemark. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1102:
		{
			m_sErrorName = "ERROR_BEGINNING_OF_MEDIA";
			m_sErrorDescription = "The beginning of the tape or a partition was encountered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1103:
		{
			m_sErrorName = "ERROR_SETMARK_DETECTED";
			m_sErrorDescription = "A tape access reached the end of a set of files. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1104:
		{
			m_sErrorName = "ERROR_NO_DATA_DETECTED";
			m_sErrorDescription = "No more data is on the tape. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1105:
		{
			m_sErrorName = "ERROR_PARTITION_FAILURE";
			m_sErrorDescription = "Tape could not be partitioned. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1106:
		{
			m_sErrorName = "ERROR_INVALID_BLOCK_LENGTH";
			m_sErrorDescription = "When accessing a new tape of a multivolume partition, the current block size is incorrect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1107:
		{
			m_sErrorName = "ERROR_DEVICE_NOT_PARTITIONED";
			m_sErrorDescription = "Tape partition information could not be found when loading a tape. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1108:
		{
			m_sErrorName = "ERROR_UNABLE_TO_LOCK_MEDIA";
			m_sErrorDescription = "Unable to lock the media eject mechanism. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1109:
		{
			m_sErrorName = "ERROR_UNABLE_TO_UNLOAD_MEDIA";
			m_sErrorDescription = "Unable to unload the media. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1110:
		{
			m_sErrorName = "ERROR_MEDIA_CHANGED";
			m_sErrorDescription = "The media in the drive may have changed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1111:
		{
			m_sErrorName = "ERROR_BUS_RESET";
			m_sErrorDescription = "The I/O bus was reset. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1112:
		{
			m_sErrorName = "ERROR_NO_MEDIA_IN_DRIVE";
			m_sErrorDescription = "No media in drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1113:
		{
			m_sErrorName = "ERROR_NO_UNICODE_TRANSLATION";
			m_sErrorDescription = "No mapping for the Unicode character exists in the target multi-byte code page. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1114:
		{
			m_sErrorName = "ERROR_DLL_INIT_FAILED";
			m_sErrorDescription = "A dynamic link library (DLL) initialization routine failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1115:
		{
			m_sErrorName = "ERROR_SHUTDOWN_IN_PROGRESS";
			m_sErrorDescription = "A system shutdown is in progress. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1116:
		{
			m_sErrorName = "ERROR_NO_SHUTDOWN_IN_PROGRESS";
			m_sErrorDescription = "Unable to abort the system shutdown because no shutdown was in progress. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1117:
		{
			m_sErrorName = "ERROR_IO_DEVICE";
			m_sErrorDescription = "The request could not be performed because of an I/O device error. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1118:
		{
			m_sErrorName = "ERROR_SERIAL_NO_DEVICE";
			m_sErrorDescription = "No serial device was successfully initialized. The serial driver will unload. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1119:
		{
			m_sErrorName = "ERROR_IRQ_BUSY";
			m_sErrorDescription = "Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1120:
		{
			m_sErrorName = "ERROR_MORE_WRITES";
			m_sErrorDescription = "A serial I/O operation was completed by another write to the serial port. (The IOCTL_SERIAL_XOFF_COUNTER reached zero.) ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1121:
		{
			m_sErrorName = "ERROR_COUNTER_TIMEOUT";
			m_sErrorDescription = "A serial I/O operation completed because the timeout period expired. (The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.) ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1122:
		{
			m_sErrorName = "ERROR_FLOPPY_ID_MARK_NOT_FOUND";
			m_sErrorDescription = "No ID address mark was found on the floppy disk. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1123:
		{
			m_sErrorName = "ERROR_FLOPPY_WRONG_CYLINDER";
			m_sErrorDescription = "Mismatch between the floppy disk sector ID field and the floppy disk controller track address. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1124:
		{
			m_sErrorName = "ERROR_FLOPPY_UNKNOWN_ERROR";
			m_sErrorDescription = "The floppy disk controller reported an error that is not recognized by the floppy disk driver. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1125:
		{
			m_sErrorName = "ERROR_FLOPPY_BAD_REGISTERS";
			m_sErrorDescription = "The floppy disk controller returned inconsistent results in its registers. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1126:
		{
			m_sErrorName = "ERROR_DISK_RECALIBRATE_FAILED";
			m_sErrorDescription = "While accessing the hard disk, a recalibrate operation failed, even after retries. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1127:
		{
			m_sErrorName = "ERROR_DISK_OPERATION_FAILED";
			m_sErrorDescription = "While accessing the hard disk, a disk operation failed even after retries. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1128:
		{
			m_sErrorName = "ERROR_DISK_RESET_FAILED";
			m_sErrorDescription = "While accessing the hard disk, a disk controller reset was needed, but even that failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1129:
		{
			m_sErrorName = "ERROR_EOM_OVERFLOW";
			m_sErrorDescription = "Physical end of tape encountered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1130:
		{
			m_sErrorName = "ERROR_NOT_ENOUGH_SERVER_MEMORY";
			m_sErrorDescription = "Not enough server storage is available to process this command. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1131:
		{
			m_sErrorName = "ERROR_POSSIBLE_DEADLOCK";
			m_sErrorDescription = "A potential deadlock condition has been detected. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1132:
		{
			m_sErrorName = "ERROR_MAPPED_ALIGNMENT";
			m_sErrorDescription = "The base address or the file offset specified does not have the proper alignment. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1140:
		{
			m_sErrorName = "ERROR_SET_POWER_STATE_VETOED";
			m_sErrorDescription = "An attempt to change the system power state was vetoed by another application or driver. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1141:
		{
			m_sErrorName = "ERROR_SET_POWER_STATE_FAILED";
			m_sErrorDescription = "The system BIOS failed an attempt to change the system power state. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1142:
		{
			m_sErrorName = "ERROR_TOO_MANY_LINKS";
			m_sErrorDescription = "An attempt was made to create more links on a file than the file system supports. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1150:
		{
			m_sErrorName = "ERROR_OLD_WIN_VERSION";
			m_sErrorDescription = "The specified program requires a newer version of Windows. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1151:
		{
			m_sErrorName = "ERROR_APP_WRONG_OS";
			m_sErrorDescription = "The specified program is not a Windows or MS-DOS program. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1152:
		{
			m_sErrorName = "ERROR_SINGLE_INSTANCE_APP";
			m_sErrorDescription = "Cannot start more than one instance of the specified program. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1153:
		{
			m_sErrorName = "ERROR_RMODE_APP";
			m_sErrorDescription = "The specified program was written for an earlier version of Windows. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1154:
		{
			m_sErrorName = "ERROR_INVALID_DLL";
			m_sErrorDescription = "One of the library files needed to run this application is damaged. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1155:
		{
			m_sErrorName = "ERROR_NO_ASSOCIATION";
			m_sErrorDescription = "No application is associated with the specified file for this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1156:
		{
			m_sErrorName = "ERROR_DDE_FAIL";
			m_sErrorDescription = "An error occurred in sending the command to the application. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1157:
		{
			m_sErrorName = "ERROR_DLL_NOT_FOUND";
			m_sErrorDescription = "One of the library files needed to run this application cannot be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1158:
		{
			m_sErrorName = "ERROR_NO_MORE_USER_HANDLES";
			m_sErrorDescription = "The current process has used all of its system allowance of handles for Window Manager objects. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1159:
		{
			m_sErrorName = "ERROR_MESSAGE_SYNC_ONLY";
			m_sErrorDescription = "The message can be used only with synchronous operations. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1160:
		{
			m_sErrorName = "ERROR_SOURCE_ELEMENT_EMPTY";
			m_sErrorDescription = "The indicated source element has no media. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1161:
		{
			m_sErrorName = "ERROR_DESTINATION_ELEMENT_FULL";
			m_sErrorDescription = "The indicated destination element already contains media. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1162:
		{
			m_sErrorName = "ERROR_ILLEGAL_ELEMENT_ADDRESS";
			m_sErrorDescription = "The indicated element does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1163:
		{
			m_sErrorName = "ERROR_MAGAZINE_NOT_PRESENT";
			m_sErrorDescription = "The indicated element is part of a magazine that is not present. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1164:
		{
			m_sErrorName = "ERROR_DEVICE_REINITIALIZATION_NEEDED";
			m_sErrorDescription = "The indicated device requires reinitialization due to hardware errors. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1165:
		{
			m_sErrorName = "ERROR_DEVICE_REQUIRES_CLEANING";
			m_sErrorDescription = "The device has indicated that cleaning is required before further operations are attempted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1166:
		{
			m_sErrorName = "ERROR_DEVICE_DOOR_OPEN";
			m_sErrorDescription = "The device has indicated that its door is open. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1167:
		{
			m_sErrorName = "ERROR_DEVICE_NOT_CONNECTED";
			m_sErrorDescription = "The device is not connected. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1168:
		{
			m_sErrorName = "ERROR_NOT_FOUND";
			m_sErrorDescription = "Element not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1169:
		{
			m_sErrorName = "ERROR_NO_MATCH";
			m_sErrorDescription = "There was no match for the specified key in the index. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1170:
		{
			m_sErrorName = "ERROR_SET_NOT_FOUND";
			m_sErrorDescription = "The property set specified does not exist on the object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1171:
		{
			m_sErrorName = "ERROR_POINT_NOT_FOUND";
			m_sErrorDescription = "The point passed to GetMouseMovePointsEx is not in the buffer. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1172:
		{
			m_sErrorName = "ERROR_NO_TRACKING_SERVICE";
			m_sErrorDescription = "The tracking (workstation) service is not running. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1173:
		{
			m_sErrorName = "ERROR_NO_VOLUME_ID";
			m_sErrorDescription = "The Volume ID could not be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1175:
		{
			m_sErrorName = "ERROR_UNABLE_TO_REMOVE_REPLACED";
			m_sErrorDescription = "Unable to remove the file to be replaced. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1176:
		{
			m_sErrorName = "ERROR_UNABLE_TO_MOVE_REPLACEMENT";
			m_sErrorDescription = "Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1177:
		{
			m_sErrorName = "ERROR_UNABLE_TO_MOVE_REPLACEMENT_2";
			m_sErrorDescription = "Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1178:
		{
			m_sErrorName = "ERROR_JOURNAL_DELETE_IN_PROGRESS";
			m_sErrorDescription = "The volume change journal is being deleted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1179:
		{
			m_sErrorName = "ERROR_JOURNAL_NOT_ACTIVE";
			m_sErrorDescription = "The volume change journal service is not active. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1180:
		{
			m_sErrorName = "ERROR_POTENTIAL_FILE_FOUND";
			m_sErrorDescription = "A file was found, but it may not be the correct file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1181:
		{
			m_sErrorName = "ERROR_JOURNAL_ENTRY_DELETED";
			m_sErrorDescription = "The journal entry has been deleted from the journal.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1200:
		{
			m_sErrorName = "ERROR_BAD_DEVICE";
			m_sErrorDescription = "The specified device name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1201:
		{
			m_sErrorName = "ERROR_CONNECTION_UNAVAIL";
			m_sErrorDescription = "The device is not currently connected but it is a remembered connection. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1202:
		{
			m_sErrorName = "ERROR_DEVICE_ALREADY_REMEMBERED";
			m_sErrorDescription = "An attempt was made to remember a device that had previously been remembered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1203:
		{
			m_sErrorName = "ERROR_NO_NET_OR_BAD_PATH";
			m_sErrorDescription = "No network provider accepted the given network path. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1204:
		{
			m_sErrorName = "ERROR_BAD_PROVIDER";
			m_sErrorDescription = "The specified network provider name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1205:
		{
			m_sErrorName = "ERROR_CANNOT_OPEN_PROFILE";
			m_sErrorDescription = "Unable to open the network connection profile. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1206:
		{
			m_sErrorName = "ERROR_BAD_PROFILE";
			m_sErrorDescription = "The network connection profile is corrupted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1207:
		{
			m_sErrorName = "ERROR_NOT_CONTAINER";
			m_sErrorDescription = "Cannot enumerate a noncontainer. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1208:
		{
			m_sErrorName = "ERROR_EXTENDED_ERROR";
			m_sErrorDescription = "An extended error has occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1209:
		{
			m_sErrorName = "ERROR_INVALID_GROUPNAME";
			m_sErrorDescription = "The format of the specified group name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1210:
		{
			m_sErrorName = "ERROR_INVALID_COMPUTERNAME";
			m_sErrorDescription = "The format of the specified computer name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1211:
		{
			m_sErrorName = "ERROR_INVALID_EVENTNAME";
			m_sErrorDescription = "The format of the specified event name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1212:
		{
			m_sErrorName = "ERROR_INVALID_DOMAINNAME";
			m_sErrorDescription = "The format of the specified domain name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1213:
		{
			m_sErrorName = "ERROR_INVALID_SERVICENAME";
			m_sErrorDescription = "The format of the specified service name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1214:
		{
			m_sErrorName = "ERROR_INVALID_NETNAME";
			m_sErrorDescription = "The format of the specified network name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1215:
		{
			m_sErrorName = "ERROR_INVALID_SHARENAME";
			m_sErrorDescription = "The format of the specified share name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1216:
		{
			m_sErrorName = "ERROR_INVALID_PASSWORDNAME";
			m_sErrorDescription = "The format of the specified password is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1217:
		{
			m_sErrorName = "ERROR_INVALID_MESSAGENAME";
			m_sErrorDescription = "The format of the specified message name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1218:
		{
			m_sErrorName = "ERROR_INVALID_MESSAGEDEST";
			m_sErrorDescription = "The format of the specified message destination is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1219:
		{
			m_sErrorName = "ERROR_SESSION_CREDENTIAL_CONFLICT";
			m_sErrorDescription = "The credentials supplied conflict with an existing set of credentials. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1220:
		{
			m_sErrorName = "ERROR_REMOTE_SESSION_LIMIT_EXCEEDED";
			m_sErrorDescription = "An attempt was made to establish a session to a network server, but there are already too many sessions established to that server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1221:
		{
			m_sErrorName = "ERROR_DUP_DOMAINNAME";
			m_sErrorDescription = "The workgroup or domain name is already in use by another computer on the network. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1222:
		{
			m_sErrorName = "ERROR_NO_NETWORK";
			m_sErrorDescription = "The network is not present or not started. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1223:
		{
			m_sErrorName = "ERROR_CANCELLED";
			m_sErrorDescription = "The operation was canceled by the user. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1224:
		{
			m_sErrorName = "ERROR_USER_MAPPED_FILE";
			m_sErrorDescription = "The requested operation cannot be performed on a file with a user-mapped section open. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1225:
		{
			m_sErrorName = "ERROR_CONNECTION_REFUSED";
			m_sErrorDescription = "The remote system refused the network connection. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1226:
		{
			m_sErrorName = "ERROR_GRACEFUL_DISCONNECT";
			m_sErrorDescription = "The network connection was gracefully closed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1227:
		{
			m_sErrorName = "ERROR_ADDRESS_ALREADY_ASSOCIATED";
			m_sErrorDescription = "The network transport endpoint already has an address associated with it. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1228:
		{
			m_sErrorName = "ERROR_ADDRESS_NOT_ASSOCIATED";
			m_sErrorDescription = "An address has not yet been associated with the network endpoint. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1229:
		{
			m_sErrorName = "ERROR_CONNECTION_INVALID";
			m_sErrorDescription = "An operation was attempted on a nonexistent network connection. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1230:
		{
			m_sErrorName = "ERROR_CONNECTION_ACTIVE";
			m_sErrorDescription = "An invalid operation was attempted on an active network connection. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1231:
		{
			m_sErrorName = "ERROR_NETWORK_UNREACHABLE";
			m_sErrorDescription = "The network location cannot be reached. For information about network troubleshooting, see Windows Help. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1232:
		{
			m_sErrorName = "ERROR_HOST_UNREACHABLE";
			m_sErrorDescription = "The network location cannot be reached. For information about network troubleshooting, see Windows Help. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1233:
		{
			m_sErrorName = "ERROR_PROTOCOL_UNREACHABLE";
			m_sErrorDescription = "The network location cannot be reached. For information about network troubleshooting, see Windows Help. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1234:
		{
			m_sErrorName = "ERROR_PORT_UNREACHABLE";
			m_sErrorDescription = "No service is operating at the destination network endpoint on the remote system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1235:
		{
			m_sErrorName = "ERROR_REQUEST_ABORTED";
			m_sErrorDescription = "The request was aborted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1236:
		{
			m_sErrorName = "ERROR_CONNECTION_ABORTED";
			m_sErrorDescription = "The network connection was aborted by the local system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1237:
		{
			m_sErrorName = "ERROR_RETRY";
			m_sErrorDescription = "The operation could not be completed. A retry should be performed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1238:
		{
			m_sErrorName = "ERROR_CONNECTION_COUNT_LIMIT";
			m_sErrorDescription = "A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1239:
		{
			m_sErrorName = "ERROR_LOGIN_TIME_RESTRICTION";
			m_sErrorDescription = "Attempting to log in during an unauthorized time of day for this account. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1240:
		{
			m_sErrorName = "ERROR_LOGIN_WKSTA_RESTRICTION";
			m_sErrorDescription = "The account is not authorized to log in from this station. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1241:
		{
			m_sErrorName = "ERROR_INCORRECT_ADDRESS";
			m_sErrorDescription = "The network address could not be used for the operation requested. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1242:
		{
			m_sErrorName = "ERROR_ALREADY_REGISTERED";
			m_sErrorDescription = "The service is already registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1243:
		{
			m_sErrorName = "ERROR_SERVICE_NOT_FOUND";
			m_sErrorDescription = "The specified service does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1244:
		{
			m_sErrorName = "ERROR_NOT_AUTHENTICATED";
			m_sErrorDescription = "The operation being requested was not performed because the user has not been authenticated. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1245:
		{
			m_sErrorName = "ERROR_NOT_LOGGED_ON";
			m_sErrorDescription = "The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1246:
		{
			m_sErrorName = "ERROR_CONTINUE";
			m_sErrorDescription = "Continue with work in progress. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1247:
		{
			m_sErrorName = "ERROR_ALREADY_INITIALIZED";
			m_sErrorDescription = "An attempt was made to perform an initialization operation when initialization has already been completed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1248:
		{
			m_sErrorName = "ERROR_NO_MORE_DEVICES";
			m_sErrorDescription = "No more local devices. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1249:
		{
			m_sErrorName = "ERROR_NO_SUCH_SITE";
			m_sErrorDescription = "The specified site does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1250:
		{
			m_sErrorName = "ERROR_DOMAIN_CONTROLLER_EXISTS";
			m_sErrorDescription = "A domain controller with the specified name already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1251:
		{
			m_sErrorName = "ERROR_ONLY_IF_CONNECTED";
			m_sErrorDescription = "This operation is supported only when you are connected to the server.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1252:
		{
			m_sErrorName = "ERROR_OVERRIDE_NOCHANGES";
			m_sErrorDescription = "The group policy framework should call the extension even if there are no changes.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1253:
		{
			m_sErrorName = "ERROR_BAD_USER_PROFILE";
			m_sErrorDescription = "The specified user does not have a valid profile.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1254:
		{
			m_sErrorName = "ERROR_NOT_SUPPORTED_ON_SBS";
			m_sErrorDescription = "This operation is not supported on a Microsoft Small Business Server.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1300:
		{
			m_sErrorName = "ERROR_NOT_ALL_ASSIGNED";
			m_sErrorDescription = "Not all privileges referenced are assigned to the caller. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1301:
		{
			m_sErrorName = "ERROR_SOME_NOT_MAPPED";
			m_sErrorDescription = "Some mapping between account names and security IDs was not done. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1302:
		{
			m_sErrorName = "ERROR_NO_QUOTAS_FOR_ACCOUNT";
			m_sErrorDescription = "No system quota limits are specifically set for this account. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1303:
		{
			m_sErrorName = "ERROR_LOCAL_USER_SESSION_KEY";
			m_sErrorDescription = "No encryption key is available. A well-known encryption key was returned. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1304:
		{
			m_sErrorName = "ERROR_NULL_LM_PASSWORD";
			m_sErrorDescription = "The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1305:
		{
			m_sErrorName = "ERROR_UNKNOWN_REVISION";
			m_sErrorDescription = "The revision level is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8399:
		{
			m_sErrorName = "ERROR_DS_ATT_SCHEMA_REQ_ID";
			m_sErrorDescription = "Cannot read the governs class identifier for the schema record.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8400:
		{
			m_sErrorName = "ERROR_DS_BAD_ATT_SCHEMA_SYNTAX";
			m_sErrorDescription = "The attribute schema has bad syntax.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8401:
		{
			m_sErrorName = "ERROR_DS_CANT_CACHE_ATT";
			m_sErrorDescription = "The attribute could not be cached.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8402:
		{
			m_sErrorName = "ERROR_DS_CANT_CACHE_CLASS";
			m_sErrorDescription = "The class could not be cached.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8403:
		{
			m_sErrorName = "ERROR_DS_CANT_REMOVE_ATT_CACHE";
			m_sErrorDescription = "The attribute could not be removed from the cache.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8404:
		{
			m_sErrorName = "ERROR_DS_CANT_REMOVE_CLASS_CACHE";
			m_sErrorDescription = "The class could not be removed from the cache.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8405:
		{
			m_sErrorName = "ERROR_DS_CANT_RETRIEVE_DN";
			m_sErrorDescription = "The distinguished name attribute could not be read.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8406:
		{
			m_sErrorName = "ERROR_DS_MISSING_SUPREF";
			m_sErrorDescription = "A required subref is missing.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8407:
		{
			m_sErrorName = "ERROR_DS_CANT_RETRIEVE_INSTANCE";
			m_sErrorDescription = "The instance type attribute could not be retrieved.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8408:
		{
			m_sErrorName = "ERROR_DS_CODE_INCONSISTENCY";
			m_sErrorDescription = "An internal error has occurred.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8409:
		{
			m_sErrorName = "ERROR_DS_DATABASE_ERROR";
			m_sErrorDescription = "A database error has occurred.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8410:
		{
			m_sErrorName = "ERROR_DS_GOVERNSID_MISSING";
			m_sErrorDescription = "The attribute GOVERNSID is missing.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8411:
		{
			m_sErrorName = "ERROR_DS_MISSING_EXPECTED_ATT";
			m_sErrorDescription = "An expected attribute is missing.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8412:
		{
			m_sErrorName = "ERROR_DS_NCNAME_MISSING_CR_REF";
			m_sErrorDescription = "The specified naming context is missing a cross reference.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8413:
		{
			m_sErrorName = "ERROR_DS_SECURITY_CHECKING_ERROR";
			m_sErrorDescription = "A security checking error has occurred.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8414:
		{
			m_sErrorName = "ERROR_DS_SCHEMA_NOT_LOADED";
			m_sErrorDescription = "The schema is not loaded.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8415:
		{
			m_sErrorName = "ERROR_DS_SCHEMA_ALLOC_FAILED";
			m_sErrorDescription = "Schema allocation failed. Please check if the machine is running low on memory. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8416:
		{
			m_sErrorName = "ERROR_DS_ATT_SCHEMA_REQ_SYNTAX";
			m_sErrorDescription = "Failed to obtain the required syntax for the attribute schema.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8417:
		{
			m_sErrorName = "ERROR_DS_GCVERIFY_ERROR";
			m_sErrorDescription = "The global catalog verification failed. The global catalog is not available or does not support the operation. Some part of the directory is currently not available.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8418:
		{
			m_sErrorName = "ERROR_DS_DRA_SCHEMA_MISMATCH";
			m_sErrorDescription = "The replication operation failed because of a schema mismatch between the servers involved. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8419:
		{
			m_sErrorName = "ERROR_DS_CANT_FIND_DSA_OBJ";
			m_sErrorDescription = "The DSA object could not be found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8420:
		{
			m_sErrorName = "ERROR_DS_CANT_FIND_EXPECTED_NC";
			m_sErrorDescription = "The naming context could not be found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8421:
		{
			m_sErrorName = "ERROR_DS_CANT_FIND_NC_IN_CACHE";
			m_sErrorDescription = "The naming context could not be found in the cache.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8422:
		{
			m_sErrorName = "ERROR_DS_CANT_RETRIEVE_CHILD";
			m_sErrorDescription = "The child object could not be retrieved.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8423:
		{
			m_sErrorName = "ERROR_DS_SECURITY_ILLEGAL_MODIFY";
			m_sErrorDescription = "The modification was not permitted for security reasons.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8424:
		{
			m_sErrorName = "ERROR_DS_CANT_REPLACE_HIDDEN_REC";
			m_sErrorDescription = "The operation cannot replace the hidden record.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8425:
		{
			m_sErrorName = "ERROR_DS_BAD_HIERARCHY_FILE";
			m_sErrorDescription = "The hierarchy file is invalid.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8426:
		{
			m_sErrorName = "ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED";
			m_sErrorDescription = "The attempt to build the hierarchy table failed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8427:
		{
			m_sErrorName = "ERROR_DS_CONFIG_PARAM_MISSING";
			m_sErrorDescription = "The directory configuration parameter is missing from the registry.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8428:
		{
			m_sErrorName = "ERROR_DS_COUNTING_AB_INDICES_FAILED";
			m_sErrorDescription = "The attempt to count the address book indices failed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8429:
		{
			m_sErrorName = "ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED";
			m_sErrorDescription = "The allocation of the hierarchy table failed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8430:
		{
			m_sErrorName = "ERROR_DS_INTERNAL_FAILURE";
			m_sErrorDescription = "The directory service encountered an internal failure. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8431:
		{
			m_sErrorName = "ERROR_DS_UNKNOWN_ERROR";
			m_sErrorDescription = "The directory service encountered an unknown failure. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8432:
		{
			m_sErrorName = "ERROR_DS_ROOT_REQUIRES_CLASS_TOP";
			m_sErrorDescription = "A root object requires a class of 'top'.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8433:
		{
			m_sErrorName = "ERROR_DS_REFUSING_FSMO_ROLES";
			m_sErrorDescription = "This directory server is shutting down, and cannot take ownership of new floating single-master operation roles. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8434:
		{
			m_sErrorName = "ERROR_DS_MISSING_FSMO_SETTINGS";
			m_sErrorDescription = "The directory service is missing mandatory configuration information, and is unable to determine the ownership of floating single-master operation roles. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8435:
		{
			m_sErrorName = "ERROR_DS_UNABLE_TO_SURRENDER_ROLES";
			m_sErrorDescription = "The directory service was unable to transfer ownership of one or more floating single-master operation roles to other servers. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8436:
		{
			m_sErrorName = "ERROR_DS_DRA_GENERIC";
			m_sErrorDescription = "The replication operation failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8437:
		{
			m_sErrorName = "ERROR_DS_DRA_INVALID_PARAMETER";
			m_sErrorDescription = "An invalid parameter was specified for this replication operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8438:
		{
			m_sErrorName = "ERROR_DS_DRA_BUSY";
			m_sErrorDescription = "The directory service is too busy to complete the replication operation at this time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8439:
		{
			m_sErrorName = "ERROR_DS_DRA_BAD_DN";
			m_sErrorDescription = "The distinguished name specified for this replication operation is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8440:
		{
			m_sErrorName = "ERROR_DS_DRA_BAD_NC";
			m_sErrorDescription = "The naming context specified for this replication operation is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8441:
		{
			m_sErrorName = "ERROR_DS_DRA_DN_EXISTS";
			m_sErrorDescription = "The distinguished name specified for this replication operation already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8442:
		{
			m_sErrorName = "ERROR_DS_DRA_INTERNAL_ERROR";
			m_sErrorDescription = "The replication system encountered an internal error. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8443:
		{
			m_sErrorName = "ERROR_DS_DRA_INCONSISTENT_DIT";
			m_sErrorDescription = "The replication operation encountered a database inconsistency. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8444:
		{
			m_sErrorName = "ERROR_DS_DRA_CONNECTION_FAILED";
			m_sErrorDescription = "The server specified for this replication operation could not be contacted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8445:
		{
			m_sErrorName = "ERROR_DS_DRA_BAD_INSTANCE_TYPE";
			m_sErrorDescription = "The replication operation encountered an object with an invalid instance type. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8446:
		{
			m_sErrorName = "ERROR_DS_DRA_OUT_OF_MEM";
			m_sErrorDescription = "The replication operation failed to allocate memory. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8447:
		{
			m_sErrorName = "ERROR_DS_DRA_MAIL_PROBLEM";
			m_sErrorDescription = "The replication operation encountered an error with the mail system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8448:
		{
			m_sErrorName = "ERROR_DS_DRA_REF_ALREADY_EXISTS";
			m_sErrorDescription = "The replication reference information for the target server already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8449:
		{
			m_sErrorName = "ERROR_DS_DRA_REF_NOT_FOUND";
			m_sErrorDescription = "The replication reference information for the target server does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8450:
		{
			m_sErrorName = "ERROR_DS_DRA_OBJ_IS_REP_SOURCE";
			m_sErrorDescription = "The naming context cannot be removed because it is replicated to another server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8451:
		{
			m_sErrorName = "ERROR_DS_DRA_DB_ERROR";
			m_sErrorDescription = "The replication operation encountered a database error. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8452:
		{
			m_sErrorName = "ERROR_DS_DRA_NO_REPLICA";
			m_sErrorDescription = "The naming context is in the process of being removed or is not replicated from the specified server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8453:
		{
			m_sErrorName = "ERROR_DS_DRA_ACCESS_DENIED";
			m_sErrorDescription = "Replication access was denied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8454:
		{
			m_sErrorName = "ERROR_DS_DRA_NOT_SUPPORTED";
			m_sErrorDescription = "The requested operation is not supported by this version of the directory service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8455:
		{
			m_sErrorName = "ERROR_DS_DRA_RPC_CANCELLED";
			m_sErrorDescription = "The replication remote procedure call was cancelled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8456:
		{
			m_sErrorName = "ERROR_DS_DRA_SOURCE_DISABLED";
			m_sErrorDescription = "The source server is currently rejecting replication requests. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8457:
		{
			m_sErrorName = "ERROR_DS_DRA_SINK_DISABLED";
			m_sErrorDescription = "The destination server is currently rejecting replication requests. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1306:
		{
			m_sErrorName = "ERROR_REVISION_MISMATCH";
			m_sErrorDescription = "Indicates two revision levels are incompatible. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1307:
		{
			m_sErrorName = "ERROR_INVALID_OWNER";
			m_sErrorDescription = "This security ID may not be assigned as the owner of this object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1308:
		{
			m_sErrorName = "ERROR_INVALID_PRIMARY_GROUP";
			m_sErrorDescription = "This security ID may not be assigned as the primary group of an object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1309:
		{
			m_sErrorName = "ERROR_NO_IMPERSONATION_TOKEN";
			m_sErrorDescription = "An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1310:
		{
			m_sErrorName = "ERROR_CANT_DISABLE_MANDATORY";
			m_sErrorDescription = "The group may not be disabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1311:
		{
			m_sErrorName = "ERROR_NO_LOGON_SERVERS";
			m_sErrorDescription = "There are currently no logon servers available to service the logon request. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1312:
		{
			m_sErrorName = "ERROR_NO_SUCH_LOGON_SESSION";
			m_sErrorDescription = "A specified logon session does not exist. It may already have been terminated. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1313:
		{
			m_sErrorName = "ERROR_NO_SUCH_PRIVILEGE";
			m_sErrorDescription = "A specified privilege does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1314:
		{
			m_sErrorName = "ERROR_PRIVILEGE_NOT_HELD";
			m_sErrorDescription = "A required privilege is not held by the client. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1315:
		{
			m_sErrorName = "ERROR_INVALID_ACCOUNT_NAME";
			m_sErrorDescription = "The name provided is not a properly formed account name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1316:
		{
			m_sErrorName = "ERROR_USER_EXISTS";
			m_sErrorDescription = "The specified user already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1317:
		{
			m_sErrorName = "ERROR_NO_SUCH_USER";
			m_sErrorDescription = "The specified user does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1318:
		{
			m_sErrorName = "ERROR_GROUP_EXISTS";
			m_sErrorDescription = "The specified group already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1319:
		{
			m_sErrorName = "ERROR_NO_SUCH_GROUP";
			m_sErrorDescription = "The specified group does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1320:
		{
			m_sErrorName = "ERROR_MEMBER_IN_GROUP";
			m_sErrorDescription = "Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1321:
		{
			m_sErrorName = "ERROR_MEMBER_NOT_IN_GROUP";
			m_sErrorDescription = "The specified user account is not a member of the specified group account. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1322:
		{
			m_sErrorName = "ERROR_LAST_ADMIN";
			m_sErrorDescription = "The last remaining administration account cannot be disabled or deleted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1323:
		{
			m_sErrorName = "ERROR_WRONG_PASSWORD";
			m_sErrorDescription = "Unable to update the password. The value provided as the current password is incorrect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1324:
		{
			m_sErrorName = "ERROR_ILL_FORMED_PASSWORD";
			m_sErrorDescription = "Unable to update the password. The value provided for the new password contains values that are not allowed in passwords. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1325:
		{
			m_sErrorName = "ERROR_PASSWORD_RESTRICTION";
			m_sErrorDescription = "Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirement of the domain. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1326:
		{
			m_sErrorName = "ERROR_LOGON_FAILURE";
			m_sErrorDescription = "Logon failure: unknown user name or bad password. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1327:
		{
			m_sErrorName = "ERROR_ACCOUNT_RESTRICTION";
			m_sErrorDescription = "Logon failure: user account restriction. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1328:
		{
			m_sErrorName = "ERROR_INVALID_LOGON_HOURS";
			m_sErrorDescription = "Logon failure: account logon time restriction violation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1329:
		{
			m_sErrorName = "ERROR_INVALID_WORKSTATION";
			m_sErrorDescription = "Logon failure: user not allowed to log on to this computer. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1330:
		{
			m_sErrorName = "ERROR_PASSWORD_EXPIRED";
			m_sErrorDescription = "Logon failure: the specified account password has expired. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1331:
		{
			m_sErrorName = "ERROR_ACCOUNT_DISABLED";
			m_sErrorDescription = "Logon failure: account currently disabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1332:
		{
			m_sErrorName = "ERROR_NONE_MAPPED";
			m_sErrorDescription = "No mapping between account names and security IDs was done. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1333:
		{
			m_sErrorName = "ERROR_TOO_MANY_LUIDS_REQUESTED";
			m_sErrorDescription = "Too many local user identifiers (LUIDs) were requested at one time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1334:
		{
			m_sErrorName = "ERROR_LUIDS_EXHAUSTED";
			m_sErrorDescription = "No more local user identifiers (LUIDs) are available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1335:
		{
			m_sErrorName = "ERROR_INVALID_SUB_AUTHORITY";
			m_sErrorDescription = "The subauthority part of a security ID is invalid for this particular use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1336:
		{
			m_sErrorName = "ERROR_INVALID_ACL";
			m_sErrorDescription = "The access control list (ACL) structure is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1337:
		{
			m_sErrorName = "ERROR_INVALID_SID";
			m_sErrorDescription = "The security ID structure is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1338:
		{
			m_sErrorName = "ERROR_INVALID_SECURITY_DESCR";
			m_sErrorDescription = "The security descriptor structure is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1340:
		{
			m_sErrorName = "ERROR_BAD_INHERITANCE_ACL";
			m_sErrorDescription = "The inherited access control list (ACL) or access control entry (ACE) could not be built. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1341:
		{
			m_sErrorName = "ERROR_SERVER_DISABLED";
			m_sErrorDescription = "The server is currently disabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1342:
		{
			m_sErrorName = "ERROR_SERVER_NOT_DISABLED";
			m_sErrorDescription = "The server is currently enabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1343:
		{
			m_sErrorName = "ERROR_INVALID_ID_AUTHORITY";
			m_sErrorDescription = "The value provided was an invalid value for an identifier authority. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1344:
		{
			m_sErrorName = "ERROR_ALLOTTED_SPACE_EXCEEDED";
			m_sErrorDescription = "No more memory is available for security information updates. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1345:
		{
			m_sErrorName = "ERROR_INVALID_GROUP_ATTRIBUTES";
			m_sErrorDescription = "The specified attributes are invalid, or incompatible with the attributes for the group as a whole. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1346:
		{
			m_sErrorName = "ERROR_BAD_IMPERSONATION_LEVEL";
			m_sErrorDescription = "Either a required impersonation level was not provided, or the provided impersonation level is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1347:
		{
			m_sErrorName = "ERROR_CANT_OPEN_ANONYMOUS";
			m_sErrorDescription = "Cannot open an anonymous level security token. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1348:
		{
			m_sErrorName = "ERROR_BAD_VALIDATION_CLASS";
			m_sErrorDescription = "The validation information class requested was invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1349:
		{
			m_sErrorName = "ERROR_BAD_TOKEN_TYPE";
			m_sErrorDescription = "The type of the token is inappropriate for its attempted use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1350:
		{
			m_sErrorName = "ERROR_NO_SECURITY_ON_OBJECT";
			m_sErrorDescription = "Unable to perform a security operation on an object that has no associated security. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1351:
		{
			m_sErrorName = "ERROR_CANT_ACCESS_DOMAIN_INFO";
			m_sErrorDescription = "Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1352:
		{
			m_sErrorName = "ERROR_INVALID_SERVER_STATE";
			m_sErrorDescription = "The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1353:
		{
			m_sErrorName = "ERROR_INVALID_DOMAIN_STATE";
			m_sErrorDescription = "The domain was in the wrong state to perform the security operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1354:
		{
			m_sErrorName = "ERROR_INVALID_DOMAIN_ROLE";
			m_sErrorDescription = "This operation is only allowed for the Primary Domain Controller of the domain. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1355:
		{
			m_sErrorName = "ERROR_NO_SUCH_DOMAIN";
			m_sErrorDescription = "The specified domain either does not exist or could not be contacted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1356:
		{
			m_sErrorName = "ERROR_DOMAIN_EXISTS";
			m_sErrorDescription = "The specified domain already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1357:
		{
			m_sErrorName = "ERROR_DOMAIN_LIMIT_EXCEEDED";
			m_sErrorDescription = "An attempt was made to exceed the limit on the number of domains per server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1358:
		{
			m_sErrorName = "ERROR_INTERNAL_DB_CORRUPTION";
			m_sErrorDescription = "Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1359:
		{
			m_sErrorName = "ERROR_INTERNAL_ERROR";
			m_sErrorDescription = "An internal error occurred.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1360:
		{
			m_sErrorName = "ERROR_GENERIC_NOT_MAPPED";
			m_sErrorDescription = "Generic access types were contained in an access mask which should already be mapped to nongeneric types. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1361:
		{
			m_sErrorName = "ERROR_BAD_DESCRIPTOR_FORMAT";
			m_sErrorDescription = "A security descriptor is not in the right format (absolute or self-relative). ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1362:
		{
			m_sErrorName = "ERROR_NOT_LOGON_PROCESS";
			m_sErrorDescription = "The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1363:
		{
			m_sErrorName = "ERROR_LOGON_SESSION_EXISTS";
			m_sErrorDescription = "Cannot start a new logon session with an ID that is already in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1364:
		{
			m_sErrorName = "ERROR_NO_SUCH_PACKAGE";
			m_sErrorDescription = "A specified authentication package is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1365:
		{
			m_sErrorName = "ERROR_BAD_LOGON_SESSION_STATE";
			m_sErrorDescription = "The logon session is not in a state that is consistent with the requested operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1366:
		{
			m_sErrorName = "ERROR_LOGON_SESSION_COLLISION";
			m_sErrorDescription = "The logon session ID is already in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1367:
		{
			m_sErrorName = "ERROR_INVALID_LOGON_TYPE";
			m_sErrorDescription = "A logon request contained an invalid logon type value. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1368:
		{
			m_sErrorName = "ERROR_CANNOT_IMPERSONATE";
			m_sErrorDescription = "Unable to impersonate using a named pipe until data has been read from that pipe. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1369:
		{
			m_sErrorName = "ERROR_RXACT_INVALID_STATE";
			m_sErrorDescription = "The transaction state of a registry subtree is incompatible with the requested operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1370:
		{
			m_sErrorName = "ERROR_RXACT_COMMIT_FAILURE";
			m_sErrorDescription = "An internal security database corruption has been encountered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1371:
		{
			m_sErrorName = "ERROR_SPECIAL_ACCOUNT";
			m_sErrorDescription = "Cannot perform this operation on built-in accounts. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1372:
		{
			m_sErrorName = "ERROR_SPECIAL_GROUP";
			m_sErrorDescription = "Cannot perform this operation on this built-in special group. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1373:
		{
			m_sErrorName = "ERROR_SPECIAL_USER";
			m_sErrorDescription = "Cannot perform this operation on this built-in special user. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1374:
		{
			m_sErrorName = "ERROR_MEMBERS_PRIMARY_GROUP";
			m_sErrorDescription = "The user cannot be removed from a group because the group is currently the user's primary group. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1375:
		{
			m_sErrorName = "ERROR_TOKEN_ALREADY_IN_USE";
			m_sErrorDescription = "The token is already in use as a primary token. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1376:
		{
			m_sErrorName = "ERROR_NO_SUCH_ALIAS";
			m_sErrorDescription = "The specified local group does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1377:
		{
			m_sErrorName = "ERROR_MEMBER_NOT_IN_ALIAS";
			m_sErrorDescription = "The specified account name is not a member of the local group. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1378:
		{
			m_sErrorName = "ERROR_MEMBER_IN_ALIAS";
			m_sErrorDescription = "The specified account name is already a member of the local group. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1379:
		{
			m_sErrorName = "ERROR_ALIAS_EXISTS";
			m_sErrorDescription = "The specified local group already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1380:
		{
			m_sErrorName = "ERROR_LOGON_NOT_GRANTED";
			m_sErrorDescription = "Logon failure: the user has not been granted the requested logon type at this computer. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1381:
		{
			m_sErrorName = "ERROR_TOO_MANY_SECRETS";
			m_sErrorDescription = "The maximum number of secrets that may be stored in a single system has been exceeded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1382:
		{
			m_sErrorName = "ERROR_SECRET_TOO_LONG";
			m_sErrorDescription = "The length of a secret exceeds the maximum length allowed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1383:
		{
			m_sErrorName = "ERROR_INTERNAL_DB_ERROR";
			m_sErrorDescription = "The local security authority database contains an internal inconsistency. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1384:
		{
			m_sErrorName = "ERROR_TOO_MANY_CONTEXT_IDS";
			m_sErrorDescription = "During a logon attempt, the user's security context accumulated too many security IDs. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1385:
		{
			m_sErrorName = "ERROR_LOGON_TYPE_NOT_GRANTED";
			m_sErrorDescription = "Logon failure: the user has not been granted the requested logon type at this computer. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1386:
		{
			m_sErrorName = "ERROR_NT_CROSS_ENCRYPTION_REQUIRED";
			m_sErrorDescription = "A cross-encrypted password is necessary to change a user password. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1387:
		{
			m_sErrorName = "ERROR_NO_SUCH_MEMBER";
			m_sErrorDescription = "A new member could not be added to or removed from the local group because the member does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1388:
		{
			m_sErrorName = "ERROR_INVALID_MEMBER";
			m_sErrorDescription = "A new member could not be added to a local group because the member has the wrong account type. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1389:
		{
			m_sErrorName = "ERROR_TOO_MANY_SIDS";
			m_sErrorDescription = "Too many security IDs have been specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1390:
		{
			m_sErrorName = "ERROR_LM_CROSS_ENCRYPTION_REQUIRED";
			m_sErrorDescription = "A cross-encrypted password is necessary to change this user password. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1391:
		{
			m_sErrorName = "ERROR_NO_INHERITANCE";
			m_sErrorDescription = "Indicates an ACL contains no inheritable components. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1392:
		{
			m_sErrorName = "ERROR_FILE_CORRUPT";
			m_sErrorDescription = "The file or directory is corrupted and unreadable. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1393:
		{
			m_sErrorName = "ERROR_DISK_CORRUPT";
			m_sErrorDescription = "The disk structure is corrupted and unreadable. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1394:
		{
			m_sErrorName = "ERROR_NO_USER_SESSION_KEY";
			m_sErrorDescription = "There is no user session key for the specified logon session. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1395:
		{
			m_sErrorName = "ERROR_LICENSE_QUOTA_EXCEEDED";
			m_sErrorDescription = "The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1396:
		{
			m_sErrorName = "ERROR_WRONG_TARGET_NAME";
			m_sErrorDescription = "Logon Failure: The target account name is incorrect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1397:
		{
			m_sErrorName = "ERROR_MUTUAL_AUTH_FAILED";
			m_sErrorDescription = "Mutual Authentication failed. The server's password is out of date at the domain controller. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1398:
		{
			m_sErrorName = "ERROR_TIME_SKEW";
			m_sErrorDescription = "There is a time difference between the client and server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1400:
		{
			m_sErrorName = "ERROR_INVALID_WINDOW_HANDLE";
			m_sErrorDescription = "Invalid window handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1401:
		{
			m_sErrorName = "ERROR_INVALID_MENU_HANDLE";
			m_sErrorDescription = "Invalid menu handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1402:
		{
			m_sErrorName = "ERROR_INVALID_CURSOR_HANDLE";
			m_sErrorDescription = "Invalid cursor handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1403:
		{
			m_sErrorName = "ERROR_INVALID_ACCEL_HANDLE";
			m_sErrorDescription = "Invalid accelerator table handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1404:
		{
			m_sErrorName = "ERROR_INVALID_HOOK_HANDLE";
			m_sErrorDescription = "Invalid hook handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1405:
		{
			m_sErrorName = "ERROR_INVALID_DWP_HANDLE";
			m_sErrorDescription = "Invalid handle to a multiple-window position structure. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1406:
		{
			m_sErrorName = "ERROR_TLW_WITH_WSCHILD";
			m_sErrorDescription = "Cannot create a top-level child window. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1407:
		{
			m_sErrorName = "ERROR_CANNOT_FIND_WND_CLASS";
			m_sErrorDescription = "Cannot find window class. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1408:
		{
			m_sErrorName = "ERROR_WINDOW_OF_OTHER_THREAD";
			m_sErrorDescription = "Invalid window; it belongs to other thread. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1409:
		{
			m_sErrorName = "ERROR_HOTKEY_ALREADY_REGISTERED";
			m_sErrorDescription = "Hot key is already registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1410:
		{
			m_sErrorName = "ERROR_CLASS_ALREADY_EXISTS";
			m_sErrorDescription = "Class already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1411:
		{
			m_sErrorName = "ERROR_CLASS_DOES_NOT_EXIST";
			m_sErrorDescription = "Class does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1412:
		{
			m_sErrorName = "ERROR_CLASS_HAS_WINDOWS";
			m_sErrorDescription = "Class still has open windows. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1413:
		{
			m_sErrorName = "ERROR_INVALID_INDEX";
			m_sErrorDescription = "Invalid index. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1414:
		{
			m_sErrorName = "ERROR_INVALID_ICON_HANDLE";
			m_sErrorDescription = "Invalid icon handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1415:
		{
			m_sErrorName = "ERROR_PRIVATE_DIALOG_INDEX";
			m_sErrorDescription = "Using private DIALOG window words. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1416:
		{
			m_sErrorName = "ERROR_LISTBOX_ID_NOT_FOUND";
			m_sErrorDescription = "The list box identifier was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1417:
		{
			m_sErrorName = "ERROR_NO_WILDCARD_CHARACTERS";
			m_sErrorDescription = "No wildcards were found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1418:
		{
			m_sErrorName = "ERROR_CLIPBOARD_NOT_OPEN";
			m_sErrorDescription = "Thread does not have a clipboard open. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1419:
		{
			m_sErrorName = "ERROR_HOTKEY_NOT_REGISTERED";
			m_sErrorDescription = "Hot key is not registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1420:
		{
			m_sErrorName = "ERROR_WINDOW_NOT_DIALOG";
			m_sErrorDescription = "The window is not a valid dialog window. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1421:
		{
			m_sErrorName = "ERROR_CONTROL_ID_NOT_FOUND";
			m_sErrorDescription = "Control ID not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1422:
		{
			m_sErrorName = "ERROR_INVALID_COMBOBOX_MESSAGE";
			m_sErrorDescription = "Invalid message for a combo box because it does not have an edit control. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1423:
		{
			m_sErrorName = "ERROR_WINDOW_NOT_COMBOBOX";
			m_sErrorDescription = "The window is not a combo box. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1424:
		{
			m_sErrorName = "ERROR_INVALID_EDIT_HEIGHT";
			m_sErrorDescription = "Height must be less than 256. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1425:
		{
			m_sErrorName = "ERROR_DC_NOT_FOUND";
			m_sErrorDescription = "Invalid device context (DC) handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1426:
		{
			m_sErrorName = "ERROR_INVALID_HOOK_FILTER";
			m_sErrorDescription = "Invalid hook procedure type. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1427:
		{
			m_sErrorName = "ERROR_INVALID_FILTER_PROC";
			m_sErrorDescription = "Invalid hook procedure. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1428:
		{
			m_sErrorName = "ERROR_HOOK_NEEDS_HMOD";
			m_sErrorDescription = "Cannot set nonlocal hook without a module handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1429:
		{
			m_sErrorName = "ERROR_GLOBAL_ONLY_HOOK";
			m_sErrorDescription = "This hook procedure can only be set globally. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1430:
		{
			m_sErrorName = "ERROR_JOURNAL_HOOK_SET";
			m_sErrorDescription = "The journal hook procedure is already installed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1431:
		{
			m_sErrorName = "ERROR_HOOK_NOT_INSTALLED";
			m_sErrorDescription = "The hook procedure is not installed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1432:
		{
			m_sErrorName = "ERROR_INVALID_LB_MESSAGE";
			m_sErrorDescription = "Invalid message for single-selection list box. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1433:
		{
			m_sErrorName = "ERROR_SETCOUNT_ON_BAD_LB";
			m_sErrorDescription = "LB_SETCOUNT sent to non-lazy list box. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1434:
		{
			m_sErrorName = "ERROR_LB_WITHOUT_TABSTOPS";
			m_sErrorDescription = "This list box does not support tab stops. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1435:
		{
			m_sErrorName = "ERROR_DESTROY_OBJECT_OF_OTHER_THREAD";
			m_sErrorDescription = "Cannot destroy object created by another thread. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1436:
		{
			m_sErrorName = "ERROR_CHILD_WINDOW_MENU";
			m_sErrorDescription = "Child windows cannot have menus. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1437:
		{
			m_sErrorName = "ERROR_NO_SYSTEM_MENU";
			m_sErrorDescription = "The window does not have a system menu. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1438:
		{
			m_sErrorName = "ERROR_INVALID_MSGBOX_STYLE";
			m_sErrorDescription = "Invalid message box style. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1439:
		{
			m_sErrorName = "ERROR_INVALID_SPI_VALUE";
			m_sErrorDescription = "Invalid system-wide (SPI_*) parameter. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1440:
		{
			m_sErrorName = "ERROR_SCREEN_ALREADY_LOCKED";
			m_sErrorDescription = "Screen already locked. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1441:
		{
			m_sErrorName = "ERROR_HWNDS_HAVE_DIFF_PARENT";
			m_sErrorDescription = "All handles to windows in a multiple-window position structure must have the same parent. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1442:
		{
			m_sErrorName = "ERROR_NOT_CHILD_WINDOW";
			m_sErrorDescription = "The window is not a child window. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1443:
		{
			m_sErrorName = "ERROR_INVALID_GW_COMMAND";
			m_sErrorDescription = "Invalid GW_* command. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1444:
		{
			m_sErrorName = "ERROR_INVALID_THREAD_ID";
			m_sErrorDescription = "Invalid thread identifier. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1445:
		{
			m_sErrorName = "ERROR_NON_MDICHILD_WINDOW";
			m_sErrorDescription = "Cannot process a message from a window that is not a multiple document interface (MDI) window. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1446:
		{
			m_sErrorName = "ERROR_POPUP_ALREADY_ACTIVE";
			m_sErrorDescription = "Popup menu already active. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1447:
		{
			m_sErrorName = "ERROR_NO_SCROLLBARS";
			m_sErrorDescription = "The window does not have scroll bars. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1448:
		{
			m_sErrorName = "ERROR_INVALID_SCROLLBAR_RANGE";
			m_sErrorDescription = "Scroll bar range cannot be greater than MAXLONG. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1449:
		{
			m_sErrorName = "ERROR_INVALID_SHOWWIN_COMMAND";
			m_sErrorDescription = "Cannot show or remove the window in the way specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1450:
		{
			m_sErrorName = "ERROR_NO_SYSTEM_RESOURCES";
			m_sErrorDescription = "Insufficient system resources exist to complete the requested service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1451:
		{
			m_sErrorName = "ERROR_NONPAGED_SYSTEM_RESOURCES";
			m_sErrorDescription = "Insufficient system resources exist to complete the requested service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1452:
		{
			m_sErrorName = "ERROR_PAGED_SYSTEM_RESOURCES";
			m_sErrorDescription = "Insufficient system resources exist to complete the requested service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1453:
		{
			m_sErrorName = "ERROR_WORKING_SET_QUOTA";
			m_sErrorDescription = "Insufficient quota to complete the requested service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1454:
		{
			m_sErrorName = "ERROR_PAGEFILE_QUOTA";
			m_sErrorDescription = "Insufficient quota to complete the requested service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1455:
		{
			m_sErrorName = "ERROR_COMMITMENT_LIMIT";
			m_sErrorDescription = "The paging file is too small for this operation to complete. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1456:
		{
			m_sErrorName = "ERROR_MENU_ITEM_NOT_FOUND";
			m_sErrorDescription = "A menu item was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1457:
		{
			m_sErrorName = "ERROR_INVALID_KEYBOARD_HANDLE";
			m_sErrorDescription = "Invalid keyboard layout handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1458:
		{
			m_sErrorName = "ERROR_HOOK_TYPE_NOT_ALLOWED";
			m_sErrorDescription = "Hook type not allowed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1459:
		{
			m_sErrorName = "ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION";
			m_sErrorDescription = "This operation requires an interactive window station. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1460:
		{
			m_sErrorName = "ERROR_TIMEOUT";
			m_sErrorDescription = "This operation returned because the timeout period expired. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1461:
		{
			m_sErrorName = "ERROR_INVALID_MONITOR_HANDLE";
			m_sErrorDescription = "Invalid monitor handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1500:
		{
			m_sErrorName = "ERROR_EVENTLOG_FILE_CORRUPT";
			m_sErrorDescription = "The event log file is corrupted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1501:
		{
			m_sErrorName = "ERROR_EVENTLOG_CANT_START";
			m_sErrorDescription = "No event log file could be opened, so the event logging service did not start. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1502:
		{
			m_sErrorName = "ERROR_LOG_FILE_FULL";
			m_sErrorDescription = "The event log file is full. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1503:
		{
			m_sErrorName = "ERROR_EVENTLOG_FILE_CHANGED";
			m_sErrorDescription = "The event log file has changed between read operations. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1601:
		{
			m_sErrorName = "ERROR_INSTALL_SERVICE_FAILURE";
			m_sErrorDescription = "The Windows Installer service could not be accessed. Contact your support personnel to verify that the Windows Installer service is properly registered.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1602:
		{
			m_sErrorName = "ERROR_INSTALL_USEREXIT";
			m_sErrorDescription = "User cancelled installation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1603:
		{
			m_sErrorName = "ERROR_INSTALL_FAILURE";
			m_sErrorDescription = "Fatal error during installation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1604:
		{
			m_sErrorName = "ERROR_INSTALL_SUSPEND";
			m_sErrorDescription = "Installation suspended, incomplete. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1605:
		{
			m_sErrorName = "ERROR_UNKNOWN_PRODUCT";
			m_sErrorDescription = "This action is only valid for products that are currently installed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1606:
		{
			m_sErrorName = "ERROR_UNKNOWN_FEATURE";
			m_sErrorDescription = "Feature ID not registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1607:
		{
			m_sErrorName = "ERROR_UNKNOWN_COMPONENT";
			m_sErrorDescription = "Component ID not registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1608:
		{
			m_sErrorName = "ERROR_UNKNOWN_PROPERTY";
			m_sErrorDescription = "Unknown property. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1609:
		{
			m_sErrorName = "ERROR_INVALID_HANDLE_STATE";
			m_sErrorDescription = "Handle is in an invalid state. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1610:
		{
			m_sErrorName = "ERROR_BAD_CONFIGURATION";
			m_sErrorDescription = "The configuration data for this product is corrupt. Contact your support personnel. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1611:
		{
			m_sErrorName = "ERROR_INDEX_ABSENT";
			m_sErrorDescription = "Component qualifier not present. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1612:
		{
			m_sErrorName = "ERROR_INSTALL_SOURCE_ABSENT";
			m_sErrorDescription = "The installation source for this product is not available. Verify that the source exists and that you can access it. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1613:
		{
			m_sErrorName = "ERROR_INSTALL_PACKAGE_VERSION";
			m_sErrorDescription = "This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1614:
		{
			m_sErrorName = "ERROR_PRODUCT_UNINSTALLED";
			m_sErrorDescription = "Product is uninstalled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1615:
		{
			m_sErrorName = "ERROR_BAD_QUERY_SYNTAX";
			m_sErrorDescription = "SQL query syntax invalid or unsupported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1616:
		{
			m_sErrorName = "ERROR_INVALID_FIELD";
			m_sErrorDescription = "Record field does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1617:
		{
			m_sErrorName = "ERROR_DEVICE_REMOVED";
			m_sErrorDescription = "The device has been removed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1618:
		{
			m_sErrorName = "ERROR_INSTALL_ALREADY_RUNNING";
			m_sErrorDescription = "Another installation is already in progress. Complete that installation before proceeding with this install. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1619:
		{
			m_sErrorName = "ERROR_INSTALL_PACKAGE_OPEN_FAILED";
			m_sErrorDescription = "This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1620:
		{
			m_sErrorName = "ERROR_INSTALL_PACKAGE_INVALID";
			m_sErrorDescription = "This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1621:
		{
			m_sErrorName = "ERROR_INSTALL_UI_FAILURE";
			m_sErrorDescription = "There was an error starting the Windows Installer service user interface. Contact your support personnel. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1622:
		{
			m_sErrorName = "ERROR_INSTALL_LOG_FAILURE";
			m_sErrorDescription = "Error opening installation log file. Verify that the specified log file location exists and that you can write to it. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1623:
		{
			m_sErrorName = "ERROR_INSTALL_LANGUAGE_UNSUPPORTED";
			m_sErrorDescription = "The language of this installation package is not supported by your system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1624:
		{
			m_sErrorName = "ERROR_INSTALL_TRANSFORM_FAILURE";
			m_sErrorDescription = "Error applying transforms. Verify that the specified transform paths are valid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1625:
		{
			m_sErrorName = "ERROR_INSTALL_PACKAGE_REJECTED";
			m_sErrorDescription = "This installation is forbidden by system policy. Contact your system administrator. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1626:
		{
			m_sErrorName = "ERROR_FUNCTION_NOT_CALLED";
			m_sErrorDescription = "Function could not be executed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1627:
		{
			m_sErrorName = "ERROR_FUNCTION_FAILED";
			m_sErrorDescription = "Function failed during execution.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1628:
		{
			m_sErrorName = "ERROR_INVALID_TABLE";
			m_sErrorDescription = "Invalid or unknown table specified.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1629:
		{
			m_sErrorName = "ERROR_DATATYPE_MISMATCH";
			m_sErrorDescription = "Data supplied is of wrong type.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1630:
		{
			m_sErrorName = "ERROR_UNSUPPORTED_TYPE";
			m_sErrorDescription = "Data of this type is not supported.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1631:
		{
			m_sErrorName = "ERROR_CREATE_FAILED";
			m_sErrorDescription = "The Windows Installer service failed to start. Contact your support personnel. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1632:
		{
			m_sErrorName = "ERROR_INSTALL_TEMP_UNWRITABLE";
			m_sErrorDescription = "The temp folder is either full or inaccessible. Verify that the temp folder exists and that you can write to it. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1633:
		{
			m_sErrorName = "ERROR_INSTALL_PLATFORM_UNSUPPORTED";
			m_sErrorDescription = "This installation package is not supported by this processor type. Contact your product vendor. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1634:
		{
			m_sErrorName = "ERROR_INSTALL_NOTUSED";
			m_sErrorDescription = "Component not used on this computer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1635:
		{
			m_sErrorName = "ERROR_PATCH_PACKAGE_OPEN_FAILED";
			m_sErrorDescription = "This patch package could not be opened. Verify that the patch package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer patch package. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1636:
		{
			m_sErrorName = "ERROR_PATCH_PACKAGE_INVALID";
			m_sErrorDescription = "This patch package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer patch package. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1637:
		{
			m_sErrorName = "ERROR_PATCH_PACKAGE_UNSUPPORTED.";
			m_sErrorDescription = "This patch package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1638:
		{
			m_sErrorName = "ERROR_PRODUCT_VERSION";
			m_sErrorDescription = "Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1639:
		{
			m_sErrorName = "ERROR_INVALID_COMMAND_LINE";
			m_sErrorDescription = "Invalid command line argument. Consult the Windows Installer SDK for detailed command line help. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1640:
		{
			m_sErrorName = "ERROR_INSTALL_REMOTE_DISALLOWED";
			m_sErrorDescription = "Only administrators have permission to add, remove, or configure server software during a Terminal Services remote session. If you want to install or configure software on the server, contact your network administrator.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1641:
		{
			m_sErrorName = "ERROR_SUCCESS_REBOOT_INITIATED";
			m_sErrorDescription = "The requested operation completed successfully. The system will be restarted so the changes can take effect.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1642:
		{
			m_sErrorName = " ";
			m_sErrorDescription = "The upgrade patch cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade patch may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade patch.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1700:
		{
			m_sErrorName = "RPC_S_INVALID_STRING_BINDING";
			m_sErrorDescription = "The string binding is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1701:
		{
			m_sErrorName = "RPC_S_WRONG_KIND_OF_BINDING";
			m_sErrorDescription = "The binding handle is not the correct type. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1702:
		{
			m_sErrorName = "RPC_S_INVALID_BINDING";
			m_sErrorDescription = "The binding handle is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1703:
		{
			m_sErrorName = "RPC_S_PROTSEQ_NOT_SUPPORTED";
			m_sErrorDescription = "The RPC protocol sequence is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1704:
		{
			m_sErrorName = "RPC_S_INVALID_RPC_PROTSEQ";
			m_sErrorDescription = "The RPC protocol sequence is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1705:
		{
			m_sErrorName = "RPC_S_INVALID_STRING_UUID";
			m_sErrorDescription = "The string universal unique identifier (UUID) is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1706:
		{
			m_sErrorName = "RPC_S_INVALID_ENDPOINT_FORMAT";
			m_sErrorDescription = "The endpoint format is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1707:
		{
			m_sErrorName = "RPC_S_INVALID_NET_ADDR";
			m_sErrorDescription = "The network address is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1708:
		{
			m_sErrorName = "RPC_S_NO_ENDPOINT_FOUND";
			m_sErrorDescription = "No endpoint was found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1709:
		{
			m_sErrorName = "RPC_S_INVALID_TIMEOUT";
			m_sErrorDescription = "The timeout value is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1710:
		{
			m_sErrorName = "RPC_S_OBJECT_NOT_FOUND";
			m_sErrorDescription = "The object universal unique identifier (UUID) was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1711:
		{
			m_sErrorName = "RPC_S_ALREADY_REGISTERED";
			m_sErrorDescription = "The object universal unique identifier (UUID) has already been registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1712:
		{
			m_sErrorName = "RPC_S_TYPE_ALREADY_REGISTERED";
			m_sErrorDescription = "The type universal unique identifier (UUID) has already been registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1713:
		{
			m_sErrorName = "RPC_S_ALREADY_LISTENING";
			m_sErrorDescription = "The RPC server is already listening. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1714:
		{
			m_sErrorName = "RPC_S_NO_PROTSEQS_REGISTERED";
			m_sErrorDescription = "No protocol sequences have been registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1715:
		{
			m_sErrorName = "RPC_S_NOT_LISTENING";
			m_sErrorDescription = "The RPC server is not listening. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1716:
		{
			m_sErrorName = "RPC_S_UNKNOWN_MGR_TYPE";
			m_sErrorDescription = "The manager type is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1717:
		{
			m_sErrorName = "RPC_S_UNKNOWN_IF";
			m_sErrorDescription = "The interface is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1718:
		{
			m_sErrorName = "RPC_S_NO_BINDINGS";
			m_sErrorDescription = "There are no bindings. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1719:
		{
			m_sErrorName = "RPC_S_NO_PROTSEQS";
			m_sErrorDescription = "There are no protocol sequences. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1720:
		{
			m_sErrorName = "RPC_S_CANT_CREATE_ENDPOINT";
			m_sErrorDescription = "The endpoint cannot be created. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1721:
		{
			m_sErrorName = "RPC_S_OUT_OF_RESOURCES";
			m_sErrorDescription = "Not enough resources are available to complete this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1722:
		{
			m_sErrorName = "RPC_S_SERVER_UNAVAILABLE";
			m_sErrorDescription = "The RPC server is unavailable. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1723:
		{
			m_sErrorName = "RPC_S_SERVER_TOO_BUSY";
			m_sErrorDescription = "The RPC server is too busy to complete this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1724:
		{
			m_sErrorName = "RPC_S_INVALID_NETWORK_OPTIONS";
			m_sErrorDescription = "The network options are invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1725:
		{
			m_sErrorName = "RPC_S_NO_CALL_ACTIVE";
			m_sErrorDescription = "There are no remote procedure calls active on this thread. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1726:
		{
			m_sErrorName = "RPC_S_CALL_FAILED";
			m_sErrorDescription = "The remote procedure call failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1727:
		{
			m_sErrorName = "RPC_S_CALL_FAILED_DNE";
			m_sErrorDescription = "The remote procedure call failed and did not execute. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1728:
		{
			m_sErrorName = "RPC_S_PROTOCOL_ERROR";
			m_sErrorDescription = "A remote procedure call (RPC) protocol error occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1730:
		{
			m_sErrorName = "RPC_S_UNSUPPORTED_TRANS_SYN";
			m_sErrorDescription = "The transfer syntax is not supported by the RPC server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1732:
		{
			m_sErrorName = "RPC_S_UNSUPPORTED_TYPE";
			m_sErrorDescription = "The universal unique identifier (UUID) type is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1733:
		{
			m_sErrorName = "RPC_S_INVALID_TAG";
			m_sErrorDescription = "The tag is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1734:
		{
			m_sErrorName = "RPC_S_INVALID_BOUND";
			m_sErrorDescription = "The array bounds are invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1735:
		{
			m_sErrorName = "RPC_S_NO_ENTRY_NAME";
			m_sErrorDescription = "The binding does not contain an entry name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1736:
		{
			m_sErrorName = "RPC_S_INVALID_NAME_SYNTAX";
			m_sErrorDescription = "The name syntax is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1737:
		{
			m_sErrorName = "RPC_S_UNSUPPORTED_NAME_SYNTAX";
			m_sErrorDescription = "The name syntax is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1739:
		{
			m_sErrorName = "RPC_S_UUID_NO_ADDRESS";
			m_sErrorDescription = "No network address is available to use to construct a universal unique identifier (UUID). ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1740:
		{
			m_sErrorName = "RPC_S_DUPLICATE_ENDPOINT";
			m_sErrorDescription = "The endpoint is a duplicate. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1741:
		{
			m_sErrorName = "RPC_S_UNKNOWN_AUTHN_TYPE";
			m_sErrorDescription = "The authentication type is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1742:
		{
			m_sErrorName = "RPC_S_MAX_CALLS_TOO_SMALL";
			m_sErrorDescription = "The maximum number of calls is too small. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1743:
		{
			m_sErrorName = "RPC_S_STRING_TOO_LONG";
			m_sErrorDescription = "The string is too long. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1744:
		{
			m_sErrorName = "RPC_S_PROTSEQ_NOT_FOUND";
			m_sErrorDescription = "The RPC protocol sequence was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1745:
		{
			m_sErrorName = "RPC_S_PROCNUM_OUT_OF_RANGE";
			m_sErrorDescription = "The procedure number is out of range. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1746:
		{
			m_sErrorName = "RPC_S_BINDING_HAS_NO_AUTH";
			m_sErrorDescription = "The binding does not contain any authentication information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1747:
		{
			m_sErrorName = "RPC_S_UNKNOWN_AUTHN_SERVICE";
			m_sErrorDescription = "The authentication service is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1748:
		{
			m_sErrorName = "RPC_S_UNKNOWN_AUTHN_LEVEL";
			m_sErrorDescription = "The authentication level is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1749:
		{
			m_sErrorName = "RPC_S_INVALID_AUTH_IDENTITY";
			m_sErrorDescription = "The security context is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1750:
		{
			m_sErrorName = "RPC_S_UNKNOWN_AUTHZ_SERVICE";
			m_sErrorDescription = "The authorization service is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1751:
		{
			m_sErrorName = "EPT_S_INVALID_ENTRY";
			m_sErrorDescription = "The entry is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1752:
		{
			m_sErrorName = "EPT_S_CANT_PERFORM_OP";
			m_sErrorDescription = "The server endpoint cannot perform the operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1753:
		{
			m_sErrorName = "EPT_S_NOT_REGISTERED";
			m_sErrorDescription = "There are no more endpoints available from the endpoint mapper. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1754:
		{
			m_sErrorName = "RPC_S_NOTHING_TO_EXPORT";
			m_sErrorDescription = "No interfaces have been exported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1755:
		{
			m_sErrorName = "RPC_S_INCOMPLETE_NAME";
			m_sErrorDescription = "The entry name is incomplete. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1756:
		{
			m_sErrorName = "RPC_S_INVALID_VERS_OPTION";
			m_sErrorDescription = "The version option is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1757:
		{
			m_sErrorName = "RPC_S_NO_MORE_MEMBERS";
			m_sErrorDescription = "There are no more members. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1758:
		{
			m_sErrorName = "RPC_S_NOT_ALL_OBJS_UNEXPORTED";
			m_sErrorDescription = "There is nothing to unexport. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1759:
		{
			m_sErrorName = "RPC_S_INTERFACE_NOT_FOUND";
			m_sErrorDescription = "The interface was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1760:
		{
			m_sErrorName = "RPC_S_ENTRY_ALREADY_EXISTS";
			m_sErrorDescription = "The entry already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1761:
		{
			m_sErrorName = "RPC_S_ENTRY_NOT_FOUND";
			m_sErrorDescription = "The entry is not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1762:
		{
			m_sErrorName = "RPC_S_NAME_SERVICE_UNAVAILABLE";
			m_sErrorDescription = "The name service is unavailable. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1763:
		{
			m_sErrorName = "RPC_S_INVALID_NAF_ID";
			m_sErrorDescription = "The network address family is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1764:
		{
			m_sErrorName = "RPC_S_CANNOT_SUPPORT";
			m_sErrorDescription = "The requested operation is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1765:
		{
			m_sErrorName = "RPC_S_NO_CONTEXT_AVAILABLE";
			m_sErrorDescription = "No security context is available to allow impersonation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1766:
		{
			m_sErrorName = "RPC_S_INTERNAL_ERROR";
			m_sErrorDescription = "An internal error occurred in a remote procedure call (RPC). ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1767:
		{
			m_sErrorName = "RPC_S_ZERO_DIVIDE";
			m_sErrorDescription = "The RPC server attempted an integer division by zero. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1768:
		{
			m_sErrorName = "RPC_S_ADDRESS_ERROR";
			m_sErrorDescription = "An addressing error occurred in the RPC server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1769:
		{
			m_sErrorName = "RPC_S_FP_DIV_ZERO";
			m_sErrorDescription = "A floating-point operation at the RPC server caused a division by zero. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1770:
		{
			m_sErrorName = "RPC_S_FP_UNDERFLOW";
			m_sErrorDescription = "A floating-point underflow occurred at the RPC server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1771:
		{
			m_sErrorName = "RPC_S_FP_OVERFLOW";
			m_sErrorDescription = "A floating-point overflow occurred at the RPC server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1772:
		{
			m_sErrorName = "RPC_X_NO_MORE_ENTRIES";
			m_sErrorDescription = "The list of RPC servers available for the binding of auto handles has been exhausted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1773:
		{
			m_sErrorName = "RPC_X_SS_CHAR_TRANS_OPEN_FAIL";
			m_sErrorDescription = "Unable to open the character translation table file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1774:
		{
			m_sErrorName = "RPC_X_SS_CHAR_TRANS_SHORT_FILE";
			m_sErrorDescription = "The file containing the character translation table has fewer than 512 bytes. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1775:
		{
			m_sErrorName = "RPC_X_SS_IN_NULL_CONTEXT";
			m_sErrorDescription = "A null context handle was passed from the client to the host during a remote procedure call. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1777:
		{
			m_sErrorName = "RPC_X_SS_CONTEXT_DAMAGED";
			m_sErrorDescription = "The context handle changed during a remote procedure call. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1778:
		{
			m_sErrorName = "RPC_X_SS_HANDLES_MISMATCH";
			m_sErrorDescription = "The binding handles passed to a remote procedure call do not match. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1779:
		{
			m_sErrorName = "RPC_X_SS_CANNOT_GET_CALL_HANDLE";
			m_sErrorDescription = "The stub is unable to get the remote procedure call handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1780:
		{
			m_sErrorName = "RPC_X_NULL_REF_POINTER";
			m_sErrorDescription = "A null reference pointer was passed to the stub. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1781:
		{
			m_sErrorName = "RPC_X_ENUM_VALUE_OUT_OF_RANGE";
			m_sErrorDescription = "The enumeration value is out of range. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1782:
		{
			m_sErrorName = "RPC_X_BYTE_COUNT_TOO_SMALL";
			m_sErrorDescription = "The byte count is too small. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1783:
		{
			m_sErrorName = "RPC_X_BAD_STUB_DATA";
			m_sErrorDescription = "The stub received bad data. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1784:
		{
			m_sErrorName = "ERROR_INVALID_USER_BUFFER";
			m_sErrorDescription = "The supplied user buffer is not valid for the requested operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1785:
		{
			m_sErrorName = "ERROR_UNRECOGNIZED_MEDIA";
			m_sErrorDescription = "The disk media is not recognized. It may not be formatted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1786:
		{
			m_sErrorName = "ERROR_NO_TRUST_LSA_SECRET";
			m_sErrorDescription = "The workstation does not have a trust secret. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1787:
		{
			m_sErrorName = "ERROR_NO_TRUST_SAM_ACCOUNT";
			m_sErrorDescription = "The security database on the server does not have a computer account for this workstation trust relationship. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1788:
		{
			m_sErrorName = "ERROR_TRUSTED_DOMAIN_FAILURE";
			m_sErrorDescription = "The trust relationship between the primary domain and the trusted domain failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1789:
		{
			m_sErrorName = "ERROR_TRUSTED_RELATIONSHIP_FAILURE";
			m_sErrorDescription = "The trust relationship between this workstation and the primary domain failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1790:
		{
			m_sErrorName = "ERROR_TRUST_FAILURE";
			m_sErrorDescription = "The network logon failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1791:
		{
			m_sErrorName = "RPC_S_CALL_IN_PROGRESS";
			m_sErrorDescription = "A remote procedure call is already in progress for this thread. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1792:
		{
			m_sErrorName = "ERROR_NETLOGON_NOT_STARTED";
			m_sErrorDescription = "An attempt was made to logon, but the network logon service was not started. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1793:
		{
			m_sErrorName = "ERROR_ACCOUNT_EXPIRED";
			m_sErrorDescription = "The user's account has expired. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1794:
		{
			m_sErrorName = "ERROR_REDIRECTOR_HAS_OPEN_HANDLES";
			m_sErrorDescription = "The redirector is in use and cannot be unloaded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1795:
		{
			m_sErrorName = "ERROR_PRINTER_DRIVER_ALREADY_INSTALLED";
			m_sErrorDescription = "The specified printer driver is already installed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1796:
		{
			m_sErrorName = "ERROR_UNKNOWN_PORT";
			m_sErrorDescription = "The specified port is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1797:
		{
			m_sErrorName = "ERROR_UNKNOWN_PRINTER_DRIVER";
			m_sErrorDescription = "The printer driver is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1798:
		{
			m_sErrorName = "ERROR_UNKNOWN_PRINTPROCESSOR";
			m_sErrorDescription = "The print processor is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1799:
		{
			m_sErrorName = "ERROR_INVALID_SEPARATOR_FILE";
			m_sErrorDescription = "The specified separator file is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1800:
		{
			m_sErrorName = "ERROR_INVALID_PRIORITY";
			m_sErrorDescription = "The specified priority is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1801:
		{
			m_sErrorName = "ERROR_INVALID_PRINTER_NAME";
			m_sErrorDescription = "The printer name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1802:
		{
			m_sErrorName = "ERROR_PRINTER_ALREADY_EXISTS";
			m_sErrorDescription = "The printer already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1803:
		{
			m_sErrorName = "ERROR_INVALID_PRINTER_COMMAND";
			m_sErrorDescription = "The printer command is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1804:
		{
			m_sErrorName = "ERROR_INVALID_DATATYPE";
			m_sErrorDescription = "The specified datatype is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1805:
		{
			m_sErrorName = "ERROR_INVALID_ENVIRONMENT";
			m_sErrorDescription = "The environment specified is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1806:
		{
			m_sErrorName = "RPC_S_NO_MORE_BINDINGS";
			m_sErrorDescription = "There are no more bindings. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1807:
		{
			m_sErrorName = "ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT";
			m_sErrorDescription = "The account used is an interdomain trust account. Use your global user account or local user account to access this server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1808:
		{
			m_sErrorName = "ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT";
			m_sErrorDescription = "The account used is a computer account. Use your global user account or local user account to access this server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1809:
		{
			m_sErrorName = "ERROR_NOLOGON_SERVER_TRUST_ACCOUNT";
			m_sErrorDescription = "The account used is a server trust account. Use your global user account or local user account to access this server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1810:
		{
			m_sErrorName = "ERROR_DOMAIN_TRUST_INCONSISTENT";
			m_sErrorDescription = "The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1811:
		{
			m_sErrorName = "ERROR_SERVER_HAS_OPEN_HANDLES";
			m_sErrorDescription = "The server is in use and cannot be unloaded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1812:
		{
			m_sErrorName = "ERROR_RESOURCE_DATA_NOT_FOUND";
			m_sErrorDescription = "The specified image file did not contain a resource section. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1813:
		{
			m_sErrorName = "ERROR_RESOURCE_TYPE_NOT_FOUND";
			m_sErrorDescription = "The specified resource type cannot be found in the image file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1814:
		{
			m_sErrorName = "ERROR_RESOURCE_NAME_NOT_FOUND";
			m_sErrorDescription = "The specified resource name cannot be found in the image file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1815:
		{
			m_sErrorName = "ERROR_RESOURCE_LANG_NOT_FOUND";
			m_sErrorDescription = "The specified resource language ID cannot be found in the image file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1816:
		{
			m_sErrorName = "ERROR_NOT_ENOUGH_QUOTA";
			m_sErrorDescription = "Not enough quota is available to process this command. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1817:
		{
			m_sErrorName = "RPC_S_NO_INTERFACES";
			m_sErrorDescription = "No interfaces have been registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1818:
		{
			m_sErrorName = "RPC_S_CALL_CANCELLED";
			m_sErrorDescription = "The remote procedure call was cancelled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1819:
		{
			m_sErrorName = "RPC_S_BINDING_INCOMPLETE";
			m_sErrorDescription = "The binding handle does not contain all required information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1820:
		{
			m_sErrorName = "RPC_S_COMM_FAILURE";
			m_sErrorDescription = "A communications failure occurred during a remote procedure call. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1821:
		{
			m_sErrorName = "RPC_S_UNSUPPORTED_AUTHN_LEVEL";
			m_sErrorDescription = "The requested authentication level is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1822:
		{
			m_sErrorName = "RPC_S_NO_PRINC_NAME";
			m_sErrorDescription = "No principal name registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1823:
		{
			m_sErrorName = "RPC_S_NOT_RPC_ERROR";
			m_sErrorDescription = "The error specified is not a valid Windows RPC error code. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1824:
		{
			m_sErrorName = "RPC_S_UUID_LOCAL_ONLY";
			m_sErrorDescription = "A UUID that is valid only on this computer has been allocated. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1825:
		{
			m_sErrorName = "RPC_S_SEC_PKG_ERROR";
			m_sErrorDescription = "A security package specific error occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1826:
		{
			m_sErrorName = "RPC_S_NOT_CANCELLED";
			m_sErrorDescription = "Thread is not canceled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1827:
		{
			m_sErrorName = "RPC_X_INVALID_ES_ACTION";
			m_sErrorDescription = "Invalid operation on the encoding/decoding handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1828:
		{
			m_sErrorName = "RPC_X_WRONG_ES_VERSION";
			m_sErrorDescription = "Incompatible version of the serializing package. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1829:
		{
			m_sErrorName = "RPC_X_WRONG_STUB_VERSION";
			m_sErrorDescription = "Incompatible version of the RPC stub. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1830:
		{
			m_sErrorName = "RPC_X_INVALID_PIPE_OBJECT";
			m_sErrorDescription = "The RPC pipe object is invalid or corrupted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1831:
		{
			m_sErrorName = "RPC_X_WRONG_PIPE_ORDER";
			m_sErrorDescription = "An invalid operation was attempted on an RPC pipe object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1832:
		{
			m_sErrorName = "RPC_X_WRONG_PIPE_VERSION";
			m_sErrorDescription = "Unsupported RPC pipe version. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1898:
		{
			m_sErrorName = "RPC_S_GROUP_MEMBER_NOT_FOUND";
			m_sErrorDescription = "The group member was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1899:
		{
			m_sErrorName = "EPT_S_CANT_CREATE";
			m_sErrorDescription = "The endpoint mapper database entry could not be created. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1900:
		{
			m_sErrorName = "RPC_S_INVALID_OBJECT";
			m_sErrorDescription = "The object universal unique identifier (UUID) is the nil UUID. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1901:
		{
			m_sErrorName = "ERROR_INVALID_TIME";
			m_sErrorDescription = "The specified time is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1902:
		{
			m_sErrorName = "ERROR_INVALID_FORM_NAME";
			m_sErrorDescription = "The specified form name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1903:
		{
			m_sErrorName = "ERROR_INVALID_FORM_SIZE";
			m_sErrorDescription = "The specified form size is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1904:
		{
			m_sErrorName = "ERROR_ALREADY_WAITING";
			m_sErrorDescription = "The specified printer handle is already being waited on ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1905:
		{
			m_sErrorName = "ERROR_PRINTER_DELETED";
			m_sErrorDescription = "The specified printer has been deleted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1906:
		{
			m_sErrorName = "ERROR_INVALID_PRINTER_STATE";
			m_sErrorDescription = "The state of the printer is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1907:
		{
			m_sErrorName = "ERROR_PASSWORD_MUST_CHANGE";
			m_sErrorDescription = "The user's password must be changed before logging on the first time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1908:
		{
			m_sErrorName = "ERROR_DOMAIN_CONTROLLER_NOT_FOUND";
			m_sErrorDescription = "Could not find the domain controller for this domain. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1909:
		{
			m_sErrorName = "ERROR_ACCOUNT_LOCKED_OUT";
			m_sErrorDescription = "The referenced account is currently locked out and may not be logged on to. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1910:
		{
			m_sErrorName = "OR_INVALID_OXID";
			m_sErrorDescription = "The object exporter specified was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1911:
		{
			m_sErrorName = "OR_INVALID_OID";
			m_sErrorDescription = "The object specified was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1912:
		{
			m_sErrorName = "OR_INVALID_SET";
			m_sErrorDescription = "The object resolver set specified was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1913:
		{
			m_sErrorName = "RPC_S_SEND_INCOMPLETE";
			m_sErrorDescription = "Some data remains to be sent in the request buffer. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1914:
		{
			m_sErrorName = "RPC_S_INVALID_ASYNC_HANDLE";
			m_sErrorDescription = "Invalid asynchronous remote procedure call handle. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1915:
		{
			m_sErrorName = "RPC_S_INVALID_ASYNC_CALL";
			m_sErrorDescription = "Invalid asynchronous RPC call handle for this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1916:
		{
			m_sErrorName = "RPC_X_PIPE_CLOSED";
			m_sErrorDescription = "The RPC pipe object has already been closed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1917:
		{
			m_sErrorName = "RPC_X_PIPE_DISCIPLINE_ERROR";
			m_sErrorDescription = "The RPC call completed before all pipes were processed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1918:
		{
			m_sErrorName = "RPC_X_PIPE_EMPTY";
			m_sErrorDescription = "No more data is available from the RPC pipe. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1919:
		{
			m_sErrorName = "ERROR_NO_SITENAME";
			m_sErrorDescription = "No site name is available for this machine. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1920:
		{
			m_sErrorName = "ERROR_CANT_ACCESS_FILE";
			m_sErrorDescription = "The file can not be accessed by the system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1921:
		{
			m_sErrorName = "ERROR_CANT_RESOLVE_FILENAME";
			m_sErrorDescription = "The name of the file cannot be resolved by the system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1922:
		{
			m_sErrorName = "RPC_S_ENTRY_TYPE_MISMATCH";
			m_sErrorDescription = "The entry is not of the expected type.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1923:
		{
			m_sErrorName = "RPC_S_NOT_ALL_OBJS_EXPORTED";
			m_sErrorDescription = "Not all object UUIDs could be exported to the specified entry.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1924:
		{
			m_sErrorName = "RPC_S_INTERFACE_NOT_EXPORTED";
			m_sErrorDescription = "Interface could not be exported to the specified entry.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1925:
		{
			m_sErrorName = "RPC_S_PROFILE_NOT_ADDED";
			m_sErrorDescription = "The specified profile entry could not be added.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1926:
		{
			m_sErrorName = "RPC_S_PRF_ELT_NOT_ADDED";
			m_sErrorDescription = "The specified profile element could not be added.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1927:
		{
			m_sErrorName = "RPC_S_PRF_ELT_NOT_REMOVED";
			m_sErrorDescription = "The specified profile element could not be removed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1928:
		{
			m_sErrorName = "RPC_S_GRP_ELT_NOT_ADDED";
			m_sErrorDescription = "The group element could not be added.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 1929:
		{
			m_sErrorName = "RPC_S_GRP_ELT_NOT_REMOVED";
			m_sErrorDescription = "The group element could not be removed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2000:
		{
			m_sErrorName = "ERROR_INVALID_PIXEL_FORMAT";
			m_sErrorDescription = "The pixel format is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2001:
		{
			m_sErrorName = "ERROR_BAD_DRIVER";
			m_sErrorDescription = "The specified driver is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2002:
		{
			m_sErrorName = "ERROR_INVALID_WINDOW_STYLE";
			m_sErrorDescription = "The window style or class attribute is invalid for this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2003:
		{
			m_sErrorName = "ERROR_METAFILE_NOT_SUPPORTED";
			m_sErrorDescription = "The requested metafile operation is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2004:
		{
			m_sErrorName = "ERROR_TRANSFORM_NOT_SUPPORTED";
			m_sErrorDescription = "The requested transformation operation is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2005:
		{
			m_sErrorName = "ERROR_CLIPPING_NOT_SUPPORTED";
			m_sErrorDescription = "The requested clipping operation is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2010:
		{
			m_sErrorName = "ERROR_INVALID_CMM";
			m_sErrorDescription = "The specified color management module is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2011:
		{
			m_sErrorName = "ERROR_INVALID_PROFILE";
			m_sErrorDescription = "The specified color profile is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2012:
		{
			m_sErrorName = "ERROR_TAG_NOT_FOUND";
			m_sErrorDescription = "The specified tag was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2013:
		{
			m_sErrorName = "ERROR_TAG_NOT_PRESENT";
			m_sErrorDescription = "A required tag is not present. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2014:
		{
			m_sErrorName = "ERROR_DUPLICATE_TAG";
			m_sErrorDescription = "The specified tag is already present. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2015:
		{
			m_sErrorName = "ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE";
			m_sErrorDescription = "The specified color profile is not associated with any device. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2016:
		{
			m_sErrorName = "ERROR_PROFILE_NOT_FOUND";
			m_sErrorDescription = "The specified color profile was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2017:
		{
			m_sErrorName = "ERROR_INVALID_COLORSPACE";
			m_sErrorDescription = "The specified color space is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2018:
		{
			m_sErrorName = "ERROR_ICM_NOT_ENABLED";
			m_sErrorDescription = "Image Color Management is not enabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2019:
		{
			m_sErrorName = "ERROR_DELETING_ICM_XFORM";
			m_sErrorDescription = "There was an error while deleting the color transform. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2020:
		{
			m_sErrorName = "ERROR_INVALID_TRANSFORM";
			m_sErrorDescription = "The specified color transform is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2021:
		{
			m_sErrorName = "ERROR_COLORSPACE_MISMATCH";
			m_sErrorDescription = "The specified transform does not match the bitmap's color space. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2022:
		{
			m_sErrorName = "ERROR_INVALID_COLORINDEX";
			m_sErrorDescription = "The specified named color index is not present in the profile. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2108:
		{
			m_sErrorName = "ERROR_CONNECTED_OTHER_PASSWORD";
			m_sErrorDescription = "The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2202:
		{
			m_sErrorName = "ERROR_BAD_USERNAME";
			m_sErrorDescription = "The specified username is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2250:
		{
			m_sErrorName = "ERROR_NOT_CONNECTED";
			m_sErrorDescription = "This network connection does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2401:
		{
			m_sErrorName = "ERROR_OPEN_FILES";
			m_sErrorDescription = "This network connection has files open or requests pending. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2402:
		{
			m_sErrorName = "ERROR_ACTIVE_CONNECTIONS";
			m_sErrorDescription = "Active connections still exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 2404:
		{
			m_sErrorName = "ERROR_DEVICE_IN_USE";
			m_sErrorDescription = "The device is in use by an active process and cannot be disconnected. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3000:
		{
			m_sErrorName = "ERROR_UNKNOWN_PRINT_MONITOR";
			m_sErrorDescription = "The specified print monitor is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3001:
		{
			m_sErrorName = "ERROR_PRINTER_DRIVER_IN_USE";
			m_sErrorDescription = "The specified printer driver is currently in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3002:
		{
			m_sErrorName = "ERROR_SPOOL_FILE_NOT_FOUND";
			m_sErrorDescription = "The spool file was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3003:
		{
			m_sErrorName = "ERROR_SPL_NO_STARTDOC";
			m_sErrorDescription = "A StartDocPrinter call was not issued. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3004:
		{
			m_sErrorName = "ERROR_SPL_NO_ADDJOB";
			m_sErrorDescription = "An AddJob call was not issued. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3005:
		{
			m_sErrorName = "ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED";
			m_sErrorDescription = "The specified print processor has already been installed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3006:
		{
			m_sErrorName = "ERROR_PRINT_MONITOR_ALREADY_INSTALLED";
			m_sErrorDescription = "The specified print monitor has already been installed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3007:
		{
			m_sErrorName = "ERROR_INVALID_PRINT_MONITOR";
			m_sErrorDescription = "The specified print monitor does not have the required functions. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3008:
		{
			m_sErrorName = "ERROR_PRINT_MONITOR_IN_USE";
			m_sErrorDescription = "The specified print monitor is currently in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3009:
		{
			m_sErrorName = "ERROR_PRINTER_HAS_JOBS_QUEUED";
			m_sErrorDescription = "The requested operation is not allowed when there are jobs queued to the printer. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3010:
		{
			m_sErrorName = "ERROR_SUCCESS_REBOOT_REQUIRED";
			m_sErrorDescription = "The requested operation is successful. Changes will not be effective until the system is rebooted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3011:
		{
			m_sErrorName = "ERROR_SUCCESS_RESTART_REQUIRED";
			m_sErrorDescription = "The requested operation is successful. Changes will not be effective until the service is restarted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 3012:
		{
			m_sErrorName = "ERROR_PRINTER_NOT_FOUND";
			m_sErrorDescription = "No printers were found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4000:
		{
			m_sErrorName = "ERROR_WINS_INTERNAL";
			m_sErrorDescription = "WINS encountered an error while processing the command. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4001:
		{
			m_sErrorName = "ERROR_CAN_NOT_DEL_LOCAL_WINS";
			m_sErrorDescription = "The local WINS can not be deleted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4002:
		{
			m_sErrorName = "ERROR_STATIC_INIT";
			m_sErrorDescription = "The importation from the file failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4003:
		{
			m_sErrorName = "ERROR_INC_BACKUP";
			m_sErrorDescription = "The backup failed. Was a full backup done before? ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4004:
		{
			m_sErrorName = "ERROR_FULL_BACKUP";
			m_sErrorDescription = "The backup failed. Check the directory to which you are backing the database. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4005:
		{
			m_sErrorName = "ERROR_REC_NON_EXISTENT";
			m_sErrorDescription = "The name does not exist in the WINS database. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4006:
		{
			m_sErrorName = "ERROR_RPL_NOT_ALLOWED";
			m_sErrorDescription = "Replication with a nonconfigured partner is not allowed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4100:
		{
			m_sErrorName = "ERROR_DHCP_ADDRESS_CONFLICT";
			m_sErrorDescription = "The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4200:
		{
			m_sErrorName = "ERROR_WMI_GUID_NOT_FOUND";
			m_sErrorDescription = "The GUID passed was not recognized as valid by a WMI data provider. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4201:
		{
			m_sErrorName = "ERROR_WMI_INSTANCE_NOT_FOUND";
			m_sErrorDescription = "The instance name passed was not recognized as valid by a WMI data provider. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4202:
		{
			m_sErrorName = "ERROR_WMI_ITEMID_NOT_FOUND";
			m_sErrorDescription = "The data item ID passed was not recognized as valid by a WMI data provider. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4203:
		{
			m_sErrorName = "ERROR_WMI_TRY_AGAIN";
			m_sErrorDescription = "The WMI request could not be completed and should be retried. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4204:
		{
			m_sErrorName = "ERROR_WMI_DP_NOT_FOUND";
			m_sErrorDescription = "The WMI data provider could not be located. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4205:
		{
			m_sErrorName = "ERROR_WMI_UNRESOLVED_INSTANCE_REF";
			m_sErrorDescription = "The WMI data provider references an instance set that has not been registered. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4206:
		{
			m_sErrorName = "ERROR_WMI_ALREADY_ENABLED";
			m_sErrorDescription = "The WMI data block or event notification has already been enabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4207:
		{
			m_sErrorName = "ERROR_WMI_GUID_DISCONNECTED";
			m_sErrorDescription = "The WMI data block is no longer available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4208:
		{
			m_sErrorName = "ERROR_WMI_SERVER_UNAVAILABLE";
			m_sErrorDescription = "The WMI data service is not available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4209:
		{
			m_sErrorName = "ERROR_WMI_DP_FAILED";
			m_sErrorDescription = "The WMI data provider failed to carry out the request. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4210:
		{
			m_sErrorName = "ERROR_WMI_INVALID_MOF";
			m_sErrorDescription = "The WMI MOF information is not valid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4211:
		{
			m_sErrorName = "ERROR_WMI_INVALID_REGINFO";
			m_sErrorDescription = "The WMI registration information is not valid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4212:
		{
			m_sErrorName = "ERROR_WMI_ALREADY_DISABLED";
			m_sErrorDescription = "The WMI data block or event notification has already been disabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4213:
		{
			m_sErrorName = "ERROR_WMI_READ_ONLY";
			m_sErrorDescription = "The WMI data item or data block is read only. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4214:
		{
			m_sErrorName = "ERROR_WMI_SET_FAILURE";
			m_sErrorDescription = "The WMI data item or data block could not be changed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4300:
		{
			m_sErrorName = "ERROR_INVALID_MEDIA";
			m_sErrorDescription = "The media identifier does not represent a valid medium. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4301:
		{
			m_sErrorName = "ERROR_INVALID_LIBRARY";
			m_sErrorDescription = "The library identifier does not represent a valid library. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4302:
		{
			m_sErrorName = "ERROR_INVALID_MEDIA_POOL";
			m_sErrorDescription = "The media pool identifier does not represent a valid media pool. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4303:
		{
			m_sErrorName = "ERROR_DRIVE_MEDIA_MISMATCH";
			m_sErrorDescription = "The drive and medium are not compatible or exist in different libraries. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4304:
		{
			m_sErrorName = "ERROR_MEDIA_OFFLINE";
			m_sErrorDescription = "The medium currently exists in an offline library and must be online to perform this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4305:
		{
			m_sErrorName = "ERROR_LIBRARY_OFFLINE";
			m_sErrorDescription = "The operation cannot be performed on an offline library. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4306:
		{
			m_sErrorName = "ERROR_EMPTY";
			m_sErrorDescription = "The library, drive, or media pool is empty. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4307:
		{
			m_sErrorName = "ERROR_NOT_EMPTY";
			m_sErrorDescription = "The library, drive, or media pool must be empty to perform this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4308:
		{
			m_sErrorName = "ERROR_MEDIA_UNAVAILABLE";
			m_sErrorDescription = "No media is currently available in this media pool or library. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4309:
		{
			m_sErrorName = "ERROR_RESOURCE_DISABLED";
			m_sErrorDescription = "A resource required for this operation is disabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4310:
		{
			m_sErrorName = "ERROR_INVALID_CLEANER";
			m_sErrorDescription = "The media identifier does not represent a valid cleaner. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4311:
		{
			m_sErrorName = "ERROR_UNABLE_TO_CLEAN";
			m_sErrorDescription = "The drive cannot be cleaned or does not support cleaning. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4312:
		{
			m_sErrorName = "ERROR_OBJECT_NOT_FOUND";
			m_sErrorDescription = "The object identifier does not represent a valid object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4313:
		{
			m_sErrorName = "ERROR_DATABASE_FAILURE";
			m_sErrorDescription = "Unable to read from or write to the database. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4314:
		{
			m_sErrorName = "ERROR_DATABASE_FULL";
			m_sErrorDescription = "The database is full. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4315:
		{
			m_sErrorName = "ERROR_MEDIA_INCOMPATIBLE";
			m_sErrorDescription = "The medium is not compatible with the device or media pool. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4316:
		{
			m_sErrorName = "ERROR_RESOURCE_NOT_PRESENT";
			m_sErrorDescription = "The resource required for this operation does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4317:
		{
			m_sErrorName = "ERROR_INVALID_OPERATION";
			m_sErrorDescription = "The operation identifier is not valid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4318:
		{
			m_sErrorName = "ERROR_MEDIA_NOT_AVAILABLE";
			m_sErrorDescription = "The media is not mounted or ready for use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4319:
		{
			m_sErrorName = "ERROR_DEVICE_NOT_AVAILABLE";
			m_sErrorDescription = "The device is not ready for use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4320:
		{
			m_sErrorName = "ERROR_REQUEST_REFUSED";
			m_sErrorDescription = "The operator or administrator has refused the request. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4321:
		{
			m_sErrorName = "ERROR_INVALID_DRIVE_OBJECT";
			m_sErrorDescription = "The drive identifier does not represent a valid drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4322:
		{
			m_sErrorName = "ERROR_LIBRARY_FULL";
			m_sErrorDescription = "Library is full. No slot is available for use.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4323:
		{
			m_sErrorName = "ERROR_MEDIUM_NOT_ACCESSIBLE";
			m_sErrorDescription = "The transport cannot access the medium. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4324:
		{
			m_sErrorName = "ERROR_UNABLE_TO_LOAD_MEDIUM";
			m_sErrorDescription = "Unable to load the medium into the drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4325:
		{
			m_sErrorName = "ERROR_UNABLE_TO_INVENTORY_DRIVE";
			m_sErrorDescription = "Unable to retrieve status about the drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4326:
		{
			m_sErrorName = "ERROR_UNABLE_TO_INVENTORY_SLOT";
			m_sErrorDescription = "Unable to retrieve status about the slot. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4327:
		{
			m_sErrorName = "ERROR_UNABLE_TO_INVENTORY_TRANSPORT";
			m_sErrorDescription = "Unable to retrieve status about the transport. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4328:
		{
			m_sErrorName = "ERROR_TRANSPORT_FULL";
			m_sErrorDescription = "Cannot use the transport because it is already in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4329:
		{
			m_sErrorName = "ERROR_CONTROLLING_IEPORT";
			m_sErrorDescription = "Unable to open or close the inject/eject port. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4330:
		{
			m_sErrorName = "ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA";
			m_sErrorDescription = "Unable to eject the media because it is in a drive. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4331:
		{
			m_sErrorName = "ERROR_CLEANER_SLOT_SET";
			m_sErrorDescription = "A cleaner slot is already reserved. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4332:
		{
			m_sErrorName = "ERROR_CLEANER_SLOT_NOT_SET";
			m_sErrorDescription = "A cleaner slot is not reserved. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4333:
		{
			m_sErrorName = "ERROR_CLEANER_CARTRIDGE_SPENT";
			m_sErrorDescription = "The cleaner cartridge has performed the maximum number of drive cleanings. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4334:
		{
			m_sErrorName = "ERROR_UNEXPECTED_OMID";
			m_sErrorDescription = "Unexpected on-medium identifier. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4335:
		{
			m_sErrorName = "ERROR_CANT_DELETE_LAST_ITEM";
			m_sErrorDescription = "The last remaining item in this group or resource cannot be deleted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4336:
		{
			m_sErrorName = "ERROR_MESSAGE_EXCEEDS_MAX_SIZE";
			m_sErrorDescription = "The message provided exceeds the maximum size allowed for this parameter. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4337:
		{
			m_sErrorName = "ERROR_VOLUME_CONTAINS_SYS_FILES";
			m_sErrorDescription = "The volume contains system or paging files.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4338:
		{
			m_sErrorName = "ERROR_INDIGENOUS_TYPE";
			m_sErrorDescription = "The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4339:
		{
			m_sErrorName = "ERROR_NO_SUPPORTING_DRIVES";
			m_sErrorDescription = "This offline media cannot be mounted on this system since no enabled drives are present which can be used.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4350:
		{
			m_sErrorName = "ERROR_FILE_OFFLINE";
			m_sErrorDescription = "The remote storage service was not able to recall the file. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4351:
		{
			m_sErrorName = "ERROR_REMOTE_STORAGE_NOT_ACTIVE";
			m_sErrorDescription = "The remote storage service is not operational at this time. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4352:
		{
			m_sErrorName = "ERROR_REMOTE_STORAGE_MEDIA_ERROR";
			m_sErrorDescription = "The remote storage service encountered a media error. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4390:
		{
			m_sErrorName = "ERROR_NOT_A_REPARSE_POINT";
			m_sErrorDescription = "The file or directory is not a reparse point. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4391:
		{
			m_sErrorName = "ERROR_REPARSE_ATTRIBUTE_CONFLICT";
			m_sErrorDescription = "The reparse point attribute cannot be set because it conflicts with an existing attribute. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4392:
		{
			m_sErrorName = "ERROR_INVALID_REPARSE_DATA";
			m_sErrorDescription = "The data present in the reparse point buffer is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4393:
		{
			m_sErrorName = "ERROR_REPARSE_TAG_INVALID";
			m_sErrorDescription = "The tag present in the reparse point buffer is invalid.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4394:
		{
			m_sErrorName = "ERROR_REPARSE_TAG_MISMATCH";
			m_sErrorDescription = "There is a mismatch between the tag specified in the request and the tag present in the reparse point.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 4500:
		{
			m_sErrorName = "ERROR_VOLUME_NOT_SIS_ENABLED";
			m_sErrorDescription = "Single Instance Storage is not available on this volume.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5001:
		{
			m_sErrorName = "ERROR_DEPENDENT_RESOURCE_EXISTS";
			m_sErrorDescription = "The cluster resource cannot be moved to another group because other resources are dependent on it. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5002:
		{
			m_sErrorName = "ERROR_DEPENDENCY_NOT_FOUND";
			m_sErrorDescription = "The cluster resource dependency cannot be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5003:
		{
			m_sErrorName = "ERROR_DEPENDENCY_ALREADY_EXISTS";
			m_sErrorDescription = "The cluster resource cannot be made dependent on the specified resource because it is already dependent. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5004:
		{
			m_sErrorName = "ERROR_RESOURCE_NOT_ONLINE";
			m_sErrorDescription = "The cluster resource is not online. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5005:
		{
			m_sErrorName = "ERROR_HOST_NODE_NOT_AVAILABLE";
			m_sErrorDescription = "A cluster node is not available for this operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5006:
		{
			m_sErrorName = "ERROR_RESOURCE_NOT_AVAILABLE";
			m_sErrorDescription = "The cluster resource is not available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5007:
		{
			m_sErrorName = "ERROR_RESOURCE_NOT_FOUND";
			m_sErrorDescription = "The cluster resource could not be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5008:
		{
			m_sErrorName = "ERROR_SHUTDOWN_CLUSTER";
			m_sErrorDescription = "The cluster is being shut down. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5009:
		{
			m_sErrorName = "ERROR_CANT_EVICT_ACTIVE_NODE";
			m_sErrorDescription = "A cluster node cannot be evicted from the cluster while it is online. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5010:
		{
			m_sErrorName = "ERROR_OBJECT_ALREADY_EXISTS";
			m_sErrorDescription = "The object already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5011:
		{
			m_sErrorName = "ERROR_OBJECT_IN_LIST";
			m_sErrorDescription = "The object is already in the list. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5012:
		{
			m_sErrorName = "ERROR_GROUP_NOT_AVAILABLE";
			m_sErrorDescription = "The cluster group is not available for any new requests. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5013:
		{
			m_sErrorName = "ERROR_GROUP_NOT_FOUND";
			m_sErrorDescription = "The cluster group could not be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5014:
		{
			m_sErrorName = "ERROR_GROUP_NOT_ONLINE";
			m_sErrorDescription = "The operation could not be completed because the cluster group is not online. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5015:
		{
			m_sErrorName = "ERROR_HOST_NODE_NOT_RESOURCE_OWNER";
			m_sErrorDescription = "The cluster node is not the owner of the resource. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5016:
		{
			m_sErrorName = "ERROR_HOST_NODE_NOT_GROUP_OWNER";
			m_sErrorDescription = "The cluster node is not the owner of the group. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5017:
		{
			m_sErrorName = "ERROR_RESMON_CREATE_FAILED";
			m_sErrorDescription = "The cluster resource could not be created in the specified resource monitor. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5018:
		{
			m_sErrorName = "ERROR_RESMON_ONLINE_FAILED";
			m_sErrorDescription = "The cluster resource could not be brought online by the resource monitor. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5019:
		{
			m_sErrorName = "ERROR_RESOURCE_ONLINE";
			m_sErrorDescription = "The operation could not be completed because the cluster resource is online. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5020:
		{
			m_sErrorName = "ERROR_QUORUM_RESOURCE";
			m_sErrorDescription = "The cluster resource could not be deleted or brought offline because it is the quorum resource. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5021:
		{
			m_sErrorName = "ERROR_NOT_QUORUM_CAPABLE";
			m_sErrorDescription = "The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5022:
		{
			m_sErrorName = "ERROR_CLUSTER_SHUTTING_DOWN";
			m_sErrorDescription = "The cluster software is shutting down. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5023:
		{
			m_sErrorName = "ERROR_INVALID_STATE";
			m_sErrorDescription = "The group or resource is not in the correct state to perform the requested operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5024:
		{
			m_sErrorName = "ERROR_RESOURCE_PROPERTIES_STORED";
			m_sErrorDescription = "The properties were stored but not all changes will take effect until the next time the resource is brought online. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5025:
		{
			m_sErrorName = "ERROR_NOT_QUORUM_CLASS";
			m_sErrorDescription = "The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5026:
		{
			m_sErrorName = "ERROR_CORE_RESOURCE";
			m_sErrorDescription = "The cluster resource could not be deleted since it is a core resource. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5027:
		{
			m_sErrorName = "ERROR_QUORUM_RESOURCE_ONLINE_FAILED";
			m_sErrorDescription = "The quorum resource failed to come online. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5028:
		{
			m_sErrorName = "ERROR_QUORUMLOG_OPEN_FAILED";
			m_sErrorDescription = "The quorum log could not be created or mounted successfully. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5029:
		{
			m_sErrorName = "ERROR_CLUSTERLOG_CORRUPT";
			m_sErrorDescription = "The cluster log is corrupt. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5030:
		{
			m_sErrorName = "ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE";
			m_sErrorDescription = "The record could not be written to the cluster log since it exceeds the maximum size. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5031:
		{
			m_sErrorName = "ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE";
			m_sErrorDescription = "The cluster log exceeds its maximum size. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5032:
		{
			m_sErrorName = "ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND";
			m_sErrorDescription = "No checkpoint record was found in the cluster log. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5033:
		{
			m_sErrorName = "ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE";
			m_sErrorDescription = "The minimum required disk space needed for logging is not available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5034:
		{
			m_sErrorName = "ERROR_QUORUM_OWNER_ALIVE";
			m_sErrorDescription = "The cluster node failed to take control of the quorum resource because the resource is owned by another active node.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5035:
		{
			m_sErrorName = "ERROR_NETWORK_NOT_AVAILABLE";
			m_sErrorDescription = "A cluster network is not available for this operation.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5036:
		{
			m_sErrorName = "ERROR_NODE_NOT_AVAILABLE";
			m_sErrorDescription = "A cluster node is not available for this operation.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5037:
		{
			m_sErrorName = "ERROR_ALL_NODES_NOT_AVAILABLE";
			m_sErrorDescription = "All cluster nodes must be running to perform this operation.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5038:
		{
			m_sErrorName = "ERROR_RESOURCE_FAILED";
			m_sErrorDescription = "A cluster resource failed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5039:
		{
			m_sErrorName = "ERROR_CLUSTER_INVALID_NODE";
			m_sErrorDescription = "The cluster node is not valid.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5040:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_EXISTS";
			m_sErrorDescription = "The cluster node already exists.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5041:
		{
			m_sErrorName = "ERROR_CLUSTER_JOIN_IN_PROGRESS";
			m_sErrorDescription = "A node is in the process of joining the cluster.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5042:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_NOT_FOUND";
			m_sErrorDescription = "The cluster node was not found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5043:
		{
			m_sErrorName = "ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND";
			m_sErrorDescription = "The cluster local node information was not found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5044:
		{
			m_sErrorName = "ERROR_CLUSTER_NETWORK_EXISTS";
			m_sErrorDescription = "The cluster network already exists.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5045:
		{
			m_sErrorName = "ERROR_CLUSTER_NETWORK_NOT_FOUND";
			m_sErrorDescription = "The cluster network was not found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5046:
		{
			m_sErrorName = "ERROR_CLUSTER_NETINTERFACE_EXISTS";
			m_sErrorDescription = "The cluster network interface already exists.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5047:
		{
			m_sErrorName = "ERROR_CLUSTER_NETINTERFACE_NOT_FOUND";
			m_sErrorDescription = "The cluster network interface was not found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5048:
		{
			m_sErrorName = "ERROR_CLUSTER_INVALID_REQUEST";
			m_sErrorDescription = "The cluster request is not valid for this object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5049:
		{
			m_sErrorName = "ERROR_CLUSTER_INVALID_NETWORK_PROVIDER";
			m_sErrorDescription = "The cluster network provider is not valid.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5050:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_DOWN";
			m_sErrorDescription = "The cluster node is down.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5051:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_UNREACHABLE";
			m_sErrorDescription = "The cluster node is not reachable.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5052:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_NOT_MEMBER";
			m_sErrorDescription = "The cluster node is not a member of the cluster.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5053:
		{
			m_sErrorName = "ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS";
			m_sErrorDescription = "A cluster join operation is not in progress.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5054:
		{
			m_sErrorName = "ERROR_CLUSTER_INVALID_NETWORK";
			m_sErrorDescription = "The cluster network is not valid.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5056:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_UP";
			m_sErrorDescription = "The cluster node is up.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5057:
		{
			m_sErrorName = "ERROR_CLUSTER_IPADDR_IN_USE";
			m_sErrorDescription = "The cluster IP address is already in use.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5058:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_NOT_PAUSED";
			m_sErrorDescription = "The cluster node is not paused.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5059:
		{
			m_sErrorName = "ERROR_CLUSTER_NO_SECURITY_CONTEXT";
			m_sErrorDescription = "No cluster security context is available.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5060:
		{
			m_sErrorName = "ERROR_CLUSTER_NETWORK_NOT_INTERNAL";
			m_sErrorDescription = "The cluster network is not configured for internal cluster communication.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5061:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_ALREADY_UP";
			m_sErrorDescription = "The cluster node is already up.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5062:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_ALREADY_DOWN";
			m_sErrorDescription = "The cluster node is already down.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5063:
		{
			m_sErrorName = "ERROR_CLUSTER_NETWORK_ALREADY_ONLINE";
			m_sErrorDescription = "The cluster network is already online.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5064:
		{
			m_sErrorName = "ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE";
			m_sErrorDescription = "The cluster network is already offline.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5065:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_ALREADY_MEMBER";
			m_sErrorDescription = "The cluster node is already a member of the cluster.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5066:
		{
			m_sErrorName = "ERROR_CLUSTER_LAST_INTERNAL_NETWORK";
			m_sErrorDescription = "The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5067:
		{
			m_sErrorName = "ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS";
			m_sErrorDescription = "One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5068:
		{
			m_sErrorName = "ERROR_INVALID_OPERATION_ON_QUORUM";
			m_sErrorDescription = "This operation cannot be performed on the cluster resource as it the quorum resource. You may not bring the quorum resource offline or modify its possible owners list.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5069:
		{
			m_sErrorName = "ERROR_DEPENDENCY_NOT_ALLOWED";
			m_sErrorDescription = "The cluster quorum resource is not allowed to have any dependencies.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5070:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_PAUSED";
			m_sErrorDescription = "The cluster node is paused.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5071:
		{
			m_sErrorName = "ERROR_NODE_CANT_HOST_RESOURCE";
			m_sErrorDescription = "The cluster resource cannot be brought online. The owner node cannot run this resource.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5072:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_NOT_READY";
			m_sErrorDescription = "The cluster node is not ready to perform the requested operation.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5073:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_SHUTTING_DOWN";
			m_sErrorDescription = "The cluster node is shutting down.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5074:
		{
			m_sErrorName = "ERROR_CLUSTER_JOIN_ABORTED";
			m_sErrorDescription = "The cluster join operation was aborted.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5075:
		{
			m_sErrorName = "ERROR_CLUSTER_INCOMPATIBLE_VERSIONS";
			m_sErrorDescription = "The cluster join operation failed due to incompatible software versions between the joining node and its sponsor.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5076:
		{
			m_sErrorName = "ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED";
			m_sErrorDescription = "This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5077:
		{
			m_sErrorName = "ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED";
			m_sErrorDescription = "The system configuration changed during the cluster join or form operation. The join or form operation was aborted.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5078:
		{
			m_sErrorName = "ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND";
			m_sErrorDescription = "The specified resource type was not found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5079:
		{
			m_sErrorName = "ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED";
			m_sErrorDescription = "The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5080:
		{
			m_sErrorName = "ERROR_CLUSTER_RESNAME_NOT_FOUND";
			m_sErrorDescription = "The specified resource name is supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5081:
		{
			m_sErrorName = "ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED";
			m_sErrorDescription = "No authentication package could be registered with the RPC server.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5082:
		{
			m_sErrorName = "ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST";
			m_sErrorDescription = "You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5083:
		{
			m_sErrorName = "ERROR_CLUSTER_DATABASE_SEQMISMATCH";
			m_sErrorDescription = "The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5084:
		{
			m_sErrorName = "ERROR_RESMON_INVALID_STATE";
			m_sErrorDescription = "The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5085:
		{
			m_sErrorName = "ERROR_CLUSTER_GUM_NOT_LOCKER";
			m_sErrorDescription = "A non locker code got a request to reserve the lock for making global updates.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5086:
		{
			m_sErrorName = "ERROR_QUORUM_DISK_NOT_FOUND";
			m_sErrorDescription = "The quorum disk could not be located by the cluster service.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5087:
		{
			m_sErrorName = "ERROR_DATABASE_BACKUP_CORRUPT";
			m_sErrorDescription = "The backup up cluster database is possibly corrupt.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5088:
		{
			m_sErrorName = "ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT";
			m_sErrorDescription = "A DFS root already exists in this cluster node.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 5089:
		{
			m_sErrorName = "ERROR_RESOURCE_PROPERTY_UNCHANGEABLE";
			m_sErrorDescription = "An attempt to modify a resource property failed because it conflicts with another existing property.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6000:
		{
			m_sErrorName = "ERROR_ENCRYPTION_FAILED";
			m_sErrorDescription = "The specified file could not be encrypted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6001:
		{
			m_sErrorName = "ERROR_DECRYPTION_FAILED";
			m_sErrorDescription = "The specified file could not be decrypted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6002:
		{
			m_sErrorName = "ERROR_FILE_ENCRYPTED";
			m_sErrorDescription = "The specified file is encrypted and the user does not have the ability to decrypt it. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6003:
		{
			m_sErrorName = "ERROR_NO_RECOVERY_POLICY";
			m_sErrorDescription = "There is no valid encryption recovery policy configured for this system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6004:
		{
			m_sErrorName = "ERROR_NO_EFS";
			m_sErrorDescription = "The required encryption driver is not loaded for this system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6005:
		{
			m_sErrorName = "ERROR_WRONG_EFS";
			m_sErrorDescription = "The file was encrypted with a different encryption driver than is currently loaded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6006:
		{
			m_sErrorName = "ERROR_NO_USER_KEYS";
			m_sErrorDescription = "There are no EFS keys defined for the user. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6007:
		{
			m_sErrorName = "ERROR_FILE_NOT_ENCRYPTED";
			m_sErrorDescription = "The specified file is not encrypted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6008:
		{
			m_sErrorName = "ERROR_NOT_EXPORT_FORMAT";
			m_sErrorDescription = "The specified file is not in the defined EFS export format. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6009:
		{
			m_sErrorName = "ERROR_FILE_READ_ONLY";
			m_sErrorDescription = "The specified file is read only.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6010:
		{
			m_sErrorName = "ERROR_DIR_EFS_DISALLOWED";
			m_sErrorDescription = "The directory has been disabled for encryption.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6011:
		{
			m_sErrorName = "ERROR_EFS_SERVER_NOT_TRUSTED";
			m_sErrorDescription = "The server is not trusted for remote encryption operation.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6118:
		{
			m_sErrorName = "ERROR_NO_BROWSER_SERVERS_FOUND";
			m_sErrorDescription = "The list of servers for this workgroup is not currently available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 6200:
		{
			m_sErrorName = "SCHED_E_SERVICE_NOT_LOCALSYSTEM";
			m_sErrorDescription = "The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7001:
		{
			m_sErrorName = "ERROR_CTX_WINSTATION_NAME_INVALID";
			m_sErrorDescription = "The specified session name is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7002:
		{
			m_sErrorName = "ERROR_CTX_INVALID_PD";
			m_sErrorDescription = "The specified protocol driver is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7003:
		{
			m_sErrorName = "ERROR_CTX_PD_NOT_FOUND";
			m_sErrorDescription = "The specified protocol driver was not found in the system path. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7004:
		{
			m_sErrorName = "ERROR_CTX_WD_NOT_FOUND";
			m_sErrorDescription = "The specified terminal connection driver was not found in the system path. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7005:
		{
			m_sErrorName = "ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY";
			m_sErrorDescription = "A registry key for event logging could not be created for this session. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7006:
		{
			m_sErrorName = "ERROR_CTX_SERVICE_NAME_COLLISION";
			m_sErrorDescription = "A service with the same name already exists on the system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7007:
		{
			m_sErrorName = "ERROR_CTX_CLOSE_PENDING";
			m_sErrorDescription = "A close operation is pending on the session. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7008:
		{
			m_sErrorName = "ERROR_CTX_NO_OUTBUF";
			m_sErrorDescription = "There are no free output buffers available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7009:
		{
			m_sErrorName = "ERROR_CTX_MODEM_INF_NOT_FOUND";
			m_sErrorDescription = "The MODEM.INF file was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7010:
		{
			m_sErrorName = "ERROR_CTX_INVALID_MODEMNAME";
			m_sErrorDescription = "The modem name was not found in MODEM.INF. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7011:
		{
			m_sErrorName = "ERROR_CTX_MODEM_RESPONSE_ERROR";
			m_sErrorDescription = "The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7012:
		{
			m_sErrorName = "ERROR_CTX_MODEM_RESPONSE_TIMEOUT";
			m_sErrorDescription = "The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7013:
		{
			m_sErrorName = "ERROR_CTX_MODEM_RESPONSE_NO_CARRIER";
			m_sErrorDescription = "Carrier detect has failed or carrier has been dropped due to disconnect. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7014:
		{
			m_sErrorName = "ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE";
			m_sErrorDescription = "Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7015:
		{
			m_sErrorName = "ERROR_CTX_MODEM_RESPONSE_BUSY";
			m_sErrorDescription = "Busy signal detected at remote site on callback. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7016:
		{
			m_sErrorName = "ERROR_CTX_MODEM_RESPONSE_VOICE";
			m_sErrorDescription = "Voice detected at remote site on callback. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7017:
		{
			m_sErrorName = "ERROR_CTX_TD_ERROR";
			m_sErrorDescription = "Transport driver error ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7022:
		{
			m_sErrorName = "ERROR_CTX_WINSTATION_NOT_FOUND";
			m_sErrorDescription = "The specified session cannot be found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7023:
		{
			m_sErrorName = "ERROR_CTX_WINSTATION_ALREADY_EXISTS";
			m_sErrorDescription = "The specified session name is already in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7024:
		{
			m_sErrorName = "ERROR_CTX_WINSTATION_BUSY";
			m_sErrorDescription = "The requested operation cannot be completed because the terminal connection is currently busy processing a connect, disconnect, reset, or delete operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7025:
		{
			m_sErrorName = "ERROR_CTX_BAD_VIDEO_MODE";
			m_sErrorDescription = "An attempt has been made to connect to a session whose video mode is not supported by the current client. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7035:
		{
			m_sErrorName = "ERROR_CTX_GRAPHICS_INVALID";
			m_sErrorDescription = "The application attempted to enable DOS graphics mode. DOS graphics mode is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7037:
		{
			m_sErrorName = "ERROR_CTX_LOGON_DISABLED";
			m_sErrorDescription = "Your interactive logon privilege has been disabled. Please contact your administrator. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7038:
		{
			m_sErrorName = "ERROR_CTX_NOT_CONSOLE";
			m_sErrorDescription = "The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7040:
		{
			m_sErrorName = "ERROR_CTX_CLIENT_QUERY_TIMEOUT";
			m_sErrorDescription = "The client failed to respond to the server connect message. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7041:
		{
			m_sErrorName = "ERROR_CTX_CONSOLE_DISCONNECT";
			m_sErrorDescription = "Disconnecting the console session is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7042:
		{
			m_sErrorName = "ERROR_CTX_CONSOLE_CONNECT";
			m_sErrorDescription = "Reconnecting a disconnected session to the console is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7044:
		{
			m_sErrorName = "ERROR_CTX_SHADOW_DENIED";
			m_sErrorDescription = "The request to control another session remotely was denied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7045:
		{
			m_sErrorName = "ERROR_CTX_WINSTATION_ACCESS_DENIED";
			m_sErrorDescription = "The requested session access is denied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7049:
		{
			m_sErrorName = "ERROR_CTX_INVALID_WD";
			m_sErrorDescription = "The specified terminal connection driver is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7050:
		{
			m_sErrorName = "ERROR_CTX_SHADOW_INVALID";
			m_sErrorDescription = "The requested session cannot be controlled remotely. This may be because the session is disconnected or does not currently have a user logged on. Also, you cannot control a session remotely from the system console or control the system console remotely . ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7051:
		{
			m_sErrorName = "ERROR_CTX_SHADOW_DISABLED";
			m_sErrorDescription = "The requested session is not configured to allow remote control. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7052:
		{
			m_sErrorName = "ERROR_CTX_CLIENT_LICENSE_IN_USE";
			m_sErrorDescription = "Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user. Please call your system administrator to obtain a new copy of the Terminal Server client with a valid, unique license number.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7053:
		{
			m_sErrorName = "ERROR_CTX_CLIENT_LICENSE_NOT_SET";
			m_sErrorDescription = "Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client. Please call your system administrator for help in entering a valid, unique license number for this Terminal Server client.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7054:
		{
			m_sErrorName = "ERROR_CTX_LICENSE_NOT_AVAILABLE";
			m_sErrorDescription = "The system has reached its licensed logon limit. Please try again later.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7055:
		{
			m_sErrorName = "ERROR_CTX_LICENSE_CLIENT_INVALID";
			m_sErrorDescription = "The client you are using is not licensed to use this system. Your logon request is denied.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 7056:
		{
			m_sErrorName = "ERROR_CTX_LICENSE_EXPIRED";
			m_sErrorDescription = "The system license has expired. Your logon request is denied.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8001:
		{
			m_sErrorName = "FRS_ERR_INVALID_API_SEQUENCE";
			m_sErrorDescription = "The file replication service API was called incorrectly. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8002:
		{
			m_sErrorName = "FRS_ERR_STARTING_SERVICE";
			m_sErrorDescription = "The file replication service cannot be started. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8003:
		{
			m_sErrorName = "FRS_ERR_STOPPING_SERVICE";
			m_sErrorDescription = "The file replication service cannot be stopped. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8004:
		{
			m_sErrorName = "FRS_ERR_INTERNAL_API";
			m_sErrorDescription = "The file replication service API terminated the request. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8005:
		{
			m_sErrorName = "FRS_ERR_INTERNAL";
			m_sErrorDescription = "The file replication service terminated the request. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8006:
		{
			m_sErrorName = "FRS_ERR_SERVICE_COMM";
			m_sErrorDescription = "The file replication service cannot be contacted. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8007:
		{
			m_sErrorName = "FRS_ERR_INSUFFICIENT_PRIV";
			m_sErrorDescription = "The file replication service cannot satisfy the request because the user has insufficient privileges. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8008:
		{
			m_sErrorName = "FRS_ERR_AUTHENTICATION";
			m_sErrorDescription = "The file replication service cannot satisfy the request because authenticated RPC is not available. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8009:
		{
			m_sErrorName = "FRS_ERR_PARENT_INSUFFICIENT_PRIV";
			m_sErrorDescription = "The file replication service cannot satisfy the request because the user has insufficient privileges on the domain controller. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8010:
		{
			m_sErrorName = "FRS_ERR_PARENT_AUTHENTICATION";
			m_sErrorDescription = "The file replication service cannot satisfy the request because authenticated RPC is not available on the domain controller. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8011:
		{
			m_sErrorName = "FRS_ERR_CHILD_TO_PARENT_COMM";
			m_sErrorDescription = "The file replication service cannot communicate with the file replication service on the domain controller. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8012:
		{
			m_sErrorName = "FRS_ERR_PARENT_TO_CHILD_COMM";
			m_sErrorDescription = "The file replication service on the domain controller cannot communicate with the file replication service on this computer. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8013:
		{
			m_sErrorName = "FRS_ERR_SYSVOL_POPULATE";
			m_sErrorDescription = "The file replication service cannot populate the system volume because of an internal error. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8014:
		{
			m_sErrorName = "FRS_ERR_SYSVOL_POPULATE_TIMEOUT";
			m_sErrorDescription = "The file replication service cannot populate the system volume because of an internal timeout. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8015:
		{
			m_sErrorName = "FRS_ERR_SYSVOL_IS_BUSY";
			m_sErrorDescription = "The file replication service cannot process the request. The system volume is busy with a previous request. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8016:
		{
			m_sErrorName = "FRS_ERR_SYSVOL_DEMOTE";
			m_sErrorDescription = "The file replication service cannot stop replicating the system volume because of an internal error. The event log may have more information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8017:
		{
			m_sErrorName = "FRS_ERR_INVALID_SERVICE_PARAMETER";
			m_sErrorDescription = "The file replication service detected an invalid parameter. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8200:
		{
			m_sErrorName = "ERROR_DS_NOT_INSTALLED";
			m_sErrorDescription = "An error occurred while installing the directory service. For more information, see the event log. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8201:
		{
			m_sErrorName = "ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY";
			m_sErrorDescription = "The directory service evaluated group memberships locally. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8202:
		{
			m_sErrorName = "ERROR_DS_NO_ATTRIBUTE_OR_VALUE";
			m_sErrorDescription = "The specified directory service attribute or value does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8203:
		{
			m_sErrorName = "ERROR_DS_INVALID_ATTRIBUTE_SYNTAX";
			m_sErrorDescription = "The attribute syntax specified to the directory service is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8204:
		{
			m_sErrorName = "ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED";
			m_sErrorDescription = "The attribute type specified to the directory service is not defined. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8205:
		{
			m_sErrorName = "ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS";
			m_sErrorDescription = "The specified directory service attribute or value already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8206:
		{
			m_sErrorName = "ERROR_DS_BUSY";
			m_sErrorDescription = "The directory service is busy. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8207:
		{
			m_sErrorName = "ERROR_DS_UNAVAILABLE";
			m_sErrorDescription = "The directory service is unavailable. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8208:
		{
			m_sErrorName = "ERROR_DS_NO_RIDS_ALLOCATED";
			m_sErrorDescription = "The directory service was unable to allocate a relative identifier. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8209:
		{
			m_sErrorName = "ERROR_DS_NO_MORE_RIDS";
			m_sErrorDescription = "The directory service has exhausted the pool of relative identifiers. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8210:
		{
			m_sErrorName = "ERROR_DS_INCORRECT_ROLE_OWNER";
			m_sErrorDescription = "The requested operation could not be performed because the directory service is not the master for that type of operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8211:
		{
			m_sErrorName = "ERROR_DS_RIDMGR_INIT_ERROR";
			m_sErrorDescription = "The directory service was unable to initialize the subsystem that allocates relative identifiers. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8212:
		{
			m_sErrorName = "ERROR_DS_OBJ_CLASS_VIOLATION";
			m_sErrorDescription = "The requested operation did not satisfy one or more constraints associated with the class of the object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8213:
		{
			m_sErrorName = "ERROR_DS_CANT_ON_NON_LEAF";
			m_sErrorDescription = "The directory service can perform the requested operation only on a leaf object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8214:
		{
			m_sErrorName = "ERROR_DS_CANT_ON_RDN";
			m_sErrorDescription = "The directory service cannot perform the requested operation on the RDN attribute of an object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8215:
		{
			m_sErrorName = "ERROR_DS_CANT_MOD_OBJ_CLASS";
			m_sErrorDescription = "The directory service detected an attempt to modify the object class of an object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8216:
		{
			m_sErrorName = "ERROR_DS_CROSS_DOM_MOVE_ERROR";
			m_sErrorDescription = "The requested cross-domain move operation could not be performed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8217:
		{
			m_sErrorName = "ERROR_DS_GC_NOT_AVAILABLE";
			m_sErrorDescription = "Unable to contact the global catalog server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8218:
		{
			m_sErrorName = "ERROR_SHARED_POLICY";
			m_sErrorDescription = "The policy object is shared and can only be modified at the root. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8219:
		{
			m_sErrorName = "ERROR_POLICY_OBJECT_NOT_FOUND";
			m_sErrorDescription = "The policy object does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8220:
		{
			m_sErrorName = "ERROR_POLICY_ONLY_IN_DS";
			m_sErrorDescription = "The requested policy information is only in the directory service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8221:
		{
			m_sErrorName = "ERROR_PROMOTION_ACTIVE";
			m_sErrorDescription = "A domain controller promotion is currently active. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8222:
		{
			m_sErrorName = "ERROR_NO_PROMOTION_ACTIVE";
			m_sErrorDescription = "A domain controller promotion is not currently active ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8224:
		{
			m_sErrorName = "ERROR_DS_OPERATIONS_ERROR";
			m_sErrorDescription = "An operations error occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8225:
		{
			m_sErrorName = "ERROR_DS_PROTOCOL_ERROR";
			m_sErrorDescription = "A protocol error occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8226:
		{
			m_sErrorName = "ERROR_DS_TIMELIMIT_EXCEEDED";
			m_sErrorDescription = "The time limit for this request was exceeded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8227:
		{
			m_sErrorName = "ERROR_DS_SIZELIMIT_EXCEEDED";
			m_sErrorDescription = "The size limit for this request was exceeded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8228:
		{
			m_sErrorName = "ERROR_DS_ADMIN_LIMIT_EXCEEDED";
			m_sErrorDescription = "The administrative limit for this request was exceeded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8229:
		{
			m_sErrorName = "ERROR_DS_COMPARE_FALSE";
			m_sErrorDescription = "The compare response was false. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8230:
		{
			m_sErrorName = "ERROR_DS_COMPARE_TRUE";
			m_sErrorDescription = "The compare response was true. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8231:
		{
			m_sErrorName = "ERROR_DS_AUTH_METHOD_NOT_SUPPORTED";
			m_sErrorDescription = "The requested authentication method is not supported by the server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8232:
		{
			m_sErrorName = "ERROR_DS_STRONG_AUTH_REQUIRED";
			m_sErrorDescription = "A more secure authentication method is required for this server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8233:
		{
			m_sErrorName = "ERROR_DS_INAPPROPRIATE_AUTH";
			m_sErrorDescription = "Inappropriate authentication. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8234:
		{
			m_sErrorName = "ERROR_DS_AUTH_UNKNOWN";
			m_sErrorDescription = "The authentication mechanism is unknown. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8235:
		{
			m_sErrorName = "ERROR_DS_REFERRAL";
			m_sErrorDescription = "A referral was returned from the server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8236:
		{
			m_sErrorName = "ERROR_DS_UNAVAILABLE_CRIT_EXTENSION";
			m_sErrorDescription = "The server does not support the requested critical extension. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8237:
		{
			m_sErrorName = "ERROR_DS_CONFIDENTIALITY_REQUIRED";
			m_sErrorDescription = "This request requires a secure connection. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8238:
		{
			m_sErrorName = "ERROR_DS_INAPPROPRIATE_MATCHING";
			m_sErrorDescription = "Inappropriate matching. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8239:
		{
			m_sErrorName = "ERROR_DS_CONSTRAINT_VIOLATION";
			m_sErrorDescription = "A constraint violation occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8240:
		{
			m_sErrorName = "ERROR_DS_NO_SUCH_OBJECT";
			m_sErrorDescription = "There is no such object on the server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8241:
		{
			m_sErrorName = "ERROR_DS_ALIAS_PROBLEM";
			m_sErrorDescription = "There is an alias problem. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8242:
		{
			m_sErrorName = "ERROR_DS_INVALID_DN_SYNTAX";
			m_sErrorDescription = "An invalid dn syntax has been specified. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8243:
		{
			m_sErrorName = "ERROR_DS_IS_LEAF";
			m_sErrorDescription = "The object is a leaf object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8244:
		{
			m_sErrorName = "ERROR_DS_ALIAS_DEREF_PROBLEM";
			m_sErrorDescription = "There is an alias dereferencing problem. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8245:
		{
			m_sErrorName = "ERROR_DS_UNWILLING_TO_PERFORM";
			m_sErrorDescription = "The server is unwilling to process the request. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8246:
		{
			m_sErrorName = "ERROR_DS_LOOP_DETECT";
			m_sErrorDescription = "A loop has been detected. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8247:
		{
			m_sErrorName = "ERROR_DS_NAMING_VIOLATION";
			m_sErrorDescription = "There is a naming violation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8248:
		{
			m_sErrorName = "ERROR_DS_OBJECT_RESULTS_TOO_LARGE";
			m_sErrorDescription = "The result set is too large. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8249:
		{
			m_sErrorName = "ERROR_DS_AFFECTS_MULTIPLE_DSAS";
			m_sErrorDescription = "The operation affects multiple DSAs ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8250:
		{
			m_sErrorName = "ERROR_DS_SERVER_DOWN";
			m_sErrorDescription = "The server is not operational. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8251:
		{
			m_sErrorName = "ERROR_DS_LOCAL_ERROR";
			m_sErrorDescription = "A local error has occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8252:
		{
			m_sErrorName = "ERROR_DS_ENCODING_ERROR";
			m_sErrorDescription = "An encoding error has occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8253:
		{
			m_sErrorName = "ERROR_DS_DECODING_ERROR";
			m_sErrorDescription = "A decoding error has occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8254:
		{
			m_sErrorName = "ERROR_DS_FILTER_UNKNOWN";
			m_sErrorDescription = "The search filter cannot be recognized. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8255:
		{
			m_sErrorName = "ERROR_DS_PARAM_ERROR";
			m_sErrorDescription = "One or more parameters are illegal. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8256:
		{
			m_sErrorName = "ERROR_DS_NOT_SUPPORTED";
			m_sErrorDescription = "The specified method is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8257:
		{
			m_sErrorName = "ERROR_DS_NO_RESULTS_RETURNED";
			m_sErrorDescription = "No results were returned. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8258:
		{
			m_sErrorName = "ERROR_DS_CONTROL_NOT_FOUND";
			m_sErrorDescription = "The specified control is not supported by the server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8259:
		{
			m_sErrorName = "ERROR_DS_CLIENT_LOOP";
			m_sErrorDescription = "A referral loop was detected by the client. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8260:
		{
			m_sErrorName = "ERROR_DS_REFERRAL_LIMIT_EXCEEDED";
			m_sErrorDescription = "The preset referral limit was exceeded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8301:
		{
			m_sErrorName = "ERROR_DS_ROOT_MUST_BE_NC";
			m_sErrorDescription = "The root object must be the head of a naming context. The root object cannot have an instantiated parent. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8302:
		{
			m_sErrorName = "ERROR_DS_ADD_REPLICA_INHIBITED";
			m_sErrorDescription = "The add replica operation cannot be performed. The naming context must be writable in order to create the replica. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8303:
		{
			m_sErrorName = "ERROR_DS_ATT_NOT_DEF_IN_SCHEMA";
			m_sErrorDescription = "A reference to an attribute that is not defined in the schema occurred. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8304:
		{
			m_sErrorName = "ERROR_DS_MAX_OBJ_SIZE_EXCEEDED";
			m_sErrorDescription = "The maximum size of an object has been exceeded. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8305:
		{
			m_sErrorName = "ERROR_DS_OBJ_STRING_NAME_EXISTS";
			m_sErrorDescription = "An attempt was made to add an object to the directory with a name that is already in use. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8306:
		{
			m_sErrorName = "ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA";
			m_sErrorDescription = "An attempt was made to add an object of a class that does not have an RDN defined in the schema. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8307:
		{
			m_sErrorName = "ERROR_DS_RDN_DOESNT_MATCH_SCHEMA";
			m_sErrorDescription = "An attempt was made to add an object using an RDN that is not the RDN defined in the schema. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8308:
		{
			m_sErrorName = "ERROR_DS_NO_REQUESTED_ATTS_FOUND";
			m_sErrorDescription = "None of the requested attributes were found on the objects. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8309:
		{
			m_sErrorName = "ERROR_DS_USER_BUFFER_TO_SMALL";
			m_sErrorDescription = "The user buffer is too small. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8310:
		{
			m_sErrorName = "ERROR_DS_ATT_IS_NOT_ON_OBJ";
			m_sErrorDescription = "The attribute specified in the operation is not present on the object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8311:
		{
			m_sErrorName = "ERROR_DS_ILLEGAL_MOD_OPERATION";
			m_sErrorDescription = "Illegal modify operation. Some aspect of the modification is not permitted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8312:
		{
			m_sErrorName = "ERROR_DS_OBJ_TOO_LARGE";
			m_sErrorDescription = "The specified object is too large. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8313:
		{
			m_sErrorName = "ERROR_DS_BAD_INSTANCE_TYPE";
			m_sErrorDescription = "The specified instance type is not valid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8314:
		{
			m_sErrorName = "ERROR_DS_MASTERDSA_REQUIRED";
			m_sErrorDescription = "The operation must be performed at a master DSA.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8315:
		{
			m_sErrorName = "ERROR_DS_OBJECT_CLASS_REQUIRED";
			m_sErrorDescription = "The object class attribute must be specified.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8316:
		{
			m_sErrorName = "ERROR_DS_MISSING_REQUIRED_ATT";
			m_sErrorDescription = "A required attribute is missing.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8317:
		{
			m_sErrorName = "ERROR_DS_ATT_NOT_DEF_FOR_CLASS";
			m_sErrorDescription = "An attempt was made to modify an object to include an attribute that is not legal for its class ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8318:
		{
			m_sErrorName = "ERROR_DS_ATT_ALREADY_EXISTS";
			m_sErrorDescription = "The specified attribute is already present on the object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8320:
		{
			m_sErrorName = "ERROR_DS_CANT_ADD_ATT_VALUES";
			m_sErrorDescription = "The specified attribute is not present, or has no values.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8321:
		{
			m_sErrorName = "ERROR_DS_SINGLE_VALUE_CONSTRAINT";
			m_sErrorDescription = "Multiple values were specified for an attribute that can have only one value.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8322:
		{
			m_sErrorName = "ERROR_DS_RANGE_CONSTRAINT";
			m_sErrorDescription = "A value for the attribute was not in the acceptable range of values.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8323:
		{
			m_sErrorName = "ERROR_DS_ATT_VAL_ALREADY_EXISTS";
			m_sErrorDescription = "The specified value already exists.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8324:
		{
			m_sErrorName = "ERROR_DS_CANT_REM_MISSING_ATT";
			m_sErrorDescription = "The attribute cannot be removed because it is not present on the object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8325:
		{
			m_sErrorName = "ERROR_DS_CANT_REM_MISSING_ATT_VAL";
			m_sErrorDescription = "The attribute value cannot be removed because it is not present on the object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8326:
		{
			m_sErrorName = "ERROR_DS_ROOT_CANT_BE_SUBREF";
			m_sErrorDescription = "The specified root object cannot be a subref.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8327:
		{
			m_sErrorName = "ERROR_DS_NO_CHAINING";
			m_sErrorDescription = "Chaining is not permitted.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8328:
		{
			m_sErrorName = "ERROR_DS_NO_CHAINED_EVAL";
			m_sErrorDescription = "Chained evaluation is not permitted.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8329:
		{
			m_sErrorName = "ERROR_DS_NO_PARENT_OBJECT";
			m_sErrorDescription = "The operation could not be performed because the object's parent is either uninstantiated or deleted.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8330:
		{
			m_sErrorName = "ERROR_DS_PARENT_IS_AN_ALIAS";
			m_sErrorDescription = "Having a parent that is an alias is not permitted. Aliases are leaf objects.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8331:
		{
			m_sErrorName = "ERROR_DS_CANT_MIX_MASTER_AND_REPS";
			m_sErrorDescription = "The object and parent must be of the same type, either both masters or both replicas. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8332:
		{
			m_sErrorName = "ERROR_DS_CHILDREN_EXIST";
			m_sErrorDescription = "The operation cannot be performed because child objects exist. This operation can only be performed on a leaf object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8333:
		{
			m_sErrorName = "ERROR_DS_OBJ_NOT_FOUND";
			m_sErrorDescription = "Directory object not found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8334:
		{
			m_sErrorName = "ERROR_DS_ALIASED_OBJ_MISSING";
			m_sErrorDescription = "The aliased object is missing.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8335:
		{
			m_sErrorName = "ERROR_DS_BAD_NAME_SYNTAX";
			m_sErrorDescription = "The object name has bad syntax.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8336:
		{
			m_sErrorName = "ERROR_DS_ALIAS_POINTS_TO_ALIAS";
			m_sErrorDescription = "It is not permitted for an alias to refer to another alias. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8337:
		{
			m_sErrorName = "ERROR_DS_CANT_DEREF_ALIAS";
			m_sErrorDescription = "The alias cannot be dereferenced.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8338:
		{
			m_sErrorName = "ERROR_DS_OUT_OF_SCOPE";
			m_sErrorDescription = "The operation is out of scope.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8340:
		{
			m_sErrorName = "ERROR_DS_CANT_DELETE_DSA_OBJ";
			m_sErrorDescription = "The DSA object cannot be deleted.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8341:
		{
			m_sErrorName = "ERROR_DS_GENERIC_ERROR";
			m_sErrorDescription = "A directory service error has occurred.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8342:
		{
			m_sErrorName = "ERROR_DS_DSA_MUST_BE_INT_MASTER";
			m_sErrorDescription = "The operation can only be performed on an internal master DSA object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8343:
		{
			m_sErrorName = "ERROR_DS_CLASS_NOT_DSA";
			m_sErrorDescription = "The object must be of class DSA.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8344:
		{
			m_sErrorName = "ERROR_DS_INSUFF_ACCESS_RIGHTS";
			m_sErrorDescription = "Insufficient access rights to perform the operation.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8345:
		{
			m_sErrorName = "ERROR_DS_ILLEGAL_SUPERIOR";
			m_sErrorDescription = "The object cannot be added because the parent is not on the list of possible superiors. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8346:
		{
			m_sErrorName = "ERROR_DS_ATTRIBUTE_OWNED_BY_SAM";
			m_sErrorDescription = "Access to the attribute is not permitted because the attribute is owned by the Security Accounts Manager (SAM). ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8347:
		{
			m_sErrorName = "ERROR_DS_NAME_TOO_MANY_PARTS";
			m_sErrorDescription = "The name has too many parts.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8348:
		{
			m_sErrorName = "ERROR_DS_NAME_TOO_LONG";
			m_sErrorDescription = "The name is too long. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8349:
		{
			m_sErrorName = "ERROR_DS_NAME_VALUE_TOO_LONG";
			m_sErrorDescription = "The name value is too long.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8350:
		{
			m_sErrorName = "ERROR_DS_NAME_UNPARSEABLE";
			m_sErrorDescription = "The directory service encountered an error parsing a name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8351:
		{
			m_sErrorName = "ERROR_DS_NAME_TYPE_UNKNOWN";
			m_sErrorDescription = "The directory service cannot get the attribute type for a name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8352:
		{
			m_sErrorName = "ERROR_DS_NOT_AN_OBJECT";
			m_sErrorDescription = "The name does not identify an object; the name identifies a phantom.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8353:
		{
			m_sErrorName = "ERROR_DS_SEC_DESC_TOO_SHORT";
			m_sErrorDescription = "The security descriptor is too short.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8354:
		{
			m_sErrorName = "ERROR_DS_SEC_DESC_INVALID";
			m_sErrorDescription = "The security descriptor is invalid.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8355:
		{
			m_sErrorName = "ERROR_DS_NO_DELETED_NAME";
			m_sErrorDescription = "Failed to create name for deleted object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8356:
		{
			m_sErrorName = "ERROR_DS_SUBREF_MUST_HAVE_PARENT";
			m_sErrorDescription = "The parent of a new subref must exist.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8357:
		{
			m_sErrorName = "ERROR_DS_NCNAME_MUST_BE_NC";
			m_sErrorDescription = "The object must be a naming context.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8358:
		{
			m_sErrorName = "ERROR_DS_CANT_ADD_SYSTEM_ONLY";
			m_sErrorDescription = "It is not permitted to add an attribute which is owned by the system.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8359:
		{
			m_sErrorName = "ERROR_DS_CLASS_MUST_BE_CONCRETE";
			m_sErrorDescription = "The class of the object must be structural; you cannot instantiate an abstract class. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8360:
		{
			m_sErrorName = "ERROR_DS_INVALID_DMD";
			m_sErrorDescription = "The schema object could not be found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8361:
		{
			m_sErrorName = "ERROR_DS_OBJ_GUID_EXISTS";
			m_sErrorDescription = "A local object with this GUID (dead or alive) already exists.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8362:
		{
			m_sErrorName = "ERROR_DS_NOT_ON_BACKLINK";
			m_sErrorDescription = "The operation cannot be performed on a back link.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8363:
		{
			m_sErrorName = "ERROR_DS_NO_CROSSREF_FOR_NC";
			m_sErrorDescription = "The cross reference for the specified naming context could not be found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8364:
		{
			m_sErrorName = "ERROR_DS_SHUTTING_DOWN";
			m_sErrorDescription = "The operation could not be performed because the directory service is shutting down.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8365:
		{
			m_sErrorName = "ERROR_DS_UNKNOWN_OPERATION";
			m_sErrorDescription = "The directory service request is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8366:
		{
			m_sErrorName = "ERROR_DS_INVALID_ROLE_OWNER";
			m_sErrorDescription = "The role owner attribute could not be read.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8367:
		{
			m_sErrorName = "ERROR_DS_COULDNT_CONTACT_FSMO";
			m_sErrorDescription = "The requested FSMO operation failed. The current FSMO holder could not be reached. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8368:
		{
			m_sErrorName = "ERROR_DS_CROSS_NC_DN_RENAME";
			m_sErrorDescription = "Modification of a DN across a naming context is not permitted.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8369:
		{
			m_sErrorName = "ERROR_DS_CANT_MOD_SYSTEM_ONLY";
			m_sErrorDescription = "The attribute cannot be modified because it is owned by the system.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8370:
		{
			m_sErrorName = "ERROR_DS_REPLICATOR_ONLY";
			m_sErrorDescription = "Only the replicator can perform this function.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8371:
		{
			m_sErrorName = "ERROR_DS_OBJ_CLASS_NOT_DEFINED";
			m_sErrorDescription = "The specified class is not defined.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8372:
		{
			m_sErrorName = "ERROR_DS_OBJ_CLASS_NOT_SUBCLASS";
			m_sErrorDescription = "The specified class is not a subclass.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8373:
		{
			m_sErrorName = "ERROR_DS_NAME_REFERENCE_INVALID";
			m_sErrorDescription = "The name reference is invalid.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8374:
		{
			m_sErrorName = "ERROR_DS_CROSS_REF_EXISTS";
			m_sErrorDescription = "A cross reference already exists.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8375:
		{
			m_sErrorName = "ERROR_DS_CANT_DEL_MASTER_CROSSREF";
			m_sErrorDescription = "It is not permitted to delete a master cross reference.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8376:
		{
			m_sErrorName = "ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD";
			m_sErrorDescription = "Subtree notifications are only supported on NC heads.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8377:
		{
			m_sErrorName = "ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX";
			m_sErrorDescription = "Notification filter is too complex.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8378:
		{
			m_sErrorName = "ERROR_DS_DUP_RDN";
			m_sErrorDescription = "Schema update failed: duplicate RDN. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8379:
		{
			m_sErrorName = "ERROR_DS_DUP_OID";
			m_sErrorDescription = "Schema update failed: duplicate OID ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8380:
		{
			m_sErrorName = "ERROR_DS_DUP_MAPI_ID";
			m_sErrorDescription = "Schema update failed: duplicate MAPI identifier. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8381:
		{
			m_sErrorName = "ERROR_DS_DUP_SCHEMA_ID_GUID";
			m_sErrorDescription = "Schema update failed: duplicate schema-id GUID. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8382:
		{
			m_sErrorName = "ERROR_DS_DUP_LDAP_DISPLAY_NAME";
			m_sErrorDescription = "Schema update failed: duplicate LDAP display name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8383:
		{
			m_sErrorName = "ERROR_DS_SEMANTIC_ATT_TEST";
			m_sErrorDescription = "Schema update failed: range-lower less than range upper ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8384:
		{
			m_sErrorName = "ERROR_DS_SYNTAX_MISMATCH";
			m_sErrorDescription = "Schema update failed: syntax mismatch ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8385:
		{
			m_sErrorName = "ERROR_DS_EXISTS_IN_MUST_HAVE";
			m_sErrorDescription = "Schema deletion failed: attribute is used in must-contain ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8386:
		{
			m_sErrorName = "ERROR_DS_EXISTS_IN_MAY_HAVE";
			m_sErrorDescription = "Schema deletion failed: attribute is used in may-contain ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8387:
		{
			m_sErrorName = "ERROR_DS_NONEXISTENT_MAY_HAVE";
			m_sErrorDescription = "Schema update failed: attribute in may-contain does not exist ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8388:
		{
			m_sErrorName = "ERROR_DS_NONEXISTENT_MUST_HAVE";
			m_sErrorDescription = "Schema update failed: attribute in must-contain does not exist ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8389:
		{
			m_sErrorName = "ERROR_DS_AUX_CLS_TEST_FAIL";
			m_sErrorDescription = "Schema update failed: class in aux-class list does not exist or is not an auxiliary class ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8390:
		{
			m_sErrorName = "ERROR_DS_NONEXISTENT_POSS_SUP";
			m_sErrorDescription = "Schema update failed: class in poss-superiors does not exist ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8391:
		{
			m_sErrorName = "ERROR_DS_SUB_CLS_TEST_FAIL";
			m_sErrorDescription = "Schema update failed: class in subclassof list does not exist or does not satisfy hierarchy rules ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8392:
		{
			m_sErrorName = "ERROR_DS_BAD_RDN_ATT_ID_SYNTAX";
			m_sErrorDescription = "Schema update failed: Rdn-Att-Id has wrong syntax ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8393:
		{
			m_sErrorName = "ERROR_DS_EXISTS_IN_AUX_CLS";
			m_sErrorDescription = "Schema deletion failed: class is used as auxiliary class ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8394:
		{
			m_sErrorName = "ERROR_DS_EXISTS_IN_SUB_CLS";
			m_sErrorDescription = "Schema deletion failed: class is used as sub class ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8395:
		{
			m_sErrorName = "ERROR_DS_EXISTS_IN_POSS_SUP";
			m_sErrorDescription = "Schema deletion failed: class is used as poss superior ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8396:
		{
			m_sErrorName = "ERROR_DS_RECALCSCHEMA_FAILED";
			m_sErrorDescription = "Schema update failed in recalculating validation cache. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8397:
		{
			m_sErrorName = "ERROR_DS_TREE_DELETE_NOT_FINISHED";
			m_sErrorDescription = "The tree deletion is not finished.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8398:
		{
			m_sErrorName = "ERROR_DS_CANT_DELETE";
			m_sErrorDescription = "The requested delete operation could not be performed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8458:
		{
			m_sErrorName = "ERROR_DS_DRA_NAME_COLLISION";
			m_sErrorDescription = "The replication operation failed due to a collision of object names. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8459:
		{
			m_sErrorName = "ERROR_DS_DRA_SOURCE_REINSTALLED";
			m_sErrorDescription = "The replication source has been reinstalled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8460:
		{
			m_sErrorName = "ERROR_DS_DRA_MISSING_PARENT";
			m_sErrorDescription = "The replication operation failed because a required parent object is missing. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8461:
		{
			m_sErrorName = "ERROR_DS_DRA_PREEMPTED";
			m_sErrorDescription = "The replication operation was preempted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8462:
		{
			m_sErrorName = "ERROR_DS_DRA_ABANDON_SYNC";
			m_sErrorDescription = "The replication synchronization attempt was abandoned because of a lack of updates. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8463:
		{
			m_sErrorName = "ERROR_DS_DRA_SHUTDOWN";
			m_sErrorDescription = "The replication operation was terminated because the system is shutting down. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8464:
		{
			m_sErrorName = "ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET";
			m_sErrorDescription = "The replication synchronization attempt failed as the destination partial attribute set is not a subset of source partial attribute set. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
		
	case 8465:
		{
			m_sErrorName = "ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA";
			m_sErrorDescription = "The replication synchronization attempt failed because a master replica attempted to sync from a partial replica. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8466:
		{
			m_sErrorName = "ERROR_DS_DRA_EXTN_CONNECTION_FAILED";
			m_sErrorDescription = "The server specified for this replication operation was contacted, but that server was unable to contact an additional server needed to complete the operation. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8467:
		{
			m_sErrorName = "ERROR_DS_INSTALL_SCHEMA_MISMATCH";
			m_sErrorDescription = "A schema mismatch is detected between the source and the build used during a replica install. The replica cannot be installed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8468:
		{
			m_sErrorName = "ERROR_DS_DUP_LINK_ID";
			m_sErrorDescription = "Schema update failed: An attribute with the same link identifier already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8469:
		{
			m_sErrorName = "ERROR_DS_NAME_ERROR_RESOLVING";
			m_sErrorDescription = "Name translation: Generic processing error. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8470:
		{
			m_sErrorName = "ERROR_DS_NAME_ERROR_NOT_FOUND";
			m_sErrorDescription = "Name translation: Could not find the name or insufficient right to see name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8471:
		{
			m_sErrorName = "ERROR_DS_NAME_ERROR_NOT_UNIQUE";
			m_sErrorDescription = "Name translation: Input name mapped to more than one output name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8472:
		{
			m_sErrorName = "ERROR_DS_NAME_ERROR_NO_MAPPING";
			m_sErrorDescription = "Name translation: Input name found, but not the associated output format. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8473:
		{
			m_sErrorName = "ERROR_DS_NAME_ERROR_DOMAIN_ONLY";
			m_sErrorDescription = "Name translation: Unable to resolve completely, only the domain was found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8474:
		{
			m_sErrorName = "ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING";
			m_sErrorDescription = "Name translation: Unable to perform purely syntactical mapping at the client without going out to the wire. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8475:
		{
			m_sErrorName = "ERROR_DS_CONSTRUCTED_ATT_MOD";
			m_sErrorDescription = "Modification of a constructed att is not allowed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8476:
		{
			m_sErrorName = "ERROR_DS_WRONG_OM_OBJ_CLASS";
			m_sErrorDescription = "The OM-Object-Class specified is incorrect for an attribute with the specified syntax. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8477:
		{
			m_sErrorName = "ERROR_DS_DRA_REPL_PENDING";
			m_sErrorDescription = "The replication request has been posted; waiting for reply. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8478:
		{
			m_sErrorName = "ERROR_DS_DS_REQUIRED";
			m_sErrorDescription = "The requested operation requires a directory service, and none was available.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8479:
		{
			m_sErrorName = "ERROR_DS_INVALID_LDAP_DISPLAY_NAME";
			m_sErrorDescription = "The LDAP display name of the class or attribute contains non-ASCII characters.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8480:
		{
			m_sErrorName = "ERROR_DS_NON_BASE_SEARCH";
			m_sErrorDescription = "The requested search operation is only supported for base searches.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8481:
		{
			m_sErrorName = "ERROR_DS_CANT_RETRIEVE_ATTS";
			m_sErrorDescription = "The search failed to retrieve attributes from the database.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8482:
		{
			m_sErrorName = "ERROR_DS_BACKLINK_WITHOUT_LINK";
			m_sErrorDescription = "The schema update operation tried to add a backward link attribute that has no corresponding forward link.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8483:
		{
			m_sErrorName = "ERROR_DS_EPOCH_MISMATCH";
			m_sErrorDescription = "Source and destination of a cross domain move do not agree on the object's epoch number. Either source or destination does not have the latest version of the object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8484:
		{
			m_sErrorName = "ERROR_DS_SRC_NAME_MISMATCH";
			m_sErrorDescription = "Source and destination of a cross domain move do not agree on the object's current name. Either source or destination does not have the latest version of the object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8485:
		{
			m_sErrorName = "ERROR_DS_SRC_AND_DST_NC_IDENTICAL";
			m_sErrorDescription = "Source and destination of a cross domain move operation are identical. Caller should use local move operation instead of cross domain move operation.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8486:
		{
			m_sErrorName = "ERROR_DS_DST_NC_MISMATCH";
			m_sErrorDescription = "Source and destination for a cross domain move are not in agreement on the naming contexts in the forest. Either source or destination does not have the latest version of the Partitions container.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8487:
		{
			m_sErrorName = "ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC";
			m_sErrorDescription = "Destination of a cross domain move is not authoritative for the destination naming context.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8488:
		{
			m_sErrorName = "ERROR_DS_SRC_GUID_MISMATCH";
			m_sErrorDescription = "Source and destination of a cross domain move do not agree on the identity of the source object. Either source or destination does not have the latest version of the source object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8489:
		{
			m_sErrorName = "ERROR_DS_CANT_MOVE_DELETED_OBJECT";
			m_sErrorDescription = "Object being moved across domains is already known to be deleted by the destination server. The source server does not have the latest version of the source object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8490:
		{
			m_sErrorName = "ERROR_DS_PDC_OPERATION_IN_PROGRESS";
			m_sErrorDescription = "Another operation which requires exclusive access to the PDC PSMO is already in progress. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8491:
		{
			m_sErrorName = "ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD";
			m_sErrorDescription = "A cross domain move operation failed such that the two versions of the moved object exist - one each in the source and destination domains. The destination object needs to be removed to restore the system to a consistent state.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8492:
		{
			m_sErrorName = "ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION";
			m_sErrorDescription = "This object may not be moved across domain boundaries either because cross domain moves for this class are disallowed, or the object has some special characteristics, eg: trust account or restricted RID, which prevent its move.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8493:
		{
			m_sErrorName = "ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS";
			m_sErrorDescription = "Can't move objects with memberships across domain boundaries as once moved, this would violate the membership conditions of the account group. Remove the object from any account group memberships and retry.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8494:
		{
			m_sErrorName = "ERROR_DS_NC_MUST_HAVE_NC_PARENT";
			m_sErrorDescription = "A naming context head must be the immediate child of another naming context head, not of an interior node.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8495:
		{
			m_sErrorName = "ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE";
			m_sErrorDescription = "The directory cannot validate the proposed naming context name because it does not hold a replica of the naming context above the proposed naming context. Please ensure that the domain naming master role is held by a server that is configured as a global catalog server, and that the server is up to date with its replication partners.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8496:
		{
			m_sErrorName = "ERROR_DS_DST_DOMAIN_NOT_NATIVE";
			m_sErrorDescription = "Destination domain must be in native mode.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8497:
		{
			m_sErrorName = "ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER";
			m_sErrorDescription = "The operation can not be performed because the server does not have an infrastructure container in the domain of interest.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8498:
		{
			m_sErrorName = "ERROR_DS_CANT_MOVE_ACCOUNT_GROUP";
			m_sErrorDescription = "Cross domain move of account groups is not allowed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8499:
		{
			m_sErrorName = "ERROR_DS_CANT_MOVE_RESOURCE_GROUP";
			m_sErrorDescription = "Cross domain move of resource groups is not allowed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8500:
		{
			m_sErrorName = "ERROR_DS_INVALID_SEARCH_FLAG";
			m_sErrorDescription = "The search flags for the attribute are invalid. The ANR bit is valid only on attributes of Unicode or Teletex strings.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8501:
		{
			m_sErrorName = "ERROR_DS_NO_TREE_DELETE_ABOVE_NC";
			m_sErrorDescription = "Tree deletions starting at an object which has an NC head as a descendant are not allowed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8502:
		{
			m_sErrorName = "ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE";
			m_sErrorDescription = "The directory service failed to lock a tree in preparation for a tree deletion because the tree was in use.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8503:
		{
			m_sErrorName = "ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE";
			m_sErrorDescription = "The directory service failed to identify the list of objects to delete while attempting a tree deletion.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8504:
		{
			m_sErrorName = "ERROR_DS_SAM_INIT_FAILURE";
			m_sErrorDescription = "Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Click OK to shut down the system and reboot into Directory Services Restore Mode. Check the event log for detailed information.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8505:
		{
			m_sErrorName = "ERROR_DS_SENSITIVE_GROUP_VIOLATION";
			m_sErrorDescription = "Only an administrator can modify the membership list of an administrative group.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8506:
		{
			m_sErrorName = "ERROR_DS_CANT_MOD_PRIMARYGROUPID";
			m_sErrorDescription = "Cannot change the primary group ID of a domain controller account.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8507:
		{
			m_sErrorName = "ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD";
			m_sErrorDescription = "An attempt is made to modify the base schema.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8508:
		{
			m_sErrorName = "ERROR_DS_NONSAFE_SCHEMA_CHANGE";
			m_sErrorDescription = "Adding a new mandatory attribute to an existing class, deleting a mandatory attribute from an existing class, or adding an optional attribute to the special class Top that is not a backlink attribute (directly or through inheritance, for example, by adding or deleting an auxiliary class) is not allowed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8509:
		{
			m_sErrorName = "ERROR_DS_SCHEMA_UPDATE_DISALLOWED";
			m_sErrorDescription = "Schema update is not allowed on this DC. Either the registry key is not set or the DC is not the schema FSMO Role Owner.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8510:
		{
			m_sErrorName = "ERROR_DS_CANT_CREATE_UNDER_SCHEMA";
			m_sErrorDescription = "An object of this class cannot be created under the schema container. You can only create attribute-schema and class-schema objects under the schema container.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8511:
		{
			m_sErrorName = "ERROR_DS_INSTALL_NO_SRC_SCH_VERSION";
			m_sErrorDescription = "The replica/child install failed to get the objectVersion attribute on the schema container on the source DC. Either the attribute is missing on the schema container or the credentials supplied do not have permission to read it.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8512:
		{
			m_sErrorName = "ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE";
			m_sErrorDescription = "The replica/child install failed to read the objectVersion attribute in the SCHEMA section of the file schema.ini in the system32 directory.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8513:
		{
			m_sErrorName = "ERROR_DS_INVALID_GROUP_TYPE";
			m_sErrorDescription = "The specified group type is invalid.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8514:
		{
			m_sErrorName = "ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN";
			m_sErrorDescription = "Cannot nest global groups in a mixed domain if the group is security-enabled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8515:
		{
			m_sErrorName = "ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN";
			m_sErrorDescription = "Cannot nest local groups in a mixed domain if the group is security-enabled.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8516:
		{
			m_sErrorName = "ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER";
			m_sErrorDescription = "A global group cannot have a local group as a member. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8517:
		{
			m_sErrorName = "ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER";
			m_sErrorDescription = "A global group cannot have a universal group as a member. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8518:
		{
			m_sErrorName = "ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER";
			m_sErrorDescription = "A universal group cannot have a local group as a member.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8519:
		{
			m_sErrorName = "ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER";
			m_sErrorDescription = "A global group cannot have a cross-domain member.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8520:
		{
			m_sErrorName = "ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER";
			m_sErrorDescription = "A local group cannot have another cross-domain local group as a member.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8521:
		{
			m_sErrorName = "ERROR_DS_HAVE_PRIMARY_MEMBERS";
			m_sErrorDescription = "A group with primary members cannot change to a security-disabled group.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8522:
		{
			m_sErrorName = "ERROR_DS_STRING_SD_CONVERSION_FAILED";
			m_sErrorDescription = "The schema cache load failed to convert the string default SD on a class-schema object.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8523:
		{
			m_sErrorName = "ERROR_DS_NAMING_MASTER_GC";
			m_sErrorDescription = "Only DSAs configured to be Global Catalog servers should be allowed to hold the Domain Naming Master FSMO role.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8524:
		{
			m_sErrorName = "ERROR_DS_LOOKUP_FAILURE";
			m_sErrorDescription = "The DSA operation is unable to proceed because of a DNS lookup failure. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8525:
		{
			m_sErrorName = "ERROR_DS_COULDNT_UPDATE_SPNS";
			m_sErrorDescription = "While processing a change to the DNS Host Name for an object, the Service Principal Name values could not be kept in sync. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8526:
		{
			m_sErrorName = "ERROR_DS_CANT_RETRIEVE_SD";
			m_sErrorDescription = "The Security Descriptor attribute could not be read.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8527:
		{
			m_sErrorName = "ERROR_DS_KEY_NOT_UNIQUE.";
			m_sErrorDescription = "The object requested was not found, but an object with that key was found.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8528:
		{
			m_sErrorName = "ERROR_DS_WRONG_LINKED_ATT_SYNTAX";
			m_sErrorDescription = "The syntax of the linked attributed being added is incorrect. Forward links can only have syntax 2.5.5.1, 2.5.5.7, and 2.5.5.14, and backlinks can only have syntax 2.5.5.1.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8529:
		{
			m_sErrorName = "ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD";
			m_sErrorDescription = "Security Account Manager needs to get the boot password.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8530:
		{
			m_sErrorName = "ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY";
			m_sErrorDescription = "Security Account Manager needs to get the boot key from floppy disk.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8531:
		{
			m_sErrorName = "ERROR_DS_CANT_START";
			m_sErrorDescription = "Directory Service cannot start.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8532:
		{
			m_sErrorName = "ERROR_DS_INIT_FAILURE";
			m_sErrorDescription = "Directory Services could not start.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8533:
		{
			m_sErrorName = "ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION";
			m_sErrorDescription = "The connection between client and server requires packet privacy or better.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8534:
		{
			m_sErrorName = "ERROR_DS_SOURCE_DOMAIN_IN_FOREST";
			m_sErrorDescription = "The source domain may not be in the same forest as destination.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8535:
		{
			m_sErrorName = "ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST";
			m_sErrorDescription = "The destination domain must be in the forest.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8536:
		{
			m_sErrorName = "ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED";
			m_sErrorDescription = "The operation requires that destination domain auditing be enabled.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8537:
		{
			m_sErrorName = "ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN";
			m_sErrorDescription = "The operation couldn't locate a DC for the source domain.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8538:
		{
			m_sErrorName = "ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER";
			m_sErrorDescription = "The source object must be a group or user.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8539:
		{
			m_sErrorName = "ERROR_DS_SRC_SID_EXISTS_IN_FOREST";
			m_sErrorDescription = "The source object's SID already exists in destination forest.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8540:
		{
			m_sErrorName = "ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH";
			m_sErrorDescription = "The source and destination object must be of the same type.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8541:
		{
			m_sErrorName = "ERROR_SAM_INIT_FAILURE";
			m_sErrorDescription = "Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Click OK to shut down the system and reboot into Safe Mode. Check the event log for detailed information. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8542:
		{
			m_sErrorName = "ERROR_DS_DRA_SCHEMA_INFO_SHIP";
			m_sErrorDescription = "Schema information could not be included in the replication request.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8543:
		{
			m_sErrorName = "ERROR_DS_DRA_SCHEMA_CONFLICT";
			m_sErrorDescription = "The replication operation could not be completed due to a schema incompatibility.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8544:
		{
			m_sErrorName = "ERROR_DS_DRA_EARLIER_SCHEMA_CONLICT";
			m_sErrorDescription = "The replication operation could not be completed due to a previous schema incompatibility.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8545:
		{
			m_sErrorName = "ERROR_DS_DRA_OBJ_NC_MISMATCH";
			m_sErrorDescription = "The replication update could not be applied because either the source or the destination has not yet received information regarding a recent cross-domain move operation.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8546:
		{
			m_sErrorName = "ERROR_DS_NC_STILL_HAS_DSAS";
			m_sErrorDescription = "The requested domain could not be deleted because there exist domain controllers that still host this domain.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8547:
		{
			m_sErrorName = "ERROR_DS_GC_REQUIRED";
			m_sErrorDescription = "The requested operation can be performed only on a global catalog server.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8548:
		{
			m_sErrorName = "ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY";
			m_sErrorDescription = "A local group can only be a member of other local groups in the same domain.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8549:
		{
			m_sErrorName = "ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS";
			m_sErrorDescription = "Foreign security principals cannot be members of universal groups.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8550:
		{
			m_sErrorName = "ERROR_DS_CANT_ADD_TO_GC";
			m_sErrorDescription = "The attribute is not allowed to be replicated to the GC because of security reasons.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8551:
		{
			m_sErrorName = "ERROR_DS_NO_CHECKPOINT_WITH_PDC";
			m_sErrorDescription = "The checkpoint with the PDC could not be taken because there are too many modifications being processed currently.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8552:
		{
			m_sErrorName = "ERROR_DS_SOURCE_AUDITING_NOT_ENABLED";
			m_sErrorDescription = "The operation requires that source domain auditing be enabled.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8553:
		{
			m_sErrorName = "ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC";
			m_sErrorDescription = "Security principal objects can only be created inside domain naming contexts.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8554:
		{
			m_sErrorName = "ERROR_DS_INVALID_NAME_FOR_SPN";
			m_sErrorDescription = "A Service Principal Name (SPN) could not be constructed because the provided hostname is not in the necessary format.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8555:
		{
			m_sErrorName = "ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS";
			m_sErrorDescription = "A Filter was passed that uses constructed attributes.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8556:
		{
			m_sErrorName = "ERROR_DS_UNICODEPWD_NOT_IN_QUOTES";
			m_sErrorDescription = "The unicodePwd attribute value must be enclosed in double quotes.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8557:
		{
			m_sErrorName = "ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED";
			m_sErrorDescription = "Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8558:
		{
			m_sErrorName = "ERROR_DS_MUST_BE_RUN_ON_DST_DC";
			m_sErrorDescription = "For security reasons, the operation must be run on the destination DC.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8559:
		{
			m_sErrorName = "ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER";
			m_sErrorDescription = "For security reasons, the source DC must be Service Pack 4 or greater.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 8560:
		{
			m_sErrorName = "ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ";
			m_sErrorDescription = "Critical Directory Service System objects cannot be deleted during tree delete operations. The tree delete may have been partially performed.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9001:
		{
			m_sErrorName = "DNS_ERROR_RCODE_FORMAT_ERROR";
			m_sErrorDescription = "DNS server unable to interpret format. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9002:
		{
			m_sErrorName = "DNS_ERROR_RCODE_SERVER_FAILURE";
			m_sErrorDescription = "DNS server failure. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9003:
		{
			m_sErrorName = "DNS_ERROR_RCODE_NAME_ERROR";
			m_sErrorDescription = "DNS name does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9004:
		{
			m_sErrorName = "DNS_ERROR_RCODE_NOT_IMPLEMENTED";
			m_sErrorDescription = "DNS request not supported by name server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9005:
		{
			m_sErrorName = "DNS_ERROR_RCODE_REFUSED";
			m_sErrorDescription = "DNS operation refused. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9006:
		{
			m_sErrorName = "DNS_ERROR_RCODE_YXDOMAIN";
			m_sErrorDescription = "DNS name that ought not exist, does exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9007:
		{
			m_sErrorName = "DNS_ERROR_RCODE_YXRRSET";
			m_sErrorDescription = "DNS RR set that ought not exist, does exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9008:
		{
			m_sErrorName = "DNS_ERROR_RCODE_NXRRSET";
			m_sErrorDescription = "DNS RR set that ought to exist, does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9009:
		{
			m_sErrorName = "DNS_ERROR_RCODE_NOTAUTH";
			m_sErrorDescription = "DNS server not authoritative for zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9010:
		{
			m_sErrorName = "DNS_ERROR_RCODE_NOTZONE";
			m_sErrorDescription = "DNS name in update or prereq is not in zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9016:
		{
			m_sErrorName = "DNS_ERROR_RCODE_BADSIG";
			m_sErrorDescription = "DNS signature failed to verify. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9017:
		{
			m_sErrorName = "DNS_ERROR_RCODE_BADKEY";
			m_sErrorDescription = "DNS bad key. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9018:
		{
			m_sErrorName = "DNS_ERROR_RCODE_BADTIME";
			m_sErrorDescription = "DNS signature validity expired. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9501:
		{
			m_sErrorName = "DNS_INFO_NO_RECORDS";
			m_sErrorDescription = "No records found for given DNS query. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9502:
		{
			m_sErrorName = "DNS_ERROR_BAD_PACKET";
			m_sErrorDescription = "Bad DNS packet. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9503:
		{
			m_sErrorName = "DNS_ERROR_NO_PACKET";
			m_sErrorDescription = "No DNS packet. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9504:
		{
			m_sErrorName = "DNS_ERROR_RCODE";
			m_sErrorDescription = "DNS error, check rcode. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9505:
		{
			m_sErrorName = "DNS_ERROR_UNSECURE_PACKET";
			m_sErrorDescription = "Unsecured DNS packet. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9551:
		{
			m_sErrorName = "DNS_ERROR_INVALID_TYPE";
			m_sErrorDescription = "Invalid DNS type. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9552:
		{
			m_sErrorName = "DNS_ERROR_INVALID_IP_ADDRESS";
			m_sErrorDescription = "Invalid IP address. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9553:
		{
			m_sErrorName = "DNS_ERROR_INVALID_PROPERTY";
			m_sErrorDescription = "Invalid property. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9554:
		{
			m_sErrorName = "DNS_ERROR_TRY_AGAIN_LATER";
			m_sErrorDescription = "Try DNS operation again later. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9555:
		{
			m_sErrorName = "DNS_ERROR_NOT_UNIQUE";
			m_sErrorDescription = "Record for given name and type is not unique. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9556:
		{
			m_sErrorName = "DNS_ERROR_NON_RFC_NAME";
			m_sErrorDescription = "DNS name does not comply with RFC specifications. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9557:
		{
			m_sErrorName = "DNS_STATUS_FQDN";
			m_sErrorDescription = "DNS name is a fully-qualified DNS name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9558:
		{
			m_sErrorName = "DNS_STATUS_DOTTED_NAME";
			m_sErrorDescription = "DNS name is dotted (multi-label). ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9559:
		{
			m_sErrorName = "DNS_STATUS_SINGLE_PART_NAME";
			m_sErrorDescription = "DNS name is a single-part name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9560:
		{
			m_sErrorName = "DNS_ERROR_INVALID_NAME_CHAR";
			m_sErrorDescription = "DSN name contains an invalid character.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9561:
		{
			m_sErrorName = "DNS_ERROR_NUMERIC_NAME";
			m_sErrorDescription = "DNS name is entirely numeric.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9601:
		{
			m_sErrorName = "DNS_ERROR_ZONE_DOES_NOT_EXIST";
			m_sErrorDescription = "DNS zone does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9602:
		{
			m_sErrorName = "DNS_ERROR_NO_ZONE_INFO";
			m_sErrorDescription = "DNS zone information not available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9603:
		{
			m_sErrorName = "DNS_ERROR_INVALID_ZONE_OPERATION";
			m_sErrorDescription = "Invalid operation for DNS zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9604:
		{
			m_sErrorName = "DNS_ERROR_ZONE_CONFIGURATION_ERROR";
			m_sErrorDescription = "Invalid DNS zone configuration. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9605:
		{
			m_sErrorName = "DNS_ERROR_ZONE_HAS_NO_SOA_RECORD";
			m_sErrorDescription = "DNS zone has no start of authority (SOA) record. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9606:
		{
			m_sErrorName = "DNS_ERROR_ZONE_HAS_NO_NS_RECORDS";
			m_sErrorDescription = "DNS zone has no name server (NS) record. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9607:
		{
			m_sErrorName = "DNS_ERROR_ZONE_LOCKED";
			m_sErrorDescription = "DNS zone is locked. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9608:
		{
			m_sErrorName = "DNS_ERROR_ZONE_CREATION_FAILED";
			m_sErrorDescription = "DNS zone creation failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9609:
		{
			m_sErrorName = "DNS_ERROR_ZONE_ALREADY_EXISTS";
			m_sErrorDescription = "DNS zone already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9610:
		{
			m_sErrorName = "DNS_ERROR_AUTOZONE_ALREADY_EXISTS";
			m_sErrorDescription = "DNS automatic zone already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9611:
		{
			m_sErrorName = "DNS_ERROR_INVALID_ZONE_TYPE";
			m_sErrorDescription = "Invalid DNS zone type. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9612:
		{
			m_sErrorName = "DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP";
			m_sErrorDescription = "Secondary DNS zone requires master IP address. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9613:
		{
			m_sErrorName = "DNS_ERROR_ZONE_NOT_SECONDARY";
			m_sErrorDescription = "DNS zone not secondary. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9614:
		{
			m_sErrorName = "DNS_ERROR_NEED_SECONDARY_ADDRESSES";
			m_sErrorDescription = "Need secondary IP address. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9615:
		{
			m_sErrorName = "DNS_ERROR_WINS_INIT_FAILED";
			m_sErrorDescription = "WINS initialization failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9616:
		{
			m_sErrorName = "DNS_ERROR_NEED_WINS_SERVERS";
			m_sErrorDescription = "Need WINS servers. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9617:
		{
			m_sErrorName = "DNS_ERROR_NBSTAT_INIT_FAILED";
			m_sErrorDescription = "NBTSTAT initialization call failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9618:
		{
			m_sErrorName = "DNS_ERROR_SOA_DELETE_INVALID";
			m_sErrorDescription = "Invalid delete of start of authority (SOA) ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9651:
		{
			m_sErrorName = "DNS_ERROR_PRIMARY_REQUIRES_DATAFILE";
			m_sErrorDescription = "Primary DNS zone requires datafile. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9652:
		{
			m_sErrorName = "DNS_ERROR_INVALID_DATAFILE_NAME";
			m_sErrorDescription = "Invalid datafile name for DNS zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9653:
		{
			m_sErrorName = "DNS_ERROR_DATAFILE_OPEN_FAILURE";
			m_sErrorDescription = "Failed to open datafile for DNS zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9654:
		{
			m_sErrorName = "DNS_ERROR_FILE_WRITEBACK_FAILED";
			m_sErrorDescription = "Failed to write datafile for DNS zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9655:
		{
			m_sErrorName = "DNS_ERROR_DATAFILE_PARSING";
			m_sErrorDescription = "Failure while reading datafile for DNS zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9701:
		{
			m_sErrorName = "DNS_ERROR_RECORD_DOES_NOT_EXIST";
			m_sErrorDescription = "DNS record does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9702:
		{
			m_sErrorName = "DNS_ERROR_RECORD_FORMAT";
			m_sErrorDescription = "DNS record format error. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9703:
		{
			m_sErrorName = "DNS_ERROR_NODE_CREATION_FAILED";
			m_sErrorDescription = "Node creation failure in DNS. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9704:
		{
			m_sErrorName = "DNS_ERROR_UNKNOWN_RECORD_TYPE";
			m_sErrorDescription = "Unknown DNS record type. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9705:
		{
			m_sErrorName = "DNS_ERROR_RECORD_TIMED_OUT";
			m_sErrorDescription = "DNS record timed out. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9706:
		{
			m_sErrorName = "DNS_ERROR_NAME_NOT_IN_ZONE";
			m_sErrorDescription = "Name not in DNS zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9707:
		{
			m_sErrorName = "DNS_ERROR_CNAME_LOOP";
			m_sErrorDescription = "CNAME loop detected. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9708:
		{
			m_sErrorName = "DNS_ERROR_NODE_IS_CNAME";
			m_sErrorDescription = "Node is a CNAME DNS record. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9709:
		{
			m_sErrorName = "DNS_ERROR_CNAME_COLLISION";
			m_sErrorDescription = "A CNAME record already exists for given name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9710:
		{
			m_sErrorName = "DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT";
			m_sErrorDescription = "Record only at DNS zone root. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9711:
		{
			m_sErrorName = "DNS_ERROR_RECORD_ALREADY_EXISTS";
			m_sErrorDescription = "DNS record already exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9712:
		{
			m_sErrorName = "DNS_ERROR_SECONDARY_DATA";
			m_sErrorDescription = "Secondary DNS zone data error. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9713:
		{
			m_sErrorName = "DNS_ERROR_NO_CREATE_CACHE_DATA";
			m_sErrorDescription = "Could not create DNS cache data. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9714:
		{
			m_sErrorName = "DNS_ERROR_NAME_DOES_NOT_EXIST";
			m_sErrorDescription = "DNS name does not exist. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9715:
		{
			m_sErrorName = "DNS_WARNING_PTR_CREATE_FAILED";
			m_sErrorDescription = "Could not create pointer (PTR) record. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9716:
		{
			m_sErrorName = "DNS_WARNING_DOMAIN_UNDELETED";
			m_sErrorDescription = "DNS domain was undeleted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9717:
		{
			m_sErrorName = "DNS_ERROR_DS_UNAVAILABLE";
			m_sErrorDescription = "The directory service is unavailable. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9718:
		{
			m_sErrorName = "DNS_ERROR_DS_ZONE_ALREADY_EXISTS";
			m_sErrorDescription = "DNS zone already exists in the directory service. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9719:
		{
			m_sErrorName = "DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE";
			m_sErrorDescription = "DNS server not creating or reading the boot file for the directory service integrated DNS zone. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9751:
		{
			m_sErrorName = "DNS_INFO_AXFR_COMPLETE";
			m_sErrorDescription = "DNS AXFR (zone transfer) complete. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9752:
		{
			m_sErrorName = "DNS_ERROR_AXFR";
			m_sErrorDescription = "DNS zone transfer failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9753:
		{
			m_sErrorName = "DNS_INFO_ADDED_LOCAL_WINS";
			m_sErrorDescription = "Added local WINS server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9801:
		{
			m_sErrorName = "DNS_STATUS_CONTINUE_NEEDED";
			m_sErrorDescription = "Secure update call needs to continue update request. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9851:
		{
			m_sErrorName = "DNS_ERROR_NO_TCPIP";
			m_sErrorDescription = "TCP/IP network protocol not installed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 9852:
		{
			m_sErrorName = "DNS_ERROR_NO_DNS_SERVERS";
			m_sErrorDescription = "No DNS servers configured for local system. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10004:
		{
			m_sErrorName = "WSAEINTR";
			m_sErrorDescription = "A blocking operation was interrupted by a call to WSACancelBlockingCall. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10009:
		{
			m_sErrorName = "WSAEBADF";
			m_sErrorDescription = "The file handle supplied is not valid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10013:
		{
			m_sErrorName = "WSAEACCES";
			m_sErrorDescription = "An attempt was made to access a socket in a way forbidden by its access permissions. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10014:
		{
			m_sErrorName = "WSAEFAULT";
			m_sErrorDescription = "The system detected an invalid pointer address in attempting to use a pointer argument in a call. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10022:
		{
			m_sErrorName = "WSAEINVAL";
			m_sErrorDescription = "An invalid argument was supplied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10024:
		{
			m_sErrorName = "WSAEMFILE";
			m_sErrorDescription = "Too many open sockets. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10035:
		{
			m_sErrorName = "WSAEWOULDBLOCK";
			m_sErrorDescription = "A non-blocking socket operation could not be completed immediately. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10036:
		{
			m_sErrorName = "WSAEINPROGRESS";
			m_sErrorDescription = "A blocking operation is currently executing. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10037:
		{
			m_sErrorName = "WSAEALREADY";
			m_sErrorDescription = "An operation was attempted on a non-blocking socket that already had an operation in progress. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10038:
		{
			m_sErrorName = "WSAENOTSOCK";
			m_sErrorDescription = "An operation was attempted on something that is not a socket. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10039:
		{
			m_sErrorName = "WSAEDESTADDRREQ";
			m_sErrorDescription = "A required address was omitted from an operation on a socket. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10040:
		{
			m_sErrorName = "WSAEMSGSIZE";
			m_sErrorDescription = "A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram into was smaller than the datagram itself. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10041:
		{
			m_sErrorName = "WSAEPROTOTYPE";
			m_sErrorDescription = "A protocol was specified in the socket function call that does not support the semantics of the socket type requested. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10042:
		{
			m_sErrorName = "WSAENOPROTOOPT";
			m_sErrorDescription = "An unknown, invalid, or unsupported option or level was specified in a getsockopt or setsockopt call. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10043:
		{
			m_sErrorName = "WSAEPROTONOSUPPORT";
			m_sErrorDescription = "The requested protocol has not been configured into the system, or no implementation for it exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10044:
		{
			m_sErrorName = "WSAESOCKTNOSUPPORT";
			m_sErrorDescription = "The support for the specified socket type does not exist in this address family. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10045:
		{
			m_sErrorName = "WSAEOPNOTSUPP";
			m_sErrorDescription = "The attempted operation is not supported for the type of object referenced. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10046:
		{
			m_sErrorName = "WSAEPFNOSUPPORT";
			m_sErrorDescription = "The protocol family has not been configured into the system or no implementation for it exists. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10047:
		{
			m_sErrorName = "WSAEAFNOSUPPORT";
			m_sErrorDescription = "An address incompatible with the requested protocol was used. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10048:
		{
			m_sErrorName = "WSAEADDRINUSE";
			m_sErrorDescription = "Only one usage of each socket address (protocol/network address/port) is normally permitted. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10049:
		{
			m_sErrorName = "WSAEADDRNOTAVAIL";
			m_sErrorDescription = "The requested address is not valid in its context. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10050:
		{
			m_sErrorName = "WSAENETDOWN";
			m_sErrorDescription = "A socket operation encountered a dead network. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10051:
		{
			m_sErrorName = "WSAENETUNREACH";
			m_sErrorDescription = "A socket operation was attempted to an unreachable network. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10052:
		{
			m_sErrorName = "WSAENETRESET";
			m_sErrorDescription = "The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10053:
		{
			m_sErrorName = "WSAECONNABORTED";
			m_sErrorDescription = "An established connection was aborted by the software in your host machine. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10054:
		{
			m_sErrorName = "WSAECONNRESET";
			m_sErrorDescription = "An existing connection was forcibly closed by the remote host. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10055:
		{
			m_sErrorName = "WSAENOBUFS";
			m_sErrorDescription = "An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10056:
		{
			m_sErrorName = "WSAEISCONN";
			m_sErrorDescription = "A connect request was made on an already connected socket. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10057:
		{
			m_sErrorName = "WSAENOTCONN";
			m_sErrorDescription = "A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using a sendto call) no address was supplied. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10058:
		{
			m_sErrorName = "WSAESHUTDOWN";
			m_sErrorDescription = "A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10059:
		{
			m_sErrorName = "WSAETOOMANYREFS";
			m_sErrorDescription = "Too many references to some kernel object. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10060:
		{
			m_sErrorName = "WSAETIMEDOUT";
			m_sErrorDescription = "A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10061:
		{
			m_sErrorName = "WSAECONNREFUSED";
			m_sErrorDescription = "No connection could be made because the target machine actively refused it. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10062:
		{
			m_sErrorName = "WSAELOOP";
			m_sErrorDescription = "Cannot translate name. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10063:
		{
			m_sErrorName = "WSAENAMETOOLONG";
			m_sErrorDescription = "Name component or name was too long. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10064:
		{
			m_sErrorName = "WSAEHOSTDOWN";
			m_sErrorDescription = "A socket operation failed because the destination host was down. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10065:
		{
			m_sErrorName = "WSAEHOSTUNREACH";
			m_sErrorDescription = "A socket operation was attempted to an unreachable host. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10066:
		{
			m_sErrorName = "WSAENOTEMPTY";
			m_sErrorDescription = "Cannot remove a directory that is not empty. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10067:
		{
			m_sErrorName = "WSAEPROCLIM";
			m_sErrorDescription = "A Windows Sockets implementation may have a limit on the number of applications that may use it simultaneously. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10068:
		{
			m_sErrorName = "WSAEUSERS";
			m_sErrorDescription = "Ran out of quota. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10069:
		{
			m_sErrorName = "WSAEDQUOT";
			m_sErrorDescription = "Ran out of disk quota. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10070:
		{
			m_sErrorName = "WSAESTALE";
			m_sErrorDescription = "File handle reference is no longer available. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10071:
		{
			m_sErrorName = "WSAEREMOTE";
			m_sErrorDescription = "Item is not available locally. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10091:
		{
			m_sErrorName = "WSASYSNOTREADY";
			m_sErrorDescription = "WSAStartup cannot function at this time because the underlying system it uses to provide network services is currently unavailable. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10092:
		{
			m_sErrorName = "WSAVERNOTSUPPORTED";
			m_sErrorDescription = "The Windows Sockets version requested is not supported. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10093:
		{
			m_sErrorName = "WSANOTINITIALISED";
			m_sErrorDescription = "Either the application has not called WSAStartup, or WSAStartup failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10101:
		{
			m_sErrorName = "WSAEDISCON";
			m_sErrorDescription = "Returned by WSARecv or WSARecvFrom to indicate the remote party has initiated a graceful shutdown sequence. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10102:
		{
			m_sErrorName = "WSAENOMORE";
			m_sErrorDescription = "No more results can be returned by WSALookupServiceNext. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10103:
		{
			m_sErrorName = "WSAECANCELLED";
			m_sErrorDescription = "A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10104:
		{
			m_sErrorName = "WSAEINVALIDPROCTABLE";
			m_sErrorDescription = "The procedure call table is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10105:
		{
			m_sErrorName = "WSAEINVALIDPROVIDER";
			m_sErrorDescription = "The requested service provider is invalid. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10106:
		{
			m_sErrorName = "WSAEPROVIDERFAILEDINIT";
			m_sErrorDescription = "The requested service provider could not be loaded or initialized. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10107:
		{
			m_sErrorName = "WSASYSCALLFAILURE";
			m_sErrorDescription = "A system call that should never fail has failed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10108:
		{
			m_sErrorName = "WSASERVICE_NOT_FOUND";
			m_sErrorDescription = "No such service is known. The service cannot be found in the specified name space. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10109:
		{
			m_sErrorName = "WSATYPE_NOT_FOUND";
			m_sErrorDescription = "The specified class was not found. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10110:
		{
			m_sErrorName = "WSA_E_NO_MORE";
			m_sErrorDescription = "No more results can be returned by WSALookupServiceNext. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10111:
		{
			m_sErrorName = "WSA_E_CANCELLED";
			m_sErrorDescription = "A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 10112:
		{
			m_sErrorName = "WSAEREFUSED";
			m_sErrorDescription = "A database query failed because it was actively refused. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11001:
		{
			m_sErrorName = "WSAHOST_NOT_FOUND";
			m_sErrorDescription = "No such host is known. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11002:
		{
			m_sErrorName = "WSATRY_AGAIN";
			m_sErrorDescription = "This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11003:
		{
			m_sErrorName = "WSANO_RECOVERY";
			m_sErrorDescription = "A non-recoverable error occurred during a database lookup. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11004:
		{
			m_sErrorName = "WSANO_DATA";
			m_sErrorDescription = "The requested name is valid and was found in the database, but it does not have the correct associated data being resolved for. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11005:
		{
			m_sErrorName = "WSA_QOS_RECEIVERS";
			m_sErrorDescription = "At least one reserve has arrived. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11006:
		{
			m_sErrorName = "WSA_QOS_SENDERS";
			m_sErrorDescription = "At least one path has arrived. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11007:
		{
			m_sErrorName = "WSA_QOS_NO_SENDERS";
			m_sErrorDescription = "There are no senders. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11008:
		{
			m_sErrorName = "WSA_QOS_NO_RECEIVERS";
			m_sErrorDescription = "There are no receivers. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11009:
		{
			m_sErrorName = "WSA_QOS_REQUEST_CONFIRMED";
			m_sErrorDescription = "Reserve has been confirmed. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11010:
		{
			m_sErrorName = "WSA_QOS_ADMISSION_FAILURE";
			m_sErrorDescription = "Error due to lack of resources. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11011:
		{
			m_sErrorName = "WSA_QOS_POLICY_FAILURE";
			m_sErrorDescription = "Rejected for administrative reasons - bad credentials. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11012:
		{
			m_sErrorName = "WSA_QOS_BAD_STYLE";
			m_sErrorDescription = "Unknown or conflicting style. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11013:
		{
			m_sErrorName = "WSA_QOS_BAD_OBJECT";
			m_sErrorDescription = "Problem with some part of the filterspec or providerspecific buffer in general. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11014:
		{
			m_sErrorName = "WSA_QOS_TRAFFIC_CTRL_ERROR";
			m_sErrorDescription = "Problem with some part of the flowspec. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11015:
		{
			m_sErrorName = "WSA_QOS_GENERIC_ERROR";
			m_sErrorDescription = "General QOS error. ";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11016:
		{
			m_sErrorName = "WSA_QOS_ESERVICETYPE";
			m_sErrorDescription = "An invalid or unrecognized service type was found in the flowspec.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11017:
		{
			m_sErrorName = "WSA_QOS_EFLOWSPEC";
			m_sErrorDescription = "An invalid or inconsistent flowspec was found in the QOS structure.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11018:
		{
			m_sErrorName = "WSA_QOS_EPROVSPECBUF";
			m_sErrorDescription = "Invalid QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11019:
		{
			m_sErrorName = "WSA_QOS_EFILTERSTYLE";
			m_sErrorDescription = "An invalid QOS filter style was used.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11020:
		{
			m_sErrorName = "WSA_QOS_EFILTERTYPE";
			m_sErrorDescription = "An invalid QOS filter type was used.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11021:
		{
			m_sErrorName = "WSA_QOS_EFILTERCOUNT";
			m_sErrorDescription = "An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11022:
		{
			m_sErrorName = "WSA_QOS_EOBJLENGTH";
			m_sErrorDescription = "An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11023:
		{
			m_sErrorName = "WSA_QOS_EFLOWCOUNT";
			m_sErrorDescription = "An incorrect number of flow descriptors was specified in the QOS structure.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11024:
		{
			m_sErrorName = "WSA_QOS_EUNKNOWNPSOBJ";
			m_sErrorDescription = "An unrecognized object was found in the QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11025:
		{
			m_sErrorName = "WSA_QOS_EPOLICYOBJ";
			m_sErrorDescription = "An invalid policy object was found in the QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11026:
		{
			m_sErrorName = "WSA_QOS_EFLOWDESC";
			m_sErrorDescription = "An invalid QOS flow descriptor was found in the flow descriptor list.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11027:
		{
			m_sErrorName = "WSA_QOS_EPSFLOWSPEC";
			m_sErrorDescription = "An invalid or inconsistent flowspec was found in the QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11028:
		{
			m_sErrorName = "WSA_QOS_EPSFILTERSPEC";
			m_sErrorDescription = "An invalid FILTERSPEC was found in the QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11029:
		{
			m_sErrorName = "WSA_QOS_ESDMODEOBJ";
			m_sErrorDescription = "An invalid shape discard mode object was found in the QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11030:
		{
			m_sErrorName = "WSA_QOS_ESHAPERATEOBJ";
			m_sErrorDescription = "An invalid shaping rate object was found in the QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	case 11031:
		{
			m_sErrorName = "WSA_QOS_RESERVED_PETYPE";
			m_sErrorDescription = "A reserved policy element was found in the QOS provider-specific buffer.";
			m_sErrorLabel = m_sErrorDescription;
			break;
		}
	}
}

BOOL CWin32Exception::GetErrorMessage(LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext)
{
	if((UINT)m_sErrorLabel.GetLength() >= nMaxError)
		return FALSE;

	strcpy(lpszError, m_sErrorLabel);
	return TRUE;
}

int CWin32Exception::ReportError(UINT nType, UINT nMessageID)
{
	CString sPrompt;
	sPrompt.Format("%s\r\n\r\n错误名称：%s\r\n错误代码：%ld", m_sErrorLabel, m_sErrorName, m_nErrorCode);

	return ::MessageBox(NULL, sPrompt, "系统错误", nMessageID);
}
