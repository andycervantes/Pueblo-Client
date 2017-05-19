#include <stdarg.h>
#include <QvString.h>
#include <QvInput.h>
#include <QvReadError.h>
#if (defined(WIN32) && !defined(_CONSOLE)) || defined(WIN16)
#include <windows.h>
#endif

// This is defined in ChConst.h, if you change this ID then update 
// ChConst.h
#if !defined( WM_VRML_PARSE_ERROR )
#define WM_VRML_PARSE_ERROR					(WM_USER + 406)
#endif

void
QvReadError::post(const QvInput *in, const char *formatString ...)
{
    char	buf[10000];
    va_list	ap;

    va_start(ap, formatString);
    vsprintf(buf, formatString, ap);
    va_end(ap);

    QvString locstr;
    in->getLocationString(locstr);
#if (defined(WIN32) && !defined(_CONSOLE)) || defined(WIN16)
	char *abuf = new char[500];
	wsprintf(abuf,"VRML read error: %s\n%s\n", buf, locstr.getString());
	if ( !in->GetAsyncNotificationInfo() )
	{
		MessageBox(0, abuf, 0, MB_OK | MB_ICONEXCLAMATION );
		delete [] abuf;
	}
	else
	{
		HWND hNotify = (HWND)in->GetAsyncNotificationInfo();
		::PostMessage( hNotify, WM_VRML_PARSE_ERROR, 0, (LPARAM)abuf );
	}
#else
    fprintf(stderr, "VRML read error: %s\n%s\n", buf, locstr.getString());
#endif
}
