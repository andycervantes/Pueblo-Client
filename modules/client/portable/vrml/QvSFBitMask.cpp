#include <QvDebugError.h>
#include <QvReadError.h>
#include <QvSFBitMask.h>

// Special characters when reading or writing value in ASCII
#define OPEN_PAREN	'('
#define CLOSE_PAREN	')'
#define BITWISE_OR	'|'

QV_SFIELD_SOURCE(QvSFBitMask);

QvBool
QvSFBitMask::readValue(QvInput *in)
{
    char	c;
    QvName	n;
    int		v;
								  // JWD: changed this to save string value if
								  // not initalized. This normally happens if 
								  // this is in an unknown node
#ifdef DEBUG
    if (enumValues == NULL) {
		QvDebugError::post("QvSFBitMask::readValue",
				   "Enum values were never initialized");
		QvReadError::post(in, "Couldn't read QvSFBitMask values");
		return FALSE;
    }
#endif /* DEBUG */

    value = 0;

    // Read first character
    if (! in->read(c))
	return FALSE;

    // Check for parenthesized list of bitwise-or'ed flags
    if (c == OPEN_PAREN) {
		if(enumValues == NULL)
		{
			strValue = "(";
		}

		// Read names separated by BITWISE_OR
		while (TRUE) {
		    if (in->read(n, TRUE) && ! (! n) ) {

				if (findEnumValue(n, v))
				    value |= v;

				else {
					if(enumValues != NULL)
					{
					    QvReadError::post(in, "Unknown QvSFBitMask bit "
							      "mask value \"%s\"", n.getString());
					    return FALSE;
					}
					else
					{
								// TODO: Append value to string value
										//  Must be QvUnknownNode, we hope
										//  Insert value n to string value
						strValue += n.getString();
					}
				}
		    }

		    if (! in->read(c)) {
				QvReadError::post(in, "EOF reached before '%c' "
						  "in QvSFBitMask value", CLOSE_PAREN);
				return FALSE;
		    }

		    if (c == CLOSE_PAREN)
			{
				if(enumValues == NULL)
				{
					strValue += ")";
				}
				break;
			}

		    else if (c != BITWISE_OR) {
				QvReadError::post(in, "Expected '%c' or '%c', got '%c' ",
						  "in QvSFBitMask value",
						  BITWISE_OR, CLOSE_PAREN, c);
				return FALSE;
		    }
			if(enumValues == NULL)
			{
				strValue += " | ";
			}

		}
    }

    else {
		in->putBack(c);

		// Read mnemonic value as a character string identifier
		if (! in->read(n, TRUE))
		    return FALSE;

		if (! findEnumValue(n, value)) {
			if(enumValues != NULL)
			{

			    QvReadError::post(in, "Unknown QvSFBitMask bit "
					      "mask value \"%s\"", n.getString());
			    return FALSE;
			}
			else
			{
								//  Must be QvUnknownNode, we hope
								//  Insert value n to string value
				strValue = n.getString();
			}
		}
    }

    return TRUE;
}
