#include <afxwin.h>
#include <ChTypes.h>
#include <iostream.h>
#include <process.h>
#include <afxext.h>						// MFC extensions

#include <winsock.h>
#include <ChData.h>
#include <ChMData.h>
#include <ChArch.h>
#include <ChTime.h>

void writeDate( ChTime  t, ostream & s );
bool TestArchive(  ChTime t, ChTimeSpan span, ostream & s );

main()
{
	ChTime now = ChTime::GetCurrentTime();

	cout << "Now:\n";
	writeDate( now, cout );

	ChTime eoy = ChTime(1969, 11, 31, 23, 59, 0);

	cout << "1 minute before 1970:\n";
	writeDate( eoy, cout );

	ChTimeSpan oneCent(365L * 100 + 25, 0, 0, 0);
	eoy -= oneCent;
	cout << "1 century before 1 minute before 1970:\n";
	writeDate( eoy, cout );

	cout << endl << "Testing some span arithmetic." << endl;

	ChTime aYearAgo = ChTime(now.GetYear() - 1, now.GetMonth(), now.GetDay(), now.GetHour(), now.GetMinute(), now.GetSecond());
	ChTimeSpan aYear = now - aYearAgo;

	cout << "A Year ago was:" << endl;
	writeDate(aYearAgo, cout);
	cout << "  which is " << aYear.GetDays() << " days ago." << endl;

	cout << endl << " A century timespan is: " << oneCent.Format() << endl;
	ChTimeSpan abit = ChTimeSpan(1,1,1,1);
	cout << " Timespan of (1,1,1,1) is: " << abit.Format() << endl;
	cout 	<< " A century negated, less (1,1,1,1) is: " 
			<< (ChTimeSpan(0) - oneCent - abit).Format() 
			<< endl;

	cout << endl << "Archiving date after 1970, positive span." << endl;
	TestArchive(now, oneCent, cout); 
	cout << endl <<"Archiving date before 1970, negative span." << endl;
	TestArchive(eoy, (ChTimeSpan(0) - oneCent - abit), cout); 

	return 0;
}

void writeDate( ChTime  t, ostream & s )
{
	string str;
	s << " Year: " << t.GetYear() << endl;
	s << " Month: " <<  t.GetMonth() << endl;
	s << " Day: " << t.GetDay() << endl;
	s << " Hour: " << t.GetHour() << endl;
	s << " Min: " << t.GetMinute() << endl;
	s << " Sec: " << t.GetSecond() << endl;
	s << " Day of Week: " << t.GetDayOfWeek() << endl;
	str = t.Format("%#c");
	s << " Long format: " << str << endl;
}

bool TestArchive( ChTime t, ChTimeSpan span, ostream & s )
{
	ChMemData myData;
	{
		ChArchive archOut(&myData, modeWrite );
		archOut << t << span;
	}
	ChArchive archIn(&myData, modeRead );
	ChTime newT;
	ChTimeSpan newSpan;

	archIn >> newT;
	archIn >> newSpan;

	bool bool1 = (t == newT);
	s << " Archive of ChTime " << (bool1 ? "succeeded." : "FAILED!") << endl;
	bool bool2 = (span == newSpan);
	s << " Archive of ChTimeSpan " << (bool2 ? "succeeded." : "FAILED!") << endl;
	return bool1 && bool2;
}
		   					
