#include <winscard.h>
#include <sstream>
#include <iomanip>
#include "scardexception.h"
#include "scarddefs.h"

SCardException::SCardException(long id) 
	: _id(id)
{}

long SCardException::getId() {

	return _id;
}

String SCardException::what() {

	std::stringstream err;

	err << "ScardException " << std::setfill('0') 
		<< std::setw(8) << std::hex << getId() << ": " << getMessage();
	
	return err.str();
}

char* SCardException:: getMessage() {

	switch(_id){

		case SCARD_F_INTERNAL_ERROR:
			return "An internal consistency check failed.";

		case SCARD_E_INVALID_HANDLE:
			return "The supplied handle was not valid.";

		case SCARD_E_INVALID_TARGET:
			return "Registry startup information is missing or not valid.";

		case SCARD_F_WAITED_TOO_LONG:
			return "An internal consistency timer has expired.";

		case SCARD_E_INSUFFICIENT_BUFFER:
			return "The data buffer for returned data is too small for the returned data.";

		case SCARD_E_TIMEOUT:
			return "The user-specified time-out value has expired.";

		case SCARD_E_SHARING_VIOLATION:
			return "The smart card cannot be accessed because of other outstanding connections.";

		case SCARD_E_NO_SMARTCARD:
			return "The operation requires a smart card, but no smart card is currently in the device.";

		case SCARD_E_UNKNOWN_CARD:
			return "The specified smart card name is not recognized.";

		case SCARD_E_PROTO_MISMATCH:
			return "The requested protocols are incompatible with the protocol currently in use with the card.";

		case SCARD_E_NOT_READY:
			return "The reader or card is not ready to accept commands.";

		case SCARD_E_SYSTEM_CANCELLED:
			return "The action was canceled by the system, presumably to log off or shut down.";

		case SCARD_F_COMM_ERROR:
			return "An internal communications error has been detected.";

		case SCARD_F_UNKNOWN_ERROR:
			return "An internal error has been detected, but the source is unknown.";

		case SCARD_E_INVALID_ATR:
			return "An ATR string obtained from the registry is not a valid ATR string.";

		case SCARD_E_READER_UNAVAILABLE:
			return "The specified reader is not currently available for use.";

		case SCARD_P_SHUTDOWN:
			return "The operation has been aborted to allow the server application to exit.";

		case SCARD_E_PCI_TOO_SMALL:
			return "The PCI receive buffer was too small.";

		case SCARD_E_READER_UNSUPPORTED:
			return "The reader driver does not meet minimal requirements for support.";

		case SCARD_E_CARD_UNSUPPORTED:
			return "The smart card does not meet minimal requirements for support.";

		case SCARD_E_SERVICE_STOPPED:
			return "The smart card resource manager has shut down.";

		case SCARD_W_UNSUPPORTED_CARD:
			return "The reader cannot communicate with the card, due to ATR string configuration conflicts.";

		case SCARD_W_UNRESPONSIVE_CARD:
			return "The smart card is not responding to a reset.";

		case SCARD_W_UNPOWERED_CARD:
			return "Power has been removed from the smart card, so that further communication is not possible.";

		case SCARD_W_RESET_CARD:
			return "The smart card was reset.";

		case SCARD_W_REMOVED_CARD:
			return "The smart card has been removed, so further communication is not possible.";

		case SCARD_E_NO_READERS_AVAILABLE:
			return "Cannot find a smart card reader.";

		case SCARD_E_NO_RESRC_MNGR_RUNNING:
			return "The Smart card resource manager is not running.";

		case ERROR_BROKEN_PIPE:
			return "The client attempted a smart card operation in a remote session, such as a client session running on a terminal server, and the operating system in use does not support smart card redirection.";

		case SCARD_E_BAD_SEEK:
			return	"An error occurred in setting the smart card file object pointer.";

		case SCARD_E_CANCELLED:
			return "The action was canceled by an SCardCancel request.";

		case SCARD_E_CANT_DISPOSE:
			return "The system could not dispose of the media in the requested manner.";

		case SCARD_E_CERTIFICATE_UNAVAILABLE:
			return "The requested certificate could not be obtained.";

		case SCARD_E_COMM_DATA_LOST:
			return "A communications error with the smart card has been detected.";

		case SCARD_E_DIR_NOT_FOUND:
			return "The specified directory does not exist in the smart card.";

		case SCARD_E_DUPLICATE_READER:
			return "The reader driver did not produce a unique reader name.";

		case SCARD_E_FILE_NOT_FOUND:
			return "The specified file does not exist in the smart card.";

		case SCARD_E_ICC_CREATEORDER:
			return "The requested order of object creation is not supported.";

		case SCARD_E_ICC_INSTALLATION:
			return "No primary provider can be found for the smart card.";

		case SCARD_E_INVALID_CHV:
			return "The supplied PIN is incorrect.";

		case SCARD_E_INVALID_PARAMETER:
			return "One or more of the supplied parameters could not be properly interpreted.";

		case SCARD_E_INVALID_VALUE:
			return "One or more of the supplied parameter values could not be properly interpreted.";

		case SCARD_E_NO_ACCESS:
			return "Access is denied to the file.";

		case SCARD_E_NO_DIR:
			return "The supplied path does not represent a smart card directory.";

		case SCARD_E_NO_FILE:
			return "The supplied path does not represent a smart card file.";

		case SCARD_E_NO_MEMORY:
			return "Not enough memory available to complete this command.";

		case SCARD_E_NO_SUCH_CERTIFICATE:
			return "The requested certificate does not exist.";

		case SCARD_E_NOT_TRANSACTED:
			return "An attempt was made to end a nonexistent transaction.";

		case SCARD_E_UNEXPECTED:
			return "An unexpected card error has occurred.";

		case SCARD_E_UNKNOWN_READER:
			return "The specified reader name is not recognized.";

		case SCARD_E_UNKNOWN_RES_MNG:
			return "An unrecognized error code was returned.";

		case SCARD_E_UNSUPPORTED_FEATURE:
			return "This smart card does not support the requested feature.";

		case SCARD_E_WRITE_TOO_MANY:
			return "An attempt was made to write more data than would fit in the target object.";

		case SCARD_S_SUCCESS:
			return "No error was encountered.";

		case SCARD_W_CANCELLED_BY_USER:
			return "The action was canceled by the user.";

		case SCARD_W_CHV_BLOCKED:
			return "The card cannot be accessed because the maximum number of PIN entry attempts has been reached.";

		case SCARD_W_EOF:
			return "The end of the smart card file has been reached.";

		case SCARD_W_SECURITY_VIOLATION:
			return "Access was denied because of a security violation.";

		case SCARD_W_WRONG_CHV:
			return "The card cannot be accessed because the wrong PIN was presented.";
			
		default:
			return "Unknown error.";

	}
		
}
